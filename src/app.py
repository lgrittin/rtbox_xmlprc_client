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
from dataclasses import dataclass
from typing import NamedTuple
from os.path import exists

import pyqtgraph as pg
import numpy as np
import sip

# ===============================================================================
# GLOBALS
# ===============================================================================

## CONNECTIVITY
RTBOX_MACADDRESS_LIST = ["20b0f7047680", "20b0f7058532"]   # RTBox1, RTBox3
RTBOX_MACADDRESS = RTBOX_MACADDRESS_LIST[0]
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
TOUT_mainWindow_RefreshRead_ms = 2000

## Specific Implementation
DESIGN_TDISC_US = 10
DESIGN_FLINE_HZ = 50
DESIGN_CAPTURE_DECIM = 1
DESIGN_CHANNELS_NUMBER = 16
DESIGN_CHANNELS_START_BLOCK = 16
DESIGN_CHANNELS_OUTSEL_BLOCK_1 = 17
DESIGN_CHANNELS_OUTSEL_BLOCK_2 = 18
DESIGN_CHANNELS_OUTSEL_BLOCK_3 = 19
DESIGN_CHANNELS_TRIG_BLOCK = 20
DATA_DIM = int(1/(DESIGN_FLINE_HZ*DESIGN_TDISC_US*0.000001)/DESIGN_CAPTURE_DECIM)
PI = 3.1415926

@dataclass
class ChannelSettings:
    Signal_amp: list
    Signal_freqRads: list
    Signal_phaseRad: list
    Ramp_freq: list
    SwNoise_amp: list
    SwNoise_freq: list
    WhiteNoise_amp: list
    Channel_en: list
    ChannelGlobal_en: int
    Channel_outSel: int
    Channel_outTrig: int

channel_settings = ChannelSettings(
    [0.0 for element in range(DESIGN_CHANNELS_NUMBER)],
    [314.159 for element in range(DESIGN_CHANNELS_NUMBER)],
    [0.0 for element in range(DESIGN_CHANNELS_NUMBER)],
    [1.0 for element in range(DESIGN_CHANNELS_NUMBER)],
    [0.0 for element in range(DESIGN_CHANNELS_NUMBER)],
    [680.0 for element in range(DESIGN_CHANNELS_NUMBER)],
    [0.0 for element in range(DESIGN_CHANNELS_NUMBER)],
    [-1 for element in range(DESIGN_CHANNELS_NUMBER)],
    0,
    0,
    0
)

class ChannelSettings_doubleSpinBox(NamedTuple):
    Signal_amp: list
    Signal_freq: list
    Signal_phase: list
    Ramp_time: list
    SwNoise_amp: list
    SwNoise_freq: list
    WhiteNoise_amp: list

class ChannelSettings_pushButton(NamedTuple):
    ChannelSet: list
    ChannelEn: list

data_Capture1 = []
data_Capture2 = []
data_Capture3 = []

# ===============================================================================
# RTBOX XMLRPC CLASS
# ===============================================================================
class RTBox(QObject):
    finished = pyqtSignal()

    def RTBox_find(self):
        global HOST_NAME
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
            QMessageBox.about(self.parent(), type(error).__name__, traceback.format_exc())
            RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED
            INPUTBLOCKS = [0]
            OUTPUTBLOCKS = [0]

    def RTBox_requestInputOutputBlocks(self):
        global INPUTBLOCKS
        global OUTPUTBLOCKS
        global RTBOX_CONNECTED
        try:
            INPUTBLOCKS = sorted(RTBOX_SERVER_XMLPRC.rtbox.getProgrammableValueBlocks())
            RTBOX_CONNECTED = ConnectionStatus.CONNECTED
        except Exception as error:
            QMessageBox.about(self.parent(), type(error).__name__, traceback.format_exc())
            RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED
            INPUTBLOCKS = [0]
        try:
            OUTPUTBLOCKS = RTBOX_SERVER_XMLPRC.rtbox.getDataCaptureBlocks()
            RTBOX_CONNECTED = ConnectionStatus.CONNECTED
        except Exception as error:
            QMessageBox.about(self.parent(), type(error).__name__, traceback.format_exc())
            RTBOX_CONNECTED = ConnectionStatus.NOT_CONNECTED
            OUTPUTBLOCKS = [0]

    def RTBox_querySimulation(self):
        global RTBOX_STATUS_INT
        global RTBOX_CONNECTED

        if (RTBOX_CONNECTED == ConnectionStatus.CONNECTED):
            try:
                RTBOX_STATUS_INT = list(RTBOX_SERVER_XMLPRC.rtbox.querySimulation().values())
            except Exception as error:
                QMessageBox.about(self.parent(), type(error).__name__, traceback.format_exc())

    def RTBox_loadDesignFile(self):
        global RTBOX_SERVER_XMLPRC
        global RTBOX_STATUS
        global DESIGN_PATH
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
            QMessageBox.about(self.parent(), type(error).__name__, traceback.format_exc())

    def RTBox_startSimulation(self):
        global RTBOX_SERVER_XMLPRC
        try:
            RTBOX_SERVER_XMLPRC.rtbox.start()
        except Exception as error:
            QMessageBox.about(self.parent(), type(error).__name__, traceback.format_exc())
        self.RTBox_requestInputOutputBlocks()

    def RTBox_stopSimulation(self):
        global RTBOX_SERVER_XMLPRC
        try:
            RTBOX_SERVER_XMLPRC.rtbox.stop()
        except Exception as error:
            QMessageBox.about(self.parent(), type(error).__name__, traceback.format_exc())


