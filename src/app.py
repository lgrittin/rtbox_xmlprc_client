# ===============================================================================
# PYTHON INTERACTIVE GUI XMLPRC CLIENT FOR RT-BOX
# 
# Luca Grittini
# 20/03/2023
# ===============================================================================

import traceback
import sys
import socket
import time
import base64
import xmlrpc.client
import pathlib
import os
import sys
import concurrent.futures
import requests
import threading

from PyQt5 import QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication, QDialog, QMainWindow, QMessageBox, QFileDialog, QLabel, QVBoxLayout
from pyqtgraph import PlotWidget, plot
from PyQt5.QtCore import QTimer, Qt, QObject, QThread, pyqtSignal, QThreadPool, QRunnable
from PyQt5.QtGui import QCursor
from PyQt5.uic import loadUi
from socket import gaierror
from enum import Enum
from pathlib import Path
from main_window_ui import Ui_MainWindow
from settings_ui import Ui_Dialog

import pyqtgraph as pg
import numpy as np
import sip

# ===============================================================================
# GLOBALS
# ===============================================================================

## CONNECTIVITY
RTBOX_MACADDRESS = "20b0f7047680"
HOST_NAME = "rtbox-" + RTBOX_MACADDRESS + ".local"
HOST_IPV4 = "000.000.000.000"
HOST_ADDRESS = "http://" + HOST_IPV4 + ":9998/RPC2"
INPUTBLOCKS = [0]
OUTPUTBLOCKS = [0]
#DESIGN_NAME = "sim_correnti_tensioni"
DESIGN_PATH = str(pathlib.Path().resolve().parent.joinpath('plecs_design'))
RTBOX_SERVER_XMLPRC = 0
ConnectionStatus = Enum('ConnectionStatus', ["NOT_CONNECTED", "CONNECTED"])
RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED
RTBOX_IPFOUND = ConnectionStatus.NOT_CONNECTED
DeviceStatus = Enum('DeviceStatus', ['STOPPED', 'RUNNING', 'LOADING_DESIGN', 'DESIGN_LOADED', 'ERROR'])
RTBOX_STATUS = DeviceStatus.STOPPED
RTBOX_STATUS_INT = 0

## STATUS DISPLAY
dispListColor = ["background-color: red", "background-color: lightgreen"]
dispList_ConnectionStatus = ["Not Connected", "Connected"]
dispListColor2 = ["background-color: orange", "background-color: lightgreen", "background-color: orange"]
dispList_DeviceStatus = ["Stopped", "Running", "Error"]
dispList_Ipv4 = ["No IP", HOST_IPV4]
TOUT_settingsDialog_RefreshLabels_ms = 500
TOUT_mainWindow_RefreshStatusBar_ms = 500
TOUT_mainWindow_RefreshWrite_ms = 2000
TOUT_mainWindow_RefreshRead_ms = 2000

## Specific Implementation
DESIGN_TDISC_US = 10
DESIGN_FLINE_HZ = 50
DATA_DIM = int(1/(DESIGN_FLINE_HZ*DESIGN_TDISC_US*0.000001)/4)
V_AC_Ampl = 0.0
V_AC_Freq = 50
V_AC_Ena = -1
V_AC_RampTime = 0.1
WhiteNoise_AC_Ampl = 0.0
WhiteNoise_AC_Ena = 0
SwitchingNoise_AC_Ampl = 0.0
SwitchingNoise_AC_Freq = 680.0
SwitchingNoise_AC_Ena = 0
UnbalVoltage_AC_Ampl = 0.0
UnbalVoltage_AC_Phase = 0
UnbalVoltage_AC_Ena = 0
V_DC_Ampl1 = 0.0
V_DC_Ampl2 = 0.0
V_DC_Ampl3 = 0.0
V_DC_Ena = -1
V_DC_RampTime = 0.1
V_DC_Link = 0
WhiteNoise_DC_Ampl = 0.0
WhiteNoise_DC_Ena = 0
SwitchingNoise_DC_Ampl = 0.0
SwitchingNoise_DC_Freq = 680.0
SwitchingNoise_DC_Ena = 0
UnbalVoltage_DC_Ampl = 0.0
UnbalVoltage_DC_Phase = 0
UnbalVoltage_DC_Ena = 0
data_Capture1 = []
data_Capture2 = []


