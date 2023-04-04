# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'main_window.ui'
##
## Created by: Qt User Interface Compiler version 6.4.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QAction, QBrush, QColor, QConicalGradient,
    QCursor, QFont, QFontDatabase, QGradient,
    QIcon, QImage, QKeySequence, QLinearGradient,
    QPainter, QPalette, QPixmap, QRadialGradient,
    QTransform)
from PySide6.QtWidgets import (QApplication, QDoubleSpinBox, QGridLayout, QGroupBox,
    QLabel, QLayout, QMainWindow, QMenu,
    QMenuBar, QPushButton, QSizePolicy, QSpinBox,
    QStatusBar, QToolBar, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(983, 343)
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        self.action_Exit = QAction(MainWindow)
        self.action_Exit.setObjectName(u"action_Exit")
        icon = QIcon()
        icon.addFile(u"resources/icons8-chiudi-la-finestra-24.png", QSize(), QIcon.Normal, QIcon.Off)
        self.action_Exit.setIcon(icon)
        self.action_About = QAction(MainWindow)
        self.action_About.setObjectName(u"action_About")
        icon1 = QIcon()
        icon1.addFile(u"resources/icons8-informazioni-24.png", QSize(), QIcon.Normal, QIcon.Off)
        self.action_About.setIcon(icon1)
        self.action_Settings = QAction(MainWindow)
        self.action_Settings.setObjectName(u"action_Settings")
        icon2 = QIcon()
        icon2.addFile(u"resources/icons8-automatico-24.png", QSize(), QIcon.Normal, QIcon.Off)
        self.action_Settings.setIcon(icon2)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayout_4 = QGridLayout(self.centralwidget)
        self.gridLayout_4.setObjectName(u"gridLayout_4")
        self.pushButton_EnablePlot = QPushButton(self.centralwidget)
        self.pushButton_EnablePlot.setObjectName(u"pushButton_EnablePlot")
        self.pushButton_EnablePlot.setCheckable(True)

        self.gridLayout_4.addWidget(self.pushButton_EnablePlot, 1, 0, 1, 1)

        self.gridLayout_3 = QGridLayout()
        self.gridLayout_3.setObjectName(u"gridLayout_3")
        self.gridLayout_3.setSizeConstraint(QLayout.SetMinimumSize)
        self.groupBox = QGroupBox(self.centralwidget)
        self.groupBox.setObjectName(u"groupBox")
        sizePolicy1 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Fixed)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.groupBox.sizePolicy().hasHeightForWidth())
        self.groupBox.setSizePolicy(sizePolicy1)
        self.gridLayout = QGridLayout(self.groupBox)
        self.gridLayout.setObjectName(u"gridLayout")
        self.label_7 = QLabel(self.groupBox)
        self.label_7.setObjectName(u"label_7")

        self.gridLayout.addWidget(self.label_7, 4, 1, 1, 1)

        self.doubleSpinBox_snAmp = QDoubleSpinBox(self.groupBox)
        self.doubleSpinBox_snAmp.setObjectName(u"doubleSpinBox_snAmp")
        self.doubleSpinBox_snAmp.setMaximum(1.000000000000000)
        self.doubleSpinBox_snAmp.setSingleStep(0.010000000000000)

        self.gridLayout.addWidget(self.doubleSpinBox_snAmp, 5, 1, 1, 1)

        self.label_6 = QLabel(self.groupBox)
        self.label_6.setObjectName(u"label_6")

        self.gridLayout.addWidget(self.label_6, 2, 1, 1, 1)

        self.doubleSpinBox_voltageRampTime = QDoubleSpinBox(self.groupBox)
        self.doubleSpinBox_voltageRampTime.setObjectName(u"doubleSpinBox_voltageRampTime")
        self.doubleSpinBox_voltageRampTime.setDecimals(1)
        self.doubleSpinBox_voltageRampTime.setMaximum(50.000000000000000)
        self.doubleSpinBox_voltageRampTime.setValue(10.000000000000000)

        self.gridLayout.addWidget(self.doubleSpinBox_voltageRampTime, 1, 3, 1, 1)

        self.pushButton_snEna = QPushButton(self.groupBox)
        self.pushButton_snEna.setObjectName(u"pushButton_snEna")
        self.pushButton_snEna.setCheckable(True)

        self.gridLayout.addWidget(self.pushButton_snEna, 5, 4, 1, 1)

        self.label_3 = QLabel(self.groupBox)
        self.label_3.setObjectName(u"label_3")

        self.gridLayout.addWidget(self.label_3, 0, 2, 1, 1)

        self.pushButton_voltageEna = QPushButton(self.groupBox)
        self.pushButton_voltageEna.setObjectName(u"pushButton_voltageEna")
        self.pushButton_voltageEna.setCheckable(True)

        self.gridLayout.addWidget(self.pushButton_voltageEna, 1, 4, 1, 1)

        self.label_16 = QLabel(self.groupBox)
        self.label_16.setObjectName(u"label_16")

        self.gridLayout.addWidget(self.label_16, 5, 0, 1, 1)

        self.doubleSpinBox_vFreq = QDoubleSpinBox(self.groupBox)
        self.doubleSpinBox_vFreq.setObjectName(u"doubleSpinBox_vFreq")
        self.doubleSpinBox_vFreq.setDecimals(0)
        self.doubleSpinBox_vFreq.setMinimum(30.000000000000000)
        self.doubleSpinBox_vFreq.setMaximum(60.000000000000000)
        self.doubleSpinBox_vFreq.setValue(50.000000000000000)

        self.gridLayout.addWidget(self.doubleSpinBox_vFreq, 1, 2, 1, 1)

        self.doubleSpinBox_unbalAmp = QDoubleSpinBox(self.groupBox)
        self.doubleSpinBox_unbalAmp.setObjectName(u"doubleSpinBox_unbalAmp")
        self.doubleSpinBox_unbalAmp.setMinimum(-1.000000000000000)
        self.doubleSpinBox_unbalAmp.setMaximum(1.000000000000000)
        self.doubleSpinBox_unbalAmp.setSingleStep(0.010000000000000)

        self.gridLayout.addWidget(self.doubleSpinBox_unbalAmp, 7, 1, 1, 1)

        self.label_2 = QLabel(self.groupBox)
        self.label_2.setObjectName(u"label_2")

        self.gridLayout.addWidget(self.label_2, 0, 1, 1, 1)

        self.label_5 = QLabel(self.groupBox)
        self.label_5.setObjectName(u"label_5")

        self.gridLayout.addWidget(self.label_5, 0, 3, 1, 1)

        self.pushButton_wnEna = QPushButton(self.groupBox)
        self.pushButton_wnEna.setObjectName(u"pushButton_wnEna")
        self.pushButton_wnEna.setCheckable(True)

        self.gridLayout.addWidget(self.pushButton_wnEna, 3, 4, 1, 1)

        self.label_12 = QLabel(self.groupBox)
        self.label_12.setObjectName(u"label_12")

        self.gridLayout.addWidget(self.label_12, 7, 0, 1, 1)

        self.doubleSpinBox_vAmp = QDoubleSpinBox(self.groupBox)
        self.doubleSpinBox_vAmp.setObjectName(u"doubleSpinBox_vAmp")
        self.doubleSpinBox_vAmp.setDecimals(3)
        self.doubleSpinBox_vAmp.setMaximum(7.000000000000000)
        self.doubleSpinBox_vAmp.setSingleStep(0.050000000000000)

        self.gridLayout.addWidget(self.doubleSpinBox_vAmp, 1, 1, 1, 1)

        self.doubleSpinBox_wnAmp = QDoubleSpinBox(self.groupBox)
        self.doubleSpinBox_wnAmp.setObjectName(u"doubleSpinBox_wnAmp")
        self.doubleSpinBox_wnAmp.setMaximum(1.000000000000000)
        self.doubleSpinBox_wnAmp.setSingleStep(0.010000000000000)

        self.gridLayout.addWidget(self.doubleSpinBox_wnAmp, 3, 1, 1, 1)

        self.pushButton_unbalEna = QPushButton(self.groupBox)
        self.pushButton_unbalEna.setObjectName(u"pushButton_unbalEna")
        self.pushButton_unbalEna.setCheckable(True)

        self.gridLayout.addWidget(self.pushButton_unbalEna, 7, 4, 1, 1)

        self.label_10 = QLabel(self.groupBox)
        self.label_10.setObjectName(u"label_10")

        self.gridLayout.addWidget(self.label_10, 3, 0, 1, 1)

        self.spinBox_unbalPhase = QSpinBox(self.groupBox)
        self.spinBox_unbalPhase.setObjectName(u"spinBox_unbalPhase")
        self.spinBox_unbalPhase.setMinimum(1)
        self.spinBox_unbalPhase.setMaximum(3)

        self.gridLayout.addWidget(self.spinBox_unbalPhase, 7, 2, 1, 1)

        self.doubleSpinBox_snFreq = QDoubleSpinBox(self.groupBox)
        self.doubleSpinBox_snFreq.setObjectName(u"doubleSpinBox_snFreq")
        self.doubleSpinBox_snFreq.setDecimals(0)
        self.doubleSpinBox_snFreq.setMaximum(1500.000000000000000)
        self.doubleSpinBox_snFreq.setValue(680.000000000000000)

        self.gridLayout.addWidget(self.doubleSpinBox_snFreq, 5, 2, 1, 1)

        self.label_8 = QLabel(self.groupBox)
        self.label_8.setObjectName(u"label_8")

        self.gridLayout.addWidget(self.label_8, 4, 2, 1, 1)

        self.label_9 = QLabel(self.groupBox)
        self.label_9.setObjectName(u"label_9")

        self.gridLayout.addWidget(self.label_9, 6, 1, 1, 1)

        self.label_14 = QLabel(self.groupBox)
        self.label_14.setObjectName(u"label_14")

        self.gridLayout.addWidget(self.label_14, 6, 2, 1, 1)

        self.label = QLabel(self.groupBox)
        self.label.setObjectName(u"label")

        self.gridLayout.addWidget(self.label, 1, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox, 0, 0, 1, 1)

        self.groupBox_2 = QGroupBox(self.centralwidget)
        self.groupBox_2.setObjectName(u"groupBox_2")
        sizePolicy1.setHeightForWidth(self.groupBox_2.sizePolicy().hasHeightForWidth())
        self.groupBox_2.setSizePolicy(sizePolicy1)
        self.gridLayout_2 = QGridLayout(self.groupBox_2)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.label_15 = QLabel(self.groupBox_2)
        self.label_15.setObjectName(u"label_15")

        self.gridLayout_2.addWidget(self.label_15, 0, 1, 1, 1)

        self.doubleSpinBox_unbalDCAmp = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_unbalDCAmp.setObjectName(u"doubleSpinBox_unbalDCAmp")
        self.doubleSpinBox_unbalDCAmp.setMinimum(-1.000000000000000)
        self.doubleSpinBox_unbalDCAmp.setMaximum(1.000000000000000)
        self.doubleSpinBox_unbalDCAmp.setSingleStep(0.010000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_unbalDCAmp, 7, 1, 1, 1)

        self.label_18 = QLabel(self.groupBox_2)
        self.label_18.setObjectName(u"label_18")

        self.gridLayout_2.addWidget(self.label_18, 0, 2, 1, 1)

        self.label_20 = QLabel(self.groupBox_2)
        self.label_20.setObjectName(u"label_20")

        self.gridLayout_2.addWidget(self.label_20, 2, 1, 1, 1)

        self.pushButton_vDCLink = QPushButton(self.groupBox_2)
        self.pushButton_vDCLink.setObjectName(u"pushButton_vDCLink")
        self.pushButton_vDCLink.setCheckable(True)

        self.gridLayout_2.addWidget(self.pushButton_vDCLink, 1, 4, 1, 1)

        self.pushButton_wnDCEna = QPushButton(self.groupBox_2)
        self.pushButton_wnDCEna.setObjectName(u"pushButton_wnDCEna")
        self.pushButton_wnDCEna.setCheckable(True)

        self.gridLayout_2.addWidget(self.pushButton_wnDCEna, 3, 5, 1, 1)

        self.doubleSpinBox_snDCAmp = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_snDCAmp.setObjectName(u"doubleSpinBox_snDCAmp")
        self.doubleSpinBox_snDCAmp.setMaximum(1.000000000000000)
        self.doubleSpinBox_snDCAmp.setSingleStep(0.010000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_snDCAmp, 5, 1, 1, 1)

        self.label_11 = QLabel(self.groupBox_2)
        self.label_11.setObjectName(u"label_11")

        self.gridLayout_2.addWidget(self.label_11, 3, 0, 1, 1)

        self.doubleSpinBox_vDCAmp1 = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_vDCAmp1.setObjectName(u"doubleSpinBox_vDCAmp1")
        self.doubleSpinBox_vDCAmp1.setDecimals(3)
        self.doubleSpinBox_vDCAmp1.setMaximum(2.000000000000000)
        self.doubleSpinBox_vDCAmp1.setSingleStep(0.010000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_vDCAmp1, 1, 1, 1, 1)

        self.pushButton_unbalDCEna = QPushButton(self.groupBox_2)
        self.pushButton_unbalDCEna.setObjectName(u"pushButton_unbalDCEna")
        self.pushButton_unbalDCEna.setCheckable(True)

        self.gridLayout_2.addWidget(self.pushButton_unbalDCEna, 7, 5, 1, 1)

        self.label_22 = QLabel(self.groupBox_2)
        self.label_22.setObjectName(u"label_22")

        self.gridLayout_2.addWidget(self.label_22, 4, 2, 1, 1)

        self.pushButton_vDCEna = QPushButton(self.groupBox_2)
        self.pushButton_vDCEna.setObjectName(u"pushButton_vDCEna")
        self.pushButton_vDCEna.setCheckable(True)

        self.gridLayout_2.addWidget(self.pushButton_vDCEna, 1, 5, 1, 1)

        self.spinBox_unbalDCPhase = QSpinBox(self.groupBox_2)
        self.spinBox_unbalDCPhase.setObjectName(u"spinBox_unbalDCPhase")
        self.spinBox_unbalDCPhase.setMinimum(1)
        self.spinBox_unbalDCPhase.setMaximum(3)

        self.gridLayout_2.addWidget(self.spinBox_unbalDCPhase, 7, 2, 1, 1)

        self.doubleSpinBox_vDCAmp3 = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_vDCAmp3.setObjectName(u"doubleSpinBox_vDCAmp3")
        self.doubleSpinBox_vDCAmp3.setDecimals(3)
        self.doubleSpinBox_vDCAmp3.setMaximum(2.000000000000000)
        self.doubleSpinBox_vDCAmp3.setSingleStep(0.010000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_vDCAmp3, 1, 3, 1, 1)

        self.doubleSpinBox_vDCAmp2 = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_vDCAmp2.setObjectName(u"doubleSpinBox_vDCAmp2")
        self.doubleSpinBox_vDCAmp2.setDecimals(3)
        self.doubleSpinBox_vDCAmp2.setMaximum(2.000000000000000)
        self.doubleSpinBox_vDCAmp2.setSingleStep(0.010000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_vDCAmp2, 1, 2, 1, 1)

        self.label_13 = QLabel(self.groupBox_2)
        self.label_13.setObjectName(u"label_13")

        self.gridLayout_2.addWidget(self.label_13, 7, 0, 1, 1)

        self.label_4 = QLabel(self.groupBox_2)
        self.label_4.setObjectName(u"label_4")

        self.gridLayout_2.addWidget(self.label_4, 1, 0, 1, 1)

        self.label_19 = QLabel(self.groupBox_2)
        self.label_19.setObjectName(u"label_19")

        self.gridLayout_2.addWidget(self.label_19, 0, 3, 1, 1)

        self.label_21 = QLabel(self.groupBox_2)
        self.label_21.setObjectName(u"label_21")

        self.gridLayout_2.addWidget(self.label_21, 4, 1, 1, 1)

        self.label_17 = QLabel(self.groupBox_2)
        self.label_17.setObjectName(u"label_17")

        self.gridLayout_2.addWidget(self.label_17, 5, 0, 1, 1)

        self.pushButton_snDCEna = QPushButton(self.groupBox_2)
        self.pushButton_snDCEna.setObjectName(u"pushButton_snDCEna")
        self.pushButton_snDCEna.setCheckable(True)

        self.gridLayout_2.addWidget(self.pushButton_snDCEna, 5, 5, 1, 1)

        self.doubleSpinBox_snDCFreq = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_snDCFreq.setObjectName(u"doubleSpinBox_snDCFreq")
        self.doubleSpinBox_snDCFreq.setDecimals(0)
        self.doubleSpinBox_snDCFreq.setMaximum(1500.000000000000000)
        self.doubleSpinBox_snDCFreq.setValue(680.000000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_snDCFreq, 5, 2, 1, 1)

        self.doubleSpinBox_wnDCAmp = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_wnDCAmp.setObjectName(u"doubleSpinBox_wnDCAmp")
        self.doubleSpinBox_wnDCAmp.setMaximum(1.000000000000000)
        self.doubleSpinBox_wnDCAmp.setSingleStep(0.010000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_wnDCAmp, 3, 1, 1, 1)

        self.label_23 = QLabel(self.groupBox_2)
        self.label_23.setObjectName(u"label_23")

        self.gridLayout_2.addWidget(self.label_23, 6, 1, 1, 1)

        self.label_24 = QLabel(self.groupBox_2)
        self.label_24.setObjectName(u"label_24")

        self.gridLayout_2.addWidget(self.label_24, 6, 2, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_2, 0, 1, 1, 1)


        self.gridLayout_4.addLayout(self.gridLayout_3, 0, 0, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 983, 21))
        self.menu_File = QMenu(self.menubar)
        self.menu_File.setObjectName(u"menu_File")
        self.menu_Edit = QMenu(self.menubar)
        self.menu_Edit.setObjectName(u"menu_Edit")
        self.menu_Help = QMenu(self.menubar)
        self.menu_Help.setObjectName(u"menu_Help")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.toolBar = QToolBar(MainWindow)
        self.toolBar.setObjectName(u"toolBar")
        MainWindow.addToolBar(Qt.TopToolBarArea, self.toolBar)

        self.menubar.addAction(self.menu_File.menuAction())
        self.menubar.addAction(self.menu_Edit.menuAction())
        self.menubar.addAction(self.menu_Help.menuAction())
        self.menu_File.addSeparator()
        self.menu_File.addAction(self.action_Exit)
        self.menu_Edit.addSeparator()
        self.menu_Edit.addAction(self.action_Settings)
        self.menu_Help.addAction(self.action_About)
        self.toolBar.addAction(self.action_About)
        self.toolBar.addAction(self.action_Settings)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Sample Editor", None))
        self.action_Exit.setText(QCoreApplication.translate("MainWindow", u"&Exit", None))
        self.action_About.setText(QCoreApplication.translate("MainWindow", u"&About...", None))
        self.action_Settings.setText(QCoreApplication.translate("MainWindow", u"&Settings", None))