class RTBox_workerWrite(QObject):
    progress = pyqtSignal(int)
    finished = pyqtSignal()

    def RTBox_setProgrammableValue(self, channelNum):
        global RTBOX_SERVER_XMLPRC
        global channel_settings

        if ((RTBOX_STATUS == DeviceStatus.RUNNING) & (RTBOX_CONNECTED == ConnectionStatus.CONNECTED)):
            if (channelNum < DESIGN_CHANNELS_NUMBER):
                try:
                    RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue(INPUTBLOCKS[channelNum],
                                                               [channel_settings.Signal_amp[channelNum],
                                                                channel_settings.Signal_freqRads[channelNum],
                                                                channel_settings.Signal_phaseRad[channelNum],
                                                                channel_settings.Ramp_freq[channelNum],
                                                                channel_settings.SwNoise_amp[channelNum],
                                                                channel_settings.SwNoise_freq[channelNum],
                                                                channel_settings.WhiteNoise_amp[channelNum]])
                except Exception:
                    pass
            elif (channelNum == DESIGN_CHANNELS_START_BLOCK):
                if channel_settings.ChannelGlobal_en == 0:
                    try:
                        RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue(INPUTBLOCKS[channelNum], [-1 for i in range(DESIGN_CHANNELS_NUMBER)])
                    except Exception:
                        pass
                else:
                    try:
                        RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue(INPUTBLOCKS[channelNum],
                                                               channel_settings.Channel_en)
                    except Exception:
                        pass
            elif ((channelNum == DESIGN_CHANNELS_OUTSEL_BLOCK_1) | (channelNum == DESIGN_CHANNELS_OUTSEL_BLOCK_2) | (channelNum == DESIGN_CHANNELS_OUTSEL_BLOCK_3)):
                try:
                    RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue(INPUTBLOCKS[channelNum],
                                                               channel_settings.Channel_outSel + 1)
                except Exception:
                    pass
            elif (channelNum == DESIGN_CHANNELS_TRIG_BLOCK):
                try:
                    RTBOX_SERVER_XMLPRC.rtbox.setProgrammableValue(INPUTBLOCKS[channelNum],
                                                               channel_settings.Channel_outTrig)
                except Exception:
                    pass
            else:
                pass
            pass
        #self.finished.emit()

class RTBox_workerRead(QObject):
    progress = pyqtSignal(int)
    finished = pyqtSignal()

    def RTBox_getCaptureData(self):
        global RTBOX_SERVER_XMLPRC
        global RTBOX_CONNECTED
        global RTBOX_STATUS
        global data_Capture1
        global data_Capture2
        global data_Capture3

        # TO BE REMOVED !!! #########################################
        #data_Capture1 = []
        #data_Capture1.insert(0, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        #data_Capture1.insert(1, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        #data_Capture1.insert(2, [np.random.uniform(-5.0,5.0) for _ in range(DATA_DIM)])
        # TO BE REMOVED !!! #########################################

        if ((RTBOX_STATUS == DeviceStatus.RUNNING) & (RTBOX_CONNECTED == ConnectionStatus.CONNECTED)):
            try:
                if (RTBOX_SERVER_XMLPRC.rtbox.getCaptureTriggerCount(OUTPUTBLOCKS[0]) != 0):
                    try:
                        data_Capture1 = []
                        data_Capture1 = list(RTBOX_SERVER_XMLPRC.rtbox.getCaptureData(OUTPUTBLOCKS[0]).values())
                        #self.progress.emit(1)
                    except Exception:
                        pass
                if (RTBOX_SERVER_XMLPRC.rtbox.getCaptureTriggerCount(OUTPUTBLOCKS[1]) != 0):
                    try:
                        data_Capture2 = []
                        data_Capture2 = list(RTBOX_SERVER_XMLPRC.rtbox.getCaptureData(OUTPUTBLOCKS[1]).values())
                        #self.progress.emit(1)
                    except Exception:
                        pass
                if (RTBOX_SERVER_XMLPRC.rtbox.getCaptureTriggerCount(OUTPUTBLOCKS[2]) != 0):
                    try:
                        data_Capture3 = []
                        data_Capture3 = list(RTBOX_SERVER_XMLPRC.rtbox.getCaptureData(OUTPUTBLOCKS[2]).values())
                        #self.progress.emit(1)
                    except Exception:
                        pass
            except Exception:
                pass
        else:
            pass
        #self.finished.emit()