# ===============================================================================
# RTBOX XMLRPC CLASS
# ===============================================================================
class RTBox(QObject):
    finished = pyqtSignal()

    def RTBox_find(self):
        global HOST_IPV4
        global HOST_ADDRESS
        global RTBOX_IPFOUND
        global dispList_Ipv4
        try:
            HOST_IPV4 = socket.gethostbyname(HOST_NAME)
            RTBOX_IPFOUND = ConnectionStatus.CONNECTED
        except gaierror:
            HOST_IPV4 = "000.000.000.000"
            RTBOX_IPFOUND = ConnectionStatus.NOT_CONNECTED
        HOST_ADDRESS = "http://" + HOST_IPV4 + ":9998/RPC2"
        dispList_Ipv4[1] = HOST_IPV4
        self.finished.emit()

    def RTBox_connect(self):
        global RTBOX_SERVER_XMLPRC
        global INPUTBLOCKS
        global OUTPUTBLOCKS
        global RTBOX_CONNECTED
        global RTBOX_STATUS_INT
        try:
            RTBOX_SERVER_XMLPRC = xmlrpc.client.Server(HOST_ADDRESS)
            RTBOX_CONNECTED = ConnectionStatus.CONNECTED
            self.RTBox_requestInputOutputBlocks()
            self.RTBox_querySimulation()
        except Exception as error:
            QMessageBox.about(self, type(error).__name__, traceback.format_exc())
            RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED
            INPUTBLOCKS = [0]
            OUTPUTBLOCKS = [0]

    def RTBox_requestInputOutputBlocks(self):
        global INPUTBLOCKS
        global OUTPUTBLOCKS
        global RTBOX_CONNECTED
        try:
            INPUTBLOCKS = RTBOX_SERVER_XMLPRC.rtbox.getProgrammableValueBlocks()
            RTBOX_CONNECTED = ConnectionStatus.CONNECTED
        except Exception as error:
            QMessageBox.about(self, type(error).__name__, traceback.format_exc())
            RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED
            INPUTBLOCKS = [0]
        try:
            OUTPUTBLOCKS = RTBOX_SERVER_XMLPRC.rtbox.getDataCaptureBlocks()
            RTBOX_CONNECTED = ConnectionStatus.CONNECTED
        except Exception as error:
            QMessageBox.about(self, type(error).__name__, traceback.format_exc())
            RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED
            OUTPUTBLOCKS = [0]

    def RTBox_querySimulation(self):
        global RTBOX_STATUS_INT
        try:
            RTBOX_STATUS_INT = RTBOX_SERVER_XMLPRC.rtbox.querySimulation()
        except Exception as error:
            QMessageBox.about(self, type(error).__name__, traceback.format_exc())

    def RTBox_loadDesignFile(self):
        global RTBOX_SERVER_XMLPRC
        global RTBOX_STATUS
        try:
            with open(DESIGN_PATH, "rb") as f:
                RTBOX_STATUS = DeviceStatus.LOADING_DESIGN
                try:
                    RTBOX_SERVER_XMLPRC.rtbox.load(xmlrpc.client.Binary(f.read()))
                    RTBOX_STATUS = DeviceStatus.DESIGN_LOADED
                except Exception as error:
                    QMessageBox.about(self, type(error).__name__, traceback.format_exc())
            f.closed
        except Exception as error:
            QMessageBox.about(self, type(error).__name__, traceback.format_exc())

    def RTBox_startSimulation(self):
        global RTBOX_SERVER_XMLPRC
        try:
            RTBOX_SERVER_XMLPRC.rtbox.start()
        except Exception as error:
            QMessageBox.about(self, type(error).__name__, traceback.format_exc())
        self.RTBox_requestInputOutputBlocks()

    def RTBox_stopSimulation(self):
        global RTBOX_SERVER_XMLPRC
        try:
            RTBOX_SERVER_XMLPRC.rtbox.stop()
        except Exception as error:
            QMessageBox.about(self, type(error).__name__, traceback.format_exc())
        self.finished.emit()


class RTBox_workerWrite(QObject):
    progress = pyqtSignal(int)
    finished = pyqtSignal()

    def RTBox_setProgrammableValue(self):
        global RTBOX_SERVER_XMLPRC
        global V_AC_Ampl
        global V_AC_Freq
        global V_AC_Ena
        global V_AC_RampTime
        global WhiteNoise_AC_Ampl
        global WhiteNoise_AC_Ena
        global SwitchingNoise_AC_Ampl
        global SwitchingNoise_AC_Freq
        global SwitchingNoise_AC_Ena
        global UnbalVoltage_AC_Ampl
        global UnbalVoltage_AC_Phase
        global UnbalVoltage_AC_Ena
        global V_DC_Ampl1
        global V_DC_Ampl2
        global V_DC_Ampl3
        global V_DC_Ena
        global V_DC_RampTime
        global V_DC_Link
        global WhiteNoise_DC_Ampl
        global WhiteNoise_DC_Ena
        global SwitchingNoise_DC_Ampl
        global SwitchingNoise_DC_Freq
        global SwitchingNoise_DC_Ena
        global UnbalVoltage_DC_Ampl
        global UnbalVoltage_DC_Phase
        global UnbalVoltage_DC_Ena

        if ((RTBOX_STATUS == DeviceStatus.RUNNING) & (RTBOX_CONNECTED == ConnectionStatus.CONNECTED)):
            try:
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('Input', [V_AC_Ampl, V_AC_Ena, V_AC_RampTime, V_AC_Freq])
                self.progress.emit(1)
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('Input1', [WhiteNoise_AC_Ampl, WhiteNoise_AC_Ena])
                self.progress.emit(2)
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('Input2', [SwitchingNoise_AC_Ampl, SwitchingNoise_AC_Freq, SwitchingNoise_AC_Ena])
                self.progress.emit(3)
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('Input3', [UnbalVoltage_AC_Ampl, UnbalVoltage_AC_Phase, UnbalVoltage_AC_Ena])
                self.progress.emit(4)
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('InputDC', [V_DC_Ampl1, V_DC_Ampl2, V_DC_Ampl3, V_DC_Ena, V_DC_RampTime])
                self.progress.emit(5)
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('InputDC1', [WhiteNoise_DC_Ampl, WhiteNoise_DC_Ena])
                self.progress.emit(6)
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('InputDC2', [SwitchingNoise_DC_Ampl, SwitchingNoise_DC_Freq, SwitchingNoise_DC_Ena])
                self.progress.emit(7)
                RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue('InputDC3', [UnbalVoltage_DC_Ampl, UnbalVoltage_DC_Phase, UnbalVoltage_DC_Ena])
                self.progress.emit(8)
            except Exception:
                pass
        else:
            pass
        self.finished.emit()