#if QT_CONFIG(tooltip)
        self.action_Settings.setToolTip(QCoreApplication.translate("MainWindow", u"Launch Settings Dialog", None))
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        self.action_Settings.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+F", None))
#endif // QT_CONFIG(shortcut)
        self.pushButton_EnablePlot.setText(QCoreApplication.translate("MainWindow", u"Plot Off", None))
        self.groupBox.setTitle(QCoreApplication.translate("MainWindow", u"AC Voltage", None))
        self.label_7.setText(QCoreApplication.translate("MainWindow", u"Ampl [V]", None))
        self.label_6.setText(QCoreApplication.translate("MainWindow", u"Ampl [V]", None))
        self.pushButton_snEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"Freq [Hz]", None))
        self.pushButton_voltageEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_16.setText(QCoreApplication.translate("MainWindow", u"Switching Noise:", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Peak [V]", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"RampT [s]", None))
        self.pushButton_wnEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_12.setText(QCoreApplication.translate("MainWindow", u"Unbalance:", None))
        self.pushButton_unbalEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_10.setText(QCoreApplication.translate("MainWindow", u"White Noise:", None))
        self.label_8.setText(QCoreApplication.translate("MainWindow", u"Freq [Hz]", None))
        self.label_9.setText(QCoreApplication.translate("MainWindow", u"Ampl [V]", None))
        self.label_14.setText(QCoreApplication.translate("MainWindow", u"Phase [n]", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"3 Phase Voltage:", None))
        self.groupBox_2.setTitle(QCoreApplication.translate("MainWindow", u"DC Voltage", None))
        self.label_15.setText(QCoreApplication.translate("MainWindow", u"Ampl1 [V]", None))
        self.label_18.setText(QCoreApplication.translate("MainWindow", u"Ampl2 [V]", None))
        self.label_20.setText(QCoreApplication.translate("MainWindow", u"Ampl [V]", None))
        self.pushButton_vDCLink.setText(QCoreApplication.translate("MainWindow", u"Link Off", None))
        self.pushButton_wnDCEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_11.setText(QCoreApplication.translate("MainWindow", u"White Noise Ampl:", None))
        self.pushButton_unbalDCEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_22.setText(QCoreApplication.translate("MainWindow", u"Freq [Hz]", None))
        self.pushButton_vDCEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_13.setText(QCoreApplication.translate("MainWindow", u"Unbalance:", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"3 DC Voltage:", None))
        self.label_19.setText(QCoreApplication.translate("MainWindow", u"Ampl3 [V]", None))
        self.label_21.setText(QCoreApplication.translate("MainWindow", u"Ampl [V]", None))
        self.label_17.setText(QCoreApplication.translate("MainWindow", u"Switching Noise:", None))
        self.pushButton_snDCEna.setText(QCoreApplication.translate("MainWindow", u"Off", None))
        self.label_23.setText(QCoreApplication.translate("MainWindow", u"Ampl [V]", None))
        self.label_24.setText(QCoreApplication.translate("MainWindow", u"Phase [n]", None))
        self.menu_File.setTitle(QCoreApplication.translate("MainWindow", u"&File", None))
        self.menu_Edit.setTitle(QCoreApplication.translate("MainWindow", u"Options", None))
        self.menu_Help.setTitle(QCoreApplication.translate("MainWindow", u"&Help", None))
        self.toolBar.setWindowTitle(QCoreApplication.translate("MainWindow", u"toolBar", None))
    # retranslateUi