# ===============================================================================
# MAIN CLASS
# ===============================================================================
class Window(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        global DATA_DIM
        super().__init__(parent)
        self.setupUi(self)
        self.numcallWrite = 0
        self.numcallRead = 0
        self.setWindowTitle("RT-Box GUI")
        #self.setFixedSize(1000, 700)
        self.groupBox_Plot_height = 200
        #self.mainHeightMin = 700
        #self.mainHeightMax = self.mainHeightMin + self.groupBox_Plot_height
        ## Status Bar # ---------------------------------------------------------
        self.label_RtBoxDeviceStatusVal = QLabel(dispList_DeviceStatus[RTBOX_STATUS.value-1])
        self.label_RtBoxConnectionVal = QLabel(dispList_ConnectionStatus[RTBOX_CONNECTED.value-1])
        self.label_Ipv4Val = QLabel(dispList_Ipv4[RTBOX_IPFOUND.value-1])
        self.statusBar().addPermanentWidget(self.label_RtBoxDeviceStatusVal)
        self.statusBar().addPermanentWidget(self.label_RtBoxConnectionVal)
        self.statusBar().addPermanentWidget(self.label_Ipv4Val)
        self.timer_RefreshStatusBar = QTimer()
        self.timer_RefreshRead = QTimer()
        ## Class RTBox and managing threads # -----------------------------------
        self.RTBox_workerWrite = RTBox_workerWrite()
        self.RTBox_workerRead = RTBox_workerRead()
        ## Connect Slots # ------------------------------------------------------
        self.connectSignalsSlots()
        ## Start Timer # --------------------------------------------------------
        self.timer_RefreshStatusBar.start(TOUT_mainWindow_RefreshStatusBar_ms)
        ## Plot # ---------------------------------------------------------------
        self.PlotData_Ena = 0
        self.DataPlot1 = np.zeros(DATA_DIM, dtype=float)
        self.DataPlot2 = np.zeros(DATA_DIM, dtype=float)
        self.DataPlot3 = np.zeros(DATA_DIM, dtype=float)
        self.init_PlotData()
        #self.groupBox_Plot.hide()
        ## Static File # --------------------------------------------------------
        #if(os.path.isfile()):
        #    self.file_exist = 1
        #else:
        #    self.file_exist = 0
        #pass

    def connectSignalsSlots(self):
        self.action_Exit.triggered.connect(self.close)
        self.action_Settings.triggered.connect(self.settingsRtBox)
        self.action_About.triggered.connect(self.about)
        self.timer_RefreshStatusBar.timeout.connect(self.refreshStatusBar)
        self.timer_RefreshRead.timeout.connect(self.refreshRead)
        self.pushButton_EnablePlot.clicked.connect(self.pushButton_EnablePlot__clicked)
        
        ## Specific Implementation

        self.doubleSpinBox__vector = ChannelSettings_doubleSpinBox(
            [self.doubleSpinBox_Signal_amp,
            self.doubleSpinBox_Signal_amp_2,
            self.doubleSpinBox_Signal_amp_3,
            self.doubleSpinBox_Signal_amp_4,
            self.doubleSpinBox_Signal_amp_5,
            self.doubleSpinBox_Signal_amp_6,
            self.doubleSpinBox_Signal_amp_7,
            self.doubleSpinBox_Signal_amp_8,
            self.doubleSpinBox_Signal_amp_9,
            self.doubleSpinBox_Signal_amp_10,
            self.doubleSpinBox_Signal_amp_11,
            self.doubleSpinBox_Signal_amp_12,
            self.doubleSpinBox_Signal_amp_13,
            self.doubleSpinBox_Signal_amp_14,
            self.doubleSpinBox_Signal_amp_15,
            self.doubleSpinBox_Signal_amp_16],
            [self.doubleSpinBox_Signal_freq,
            self.doubleSpinBox_Signal_freq_2,
            self.doubleSpinBox_Signal_freq_3,
            self.doubleSpinBox_Signal_freq_4,
            self.doubleSpinBox_Signal_freq_5,
            self.doubleSpinBox_Signal_freq_6,
            self.doubleSpinBox_Signal_freq_7,
            self.doubleSpinBox_Signal_freq_8,
            self.doubleSpinBox_Signal_freq_9,
            self.doubleSpinBox_Signal_freq_10,
            self.doubleSpinBox_Signal_freq_11,
            self.doubleSpinBox_Signal_freq_12,
            self.doubleSpinBox_Signal_freq_13,
            self.doubleSpinBox_Signal_freq_14,
            self.doubleSpinBox_Signal_freq_15,
            self.doubleSpinBox_Signal_freq_16],
            [self.doubleSpinBox_Signal_phase,
            self.doubleSpinBox_Signal_phase_2,
            self.doubleSpinBox_Signal_phase_3,
            self.doubleSpinBox_Signal_phase_4,
            self.doubleSpinBox_Signal_phase_5,
            self.doubleSpinBox_Signal_phase_6,
            self.doubleSpinBox_Signal_phase_7,
            self.doubleSpinBox_Signal_phase_8,
            self.doubleSpinBox_Signal_phase_9,
            self.doubleSpinBox_Signal_phase_10,
            self.doubleSpinBox_Signal_phase_11,
            self.doubleSpinBox_Signal_phase_12,
            self.doubleSpinBox_Signal_phase_13,
            self.doubleSpinBox_Signal_phase_14,
            self.doubleSpinBox_Signal_phase_15,
            self.doubleSpinBox_Signal_phase_16],
            [self.doubleSpinBox_Ramp_time,
            self.doubleSpinBox_Ramp_time_2,
            self.doubleSpinBox_Ramp_time_3,
            self.doubleSpinBox_Ramp_time_4,
            self.doubleSpinBox_Ramp_time_5,
            self.doubleSpinBox_Ramp_time_6,
            self.doubleSpinBox_Ramp_time_7,
            self.doubleSpinBox_Ramp_time_8,
            self.doubleSpinBox_Ramp_time_9,
            self.doubleSpinBox_Ramp_time_10,
            self.doubleSpinBox_Ramp_time_11,
            self.doubleSpinBox_Ramp_time_12,
            self.doubleSpinBox_Ramp_time_13,
            self.doubleSpinBox_Ramp_time_14,
            self.doubleSpinBox_Ramp_time_15,
            self.doubleSpinBox_Ramp_time_16],
            [self.doubleSpinBox_SwNoise_amp,
            self.doubleSpinBox_SwNoise_amp_2,
            self.doubleSpinBox_SwNoise_amp_3,
            self.doubleSpinBox_SwNoise_amp_4,
            self.doubleSpinBox_SwNoise_amp_5,
            self.doubleSpinBox_SwNoise_amp_6,
            self.doubleSpinBox_SwNoise_amp_7,
            self.doubleSpinBox_SwNoise_amp_8,
            self.doubleSpinBox_SwNoise_amp_9,
            self.doubleSpinBox_SwNoise_amp_10,
            self.doubleSpinBox_SwNoise_amp_11,
            self.doubleSpinBox_SwNoise_amp_12,
            self.doubleSpinBox_SwNoise_amp_13,
            self.doubleSpinBox_SwNoise_amp_14,
            self.doubleSpinBox_SwNoise_amp_15,
            self.doubleSpinBox_SwNoise_amp_16],
            [self.doubleSpinBox_SwNoise_freq,
            self.doubleSpinBox_SwNoise_freq_2,
            self.doubleSpinBox_SwNoise_freq_3,
            self.doubleSpinBox_SwNoise_freq_4,
            self.doubleSpinBox_SwNoise_freq_5,
            self.doubleSpinBox_SwNoise_freq_6,
            self.doubleSpinBox_SwNoise_freq_7,
            self.doubleSpinBox_SwNoise_freq_8,
            self.doubleSpinBox_SwNoise_freq_9,
            self.doubleSpinBox_SwNoise_freq_10,
            self.doubleSpinBox_SwNoise_freq_11,
            self.doubleSpinBox_SwNoise_freq_12,
            self.doubleSpinBox_SwNoise_freq_13,
            self.doubleSpinBox_SwNoise_freq_14,
            self.doubleSpinBox_SwNoise_freq_15,
            self.doubleSpinBox_SwNoise_freq_16],
            [self.doubleSpinBox_WhiteNoise_amp,
            self.doubleSpinBox_WhiteNoise_amp_2,
            self.doubleSpinBox_WhiteNoise_amp_3,
            self.doubleSpinBox_WhiteNoise_amp_4,
            self.doubleSpinBox_WhiteNoise_amp_5,
            self.doubleSpinBox_WhiteNoise_amp_6,
            self.doubleSpinBox_WhiteNoise_amp_7,
            self.doubleSpinBox_WhiteNoise_amp_8,
            self.doubleSpinBox_WhiteNoise_amp_9,
            self.doubleSpinBox_WhiteNoise_amp_10,
            self.doubleSpinBox_WhiteNoise_amp_11,
            self.doubleSpinBox_WhiteNoise_amp_12,
            self.doubleSpinBox_WhiteNoise_amp_13,
            self.doubleSpinBox_WhiteNoise_amp_14,
            self.doubleSpinBox_WhiteNoise_amp_15,
            self.doubleSpinBox_WhiteNoise_amp_16]
        )

        self.pushButton__vector = ChannelSettings_pushButton(
            [self.pushButton_Channel0_set,
            self.pushButton_Channel0_set_2,
            self.pushButton_Channel0_set_3,
            self.pushButton_Channel0_set_4,
            self.pushButton_Channel0_set_5,
            self.pushButton_Channel0_set_6,
            self.pushButton_Channel0_set_7,
            self.pushButton_Channel0_set_8,
            self.pushButton_Channel0_set_9,
            self.pushButton_Channel0_set_10,
            self.pushButton_Channel0_set_11,
            self.pushButton_Channel0_set_12,
            self.pushButton_Channel0_set_13,
            self.pushButton_Channel0_set_14,
            self.pushButton_Channel0_set_15,
            self.pushButton_Channel0_set_16],
            [self.pushButton_Channel0_en,
            self.pushButton_Channel0_en_2,
            self.pushButton_Channel0_en_3,
            self.pushButton_Channel0_en_4,
            self.pushButton_Channel0_en_5,
            self.pushButton_Channel0_en_6,
            self.pushButton_Channel0_en_7,
            self.pushButton_Channel0_en_8,
            self.pushButton_Channel0_en_9,
            self.pushButton_Channel0_en_10,
            self.pushButton_Channel0_en_11,
            self.pushButton_Channel0_en_12,
            self.pushButton_Channel0_en_13,
            self.pushButton_Channel0_en_14,
            self.pushButton_Channel0_en_15,
            self.pushButton_Channel0_en_16]
        )

        self.pushButton_ChannelGlobal_en.clicked.connect(self.pushButton_ChannelGlobal_en__clicked)
        self.pushButton_EnablePlot.clicked.connect(self.pushButton_EnablePlot__clicked)
        self.spinBox_selPlot_1.valueChanged.connect(lambda: self.spinBox_selPlot__valueChanged(1, self.spinBox_selPlot_1.value()))
        self.spinBox_selPlot_2.valueChanged.connect(lambda: self.spinBox_selPlot__valueChanged(2, self.spinBox_selPlot_2.value()))
        self.spinBox_selPlot_3.valueChanged.connect(lambda: self.spinBox_selPlot__valueChanged(3, self.spinBox_selPlot_3.value()))
        self.spinBox_selTrig.valueChanged.connect(lambda: self.spinBox_selTrig__valueChanged(self.spinBox_selTrig.value()))

        self.pushButton__vector.ChannelEn[0 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(0 ))
        self.pushButton__vector.ChannelEn[1 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(1 ))
        self.pushButton__vector.ChannelEn[2 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(2 ))
        self.pushButton__vector.ChannelEn[3 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(3 ))
        self.pushButton__vector.ChannelEn[4 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(4 ))
        self.pushButton__vector.ChannelEn[5 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(5 ))
        self.pushButton__vector.ChannelEn[6 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(6 ))
        self.pushButton__vector.ChannelEn[7 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(7 ))
        self.pushButton__vector.ChannelEn[8 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(8 ))
        self.pushButton__vector.ChannelEn[9 ].clicked.connect(lambda: self.pushButton_Channel_en__clicked(9 ))
        self.pushButton__vector.ChannelEn[10].clicked.connect(lambda: self.pushButton_Channel_en__clicked(10))
        self.pushButton__vector.ChannelEn[11].clicked.connect(lambda: self.pushButton_Channel_en__clicked(11))
        self.pushButton__vector.ChannelEn[12].clicked.connect(lambda: self.pushButton_Channel_en__clicked(12))
        self.pushButton__vector.ChannelEn[13].clicked.connect(lambda: self.pushButton_Channel_en__clicked(13))
        self.pushButton__vector.ChannelEn[14].clicked.connect(lambda: self.pushButton_Channel_en__clicked(14))
        self.pushButton__vector.ChannelEn[15].clicked.connect(lambda: self.pushButton_Channel_en__clicked(15))

        self.pushButton__vector.ChannelSet[0 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(0 ))
        self.pushButton__vector.ChannelSet[1 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(1 ))
        self.pushButton__vector.ChannelSet[2 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(2 ))
        self.pushButton__vector.ChannelSet[3 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(3 ))
        self.pushButton__vector.ChannelSet[4 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(4 ))
        self.pushButton__vector.ChannelSet[5 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(5 ))
        self.pushButton__vector.ChannelSet[6 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(6 ))
        self.pushButton__vector.ChannelSet[7 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(7 ))
        self.pushButton__vector.ChannelSet[8 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(8 ))
        self.pushButton__vector.ChannelSet[9 ].clicked.connect(lambda: self.pushButton_Channel_set__clicked(9 ))
        self.pushButton__vector.ChannelSet[10].clicked.connect(lambda: self.pushButton_Channel_set__clicked(10))
        self.pushButton__vector.ChannelSet[11].clicked.connect(lambda: self.pushButton_Channel_set__clicked(11))
        self.pushButton__vector.ChannelSet[12].clicked.connect(lambda: self.pushButton_Channel_set__clicked(12))
        self.pushButton__vector.ChannelSet[13].clicked.connect(lambda: self.pushButton_Channel_set__clicked(13))
        self.pushButton__vector.ChannelSet[14].clicked.connect(lambda: self.pushButton_Channel_set__clicked(14))
        self.pushButton__vector.ChannelSet[15].clicked.connect(lambda: self.pushButton_Channel_set__clicked(15))

        self.doubleSpinBox__vector.WhiteNoise_amp[0 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(0 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[1 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(1 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[2 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(2 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[3 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(3 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[4 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(4 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[5 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(5 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[6 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(6 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[7 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(7 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[8 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(8 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[9 ].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(9 ))
        self.doubleSpinBox__vector.WhiteNoise_amp[10].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(10))
        self.doubleSpinBox__vector.WhiteNoise_amp[11].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(11))
        self.doubleSpinBox__vector.WhiteNoise_amp[12].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(12))
        self.doubleSpinBox__vector.WhiteNoise_amp[13].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(13))
        self.doubleSpinBox__vector.WhiteNoise_amp[14].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(14))
        self.doubleSpinBox__vector.WhiteNoise_amp[15].valueChanged.connect(lambda: self.doubleSpinBox_WhiteNoise_amp__valueChanged(15))

        self.doubleSpinBox__vector.SwNoise_freq[0 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(0 ))
        self.doubleSpinBox__vector.SwNoise_freq[1 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(1 ))
        self.doubleSpinBox__vector.SwNoise_freq[2 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(2 ))
        self.doubleSpinBox__vector.SwNoise_freq[3 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(3 ))
        self.doubleSpinBox__vector.SwNoise_freq[4 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(4 ))
        self.doubleSpinBox__vector.SwNoise_freq[5 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(5 ))
        self.doubleSpinBox__vector.SwNoise_freq[6 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(6 ))
        self.doubleSpinBox__vector.SwNoise_freq[7 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(7 ))
        self.doubleSpinBox__vector.SwNoise_freq[8 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(8 ))
        self.doubleSpinBox__vector.SwNoise_freq[9 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(9 ))
        self.doubleSpinBox__vector.SwNoise_freq[10].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(10))
        self.doubleSpinBox__vector.SwNoise_freq[11].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(11))
        self.doubleSpinBox__vector.SwNoise_freq[12].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(12))
        self.doubleSpinBox__vector.SwNoise_freq[13].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(13))
        self.doubleSpinBox__vector.SwNoise_freq[14].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(14))
        self.doubleSpinBox__vector.SwNoise_freq[15].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_freq__valueChanged(15))

        self.doubleSpinBox__vector.SwNoise_amp[0 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(0 ))
        self.doubleSpinBox__vector.SwNoise_amp[1 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(1 ))
        self.doubleSpinBox__vector.SwNoise_amp[2 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(2 ))
        self.doubleSpinBox__vector.SwNoise_amp[3 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(3 ))
        self.doubleSpinBox__vector.SwNoise_amp[4 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(4 ))
        self.doubleSpinBox__vector.SwNoise_amp[5 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(5 ))
        self.doubleSpinBox__vector.SwNoise_amp[6 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(6 ))
        self.doubleSpinBox__vector.SwNoise_amp[7 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(7 ))
        self.doubleSpinBox__vector.SwNoise_amp[8 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(8 ))
        self.doubleSpinBox__vector.SwNoise_amp[9 ].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(9 ))
        self.doubleSpinBox__vector.SwNoise_amp[10].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(10))
        self.doubleSpinBox__vector.SwNoise_amp[11].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(11))
        self.doubleSpinBox__vector.SwNoise_amp[12].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(12))
        self.doubleSpinBox__vector.SwNoise_amp[13].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(13))
        self.doubleSpinBox__vector.SwNoise_amp[14].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(14))
        self.doubleSpinBox__vector.SwNoise_amp[15].valueChanged.connect(lambda: self.doubleSpinBox_SwNoise_amp__valueChanged(15))

        self.doubleSpinBox__vector.Ramp_time[0 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(0 ))
        self.doubleSpinBox__vector.Ramp_time[1 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(1 ))
        self.doubleSpinBox__vector.Ramp_time[2 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(2 ))
        self.doubleSpinBox__vector.Ramp_time[3 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(3 ))
        self.doubleSpinBox__vector.Ramp_time[4 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(4 ))
        self.doubleSpinBox__vector.Ramp_time[5 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(5 ))
        self.doubleSpinBox__vector.Ramp_time[6 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(6 ))
        self.doubleSpinBox__vector.Ramp_time[7 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(7 ))
        self.doubleSpinBox__vector.Ramp_time[8 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(8 ))
        self.doubleSpinBox__vector.Ramp_time[9 ].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(9 ))
        self.doubleSpinBox__vector.Ramp_time[10].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(10))
        self.doubleSpinBox__vector.Ramp_time[11].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(11))
        self.doubleSpinBox__vector.Ramp_time[12].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(12))
        self.doubleSpinBox__vector.Ramp_time[13].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(13))
        self.doubleSpinBox__vector.Ramp_time[14].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(14))
        self.doubleSpinBox__vector.Ramp_time[15].valueChanged.connect(lambda: self.doubleSpinBox_Ramp_time__valueChanged(15))

        self.doubleSpinBox__vector.Signal_amp[0 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(0 ))
        self.doubleSpinBox__vector.Signal_amp[1 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(1 ))
        self.doubleSpinBox__vector.Signal_amp[2 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(2 ))
        self.doubleSpinBox__vector.Signal_amp[3 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(3 ))
        self.doubleSpinBox__vector.Signal_amp[4 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(4 ))
        self.doubleSpinBox__vector.Signal_amp[5 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(5 ))
        self.doubleSpinBox__vector.Signal_amp[6 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(6 ))
        self.doubleSpinBox__vector.Signal_amp[7 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(7 ))
        self.doubleSpinBox__vector.Signal_amp[8 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(8 ))
        self.doubleSpinBox__vector.Signal_amp[9 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(9 ))
        self.doubleSpinBox__vector.Signal_amp[10].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(10))
        self.doubleSpinBox__vector.Signal_amp[11].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(11))
        self.doubleSpinBox__vector.Signal_amp[12].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(12))
        self.doubleSpinBox__vector.Signal_amp[13].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(13))
        self.doubleSpinBox__vector.Signal_amp[14].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(14))
        self.doubleSpinBox__vector.Signal_amp[15].valueChanged.connect(lambda: self.doubleSpinBox_Signal_amp__valueChanged(15))

        self.doubleSpinBox__vector.Signal_phase[0 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(0 ))
        self.doubleSpinBox__vector.Signal_phase[1 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(1 ))
        self.doubleSpinBox__vector.Signal_phase[2 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(2 ))
        self.doubleSpinBox__vector.Signal_phase[3 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(3 ))
        self.doubleSpinBox__vector.Signal_phase[4 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(4 ))
        self.doubleSpinBox__vector.Signal_phase[5 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(5 ))
        self.doubleSpinBox__vector.Signal_phase[6 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(6 ))
        self.doubleSpinBox__vector.Signal_phase[7 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(7 ))
        self.doubleSpinBox__vector.Signal_phase[8 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(8 ))
        self.doubleSpinBox__vector.Signal_phase[9 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(9 ))
        self.doubleSpinBox__vector.Signal_phase[10].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(10))
        self.doubleSpinBox__vector.Signal_phase[11].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(11))
        self.doubleSpinBox__vector.Signal_phase[12].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(12))
        self.doubleSpinBox__vector.Signal_phase[13].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(13))
        self.doubleSpinBox__vector.Signal_phase[14].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(14))
        self.doubleSpinBox__vector.Signal_phase[15].valueChanged.connect(lambda: self.doubleSpinBox_Signal_phase__valueChanged(15))

        self.doubleSpinBox__vector.Signal_freq[0 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(0 ))
        self.doubleSpinBox__vector.Signal_freq[1 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(1 ))
        self.doubleSpinBox__vector.Signal_freq[2 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(2 ))
        self.doubleSpinBox__vector.Signal_freq[3 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(3 ))
        self.doubleSpinBox__vector.Signal_freq[4 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(4 ))
        self.doubleSpinBox__vector.Signal_freq[5 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(5 ))
        self.doubleSpinBox__vector.Signal_freq[6 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(6 ))
        self.doubleSpinBox__vector.Signal_freq[7 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(7 ))
        self.doubleSpinBox__vector.Signal_freq[8 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(8 ))
        self.doubleSpinBox__vector.Signal_freq[9 ].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(9 ))
        self.doubleSpinBox__vector.Signal_freq[10].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(10))
        self.doubleSpinBox__vector.Signal_freq[11].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(11))
        self.doubleSpinBox__vector.Signal_freq[12].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(12))
        self.doubleSpinBox__vector.Signal_freq[13].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(13))
        self.doubleSpinBox__vector.Signal_freq[14].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(14))
        self.doubleSpinBox__vector.Signal_freq[15].valueChanged.connect(lambda: self.doubleSpinBox_Signal_freq__valueChanged(15))

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

    def refreshWrite(self, numChannel):
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
        self.RTBox_workerWrite.RTBox_setProgrammableValue(numChannel)

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
        self.update_PlotData()

    def reportProgressRead(self, n):
        print("Read " + n + " Completed")

    def reportReadFinished(self):
        self.time = time.time()
        self.numcallRead = self.numcallRead + 1
        print("MainWindows Read. Call " + str(self.numcallRead) + " Time: " + str(self.time))

    def init_PlotData(self):
        #self.groupBox_Plot = QtWidgets.QGroupBox(self.centralwidget)
        #self.groupBox_Plot.setObjectName("groupBox_Plot")
        #self.groupBox_Plot.setFixedHeight(self.groupBox_Plot_height)
        #self.gridLayout_4.addWidget(self.groupBox_Plot, 2, 0, 1, 1)
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
        self.data_line_AC1 =  self.graphWidget.plot(self.x, self.DataPlot1, pen = pen1)
        self.data_line_AC2 =  self.graphWidget.plot(self.x, self.DataPlot2, pen = pen2)
        self.data_line_AC3 =  self.graphWidget.plot(self.x, self.DataPlot3, pen = pen3)

    def update_PlotData(self):
        if ((self.PlotData_Ena == 1) & (RTBOX_STATUS == DeviceStatus.RUNNING) & (RTBOX_CONNECTED == ConnectionStatus.CONNECTED)
            & (data_Capture1 != [])
            & (data_Capture2 != [])
            & (data_Capture3 != [])):
            self.DataPlot1 = [idx[0] for idx in data_Capture1[0]]   #data_Capture1[0]
            self.DataPlot2 = [idx[0] for idx in data_Capture2[0]]
            self.DataPlot3 = [idx[0] for idx in data_Capture3[0]]
            self.data_line_AC1.setData(self.x, self.DataPlot1)
            self.data_line_AC2.setData(self.x, self.DataPlot2)
            self.data_line_AC3.setData(self.x, self.DataPlot3)
        else:
            pass

    ## Specific Implementation

    def doubleSpinBox_Signal_amp__valueChanged(self, channelNum):
        global channel_settings
        channel_settings.Signal_amp[channelNum] = self.doubleSpinBox__vector.Signal_amp[channelNum].value()

    def doubleSpinBox_Signal_freq__valueChanged(self, channelNum):
        global channel_settings
        if (self.doubleSpinBox__vector.Signal_freq[channelNum].value() != 0.0):
            channel_settings.Signal_freqRads[channelNum] = (2*PI) * self.doubleSpinBox__vector.Signal_freq[channelNum].value()
            self.doubleSpinBox__vector.Signal_phase[channelNum].setEnabled(1)
        else:
            channel_settings.Signal_freqRads[channelNum] = 0.0
            channel_settings.Signal_amp[channelNum] = self.doubleSpinBox__vector.Signal_amp[channelNum].value()
            channel_settings.Signal_phaseRad[channelNum] = (PI/2.0)
            self.doubleSpinBox__vector.Signal_phase[channelNum].setEnabled(0)

    def doubleSpinBox_Signal_phase__valueChanged(self, channelNum):
        global channel_settings
        channel_settings.Signal_phaseRad[channelNum] = ((self.doubleSpinBox__vector.Signal_phase[channelNum].value())*2*PI/360.0)

    def doubleSpinBox_Ramp_time__valueChanged(self, channelNum):
        global channel_settings
        channel_settings.Ramp_freq[channelNum] = (1.0) / self.doubleSpinBox__vector.Ramp_time[channelNum].value()

    def doubleSpinBox_SwNoise_amp__valueChanged(self, channelNum):
        global channel_settings
        channel_settings.SwNoise_amp[channelNum] = self.doubleSpinBox__vector.SwNoise_amp[channelNum].value()

    def doubleSpinBox_SwNoise_freq__valueChanged(self, channelNum):
        global channel_settings
        channel_settings.SwNoise_freq[channelNum] = self.doubleSpinBox__vector.SwNoise_freq[channelNum].value()

    def doubleSpinBox_WhiteNoise_amp__valueChanged(self, channelNum):
        global channel_settings
        channel_settings.WhiteNoise_amp[channelNum] = self.doubleSpinBox__vector.WhiteNoise_amp[channelNum].value()

    def pushButton_Channel_set__clicked(self, channelNum):
        global channel_settings
        self.refreshWrite(channelNum)

    def pushButton_Channel_en__clicked(self, channelNum):
        global channel_settings
        if (self.pushButton__vector.ChannelEn[channelNum].isChecked() == 1):
            self.pushButton__vector.ChannelEn[channelNum].setText("Channel On")
            channel_settings.Channel_en[channelNum] = 1
        else:
            self.pushButton__vector.ChannelEn[channelNum].setText("Channel Off")
            channel_settings.Channel_en[channelNum] = -1
        
        if (channel_settings.ChannelGlobal_en == 1):
            self.refreshWrite(DESIGN_CHANNELS_START_BLOCK)

    def pushButton_ChannelGlobal_en__clicked(self):
        global channel_settings
        if (self.pushButton_ChannelGlobal_en.isChecked() == 1):
            self.pushButton_ChannelGlobal_en.setText("Channel Global Enable On")
            channel_settings.ChannelGlobal_en = 1
            self.refreshWrite(DESIGN_CHANNELS_START_BLOCK)
        else:
            self.pushButton_ChannelGlobal_en.setText("Channel Global Enable Off")
            channel_settings.ChannelGlobal_en = 0
            self.refreshWrite(DESIGN_CHANNELS_START_BLOCK)

    def pushButton_EnablePlot__clicked(self):
        if self.pushButton_EnablePlot.isChecked():
            self.pushButton_EnablePlot.setText("Plot On")
            self.PlotData_Ena = 1
            #self.groupBox_Plot.show()
            self.timer_RefreshRead.start(TOUT_mainWindow_RefreshRead_ms)
            #self.mainHeightMin = 700
        else:
            self.pushButton_EnablePlot.setText("Plot Off")
            self.PlotData_Ena = 0
            self.timer_RefreshRead.stop()
            #self.layout.removeWidget(self.groupBox_Plot)
            #sip.delete(self.groupBox_Plot)
            #self.groupBox_Plot.hide()
            #self.mainHeightMax = 900
            #self.setFixedHeight(700)

    def spinBox_selPlot__valueChanged(self, selNum, selVal):
        global channel_settings

        match (selNum):
            case 1:
                channel_settings.Channel_outSel = selVal
                self.refreshWrite(DESIGN_CHANNELS_OUTSEL_BLOCK_1)
            case 2:
                channel_settings.Channel_outSel = selVal
                self.refreshWrite(DESIGN_CHANNELS_OUTSEL_BLOCK_2)
            case 3:
                channel_settings.Channel_outSel = selVal
                self.refreshWrite(DESIGN_CHANNELS_OUTSEL_BLOCK_3)

    def spinBox_selTrig__valueChanged(self, selVal):
        global channel_settings
        
        channel_settings.Channel_outTrig = selVal
        self.refreshWrite(DESIGN_CHANNELS_TRIG_BLOCK)