class RTBox_workerRead(QObject):
    progress = pyqtSignal(int)
    finished = pyqtSignal()

    def RTBox_getCaptureData(self):
        global RTBOX_SERVER_XMLPRC
        global RTBOX_CONNECTED
        global RTBOX_STATUS
        global data_Capture1
        global data_Capture2

        # TO BE REMOVED !!! #########################################
        #data_Capture1 = []
        #data_Capture1.insert(0, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        #data_Capture1.insert(1, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        #data_Capture1.insert(2, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        #data_Capture2 = []
        #data_Capture2.insert(0, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        #data_Capture2.insert(1, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        #data_Capture2.insert(2, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        # TO BE REMOVED !!! #########################################

        if ((RTBOX_STATUS == DeviceStatus.RUNNING) & (RTBOX_CONNECTED == ConnectionStatus.CONNECTED)):
            try:
                if (RTBOX_SERVER_XMLPRC.rtbox.getCaptureTriggerCount('Capture1') != 0):
                    try:
                        data_Capture1 = []
                        data_Capture1 = list(RTBOX_SERVER_XMLPRC.rtbox.getCaptureData('Capture1').values())
                        self.progress.emit(1)
                    except Exception:
                        pass
                if (RTBOX_SERVER_XMLPRC.rtbox.getCaptureTriggerCount('Capture2') != 0):
                    try:
                        data_Capture2 = []
                        data_Capture2 = list(RTBOX_SERVER_XMLPRC.rtbox.getCaptureData('Capture2').values())
                        self.progress.emit(2)
                    except Exception:
                        pass
            except Exception:
                pass
        else:
            pass
        self.finished.emit()

# ===============================================================================
# MAIN CLASS
# ===============================================================================
class Window(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        global DATA_DIM
        super().__init__(parent)
        self.setupUi(self)
        #self.setFixedSize(900, 300)
        self.numcallWrite = 0
        self.numcallRead = 0
        self.setWindowTitle("RT-Box GUI")
        self.setFixedSize(self.sizeHint().width(), self.sizeHint().height())
        self.groupBox_Plot_height = 500
        self.mainHeightMin = self.sizeHint().height()
        self.mainHeightMax = self.mainHeightMin + self.groupBox_Plot_height
        ## Status Bar # ---------------------------------------------------------
        self.label_RtBoxDeviceStatusVal = QLabel(dispList_DeviceStatus[RTBOX_STATUS.value-1])
        self.label_RtBoxConnectionVal = QLabel(dispList_ConnectionStatus[RTBOX_CONNECTED.value-1])
        self.label_Ipv4Val = QLabel(dispList_Ipv4[RTBOX_IPFOUND.value-1])
        self.statusBar().addPermanentWidget(self.label_RtBoxDeviceStatusVal)
        self.statusBar().addPermanentWidget(self.label_RtBoxConnectionVal)
        self.statusBar().addPermanentWidget(self.label_Ipv4Val)
        self.timer_RefreshStatusBar = QTimer()
        self.timer_RefreshWrite = QTimer()
        self.timer_RefreshRead = QTimer()
        ## Class RTBox and managing threads # -----------------------------------
        self.RTBox_workerWrite = RTBox_workerWrite()
        self.RTBox_workerRead = RTBox_workerRead()
        ## Connect Slots # ------------------------------------------------------
        self.connectSignalsSlots()
        ## Start Timer # --------------------------------------------------------
        self.timer_RefreshStatusBar.start(TOUT_mainWindow_RefreshStatusBar_ms)
        self.timer_RefreshWrite.start(TOUT_mainWindow_RefreshWrite_ms)
        ## Specific Implementation # --------------------------------------------
        self.PlotData_Ena = 0
        self.Voltage_AC_R = np.zeros(DATA_DIM, dtype=float)
        self.Voltage_AC_S = np.zeros(DATA_DIM, dtype=float)
        self.Voltage_AC_T = np.zeros(DATA_DIM, dtype=float)
        self.Voltage_DC_R = np.zeros(DATA_DIM, dtype=float)
        self.Voltage_DC_S = np.zeros(DATA_DIM, dtype=float)
        self.Voltage_DC_T = np.zeros(DATA_DIM, dtype=float)

    def connectSignalsSlots(self):
        self.action_Exit.triggered.connect(self.close)
        self.action_Settings.triggered.connect(self.settingsRtBox)
        self.action_About.triggered.connect(self.about)
        self.timer_RefreshStatusBar.timeout.connect(self.refreshStatusBar)
        self.timer_RefreshWrite.timeout.connect(self.refreshWrite)
        self.timer_RefreshRead.timeout.connect(self.refreshRead)
        self.pushButton_EnablePlot.clicked.connect(self.pushButton_EnablePlot_clicked)
        
        ## Specific Implementation
        # DoubleSpinBox
        self.doubleSpinBox_vAmp.valueChanged.connect(self.doubleSpinBox_vAmp_valueChanged)
        self.doubleSpinBox_vFreq.valueChanged.connect(self.doubleSpinBox_vFreq_valueChanged)
        self.doubleSpinBox_voltageRampTime.valueChanged.connect(self.doubleSpinBox_voltageRampTime_valueChanged)
        self.doubleSpinBox_wnAmp.valueChanged.connect(self.doubleSpinBox_wnAmp_valueChanged)
        self.doubleSpinBox_snAmp.valueChanged.connect(self.doubleSpinBox_snAmp_valueChanged)
        self.doubleSpinBox_snFreq.valueChanged.connect(self.doubleSpinBox_snFreq_valueChanged)
        self.doubleSpinBox_unbalAmp.valueChanged.connect(self.doubleSpinBox_unbalAmp_valueChanged)
        self.spinBox_unbalPhase.valueChanged.connect(self.spinBox_unbalPhase_valueChanged)
        self.doubleSpinBox_vDCAmp1.valueChanged.connect(self.doubleSpinBox_vDCAmp1_valueChanged)
        self.doubleSpinBox_vDCAmp2.valueChanged.connect(self.doubleSpinBox_vDCAmp2_valueChanged)
        self.doubleSpinBox_vDCAmp3.valueChanged.connect(self.doubleSpinBox_vDCAmp3_valueChanged)
        self.doubleSpinBox_wnDCAmp.valueChanged.connect(self.doubleSpinBox_wnDCAmp_valueChanged)
        self.doubleSpinBox_snDCAmp.valueChanged.connect(self.doubleSpinBox_snDCAmp_valueChanged)
        self.doubleSpinBox_snDCFreq.valueChanged.connect(self.doubleSpinBox_snDCFreq_valueChanged)
        self.doubleSpinBox_unbalDCAmp.valueChanged.connect(self.doubleSpinBox_unbalDCAmp_valueChanged)
        self.spinBox_unbalDCPhase.valueChanged.connect(self.spinBox_unbalDCPhase_valueChanged)
        # PushButton
        self.pushButton_voltageEna.clicked.connect(self.pushButton_voltageEna_clicked)
        self.pushButton_wnEna.clicked.connect(self.pushButton_wnEna_clicked)
        self.pushButton_snEna.clicked.connect(self.pushButton_snEna_clicked)
        self.pushButton_unbalEna.clicked.connect(self.pushButton_unbalEna_clicked)
        self.pushButton_vDCEna.clicked.connect(self.pushButton_vDCEna_clicked)
        self.pushButton_wnDCEna.clicked.connect(self.pushButton_wnDCEna_clicked)
        self.pushButton_snDCEna.clicked.connect(self.pushButton_snDCEna_clicked)
        self.pushButton_unbalDCEna.clicked.connect(self.pushButton_unbalDCEna_clicked)
        self.pushButton_vDCLink.clicked.connect(self.pushButton_vDCLink_clicked)

    def settingsRtBox(self):
        dialog = settingsDialog(self)
        dialog.exec()

    def about(self):
        QMessageBox.about(
            self,
            "About",
            """ This project represents a simple xml-prc client for PLECS RTBox1."""
            """It consists in a PyQt5-based GUI which lets to connect to RTBox1"""
            """and send parameters and read data. The PLECS design implemented"""
            """in RTBox1 actually consists in a configurable function generator."""
            """<p>Copyright (c) 2023 lgrittin - MIT License</p>
            <p>luca.grittini@nidec-asi.com</p>"""
        )

    def refreshStatusBar(self):
        try:
            self.label_RtBoxDeviceStatusVal.setStyleSheet(dispListColor2[RTBOX_STATUS.value-1])
            self.label_RtBoxDeviceStatusVal.setText(dispList_DeviceStatus[RTBOX_STATUS.value-1])
            self.label_RtBoxConnectionVal.setStyleSheet(dispListColor[RTBOX_CONNECTED.value-1])
            self.label_RtBoxConnectionVal.setText(dispList_ConnectionStatus[RTBOX_CONNECTED.value-1])
            self.label_Ipv4Val.setStyleSheet(dispListColor[RTBOX_IPFOUND.value-1])
            self.label_Ipv4Val.setText(dispList_Ipv4[RTBOX_IPFOUND.value-1])
        except Exception:
            pass

    def pushButton_EnablePlot_clicked(self):
        if self.pushButton_EnablePlot.isChecked():
            self.pushButton_EnablePlot.setText("Plot On")
            self.PlotData_Ena = 1
            self.init_PlotData()
            self.timer_RefreshRead.start(TOUT_mainWindow_RefreshRead_ms)
            self.mainHeightMin = self.sizeHint().height()
            self.setFixedSize(self.sizeHint().width(), self.mainHeightMax)
        else:
            self.pushButton_EnablePlot.setText("Plot Off")
            self.PlotData_Ena = 0
            self.timer_RefreshRead.stop()
            self.layout.removeWidget(self.groupBox_Plot)
            sip.delete(self.groupBox_Plot)
            self.mainHeightMax = self.sizeHint().height()
            self.setFixedSize(self.sizeHint().width(), self.mainHeightMin)

    def refreshWrite(self):
        #self.RTBox_workerWrite = RTBox_workerWrite()
        #self.thread_writeToRTBox = QThread()
        #self.RTBox_workerWrite.moveToThread(self.thread_writeToRTBox)
        #self.thread_writeToRTBox.started.connect(self.RTBox_workerWrite.RTBox_setProgrammableValue)
        #self.RTBox_workerWrite.finished.connect(self.thread_writeToRTBox.quit)
        #self.RTBox_workerWrite.progress.connect(self.reportProgressWrite)
        #self.RTBox_workerWrite.finished.connect(self.RTBox_workerWrite.deleteLater)
        #self.thread_writeToRTBox.finished.connect(self.thread_writeToRTBox.deleteLater)
        #self.thread_writeToRTBox.finished.connect(self.reportWriteFinished)
        #self.thread_writeToRTBox.start()
        self.RTBox_workerWrite.RTBox_setProgrammableValue()

    def reportProgressWrite(self, n):
        print("Write " + n + " Completed")

    def reportWriteFinished(self):
        self.time = time.time()
        self.numcallWrite = self.numcallWrite + 1
        print("MainWindows Write. Call " + str(self.numcallWrite) + " Time: " + str(self.time))

    def refreshRead(self):
        #self.RTBox_workerRead = RTBox_workerRead()
        #self.thread_readFromRTBox = QThread()
        #self.RTBox_workerRead.moveToThread(self.thread_readFromRTBox)
        #self.thread_readFromRTBox.started.connect(self.RTBox_workerRead.RTBox_getCaptureData)
        #self.RTBox_workerRead.finished.connect(self.thread_readFromRTBox.quit)
        #self.RTBox_workerRead.progress.connect(self.reportProgressRead)
        #self.RTBox_workerRead.finished.connect(self.RTBox_workerRead.deleteLater)
        #self.thread_readFromRTBox.finished.connect(self.thread_readFromRTBox.deleteLater)
        #self.thread_readFromRTBox.finished.connect(self.update_PlotData)
        #self.thread_readFromRTBox.finished.connect(self.reportReadFinished)
        #self.thread_readFromRTBox.start()
        self.RTBox_workerRead.RTBox_getCaptureData()

    def reportProgressRead(self, n):
        print("Read " + n + " Completed")

    def reportReadFinished(self):
        self.time = time.time()
        self.numcallRead = self.numcallRead + 1
        print("MainWindows Read. Call " + str(self.numcallRead) + " Time: " + str(self.time))

    # DoubleSpinBox

    def doubleSpinBox_vAmp_valueChanged(self):
        global V_AC_Ampl
        V_AC_Ampl = self.doubleSpinBox_vAmp.value()

    def doubleSpinBox_vFreq_valueChanged(self):
        global V_AC_Freq
        V_AC_Freq = self.doubleSpinBox_vFreq.value()

    def doubleSpinBox_voltageRampTime_valueChanged(self):
        global V_AC_RampTime
        global V_DC_RampTime
        V_AC_RampTime = V_DC_RampTime = 1.0/self.doubleSpinBox_voltageRampTime.value()

    def doubleSpinBox_wnAmp_valueChanged(self):
        global WhiteNoise_AC_Ampl
        WhiteNoise_AC_Ampl = self.doubleSpinBox_wnAmp.value()

    def doubleSpinBox_snAmp_valueChanged(self):
        global SwitchingNoise_AC_Ampl
        SwitchingNoise_AC_Ampl = self.doubleSpinBox_snAmp.value()

    def doubleSpinBox_snFreq_valueChanged(self):
        global SwitchingNoise_AC_Freq
        SwitchingNoise_AC_Freq = self.doubleSpinBox_snFreq.value()

    def doubleSpinBox_unbalAmp_valueChanged(self):
        global UnbalVoltage_AC_Ampl
        UnbalVoltage_AC_Ampl = self.doubleSpinBox_unbalAmp.value()

    def spinBox_unbalPhase_valueChanged(self):
        global UnbalVoltage_AC_Phase
        UnbalVoltage_AC_Phase = self.spinBox_unbalPhase.value()

    def doubleSpinBox_vDCAmp1_valueChanged(self):
        global V_DC_Ampl1
        global V_DC_Ampl2
        global V_DC_Ampl3
        global V_DC_Link
        V_DC_Ampl1 = self.doubleSpinBox_vDCAmp1.value()
        if (V_DC_Link == 1):
            V_DC_Ampl2 = V_DC_Ampl1
            V_DC_Ampl3 = V_DC_Ampl1

    def doubleSpinBox_vDCAmp2_valueChanged(self):
        global V_DC_Ampl2
        V_DC_Ampl2 = self.doubleSpinBox_vDCAmp2.value()

    def doubleSpinBox_vDCAmp3_valueChanged(self):
        global V_DC_Ampl3
        V_DC_Ampl3 = self.doubleSpinBox_vDCAmp3.value()

    def doubleSpinBox_wnDCAmp_valueChanged(self):
        global WhiteNoise_DC_Ampl
        WhiteNoise_DC_Ampl = self.doubleSpinBox_wnDCAmp.value()

    def doubleSpinBox_snDCAmp_valueChanged(self):
        global SwitchingNoise_DC_Ampl
        SwitchingNoise_DC_Ampl = self.doubleSpinBox_snDCAmp.value()

    def doubleSpinBox_snDCFreq_valueChanged(self):
        global SwitchingNoise_DC_Freq
        SwitchingNoise_DC_Freq = self.doubleSpinBox_snDCFreq.value()

    def doubleSpinBox_unbalDCAmp_valueChanged(self):
        global UnbalVoltage_DC_Ampl
        UnbalVoltage_DC_Ampl = self.doubleSpinBox_unbalDCAmp.value()

    def spinBox_unbalDCPhase_valueChanged(self):
        global UnbalVoltage_DC_Phase
        UnbalVoltage_DC_Phase = self.spinBox_unbalDCPhase.value()

    # PushButton

    def pushButton_voltageEna_clicked(self):
        global V_AC_Ena
        if self.pushButton_voltageEna.isChecked():
            self.pushButton_voltageEna.setText("On")
            V_AC_Ena = 1
        else:
            self.pushButton_voltageEna.setText("Off")
            V_AC_Ena = -1

    def pushButton_wnEna_clicked(self):
        global WhiteNoise_AC_Ena
        if self.pushButton_wnEna.isChecked():
            self.pushButton_wnEna.setText("On")
            WhiteNoise_AC_Ena = 1
        else:
            self.pushButton_wnEna.setText("Off")
            WhiteNoise_AC_Ena = 0

    def pushButton_snEna_clicked(self):
        global SwitchingNoise_AC_Ena
        if self.pushButton_snEna.isChecked():
            self.pushButton_snEna.setText("On")
            SwitchingNoise_AC_Ena = 1
        else:
            self.pushButton_snEna.setText("Off")
            SwitchingNoise_AC_Ena = 0

    def pushButton_unbalEna_clicked(self):
        global UnbalVoltage_AC_Ena
        if self.pushButton_unbalEna.isChecked():
            self.pushButton_unbalEna.setText("On")
            UnbalVoltage_AC_Ena = 1
        else:
            self.pushButton_unbalEna.setText("Off")
            UnbalVoltage_AC_Ena = 0

    def pushButton_vDCEna_clicked(self):
        global V_DC_Ena
        if self.pushButton_vDCEna.isChecked():
            self.pushButton_vDCEna.setText("On")
            V_DC_Ena = 1
        else:
            self.pushButton_vDCEna.setText("Off")
            V_DC_Ena = -1

    def pushButton_wnDCEna_clicked(self):
        global WhiteNoise_DC_Ena
        if self.pushButton_wnDCEna.isChecked():
            self.pushButton_wnDCEna.setText("On")
            WhiteNoise_DC_Ena = 1
        else:
            self.pushButton_wnDCEna.setText("Off")
            WhiteNoise_DC_Ena = 0

    def pushButton_snDCEna_clicked(self):
        global SwitchingNoise_DC_Ena
        if self.pushButton_snDCEna.isChecked():
            self.pushButton_snDCEna.setText("On")
            SwitchingNoise_DC_Ena = 1
        else:
            self.pushButton_snDCEna.setText("Off")
            SwitchingNoise_DC_Ena = 0

    def pushButton_unbalDCEna_clicked(self):
        global UnbalVoltage_DC_Ena
        if self.pushButton_unbalDCEna.isChecked():
            self.pushButton_unbalDCEna.setText("On")
            UnbalVoltage_DC_Ena = 1
        else:
            self.pushButton_unbalDCEna.setText("Off")
            UnbalVoltage_DC_Ena = 0

    def pushButton_vDCLink_clicked(self):
        global V_DC_Link
        global V_DC_Ampl1
        global V_DC_Ampl2
        global V_DC_Ampl3
        if self.pushButton_vDCLink.isChecked():
            self.pushButton_vDCLink.setText("Link On")
            self.doubleSpinBox_vDCAmp2.setEnabled(0)
            self.doubleSpinBox_vDCAmp3.setEnabled(0)
            V_DC_Link = 1
            V_DC_Ampl2 = V_DC_Ampl1
            V_DC_Ampl3 = V_DC_Ampl1
        else:
            self.pushButton_vDCLink.setText("Link Off")
            self.doubleSpinBox_vDCAmp2.setEnabled(1)
            self.doubleSpinBox_vDCAmp3.setEnabled(1)
            V_DC_Link = 0
            V_DC_Ampl2 = self.doubleSpinBox_vDCAmp2.value()
            V_DC_Ampl3 = self.doubleSpinBox_vDCAmp3.value()
        
    def init_PlotData(self):
        self.groupBox_Plot = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_Plot.setObjectName("groupBox_Plot")
        self.groupBox_Plot.setFixedHeight(self.groupBox_Plot_height)
        self.gridLayout_4.addWidget(self.groupBox_Plot, 2, 0, 1, 1)
        self.groupBox_Plot.setTitle("Plot")
        self.layout = self.groupBox_Plot.layout()#QVBoxLayout()
        if self.layout is None:
            self.layout = QVBoxLayout(self.groupBox_Plot)
        self.graphWidget = PlotWidget()
        self.layout.addWidget(self.graphWidget)
        # Data
        self.x = list(range(DATA_DIM))
        # Background Color
        color = self.palette().color(QtGui.QPalette.Window)  # Get the default window background
        self.graphWidget.setBackground(color)
        # Axis Style/Labels
        styles = {'color':'k', 'font-size':'10px'}
        self.graphWidget.setLabel('left', 'Voltage [V]', **styles)
        self.graphWidget.setLabel('bottom', 'Samples', **styles)
        # Legends
        self.graphWidget.addLegend()
        # Grid
        self.graphWidget.showGrid(x=True, y=True)
        #Set Range
        self.graphWidget.setXRange(0, DATA_DIM, padding=0)
        self.graphWidget.setYRange(-6.5, 6.5, padding=0)
        # Pen Styles
        pen1 = pg.mkPen(color = 'g', width = 2, style = Qt.SolidLine)
        pen2 = pg.mkPen(color = 'r', width = 2, style = Qt.SolidLine)
        pen3 = pg.mkPen(color = 'b', width = 2, style = Qt.SolidLine)
        # Data Plot
        self.data_line_AC1 =  self.graphWidget.plot(self.x, self.Voltage_AC_R, pen = pen1)
        self.data_line_AC2 =  self.graphWidget.plot(self.x, self.Voltage_AC_S, pen = pen2)
        self.data_line_AC3 =  self.graphWidget.plot(self.x, self.Voltage_AC_T, pen = pen3)
        self.data_line_DC1 =  self.graphWidget.plot(self.x, self.Voltage_DC_R, pen = pen1)
        self.data_line_DC2 =  self.graphWidget.plot(self.x, self.Voltage_DC_S, pen = pen2)
        self.data_line_DC3 =  self.graphWidget.plot(self.x, self.Voltage_DC_T, pen = pen3)

    def update_PlotData(self):
        if ((self.PlotData_Ena == 1) & (RTBOX_STATUS == DeviceStatus.RUNNING) & (RTBOX_CONNECTED == ConnectionStatus.CONNECTED)):
            self.Voltage_DC_R = [idx[0] for idx in data_Capture1[0]]   #data_Capture1[0]
            self.Voltage_DC_S = [idx[1] for idx in data_Capture1[0]]   #data_Capture1[1]
            self.Voltage_DC_T = [idx[2] for idx in data_Capture1[0]]   #data_Capture1[2]
            self.Voltage_AC_R = [idx[0] for idx in data_Capture2[0]]   #data_Capture2[0]
            self.Voltage_AC_S = [idx[1] for idx in data_Capture2[0]]   #data_Capture2[1]
            self.Voltage_AC_T = [idx[2] for idx in data_Capture2[0]]   #data_Capture2[2]

            self.data_line_AC1.setData(self.x, self.Voltage_AC_R)
            self.data_line_AC2.setData(self.x, self.Voltage_AC_S)
            self.data_line_AC3.setData(self.x, self.Voltage_AC_T)
            self.data_line_DC1.setData(self.x, self.Voltage_DC_R)
            self.data_line_DC2.setData(self.x, self.Voltage_DC_S)
            self.data_line_DC3.setData(self.x, self.Voltage_DC_T)
        else:
            pass

# ===============================================================================
# SETTINGS DIALOG CLASS
# ===============================================================================
class settingsDialog(QDialog, Ui_Dialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)
        self.setWindowTitle("RT-Box Settings")
        self.numcall = 0
        self.lineEdit_DesignFilePath.setText(DESIGN_PATH)
        ## Class RTBox and managing threads # -----------------------------------
        self.RTBox = RTBox()
        ## Connect Slots # ------------------------------------------------------
        self.timer_RefreshLabels = QTimer()
        self.connectSignalsSlots()
        ## Start Timer # --------------------------------------------------------
        self.timer_RefreshLabels.start(TOUT_settingsDialog_RefreshLabels_ms)

    def connectSignalsSlots(self):
        self.pushButton_Find.clicked.connect(lambda: self.callRTBoxMethod(0))
        self.pushButton_Connect.clicked.connect(lambda: self.callRTBoxMethod(1))
        self.pushButton_LoadDesign.clicked.connect(lambda: self.callRTBoxMethod(2))
        self.pushButton_Start.clicked.connect(lambda: self.callRTBoxMethod(3))
        self.pushButton_Stop.clicked.connect(lambda: self.callRTBoxMethod(4))
        self.pushButton_BrowseDesignFilePath.clicked.connect(self.browseDesignFile)
        self.timer_RefreshLabels.timeout.connect(self.refreshLabels)

    def refreshLabels(self):
        global RTBOX_SERVER_XMLPRC
        global RTBOX_STATUS_INT
        global RTBOX_STATUS
        global RTBOX_CONNECTED
        global RTBOX_IPFOUND

        if (RTBOX_CONNECTED == ConnectionStatus.CONNECTED):
            try:
                RTBOX_STATUS_INT = list(RTBOX_SERVER_XMLPRC.rtbox.querySimulation().values())
                if (RTBOX_STATUS_INT[7] == 'running'):
                    RTBOX_STATUS = DeviceStatus.RUNNING
                    self.pushButton_Start.setEnabled(0)
                    self.pushButton_Stop.setEnabled(1)
                elif(RTBOX_STATUS_INT[7] == 'stopped'):
                    RTBOX_STATUS = DeviceStatus.STOPPED
                    self.pushButton_Start.setEnabled(1)
                    self.pushButton_Stop.setEnabled(0)
                elif(RTBOX_STATUS_INT[7] == 'error'):
                    RTBOX_STATUS = DeviceStatus.ERROR
                    self.pushButton_Start.setEnabled(0)
                    self.pushButton_Stop.setEnabled(0)
                else:
                    self.pushButton_Start.setEnabled(1)
                    self.pushButton_Stop.setEnabled(1)
            except Exception as error:
                QMessageBox.about(self, type(error).__name__, traceback.format_exc())
                RTBOX_STATUS = DeviceStatus.ERROR
                RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED

        self.lineEdit_MacResult.setText(RTBOX_MACADDRESS)
        self.label_Ipv4Result.setStyleSheet(dispListColor[RTBOX_IPFOUND.value-1])
        self.label_Ipv4Result.setText(dispList_Ipv4[RTBOX_IPFOUND.value-1])
        self.label_StatusResult.setStyleSheet(dispListColor[RTBOX_CONNECTED.value-1])
        self.label_StatusResult.setText(dispList_ConnectionStatus[RTBOX_CONNECTED.value-1])
        self.label_DeviceStatusResult.setStyleSheet(dispListColor2[RTBOX_STATUS.value-1])
        self.label_DeviceStatusResult.setText(dispList_DeviceStatus[RTBOX_STATUS.value-1])
        self.label_DataCaptureBlocksResult.setText(str(len(OUTPUTBLOCKS)))
        self.label_NumProgrValueBlocksResult.setText(str(len(INPUTBLOCKS)))

        if (RTBOX_IPFOUND == ConnectionStatus.NOT_CONNECTED):
            self.pushButton_Connect.setEnabled(0)
            self.pushButton_Start.setEnabled(0)
            self.pushButton_Stop.setEnabled(0)
        else:
            self.pushButton_Connect.setEnabled(1)

        if (RTBOX_CONNECTED == ConnectionStatus.NOT_CONNECTED):
            self.pushButton_LoadDesign.setEnabled(0)
            self.pushButton_Start.setEnabled(0)
            self.pushButton_Stop.setEnabled(0)
        else:
            self.pushButton_LoadDesign.setEnabled(1)

    def browseDesignFile(self):
        global DESIGN_PATH
        fname = QFileDialog.getOpenFileName(self, 'Open File', DESIGN_PATH, 'Plecs Autogenerated Code (*.elf)')
        DESIGN_PATH = fname[0]
        self.lineEdit_DesignFilePath.setText(DESIGN_PATH)

    def callRTBoxMethod(self, methodNum):
        #self.RTBox = RTBox()
        #self.thread_callRTBoxMethod = QThread()
        #self.RTBox.moveToThread(self.thread_callRTBoxMethod)
        #self.RTBox.finished.connect(self.thread_callRTBoxMethod.quit)
        #self.RTBox.finished.connect(self.RTBox.deleteLater)
        #self.thread_callRTBoxMethod.finished.connect(self.thread_callRTBoxMethod.deleteLater)
        #self.thread_callRTBoxMethod.finished.connect(lambda: self.reportFinished(methodNum))
        #self.thread_callRTBoxMethod.finished.connect(lambda: QApplication.restoreOverrideCursor())

        match methodNum:
            case 0:
                self.RTBox.RTBox_find()
                #self.thread_callRTBoxMethod.started.connect(self.RTBox.RTBox_find)
                #self.pushButton_Find.setEnabled(0)
                #self.thread_callRTBoxMethod.finished.connect(
                #lambda: self.pushButton_Find.setEnabled(1))
            case 1:
                self.RTBox.RTBox_connect()
                #self.thread_callRTBoxMethod.started.connect(self.RTBox.RTBox_connect)
                #self.pushButton_Connect.setEnabled(0)
                #self.thread_callRTBoxMethod.finished.connect(
                #lambda: self.pushButton_Connect.setEnabled(1))
            case 2:
                self.RTBox.RTBox_loadDesignFile()
                #self.thread_callRTBoxMethod.started.connect(self.RTBox.RTBox_loadDesignFile)
                #self.pushButton_LoadDesign.setEnabled(0)
                #self.thread_callRTBoxMethod.finished.connect(
                #lambda: self.pushButton_LoadDesign.setEnabled(1))
            case 3:
                self.RTBox.RTBox_startSimulation()
                #self.thread_callRTBoxMethod.started.connect(self.RTBox.RTBox_startSimulation)
                #self.pushButton_Start.setEnabled(0)
                #self.thread_callRTBoxMethod.finished.connect(
                #lambda: self.pushButton_Start.setEnabled(1))
            case 4:
                self.RTBox.RTBox_stopSimulation()
                #self.thread_callRTBoxMethod.started.connect(self.RTBox.RTBox_stopSimulation)
                #self.pushButton_Stop.setEnabled(0)
                #self.thread_callRTBoxMethod.finished.connect(
                #lambda: self.pushButton_Stop.setEnabled(1))
            case _:
                pass

        #self.thread_callRTBoxMethod.start()
        #QApplication.setOverrideCursor(QCursor(Qt.WaitCursor))
            
    def reportFinished(self, methodNum):
        self.time = time.time()
        self.numcall = self.numcall + 1
        print("Settings. Call " + str(self.numcall) + " - Method " + str(methodNum) + ". Time: " + str(self.time))


# ===============================================================================
# MAIN FUNCTION
# ===============================================================================
if __name__ == "__main__":
    app = QApplication(sys.argv)
    rtbox = RTBox()
    win = Window()
    win.show()
    sys.exit(app.exec())