# ===============================================================================
# SETTINGS DIALOG CLASS
# ===============================================================================
class settingsDialog(QDialog, Ui_Dialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)
        self.setWindowTitle("RT-Box Settings")
        self.numcall = 0
        self.comboBox_RtBoxMacAddress.insertItem(0, str("RtBox1 - " + RTBOX_MACADDRESS_LIST[0]))
        self.comboBox_RtBoxMacAddress.insertItem(1, str("RtBox3 - " + RTBOX_MACADDRESS_LIST[1]))
        if (RTBOX_MACADDRESS == RTBOX_MACADDRESS_LIST[0]):
            self.comboBox_RtBoxMacAddress.setCurrentIndex(0)
        else:
            self.comboBox_RtBoxMacAddress.setCurrentIndex(1)
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
        self.comboBox_RtBoxMacAddress.currentIndexChanged.connect(self.onComboBox_indexChanged)
        self.pushButton_BrowseDesignFilePath.clicked.connect(self.browseDesignFile)
        self.timer_RefreshLabels.timeout.connect(self.refreshLabels)
        self.timer_RefreshLabels.timeout.connect(lambda: self.callRTBoxMethod(5))

    def refreshLabels(self):
        global RTBOX_SERVER_XMLPRC
        global RTBOX_STATUS_INT
        global RTBOX_STATUS
        global RTBOX_CONNECTED
        global RTBOX_IPFOUND

        if (RTBOX_CONNECTED == ConnectionStatus.CONNECTED):

            if (RTBOX_MACADDRESS == RTBOX_MACADDRESS_LIST[0]):   # RTBox1
                idxsel = 7
            elif (RTBOX_MACADDRESS == RTBOX_MACADDRESS_LIST[1]):   # RTBox3
                idxsel = 8

            if (RTBOX_STATUS_INT[idxsel] == 'running'):
                RTBOX_STATUS = DeviceStatus.RUNNING
                self.pushButton_Start.setEnabled(0)
                self.pushButton_Stop.setEnabled(1)
            elif(RTBOX_STATUS_INT[idxsel] == 'stopped'):
                RTBOX_STATUS = DeviceStatus.STOPPED
                self.pushButton_Start.setEnabled(1)
                self.pushButton_Stop.setEnabled(0)
            elif(RTBOX_STATUS_INT[idxsel] == 'error'):
                RTBOX_STATUS = DeviceStatus.ERROR
                self.pushButton_Start.setEnabled(0)
                self.pushButton_Stop.setEnabled(0)
            else:
                self.pushButton_Start.setEnabled(1)
                self.pushButton_Stop.setEnabled(1)

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

    def onComboBox_indexChanged(self):
        global HOST_NAME
        global RTBOX_MACADDRESS
        idx = self.comboBox_RtBoxMacAddress.currentIndex()
        RTBOX_MACADDRESS = RTBOX_MACADDRESS_LIST[idx]
        HOST_NAME = "rtbox-" + RTBOX_MACADDRESS + ".local"

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
            case 5:
                self.RTBox.RTBox_querySimulation()
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