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
    QMenuBar, QPushButton, QSizePolicy, QSpacerItem,
    QSpinBox, QStatusBar, QTabWidget, QToolBar,
    QVBoxLayout, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.setWindowModality(Qt.NonModal)
        MainWindow.resize(984, 842)
        sizePolicy = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setTabShape(QTabWidget.Rounded)
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
        self.layoutWidget = QWidget(self.centralwidget)
        self.layoutWidget.setObjectName(u"layoutWidget")
        self.layoutWidget.setGeometry(QRect(10, 14, 954, 750))
        self.verticalLayout = QVBoxLayout(self.layoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setSizeConstraint(QLayout.SetMinimumSize)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_3 = QGridLayout()
        self.gridLayout_3.setObjectName(u"gridLayout_3")
        self.gridLayout_3.setSizeConstraint(QLayout.SetMinimumSize)
        self.groupBox = QGroupBox(self.layoutWidget)
        self.groupBox.setObjectName(u"groupBox")
        sizePolicy1 = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Minimum)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.groupBox.sizePolicy().hasHeightForWidth())
        self.groupBox.setSizePolicy(sizePolicy1)
        self.groupBox.setMaximumSize(QSize(16777215, 16777215))
        self.gridLayout = QGridLayout(self.groupBox)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.label_14 = QLabel(self.groupBox)
        self.label_14.setObjectName(u"label_14")
        sizePolicy2 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Fixed)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.label_14.sizePolicy().hasHeightForWidth())
        self.label_14.setSizePolicy(sizePolicy2)
        self.label_14.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_14, 6, 0, 1, 1)

        self.label_9 = QLabel(self.groupBox)
        self.label_9.setObjectName(u"label_9")
        sizePolicy2.setHeightForWidth(self.label_9.sizePolicy().hasHeightForWidth())
        self.label_9.setSizePolicy(sizePolicy2)
        self.label_9.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_9, 3, 0, 1, 1)

        self.label_4 = QLabel(self.groupBox)
        self.label_4.setObjectName(u"label_4")
        sizePolicy2.setHeightForWidth(self.label_4.sizePolicy().hasHeightForWidth())
        self.label_4.setSizePolicy(sizePolicy2)
        self.label_4.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_4, 0, 0, 1, 1)

        self.label_13 = QLabel(self.groupBox)
        self.label_13.setObjectName(u"label_13")
        sizePolicy2.setHeightForWidth(self.label_13.sizePolicy().hasHeightForWidth())
        self.label_13.setSizePolicy(sizePolicy2)
        self.label_13.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_13, 2, 0, 1, 1)

        self.label_10 = QLabel(self.groupBox)
        self.label_10.setObjectName(u"label_10")
        sizePolicy2.setHeightForWidth(self.label_10.sizePolicy().hasHeightForWidth())
        self.label_10.setSizePolicy(sizePolicy2)
        self.label_10.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_10, 5, 0, 1, 1)

        self.label_6 = QLabel(self.groupBox)
        self.label_6.setObjectName(u"label_6")
        sizePolicy2.setHeightForWidth(self.label_6.sizePolicy().hasHeightForWidth())
        self.label_6.setSizePolicy(sizePolicy2)
        self.label_6.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_6, 4, 0, 1, 1)

        self.label_12 = QLabel(self.groupBox)
        self.label_12.setObjectName(u"label_12")
        sizePolicy2.setHeightForWidth(self.label_12.sizePolicy().hasHeightForWidth())
        self.label_12.setSizePolicy(sizePolicy2)
        self.label_12.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_12, 1, 0, 1, 1)

        self.label_15 = QLabel(self.groupBox)
        self.label_15.setObjectName(u"label_15")
        sizePolicy2.setHeightForWidth(self.label_15.sizePolicy().hasHeightForWidth())
        self.label_15.setSizePolicy(sizePolicy2)
        self.label_15.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_15, 8, 0, 1, 1)

        self.label_21 = QLabel(self.groupBox)
        self.label_21.setObjectName(u"label_21")
        sizePolicy2.setHeightForWidth(self.label_21.sizePolicy().hasHeightForWidth())
        self.label_21.setSizePolicy(sizePolicy2)
        self.label_21.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout.addWidget(self.label_21, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox, 0, 0, 1, 1)

        self.groupBox_2 = QGroupBox(self.layoutWidget)
        self.groupBox_2.setObjectName(u"groupBox_2")
        sizePolicy3 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Minimum)
        sizePolicy3.setHorizontalStretch(0)
        sizePolicy3.setVerticalStretch(0)
        sizePolicy3.setHeightForWidth(self.groupBox_2.sizePolicy().hasHeightForWidth())
        self.groupBox_2.setSizePolicy(sizePolicy3)
        self.gridLayout_2 = QGridLayout(self.groupBox_2)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.gridLayout_2.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_amp = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_Signal_amp.setObjectName(u"doubleSpinBox_Signal_amp")
        sizePolicy4 = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy4.setHorizontalStretch(0)
        sizePolicy4.setVerticalStretch(0)
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp.setDecimals(3)
        self.doubleSpinBox_Signal_amp.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp.setSingleStep(0.050000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_Signal_amp, 0, 0, 1, 1)

        self.doubleSpinBox_Signal_freq = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_Signal_freq.setObjectName(u"doubleSpinBox_Signal_freq")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq.setDecimals(1)
        self.doubleSpinBox_Signal_freq.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq.setValue(50.000000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_Signal_freq, 1, 0, 1, 1)

        self.doubleSpinBox_Signal_phase = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_Signal_phase.setObjectName(u"doubleSpinBox_Signal_phase")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase.setDecimals(1)
        self.doubleSpinBox_Signal_phase.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase.setValue(0.000000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_Signal_phase, 2, 0, 1, 1)

        self.pushButton_Channel0_en = QPushButton(self.groupBox_2)
        self.pushButton_Channel0_en.setObjectName(u"pushButton_Channel0_en")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en.setCheckable(True)

        self.gridLayout_2.addWidget(self.pushButton_Channel0_en, 8, 0, 1, 1)

        self.doubleSpinBox_Ramp_time = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_Ramp_time.setObjectName(u"doubleSpinBox_Ramp_time")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time.setDecimals(1)
        self.doubleSpinBox_Ramp_time.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time.setValue(5.000000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_Ramp_time, 3, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_WhiteNoise_amp.setObjectName(u"doubleSpinBox_WhiteNoise_amp")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp.setSingleStep(0.005000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_WhiteNoise_amp, 4, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_SwNoise_amp.setObjectName(u"doubleSpinBox_SwNoise_amp")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp.setSingleStep(0.010000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_SwNoise_amp, 5, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq = QDoubleSpinBox(self.groupBox_2)
        self.doubleSpinBox_SwNoise_freq.setObjectName(u"doubleSpinBox_SwNoise_freq")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq.setValue(680.000000000000000)

        self.gridLayout_2.addWidget(self.doubleSpinBox_SwNoise_freq, 6, 0, 1, 1)

        self.pushButton_Channel0_set = QPushButton(self.groupBox_2)
        self.pushButton_Channel0_set.setObjectName(u"pushButton_Channel0_set")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set.setCheckable(False)

        self.gridLayout_2.addWidget(self.pushButton_Channel0_set, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_2, 0, 1, 1, 1)

        self.groupBox_3 = QGroupBox(self.layoutWidget)
        self.groupBox_3.setObjectName(u"groupBox_3")
        sizePolicy3.setHeightForWidth(self.groupBox_3.sizePolicy().hasHeightForWidth())
        self.groupBox_3.setSizePolicy(sizePolicy3)
        self.gridLayout_4 = QGridLayout(self.groupBox_3)
        self.gridLayout_4.setObjectName(u"gridLayout_4")
        self.gridLayout_4.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_amp_2 = QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_Signal_amp_2.setObjectName(u"doubleSpinBox_Signal_amp_2")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_2.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_2.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_2.setDecimals(3)
        self.doubleSpinBox_Signal_amp_2.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_2.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_2.setSingleStep(0.050000000000000)

        self.gridLayout_4.addWidget(self.doubleSpinBox_Signal_amp_2, 0, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_2 = QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_Signal_phase_2.setObjectName(u"doubleSpinBox_Signal_phase_2")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_2.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_2.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_2.setDecimals(1)
        self.doubleSpinBox_Signal_phase_2.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_2.setValue(0.000000000000000)

        self.gridLayout_4.addWidget(self.doubleSpinBox_Signal_phase_2, 2, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_2 = QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_Ramp_time_2.setObjectName(u"doubleSpinBox_Ramp_time_2")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_2.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_2.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_2.setDecimals(1)
        self.doubleSpinBox_Ramp_time_2.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_2.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_2.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_2.setValue(5.000000000000000)

        self.gridLayout_4.addWidget(self.doubleSpinBox_Ramp_time_2, 3, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_2 = QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_WhiteNoise_amp_2.setObjectName(u"doubleSpinBox_WhiteNoise_amp_2")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_2.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_2.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_2.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_2.setSingleStep(0.005000000000000)

        self.gridLayout_4.addWidget(self.doubleSpinBox_WhiteNoise_amp_2, 4, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_2 = QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_Signal_freq_2.setObjectName(u"doubleSpinBox_Signal_freq_2")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_2.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_2.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_2.setDecimals(1)
        self.doubleSpinBox_Signal_freq_2.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_2.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_2.setValue(50.000000000000000)

        self.gridLayout_4.addWidget(self.doubleSpinBox_Signal_freq_2, 1, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_2 = QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_SwNoise_freq_2.setObjectName(u"doubleSpinBox_SwNoise_freq_2")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_2.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_2.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_2.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_2.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_2.setValue(680.000000000000000)

        self.gridLayout_4.addWidget(self.doubleSpinBox_SwNoise_freq_2, 6, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_2 = QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_SwNoise_amp_2.setObjectName(u"doubleSpinBox_SwNoise_amp_2")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_2.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_2.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_2.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_2.setSingleStep(0.010000000000000)

        self.gridLayout_4.addWidget(self.doubleSpinBox_SwNoise_amp_2, 5, 0, 1, 1)

        self.pushButton_Channel0_en_2 = QPushButton(self.groupBox_3)
        self.pushButton_Channel0_en_2.setObjectName(u"pushButton_Channel0_en_2")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_2.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_2.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_2.setCheckable(True)

        self.gridLayout_4.addWidget(self.pushButton_Channel0_en_2, 8, 0, 1, 1)

        self.pushButton_Channel0_set_2 = QPushButton(self.groupBox_3)
        self.pushButton_Channel0_set_2.setObjectName(u"pushButton_Channel0_set_2")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_2.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_2.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_2.setCheckable(False)

        self.gridLayout_4.addWidget(self.pushButton_Channel0_set_2, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_3, 0, 2, 1, 1)

        self.groupBox_4 = QGroupBox(self.layoutWidget)
        self.groupBox_4.setObjectName(u"groupBox_4")
        sizePolicy3.setHeightForWidth(self.groupBox_4.sizePolicy().hasHeightForWidth())
        self.groupBox_4.setSizePolicy(sizePolicy3)
        self.gridLayout_5 = QGridLayout(self.groupBox_4)
        self.gridLayout_5.setObjectName(u"gridLayout_5")
        self.gridLayout_5.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_amp_3 = QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_Signal_amp_3.setObjectName(u"doubleSpinBox_Signal_amp_3")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_3.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_3.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_3.setDecimals(3)
        self.doubleSpinBox_Signal_amp_3.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_3.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_3.setSingleStep(0.050000000000000)

        self.gridLayout_5.addWidget(self.doubleSpinBox_Signal_amp_3, 0, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_3 = QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_Signal_phase_3.setObjectName(u"doubleSpinBox_Signal_phase_3")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_3.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_3.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_3.setDecimals(1)
        self.doubleSpinBox_Signal_phase_3.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_3.setValue(0.000000000000000)

        self.gridLayout_5.addWidget(self.doubleSpinBox_Signal_phase_3, 2, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_3 = QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_Ramp_time_3.setObjectName(u"doubleSpinBox_Ramp_time_3")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_3.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_3.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_3.setDecimals(1)
        self.doubleSpinBox_Ramp_time_3.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_3.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_3.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_3.setValue(5.000000000000000)

        self.gridLayout_5.addWidget(self.doubleSpinBox_Ramp_time_3, 3, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_3 = QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_SwNoise_amp_3.setObjectName(u"doubleSpinBox_SwNoise_amp_3")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_3.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_3.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_3.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_3.setSingleStep(0.010000000000000)

        self.gridLayout_5.addWidget(self.doubleSpinBox_SwNoise_amp_3, 5, 0, 1, 1)

        self.pushButton_Channel0_en_3 = QPushButton(self.groupBox_4)
        self.pushButton_Channel0_en_3.setObjectName(u"pushButton_Channel0_en_3")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_3.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_3.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_3.setCheckable(True)

        self.gridLayout_5.addWidget(self.pushButton_Channel0_en_3, 8, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_3 = QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_WhiteNoise_amp_3.setObjectName(u"doubleSpinBox_WhiteNoise_amp_3")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_3.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_3.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_3.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_3.setSingleStep(0.005000000000000)

        self.gridLayout_5.addWidget(self.doubleSpinBox_WhiteNoise_amp_3, 4, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_3 = QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_Signal_freq_3.setObjectName(u"doubleSpinBox_Signal_freq_3")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_3.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_3.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_3.setDecimals(1)
        self.doubleSpinBox_Signal_freq_3.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_3.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_3.setValue(50.000000000000000)

        self.gridLayout_5.addWidget(self.doubleSpinBox_Signal_freq_3, 1, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_3 = QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_SwNoise_freq_3.setObjectName(u"doubleSpinBox_SwNoise_freq_3")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_3.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_3.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_3.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_3.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_3.setValue(680.000000000000000)

        self.gridLayout_5.addWidget(self.doubleSpinBox_SwNoise_freq_3, 6, 0, 1, 1)

        self.pushButton_Channel0_set_3 = QPushButton(self.groupBox_4)
        self.pushButton_Channel0_set_3.setObjectName(u"pushButton_Channel0_set_3")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_3.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_3.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_3.setCheckable(False)

        self.gridLayout_5.addWidget(self.pushButton_Channel0_set_3, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_4, 0, 3, 1, 1)

        self.groupBox_5 = QGroupBox(self.layoutWidget)
        self.groupBox_5.setObjectName(u"groupBox_5")
        sizePolicy3.setHeightForWidth(self.groupBox_5.sizePolicy().hasHeightForWidth())
        self.groupBox_5.setSizePolicy(sizePolicy3)
        self.gridLayout_6 = QGridLayout(self.groupBox_5)
        self.gridLayout_6.setObjectName(u"gridLayout_6")
        self.gridLayout_6.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_amp_4 = QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_Signal_amp_4.setObjectName(u"doubleSpinBox_Signal_amp_4")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_4.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_4.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_4.setDecimals(3)
        self.doubleSpinBox_Signal_amp_4.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_4.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_4.setSingleStep(0.050000000000000)

        self.gridLayout_6.addWidget(self.doubleSpinBox_Signal_amp_4, 0, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_4 = QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_WhiteNoise_amp_4.setObjectName(u"doubleSpinBox_WhiteNoise_amp_4")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_4.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_4.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_4.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_4.setSingleStep(0.005000000000000)

        self.gridLayout_6.addWidget(self.doubleSpinBox_WhiteNoise_amp_4, 4, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_4 = QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_Signal_freq_4.setObjectName(u"doubleSpinBox_Signal_freq_4")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_4.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_4.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_4.setDecimals(1)
        self.doubleSpinBox_Signal_freq_4.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_4.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_4.setValue(50.000000000000000)

        self.gridLayout_6.addWidget(self.doubleSpinBox_Signal_freq_4, 1, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_4 = QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_Signal_phase_4.setObjectName(u"doubleSpinBox_Signal_phase_4")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_4.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_4.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_4.setDecimals(1)
        self.doubleSpinBox_Signal_phase_4.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_4.setValue(0.000000000000000)

        self.gridLayout_6.addWidget(self.doubleSpinBox_Signal_phase_4, 2, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_4 = QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_Ramp_time_4.setObjectName(u"doubleSpinBox_Ramp_time_4")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_4.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_4.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_4.setDecimals(1)
        self.doubleSpinBox_Ramp_time_4.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_4.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_4.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_4.setValue(5.000000000000000)

        self.gridLayout_6.addWidget(self.doubleSpinBox_Ramp_time_4, 3, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_4 = QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_SwNoise_amp_4.setObjectName(u"doubleSpinBox_SwNoise_amp_4")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_4.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_4.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_4.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_4.setSingleStep(0.010000000000000)

        self.gridLayout_6.addWidget(self.doubleSpinBox_SwNoise_amp_4, 5, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_4 = QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_SwNoise_freq_4.setObjectName(u"doubleSpinBox_SwNoise_freq_4")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_4.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_4.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_4.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_4.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_4.setValue(680.000000000000000)

        self.gridLayout_6.addWidget(self.doubleSpinBox_SwNoise_freq_4, 6, 0, 1, 1)

        self.pushButton_Channel0_en_4 = QPushButton(self.groupBox_5)
        self.pushButton_Channel0_en_4.setObjectName(u"pushButton_Channel0_en_4")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_4.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_4.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_4.setCheckable(True)

        self.gridLayout_6.addWidget(self.pushButton_Channel0_en_4, 8, 0, 1, 1)

        self.pushButton_Channel0_set_4 = QPushButton(self.groupBox_5)
        self.pushButton_Channel0_set_4.setObjectName(u"pushButton_Channel0_set_4")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_4.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_4.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_4.setCheckable(False)

        self.gridLayout_6.addWidget(self.pushButton_Channel0_set_4, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_5, 0, 4, 1, 1)

        self.groupBox_6 = QGroupBox(self.layoutWidget)
        self.groupBox_6.setObjectName(u"groupBox_6")
        sizePolicy3.setHeightForWidth(self.groupBox_6.sizePolicy().hasHeightForWidth())
        self.groupBox_6.setSizePolicy(sizePolicy3)
        self.gridLayout_7 = QGridLayout(self.groupBox_6)
        self.gridLayout_7.setObjectName(u"gridLayout_7")
        self.gridLayout_7.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_freq_5 = QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_Signal_freq_5.setObjectName(u"doubleSpinBox_Signal_freq_5")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_5.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_5.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_5.setDecimals(1)
        self.doubleSpinBox_Signal_freq_5.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_5.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_5.setValue(50.000000000000000)

        self.gridLayout_7.addWidget(self.doubleSpinBox_Signal_freq_5, 1, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_5 = QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_WhiteNoise_amp_5.setObjectName(u"doubleSpinBox_WhiteNoise_amp_5")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_5.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_5.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_5.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_5.setSingleStep(0.005000000000000)

        self.gridLayout_7.addWidget(self.doubleSpinBox_WhiteNoise_amp_5, 4, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_5 = QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_Signal_phase_5.setObjectName(u"doubleSpinBox_Signal_phase_5")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_5.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_5.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_5.setDecimals(1)
        self.doubleSpinBox_Signal_phase_5.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_5.setValue(0.000000000000000)

        self.gridLayout_7.addWidget(self.doubleSpinBox_Signal_phase_5, 2, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_5 = QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_Ramp_time_5.setObjectName(u"doubleSpinBox_Ramp_time_5")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_5.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_5.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_5.setDecimals(1)
        self.doubleSpinBox_Ramp_time_5.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_5.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_5.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_5.setValue(5.000000000000000)

        self.gridLayout_7.addWidget(self.doubleSpinBox_Ramp_time_5, 3, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_5 = QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_SwNoise_amp_5.setObjectName(u"doubleSpinBox_SwNoise_amp_5")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_5.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_5.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_5.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_5.setSingleStep(0.010000000000000)

        self.gridLayout_7.addWidget(self.doubleSpinBox_SwNoise_amp_5, 5, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_5 = QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_Signal_amp_5.setObjectName(u"doubleSpinBox_Signal_amp_5")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_5.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_5.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_5.setDecimals(3)
        self.doubleSpinBox_Signal_amp_5.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_5.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_5.setSingleStep(0.050000000000000)

        self.gridLayout_7.addWidget(self.doubleSpinBox_Signal_amp_5, 0, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_5 = QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_SwNoise_freq_5.setObjectName(u"doubleSpinBox_SwNoise_freq_5")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_5.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_5.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_5.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_5.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_5.setValue(680.000000000000000)

        self.gridLayout_7.addWidget(self.doubleSpinBox_SwNoise_freq_5, 6, 0, 1, 1)

        self.pushButton_Channel0_en_5 = QPushButton(self.groupBox_6)
        self.pushButton_Channel0_en_5.setObjectName(u"pushButton_Channel0_en_5")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_5.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_5.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_5.setCheckable(True)

        self.gridLayout_7.addWidget(self.pushButton_Channel0_en_5, 8, 0, 1, 1)

        self.pushButton_Channel0_set_5 = QPushButton(self.groupBox_6)
        self.pushButton_Channel0_set_5.setObjectName(u"pushButton_Channel0_set_5")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_5.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_5.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_5.setCheckable(False)

        self.gridLayout_7.addWidget(self.pushButton_Channel0_set_5, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_6, 0, 5, 1, 1)

        self.groupBox_7 = QGroupBox(self.layoutWidget)
        self.groupBox_7.setObjectName(u"groupBox_7")
        sizePolicy3.setHeightForWidth(self.groupBox_7.sizePolicy().hasHeightForWidth())
        self.groupBox_7.setSizePolicy(sizePolicy3)
        self.gridLayout_8 = QGridLayout(self.groupBox_7)
        self.gridLayout_8.setObjectName(u"gridLayout_8")
        self.gridLayout_8.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_phase_6 = QDoubleSpinBox(self.groupBox_7)
        self.doubleSpinBox_Signal_phase_6.setObjectName(u"doubleSpinBox_Signal_phase_6")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_6.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_6.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_6.setDecimals(1)
        self.doubleSpinBox_Signal_phase_6.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_6.setValue(0.000000000000000)

        self.gridLayout_8.addWidget(self.doubleSpinBox_Signal_phase_6, 2, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_6 = QDoubleSpinBox(self.groupBox_7)
        self.doubleSpinBox_SwNoise_amp_6.setObjectName(u"doubleSpinBox_SwNoise_amp_6")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_6.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_6.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_6.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_6.setSingleStep(0.010000000000000)

        self.gridLayout_8.addWidget(self.doubleSpinBox_SwNoise_amp_6, 5, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_6 = QDoubleSpinBox(self.groupBox_7)
        self.doubleSpinBox_Signal_freq_6.setObjectName(u"doubleSpinBox_Signal_freq_6")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_6.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_6.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_6.setDecimals(1)
        self.doubleSpinBox_Signal_freq_6.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_6.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_6.setValue(50.000000000000000)

        self.gridLayout_8.addWidget(self.doubleSpinBox_Signal_freq_6, 1, 0, 1, 1)

        self.pushButton_Channel0_en_6 = QPushButton(self.groupBox_7)
        self.pushButton_Channel0_en_6.setObjectName(u"pushButton_Channel0_en_6")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_6.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_6.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_6.setCheckable(True)

        self.gridLayout_8.addWidget(self.pushButton_Channel0_en_6, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_6 = QDoubleSpinBox(self.groupBox_7)
        self.doubleSpinBox_Signal_amp_6.setObjectName(u"doubleSpinBox_Signal_amp_6")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_6.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_6.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_6.setDecimals(3)
        self.doubleSpinBox_Signal_amp_6.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_6.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_6.setSingleStep(0.050000000000000)

        self.gridLayout_8.addWidget(self.doubleSpinBox_Signal_amp_6, 0, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_6 = QDoubleSpinBox(self.groupBox_7)
        self.doubleSpinBox_WhiteNoise_amp_6.setObjectName(u"doubleSpinBox_WhiteNoise_amp_6")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_6.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_6.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_6.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_6.setSingleStep(0.005000000000000)

        self.gridLayout_8.addWidget(self.doubleSpinBox_WhiteNoise_amp_6, 4, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_6 = QDoubleSpinBox(self.groupBox_7)
        self.doubleSpinBox_SwNoise_freq_6.setObjectName(u"doubleSpinBox_SwNoise_freq_6")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_6.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_6.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_6.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_6.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_6.setValue(680.000000000000000)

        self.gridLayout_8.addWidget(self.doubleSpinBox_SwNoise_freq_6, 6, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_6 = QDoubleSpinBox(self.groupBox_7)
        self.doubleSpinBox_Ramp_time_6.setObjectName(u"doubleSpinBox_Ramp_time_6")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_6.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_6.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_6.setDecimals(1)
        self.doubleSpinBox_Ramp_time_6.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_6.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_6.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_6.setValue(5.000000000000000)

        self.gridLayout_8.addWidget(self.doubleSpinBox_Ramp_time_6, 3, 0, 1, 1)

        self.pushButton_Channel0_set_6 = QPushButton(self.groupBox_7)
        self.pushButton_Channel0_set_6.setObjectName(u"pushButton_Channel0_set_6")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_6.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_6.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_6.setCheckable(False)

        self.gridLayout_8.addWidget(self.pushButton_Channel0_set_6, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_7, 0, 6, 1, 1)

        self.groupBox_8 = QGroupBox(self.layoutWidget)
        self.groupBox_8.setObjectName(u"groupBox_8")
        sizePolicy3.setHeightForWidth(self.groupBox_8.sizePolicy().hasHeightForWidth())
        self.groupBox_8.setSizePolicy(sizePolicy3)
        self.gridLayout_9 = QGridLayout(self.groupBox_8)
        self.gridLayout_9.setObjectName(u"gridLayout_9")
        self.gridLayout_9.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_WhiteNoise_amp_7 = QDoubleSpinBox(self.groupBox_8)
        self.doubleSpinBox_WhiteNoise_amp_7.setObjectName(u"doubleSpinBox_WhiteNoise_amp_7")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_7.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_7.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_7.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_7.setSingleStep(0.005000000000000)

        self.gridLayout_9.addWidget(self.doubleSpinBox_WhiteNoise_amp_7, 4, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_7 = QDoubleSpinBox(self.groupBox_8)
        self.doubleSpinBox_Signal_freq_7.setObjectName(u"doubleSpinBox_Signal_freq_7")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_7.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_7.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_7.setDecimals(1)
        self.doubleSpinBox_Signal_freq_7.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_7.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_7.setValue(50.000000000000000)

        self.gridLayout_9.addWidget(self.doubleSpinBox_Signal_freq_7, 1, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_7 = QDoubleSpinBox(self.groupBox_8)
        self.doubleSpinBox_SwNoise_freq_7.setObjectName(u"doubleSpinBox_SwNoise_freq_7")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_7.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_7.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_7.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_7.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_7.setValue(680.000000000000000)

        self.gridLayout_9.addWidget(self.doubleSpinBox_SwNoise_freq_7, 6, 0, 1, 1)

        self.pushButton_Channel0_en_7 = QPushButton(self.groupBox_8)
        self.pushButton_Channel0_en_7.setObjectName(u"pushButton_Channel0_en_7")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_7.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_7.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_7.setCheckable(True)

        self.gridLayout_9.addWidget(self.pushButton_Channel0_en_7, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_7 = QDoubleSpinBox(self.groupBox_8)
        self.doubleSpinBox_Signal_phase_7.setObjectName(u"doubleSpinBox_Signal_phase_7")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_7.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_7.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_7.setDecimals(1)
        self.doubleSpinBox_Signal_phase_7.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_7.setValue(0.000000000000000)

        self.gridLayout_9.addWidget(self.doubleSpinBox_Signal_phase_7, 2, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_7 = QDoubleSpinBox(self.groupBox_8)
        self.doubleSpinBox_SwNoise_amp_7.setObjectName(u"doubleSpinBox_SwNoise_amp_7")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_7.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_7.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_7.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_7.setSingleStep(0.010000000000000)

        self.gridLayout_9.addWidget(self.doubleSpinBox_SwNoise_amp_7, 5, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_7 = QDoubleSpinBox(self.groupBox_8)
        self.doubleSpinBox_Signal_amp_7.setObjectName(u"doubleSpinBox_Signal_amp_7")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_7.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_7.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_7.setDecimals(3)
        self.doubleSpinBox_Signal_amp_7.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_7.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_7.setSingleStep(0.050000000000000)

        self.gridLayout_9.addWidget(self.doubleSpinBox_Signal_amp_7, 0, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_7 = QDoubleSpinBox(self.groupBox_8)
        self.doubleSpinBox_Ramp_time_7.setObjectName(u"doubleSpinBox_Ramp_time_7")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_7.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_7.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_7.setDecimals(1)
        self.doubleSpinBox_Ramp_time_7.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_7.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_7.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_7.setValue(5.000000000000000)

        self.gridLayout_9.addWidget(self.doubleSpinBox_Ramp_time_7, 3, 0, 1, 1)

        self.pushButton_Channel0_set_7 = QPushButton(self.groupBox_8)
        self.pushButton_Channel0_set_7.setObjectName(u"pushButton_Channel0_set_7")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_7.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_7.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_7.setCheckable(False)

        self.gridLayout_9.addWidget(self.pushButton_Channel0_set_7, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_8, 0, 7, 1, 1)

        self.groupBox_9 = QGroupBox(self.layoutWidget)
        self.groupBox_9.setObjectName(u"groupBox_9")
        sizePolicy3.setHeightForWidth(self.groupBox_9.sizePolicy().hasHeightForWidth())
        self.groupBox_9.setSizePolicy(sizePolicy3)
        self.gridLayout_10 = QGridLayout(self.groupBox_9)
        self.gridLayout_10.setObjectName(u"gridLayout_10")
        self.gridLayout_10.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Ramp_time_8 = QDoubleSpinBox(self.groupBox_9)
        self.doubleSpinBox_Ramp_time_8.setObjectName(u"doubleSpinBox_Ramp_time_8")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_8.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_8.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_8.setDecimals(1)
        self.doubleSpinBox_Ramp_time_8.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_8.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_8.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_8.setValue(5.000000000000000)

        self.gridLayout_10.addWidget(self.doubleSpinBox_Ramp_time_8, 3, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_8 = QDoubleSpinBox(self.groupBox_9)
        self.doubleSpinBox_WhiteNoise_amp_8.setObjectName(u"doubleSpinBox_WhiteNoise_amp_8")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_8.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_8.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_8.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_8.setSingleStep(0.005000000000000)

        self.gridLayout_10.addWidget(self.doubleSpinBox_WhiteNoise_amp_8, 4, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_8 = QDoubleSpinBox(self.groupBox_9)
        self.doubleSpinBox_SwNoise_amp_8.setObjectName(u"doubleSpinBox_SwNoise_amp_8")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_8.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_8.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_8.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_8.setSingleStep(0.010000000000000)

        self.gridLayout_10.addWidget(self.doubleSpinBox_SwNoise_amp_8, 5, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_8 = QDoubleSpinBox(self.groupBox_9)
        self.doubleSpinBox_Signal_phase_8.setObjectName(u"doubleSpinBox_Signal_phase_8")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_8.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_8.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_8.setDecimals(1)
        self.doubleSpinBox_Signal_phase_8.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_8.setValue(0.000000000000000)

        self.gridLayout_10.addWidget(self.doubleSpinBox_Signal_phase_8, 2, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_8 = QDoubleSpinBox(self.groupBox_9)
        self.doubleSpinBox_SwNoise_freq_8.setObjectName(u"doubleSpinBox_SwNoise_freq_8")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_8.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_8.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_8.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_8.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_8.setValue(680.000000000000000)

        self.gridLayout_10.addWidget(self.doubleSpinBox_SwNoise_freq_8, 6, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_8 = QDoubleSpinBox(self.groupBox_9)
        self.doubleSpinBox_Signal_amp_8.setObjectName(u"doubleSpinBox_Signal_amp_8")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_8.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_8.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_8.setDecimals(3)
        self.doubleSpinBox_Signal_amp_8.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_8.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_8.setSingleStep(0.050000000000000)

        self.gridLayout_10.addWidget(self.doubleSpinBox_Signal_amp_8, 0, 0, 1, 1)

        self.pushButton_Channel0_en_8 = QPushButton(self.groupBox_9)
        self.pushButton_Channel0_en_8.setObjectName(u"pushButton_Channel0_en_8")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_8.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_8.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_8.setCheckable(True)

        self.gridLayout_10.addWidget(self.pushButton_Channel0_en_8, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_8 = QDoubleSpinBox(self.groupBox_9)
        self.doubleSpinBox_Signal_freq_8.setObjectName(u"doubleSpinBox_Signal_freq_8")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_8.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_8.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_8.setDecimals(1)
        self.doubleSpinBox_Signal_freq_8.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_8.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_8.setValue(50.000000000000000)

        self.gridLayout_10.addWidget(self.doubleSpinBox_Signal_freq_8, 1, 0, 1, 1)

        self.pushButton_Channel0_set_8 = QPushButton(self.groupBox_9)
        self.pushButton_Channel0_set_8.setObjectName(u"pushButton_Channel0_set_8")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_8.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_8.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_8.setCheckable(False)

        self.gridLayout_10.addWidget(self.pushButton_Channel0_set_8, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_9, 0, 8, 1, 1)

        self.groupBox_18 = QGroupBox(self.layoutWidget)
        self.groupBox_18.setObjectName(u"groupBox_18")
        sizePolicy1.setHeightForWidth(self.groupBox_18.sizePolicy().hasHeightForWidth())
        self.groupBox_18.setSizePolicy(sizePolicy1)
        self.gridLayout_19 = QGridLayout(self.groupBox_18)
        self.gridLayout_19.setObjectName(u"gridLayout_19")
        self.gridLayout_19.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.label_16 = QLabel(self.groupBox_18)
        self.label_16.setObjectName(u"label_16")
        sizePolicy2.setHeightForWidth(self.label_16.sizePolicy().hasHeightForWidth())
        self.label_16.setSizePolicy(sizePolicy2)
        self.label_16.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_16, 1, 0, 1, 1)

        self.label_18 = QLabel(self.groupBox_18)
        self.label_18.setObjectName(u"label_18")
        sizePolicy2.setHeightForWidth(self.label_18.sizePolicy().hasHeightForWidth())
        self.label_18.setSizePolicy(sizePolicy2)
        self.label_18.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_18, 5, 0, 1, 1)

        self.label_20 = QLabel(self.groupBox_18)
        self.label_20.setObjectName(u"label_20")
        sizePolicy2.setHeightForWidth(self.label_20.sizePolicy().hasHeightForWidth())
        self.label_20.setSizePolicy(sizePolicy2)
        self.label_20.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_20, 8, 0, 1, 1)

        self.label_5 = QLabel(self.groupBox_18)
        self.label_5.setObjectName(u"label_5")
        sizePolicy2.setHeightForWidth(self.label_5.sizePolicy().hasHeightForWidth())
        self.label_5.setSizePolicy(sizePolicy2)
        self.label_5.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_5, 0, 0, 1, 1)

        self.label_11 = QLabel(self.groupBox_18)
        self.label_11.setObjectName(u"label_11")
        sizePolicy2.setHeightForWidth(self.label_11.sizePolicy().hasHeightForWidth())
        self.label_11.setSizePolicy(sizePolicy2)
        self.label_11.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_11, 3, 0, 1, 1)

        self.label_7 = QLabel(self.groupBox_18)
        self.label_7.setObjectName(u"label_7")
        sizePolicy2.setHeightForWidth(self.label_7.sizePolicy().hasHeightForWidth())
        self.label_7.setSizePolicy(sizePolicy2)
        self.label_7.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_7, 4, 0, 1, 1)

        self.label_17 = QLabel(self.groupBox_18)
        self.label_17.setObjectName(u"label_17")
        sizePolicy2.setHeightForWidth(self.label_17.sizePolicy().hasHeightForWidth())
        self.label_17.setSizePolicy(sizePolicy2)
        self.label_17.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_17, 2, 0, 1, 1)

        self.label_19 = QLabel(self.groupBox_18)
        self.label_19.setObjectName(u"label_19")
        sizePolicy2.setHeightForWidth(self.label_19.sizePolicy().hasHeightForWidth())
        self.label_19.setSizePolicy(sizePolicy2)
        self.label_19.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_19, 6, 0, 1, 1)

        self.label_22 = QLabel(self.groupBox_18)
        self.label_22.setObjectName(u"label_22")
        sizePolicy2.setHeightForWidth(self.label_22.sizePolicy().hasHeightForWidth())
        self.label_22.setSizePolicy(sizePolicy2)
        self.label_22.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)

        self.gridLayout_19.addWidget(self.label_22, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_18, 1, 0, 1, 1)

        self.groupBox_10 = QGroupBox(self.layoutWidget)
        self.groupBox_10.setObjectName(u"groupBox_10")
        sizePolicy3.setHeightForWidth(self.groupBox_10.sizePolicy().hasHeightForWidth())
        self.groupBox_10.setSizePolicy(sizePolicy3)
        self.gridLayout_11 = QGridLayout(self.groupBox_10)
        self.gridLayout_11.setObjectName(u"gridLayout_11")
        self.gridLayout_11.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_freq_9 = QDoubleSpinBox(self.groupBox_10)
        self.doubleSpinBox_Signal_freq_9.setObjectName(u"doubleSpinBox_Signal_freq_9")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_9.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_9.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_9.setDecimals(1)
        self.doubleSpinBox_Signal_freq_9.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_9.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_9.setValue(50.000000000000000)

        self.gridLayout_11.addWidget(self.doubleSpinBox_Signal_freq_9, 1, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_9 = QDoubleSpinBox(self.groupBox_10)
        self.doubleSpinBox_WhiteNoise_amp_9.setObjectName(u"doubleSpinBox_WhiteNoise_amp_9")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_9.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_9.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_9.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_9.setSingleStep(0.010000000000000)

        self.gridLayout_11.addWidget(self.doubleSpinBox_WhiteNoise_amp_9, 4, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_9 = QDoubleSpinBox(self.groupBox_10)
        self.doubleSpinBox_SwNoise_freq_9.setObjectName(u"doubleSpinBox_SwNoise_freq_9")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_9.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_9.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_9.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_9.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_9.setValue(680.000000000000000)

        self.gridLayout_11.addWidget(self.doubleSpinBox_SwNoise_freq_9, 6, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_9 = QDoubleSpinBox(self.groupBox_10)
        self.doubleSpinBox_Signal_amp_9.setObjectName(u"doubleSpinBox_Signal_amp_9")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_9.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_9.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_9.setDecimals(3)
        self.doubleSpinBox_Signal_amp_9.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_9.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_9.setSingleStep(0.050000000000000)

        self.gridLayout_11.addWidget(self.doubleSpinBox_Signal_amp_9, 0, 0, 1, 1)

        self.pushButton_Channel0_en_9 = QPushButton(self.groupBox_10)
        self.pushButton_Channel0_en_9.setObjectName(u"pushButton_Channel0_en_9")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_9.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_9.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_9.setCheckable(True)

        self.gridLayout_11.addWidget(self.pushButton_Channel0_en_9, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_9 = QDoubleSpinBox(self.groupBox_10)
        self.doubleSpinBox_Signal_phase_9.setObjectName(u"doubleSpinBox_Signal_phase_9")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_9.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_9.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_9.setDecimals(1)
        self.doubleSpinBox_Signal_phase_9.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_9.setValue(0.000000000000000)

        self.gridLayout_11.addWidget(self.doubleSpinBox_Signal_phase_9, 2, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_9 = QDoubleSpinBox(self.groupBox_10)
        self.doubleSpinBox_Ramp_time_9.setObjectName(u"doubleSpinBox_Ramp_time_9")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_9.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_9.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_9.setDecimals(1)
        self.doubleSpinBox_Ramp_time_9.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_9.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_9.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_9.setValue(5.000000000000000)

        self.gridLayout_11.addWidget(self.doubleSpinBox_Ramp_time_9, 3, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_9 = QDoubleSpinBox(self.groupBox_10)
        self.doubleSpinBox_SwNoise_amp_9.setObjectName(u"doubleSpinBox_SwNoise_amp_9")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_9.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_9.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_9.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_9.setSingleStep(0.005000000000000)

        self.gridLayout_11.addWidget(self.doubleSpinBox_SwNoise_amp_9, 5, 0, 1, 1)

        self.pushButton_Channel0_set_9 = QPushButton(self.groupBox_10)
        self.pushButton_Channel0_set_9.setObjectName(u"pushButton_Channel0_set_9")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_9.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_9.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_9.setCheckable(False)

        self.gridLayout_11.addWidget(self.pushButton_Channel0_set_9, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_10, 1, 1, 1, 1)

        self.groupBox_11 = QGroupBox(self.layoutWidget)
        self.groupBox_11.setObjectName(u"groupBox_11")
        sizePolicy3.setHeightForWidth(self.groupBox_11.sizePolicy().hasHeightForWidth())
        self.groupBox_11.setSizePolicy(sizePolicy3)
        self.gridLayout_12 = QGridLayout(self.groupBox_11)
        self.gridLayout_12.setObjectName(u"gridLayout_12")
        self.gridLayout_12.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Ramp_time_10 = QDoubleSpinBox(self.groupBox_11)
        self.doubleSpinBox_Ramp_time_10.setObjectName(u"doubleSpinBox_Ramp_time_10")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_10.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_10.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_10.setDecimals(1)
        self.doubleSpinBox_Ramp_time_10.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_10.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_10.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_10.setValue(5.000000000000000)

        self.gridLayout_12.addWidget(self.doubleSpinBox_Ramp_time_10, 3, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_10 = QDoubleSpinBox(self.groupBox_11)
        self.doubleSpinBox_Signal_phase_10.setObjectName(u"doubleSpinBox_Signal_phase_10")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_10.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_10.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_10.setDecimals(1)
        self.doubleSpinBox_Signal_phase_10.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_10.setValue(0.000000000000000)

        self.gridLayout_12.addWidget(self.doubleSpinBox_Signal_phase_10, 2, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_10 = QDoubleSpinBox(self.groupBox_11)
        self.doubleSpinBox_WhiteNoise_amp_10.setObjectName(u"doubleSpinBox_WhiteNoise_amp_10")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_10.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_10.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_10.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_10.setSingleStep(0.010000000000000)

        self.gridLayout_12.addWidget(self.doubleSpinBox_WhiteNoise_amp_10, 4, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_10 = QDoubleSpinBox(self.groupBox_11)
        self.doubleSpinBox_SwNoise_freq_10.setObjectName(u"doubleSpinBox_SwNoise_freq_10")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_10.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_10.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_10.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_10.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_10.setValue(680.000000000000000)

        self.gridLayout_12.addWidget(self.doubleSpinBox_SwNoise_freq_10, 6, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_10 = QDoubleSpinBox(self.groupBox_11)
        self.doubleSpinBox_Signal_freq_10.setObjectName(u"doubleSpinBox_Signal_freq_10")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_10.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_10.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_10.setDecimals(1)
        self.doubleSpinBox_Signal_freq_10.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_10.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_10.setValue(50.000000000000000)

        self.gridLayout_12.addWidget(self.doubleSpinBox_Signal_freq_10, 1, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_10 = QDoubleSpinBox(self.groupBox_11)
        self.doubleSpinBox_SwNoise_amp_10.setObjectName(u"doubleSpinBox_SwNoise_amp_10")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_10.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_10.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_10.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_10.setSingleStep(0.005000000000000)

        self.gridLayout_12.addWidget(self.doubleSpinBox_SwNoise_amp_10, 5, 0, 1, 1)

        self.pushButton_Channel0_en_10 = QPushButton(self.groupBox_11)
        self.pushButton_Channel0_en_10.setObjectName(u"pushButton_Channel0_en_10")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_10.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_10.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_10.setCheckable(True)

        self.gridLayout_12.addWidget(self.pushButton_Channel0_en_10, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_10 = QDoubleSpinBox(self.groupBox_11)
        self.doubleSpinBox_Signal_amp_10.setObjectName(u"doubleSpinBox_Signal_amp_10")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_10.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_10.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_10.setDecimals(3)
        self.doubleSpinBox_Signal_amp_10.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_10.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_10.setSingleStep(0.050000000000000)

        self.gridLayout_12.addWidget(self.doubleSpinBox_Signal_amp_10, 0, 0, 1, 1)

        self.pushButton_Channel0_set_10 = QPushButton(self.groupBox_11)
        self.pushButton_Channel0_set_10.setObjectName(u"pushButton_Channel0_set_10")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_10.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_10.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_10.setCheckable(False)

        self.gridLayout_12.addWidget(self.pushButton_Channel0_set_10, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_11, 1, 2, 1, 1)

        self.groupBox_12 = QGroupBox(self.layoutWidget)
        self.groupBox_12.setObjectName(u"groupBox_12")
        sizePolicy3.setHeightForWidth(self.groupBox_12.sizePolicy().hasHeightForWidth())
        self.groupBox_12.setSizePolicy(sizePolicy3)
        self.gridLayout_13 = QGridLayout(self.groupBox_12)
        self.gridLayout_13.setObjectName(u"gridLayout_13")
        self.gridLayout_13.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_freq_11 = QDoubleSpinBox(self.groupBox_12)
        self.doubleSpinBox_Signal_freq_11.setObjectName(u"doubleSpinBox_Signal_freq_11")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_11.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_11.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_11.setDecimals(1)
        self.doubleSpinBox_Signal_freq_11.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_11.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_11.setValue(50.000000000000000)

        self.gridLayout_13.addWidget(self.doubleSpinBox_Signal_freq_11, 1, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_11 = QDoubleSpinBox(self.groupBox_12)
        self.doubleSpinBox_SwNoise_amp_11.setObjectName(u"doubleSpinBox_SwNoise_amp_11")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_11.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_11.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_11.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_11.setSingleStep(0.005000000000000)

        self.gridLayout_13.addWidget(self.doubleSpinBox_SwNoise_amp_11, 5, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_11 = QDoubleSpinBox(self.groupBox_12)
        self.doubleSpinBox_WhiteNoise_amp_11.setObjectName(u"doubleSpinBox_WhiteNoise_amp_11")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_11.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_11.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_11.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_11.setSingleStep(0.010000000000000)

        self.gridLayout_13.addWidget(self.doubleSpinBox_WhiteNoise_amp_11, 4, 0, 1, 1)

        self.pushButton_Channel0_en_11 = QPushButton(self.groupBox_12)
        self.pushButton_Channel0_en_11.setObjectName(u"pushButton_Channel0_en_11")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_11.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_11.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_11.setCheckable(True)

        self.gridLayout_13.addWidget(self.pushButton_Channel0_en_11, 8, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_11 = QDoubleSpinBox(self.groupBox_12)
        self.doubleSpinBox_SwNoise_freq_11.setObjectName(u"doubleSpinBox_SwNoise_freq_11")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_11.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_11.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_11.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_11.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_11.setValue(680.000000000000000)

        self.gridLayout_13.addWidget(self.doubleSpinBox_SwNoise_freq_11, 6, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_11 = QDoubleSpinBox(self.groupBox_12)
        self.doubleSpinBox_Signal_amp_11.setObjectName(u"doubleSpinBox_Signal_amp_11")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_11.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_11.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_11.setDecimals(3)
        self.doubleSpinBox_Signal_amp_11.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_11.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_11.setSingleStep(0.050000000000000)

        self.gridLayout_13.addWidget(self.doubleSpinBox_Signal_amp_11, 0, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_11 = QDoubleSpinBox(self.groupBox_12)
        self.doubleSpinBox_Ramp_time_11.setObjectName(u"doubleSpinBox_Ramp_time_11")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_11.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_11.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_11.setDecimals(1)
        self.doubleSpinBox_Ramp_time_11.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_11.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_11.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_11.setValue(5.000000000000000)

        self.gridLayout_13.addWidget(self.doubleSpinBox_Ramp_time_11, 3, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_11 = QDoubleSpinBox(self.groupBox_12)
        self.doubleSpinBox_Signal_phase_11.setObjectName(u"doubleSpinBox_Signal_phase_11")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_11.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_11.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_11.setDecimals(1)
        self.doubleSpinBox_Signal_phase_11.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_11.setValue(0.000000000000000)

        self.gridLayout_13.addWidget(self.doubleSpinBox_Signal_phase_11, 2, 0, 1, 1)

        self.pushButton_Channel0_set_11 = QPushButton(self.groupBox_12)
        self.pushButton_Channel0_set_11.setObjectName(u"pushButton_Channel0_set_11")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_11.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_11.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_11.setCheckable(False)

        self.gridLayout_13.addWidget(self.pushButton_Channel0_set_11, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_12, 1, 3, 1, 1)

        self.groupBox_13 = QGroupBox(self.layoutWidget)
        self.groupBox_13.setObjectName(u"groupBox_13")
        sizePolicy3.setHeightForWidth(self.groupBox_13.sizePolicy().hasHeightForWidth())
        self.groupBox_13.setSizePolicy(sizePolicy3)
        self.gridLayout_14 = QGridLayout(self.groupBox_13)
        self.gridLayout_14.setObjectName(u"gridLayout_14")
        self.gridLayout_14.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Ramp_time_12 = QDoubleSpinBox(self.groupBox_13)
        self.doubleSpinBox_Ramp_time_12.setObjectName(u"doubleSpinBox_Ramp_time_12")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_12.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_12.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_12.setDecimals(1)
        self.doubleSpinBox_Ramp_time_12.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_12.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_12.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_12.setValue(5.000000000000000)

        self.gridLayout_14.addWidget(self.doubleSpinBox_Ramp_time_12, 3, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_12 = QDoubleSpinBox(self.groupBox_13)
        self.doubleSpinBox_Signal_freq_12.setObjectName(u"doubleSpinBox_Signal_freq_12")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_12.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_12.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_12.setDecimals(1)
        self.doubleSpinBox_Signal_freq_12.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_12.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_12.setValue(50.000000000000000)

        self.gridLayout_14.addWidget(self.doubleSpinBox_Signal_freq_12, 1, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_12 = QDoubleSpinBox(self.groupBox_13)
        self.doubleSpinBox_Signal_amp_12.setObjectName(u"doubleSpinBox_Signal_amp_12")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_12.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_12.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_12.setDecimals(3)
        self.doubleSpinBox_Signal_amp_12.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_12.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_12.setSingleStep(0.050000000000000)

        self.gridLayout_14.addWidget(self.doubleSpinBox_Signal_amp_12, 0, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_12 = QDoubleSpinBox(self.groupBox_13)
        self.doubleSpinBox_SwNoise_amp_12.setObjectName(u"doubleSpinBox_SwNoise_amp_12")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_12.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_12.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_12.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_12.setSingleStep(0.005000000000000)

        self.gridLayout_14.addWidget(self.doubleSpinBox_SwNoise_amp_12, 5, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_12 = QDoubleSpinBox(self.groupBox_13)
        self.doubleSpinBox_Signal_phase_12.setObjectName(u"doubleSpinBox_Signal_phase_12")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_12.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_12.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_12.setDecimals(1)
        self.doubleSpinBox_Signal_phase_12.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_12.setValue(0.000000000000000)

        self.gridLayout_14.addWidget(self.doubleSpinBox_Signal_phase_12, 2, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_12 = QDoubleSpinBox(self.groupBox_13)
        self.doubleSpinBox_SwNoise_freq_12.setObjectName(u"doubleSpinBox_SwNoise_freq_12")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_12.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_12.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_12.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_12.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_12.setValue(680.000000000000000)

        self.gridLayout_14.addWidget(self.doubleSpinBox_SwNoise_freq_12, 6, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_12 = QDoubleSpinBox(self.groupBox_13)
        self.doubleSpinBox_WhiteNoise_amp_12.setObjectName(u"doubleSpinBox_WhiteNoise_amp_12")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_12.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_12.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_12.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_12.setSingleStep(0.010000000000000)

        self.gridLayout_14.addWidget(self.doubleSpinBox_WhiteNoise_amp_12, 4, 0, 1, 1)

        self.pushButton_Channel0_en_12 = QPushButton(self.groupBox_13)
        self.pushButton_Channel0_en_12.setObjectName(u"pushButton_Channel0_en_12")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_12.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_12.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_12.setCheckable(True)

        self.gridLayout_14.addWidget(self.pushButton_Channel0_en_12, 8, 0, 1, 1)

        self.pushButton_Channel0_set_12 = QPushButton(self.groupBox_13)
        self.pushButton_Channel0_set_12.setObjectName(u"pushButton_Channel0_set_12")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_12.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_12.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_12.setCheckable(False)

        self.gridLayout_14.addWidget(self.pushButton_Channel0_set_12, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_13, 1, 4, 1, 1)

        self.groupBox_14 = QGroupBox(self.layoutWidget)
        self.groupBox_14.setObjectName(u"groupBox_14")
        sizePolicy3.setHeightForWidth(self.groupBox_14.sizePolicy().hasHeightForWidth())
        self.groupBox_14.setSizePolicy(sizePolicy3)
        self.gridLayout_15 = QGridLayout(self.groupBox_14)
        self.gridLayout_15.setObjectName(u"gridLayout_15")
        self.gridLayout_15.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_SwNoise_freq_13 = QDoubleSpinBox(self.groupBox_14)
        self.doubleSpinBox_SwNoise_freq_13.setObjectName(u"doubleSpinBox_SwNoise_freq_13")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_13.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_13.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_13.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_13.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_13.setValue(680.000000000000000)

        self.gridLayout_15.addWidget(self.doubleSpinBox_SwNoise_freq_13, 6, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_13 = QDoubleSpinBox(self.groupBox_14)
        self.doubleSpinBox_SwNoise_amp_13.setObjectName(u"doubleSpinBox_SwNoise_amp_13")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_13.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_13.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_13.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_13.setSingleStep(0.005000000000000)

        self.gridLayout_15.addWidget(self.doubleSpinBox_SwNoise_amp_13, 5, 0, 1, 1)

        self.pushButton_Channel0_en_13 = QPushButton(self.groupBox_14)
        self.pushButton_Channel0_en_13.setObjectName(u"pushButton_Channel0_en_13")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_13.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_13.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_13.setCheckable(True)

        self.gridLayout_15.addWidget(self.pushButton_Channel0_en_13, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_13 = QDoubleSpinBox(self.groupBox_14)
        self.doubleSpinBox_Signal_freq_13.setObjectName(u"doubleSpinBox_Signal_freq_13")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_13.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_13.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_13.setDecimals(1)
        self.doubleSpinBox_Signal_freq_13.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_13.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_13.setValue(50.000000000000000)

        self.gridLayout_15.addWidget(self.doubleSpinBox_Signal_freq_13, 1, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_13 = QDoubleSpinBox(self.groupBox_14)
        self.doubleSpinBox_Signal_phase_13.setObjectName(u"doubleSpinBox_Signal_phase_13")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_13.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_13.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_13.setDecimals(1)
        self.doubleSpinBox_Signal_phase_13.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_13.setValue(0.000000000000000)

        self.gridLayout_15.addWidget(self.doubleSpinBox_Signal_phase_13, 2, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_13 = QDoubleSpinBox(self.groupBox_14)
        self.doubleSpinBox_Ramp_time_13.setObjectName(u"doubleSpinBox_Ramp_time_13")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_13.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_13.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_13.setDecimals(1)
        self.doubleSpinBox_Ramp_time_13.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_13.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_13.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_13.setValue(5.000000000000000)

        self.gridLayout_15.addWidget(self.doubleSpinBox_Ramp_time_13, 3, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_13 = QDoubleSpinBox(self.groupBox_14)
        self.doubleSpinBox_WhiteNoise_amp_13.setObjectName(u"doubleSpinBox_WhiteNoise_amp_13")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_13.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_13.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_13.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_13.setSingleStep(0.010000000000000)

        self.gridLayout_15.addWidget(self.doubleSpinBox_WhiteNoise_amp_13, 4, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_13 = QDoubleSpinBox(self.groupBox_14)
        self.doubleSpinBox_Signal_amp_13.setObjectName(u"doubleSpinBox_Signal_amp_13")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_13.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_13.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_13.setDecimals(3)
        self.doubleSpinBox_Signal_amp_13.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_13.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_13.setSingleStep(0.050000000000000)

        self.gridLayout_15.addWidget(self.doubleSpinBox_Signal_amp_13, 0, 0, 1, 1)

        self.pushButton_Channel0_set_13 = QPushButton(self.groupBox_14)
        self.pushButton_Channel0_set_13.setObjectName(u"pushButton_Channel0_set_13")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_13.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_13.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_13.setCheckable(False)

        self.gridLayout_15.addWidget(self.pushButton_Channel0_set_13, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_14, 1, 5, 1, 1)

        self.groupBox_15 = QGroupBox(self.layoutWidget)
        self.groupBox_15.setObjectName(u"groupBox_15")
        sizePolicy3.setHeightForWidth(self.groupBox_15.sizePolicy().hasHeightForWidth())
        self.groupBox_15.setSizePolicy(sizePolicy3)
        self.gridLayout_16 = QGridLayout(self.groupBox_15)
        self.gridLayout_16.setObjectName(u"gridLayout_16")
        self.gridLayout_16.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Ramp_time_14 = QDoubleSpinBox(self.groupBox_15)
        self.doubleSpinBox_Ramp_time_14.setObjectName(u"doubleSpinBox_Ramp_time_14")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_14.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_14.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_14.setDecimals(1)
        self.doubleSpinBox_Ramp_time_14.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_14.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_14.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_14.setValue(5.000000000000000)

        self.gridLayout_16.addWidget(self.doubleSpinBox_Ramp_time_14, 3, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_14 = QDoubleSpinBox(self.groupBox_15)
        self.doubleSpinBox_Signal_amp_14.setObjectName(u"doubleSpinBox_Signal_amp_14")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_14.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_14.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_14.setDecimals(3)
        self.doubleSpinBox_Signal_amp_14.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_14.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_14.setSingleStep(0.050000000000000)

        self.gridLayout_16.addWidget(self.doubleSpinBox_Signal_amp_14, 0, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_14 = QDoubleSpinBox(self.groupBox_15)
        self.doubleSpinBox_SwNoise_amp_14.setObjectName(u"doubleSpinBox_SwNoise_amp_14")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_14.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_14.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_14.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_14.setSingleStep(0.005000000000000)

        self.gridLayout_16.addWidget(self.doubleSpinBox_SwNoise_amp_14, 5, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_14 = QDoubleSpinBox(self.groupBox_15)
        self.doubleSpinBox_SwNoise_freq_14.setObjectName(u"doubleSpinBox_SwNoise_freq_14")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_14.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_14.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_14.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_14.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_14.setValue(680.000000000000000)

        self.gridLayout_16.addWidget(self.doubleSpinBox_SwNoise_freq_14, 6, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_14 = QDoubleSpinBox(self.groupBox_15)
        self.doubleSpinBox_Signal_freq_14.setObjectName(u"doubleSpinBox_Signal_freq_14")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_14.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_14.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_14.setDecimals(1)
        self.doubleSpinBox_Signal_freq_14.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_14.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_14.setValue(50.000000000000000)

        self.gridLayout_16.addWidget(self.doubleSpinBox_Signal_freq_14, 1, 0, 1, 1)

        self.pushButton_Channel0_en_14 = QPushButton(self.groupBox_15)
        self.pushButton_Channel0_en_14.setObjectName(u"pushButton_Channel0_en_14")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_14.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_14.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_14.setCheckable(True)

        self.gridLayout_16.addWidget(self.pushButton_Channel0_en_14, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_14 = QDoubleSpinBox(self.groupBox_15)
        self.doubleSpinBox_Signal_phase_14.setObjectName(u"doubleSpinBox_Signal_phase_14")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_14.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_14.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_14.setDecimals(1)
        self.doubleSpinBox_Signal_phase_14.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_14.setValue(0.000000000000000)

        self.gridLayout_16.addWidget(self.doubleSpinBox_Signal_phase_14, 2, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_14 = QDoubleSpinBox(self.groupBox_15)
        self.doubleSpinBox_WhiteNoise_amp_14.setObjectName(u"doubleSpinBox_WhiteNoise_amp_14")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_14.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_14.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_14.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_14.setSingleStep(0.010000000000000)

        self.gridLayout_16.addWidget(self.doubleSpinBox_WhiteNoise_amp_14, 4, 0, 1, 1)

        self.pushButton_Channel0_set_14 = QPushButton(self.groupBox_15)
        self.pushButton_Channel0_set_14.setObjectName(u"pushButton_Channel0_set_14")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_14.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_14.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_14.setCheckable(False)

        self.gridLayout_16.addWidget(self.pushButton_Channel0_set_14, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_15, 1, 6, 1, 1)

        self.groupBox_16 = QGroupBox(self.layoutWidget)
        self.groupBox_16.setObjectName(u"groupBox_16")
        sizePolicy3.setHeightForWidth(self.groupBox_16.sizePolicy().hasHeightForWidth())
        self.groupBox_16.setSizePolicy(sizePolicy3)
        self.gridLayout_17 = QGridLayout(self.groupBox_16)
        self.gridLayout_17.setObjectName(u"gridLayout_17")
        self.gridLayout_17.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_Signal_freq_15 = QDoubleSpinBox(self.groupBox_16)
        self.doubleSpinBox_Signal_freq_15.setObjectName(u"doubleSpinBox_Signal_freq_15")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_15.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_15.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_15.setDecimals(1)
        self.doubleSpinBox_Signal_freq_15.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_15.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_15.setValue(50.000000000000000)

        self.gridLayout_17.addWidget(self.doubleSpinBox_Signal_freq_15, 1, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_15 = QDoubleSpinBox(self.groupBox_16)
        self.doubleSpinBox_Signal_phase_15.setObjectName(u"doubleSpinBox_Signal_phase_15")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_15.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_15.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_15.setDecimals(1)
        self.doubleSpinBox_Signal_phase_15.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_15.setValue(0.000000000000000)

        self.gridLayout_17.addWidget(self.doubleSpinBox_Signal_phase_15, 2, 0, 1, 1)

        self.pushButton_Channel0_en_15 = QPushButton(self.groupBox_16)
        self.pushButton_Channel0_en_15.setObjectName(u"pushButton_Channel0_en_15")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_15.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_15.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_15.setCheckable(True)

        self.gridLayout_17.addWidget(self.pushButton_Channel0_en_15, 8, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_15 = QDoubleSpinBox(self.groupBox_16)
        self.doubleSpinBox_WhiteNoise_amp_15.setObjectName(u"doubleSpinBox_WhiteNoise_amp_15")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_15.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_15.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_15.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_15.setSingleStep(0.010000000000000)

        self.gridLayout_17.addWidget(self.doubleSpinBox_WhiteNoise_amp_15, 4, 0, 1, 1)

        self.doubleSpinBox_SwNoise_freq_15 = QDoubleSpinBox(self.groupBox_16)
        self.doubleSpinBox_SwNoise_freq_15.setObjectName(u"doubleSpinBox_SwNoise_freq_15")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_15.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_15.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_15.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_15.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_15.setValue(680.000000000000000)

        self.gridLayout_17.addWidget(self.doubleSpinBox_SwNoise_freq_15, 6, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_15 = QDoubleSpinBox(self.groupBox_16)
        self.doubleSpinBox_Ramp_time_15.setObjectName(u"doubleSpinBox_Ramp_time_15")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_15.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_15.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_15.setDecimals(1)
        self.doubleSpinBox_Ramp_time_15.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_15.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_15.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_15.setValue(5.000000000000000)

        self.gridLayout_17.addWidget(self.doubleSpinBox_Ramp_time_15, 3, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_15 = QDoubleSpinBox(self.groupBox_16)
        self.doubleSpinBox_SwNoise_amp_15.setObjectName(u"doubleSpinBox_SwNoise_amp_15")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_15.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_15.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_15.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_15.setSingleStep(0.005000000000000)

        self.gridLayout_17.addWidget(self.doubleSpinBox_SwNoise_amp_15, 5, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_15 = QDoubleSpinBox(self.groupBox_16)
        self.doubleSpinBox_Signal_amp_15.setObjectName(u"doubleSpinBox_Signal_amp_15")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_15.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_15.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_15.setDecimals(3)
        self.doubleSpinBox_Signal_amp_15.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_15.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_15.setSingleStep(0.050000000000000)

        self.gridLayout_17.addWidget(self.doubleSpinBox_Signal_amp_15, 0, 0, 1, 1)

        self.pushButton_Channel0_set_15 = QPushButton(self.groupBox_16)
        self.pushButton_Channel0_set_15.setObjectName(u"pushButton_Channel0_set_15")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_15.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_15.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_15.setCheckable(False)

        self.gridLayout_17.addWidget(self.pushButton_Channel0_set_15, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_16, 1, 7, 1, 1)

        self.groupBox_17 = QGroupBox(self.layoutWidget)
        self.groupBox_17.setObjectName(u"groupBox_17")
        sizePolicy3.setHeightForWidth(self.groupBox_17.sizePolicy().hasHeightForWidth())
        self.groupBox_17.setSizePolicy(sizePolicy3)
        self.gridLayout_18 = QGridLayout(self.groupBox_17)
        self.gridLayout_18.setObjectName(u"gridLayout_18")
        self.gridLayout_18.setSizeConstraint(QLayout.SetMaximumSize)
        self.doubleSpinBox_SwNoise_freq_16 = QDoubleSpinBox(self.groupBox_17)
        self.doubleSpinBox_SwNoise_freq_16.setObjectName(u"doubleSpinBox_SwNoise_freq_16")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_freq_16.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_freq_16.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_freq_16.setDecimals(0)
        self.doubleSpinBox_SwNoise_freq_16.setMaximum(1500.000000000000000)
        self.doubleSpinBox_SwNoise_freq_16.setValue(680.000000000000000)

        self.gridLayout_18.addWidget(self.doubleSpinBox_SwNoise_freq_16, 6, 0, 1, 1)

        self.pushButton_Channel0_en_16 = QPushButton(self.groupBox_17)
        self.pushButton_Channel0_en_16.setObjectName(u"pushButton_Channel0_en_16")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_en_16.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_en_16.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_en_16.setCheckable(True)

        self.gridLayout_18.addWidget(self.pushButton_Channel0_en_16, 8, 0, 1, 1)

        self.doubleSpinBox_Signal_phase_16 = QDoubleSpinBox(self.groupBox_17)
        self.doubleSpinBox_Signal_phase_16.setObjectName(u"doubleSpinBox_Signal_phase_16")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_phase_16.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_phase_16.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_phase_16.setDecimals(1)
        self.doubleSpinBox_Signal_phase_16.setMaximum(360.000000000000000)
        self.doubleSpinBox_Signal_phase_16.setValue(0.000000000000000)

        self.gridLayout_18.addWidget(self.doubleSpinBox_Signal_phase_16, 2, 0, 1, 1)

        self.doubleSpinBox_Ramp_time_16 = QDoubleSpinBox(self.groupBox_17)
        self.doubleSpinBox_Ramp_time_16.setObjectName(u"doubleSpinBox_Ramp_time_16")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Ramp_time_16.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Ramp_time_16.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Ramp_time_16.setDecimals(1)
        self.doubleSpinBox_Ramp_time_16.setMinimum(0.100000000000000)
        self.doubleSpinBox_Ramp_time_16.setMaximum(50.000000000000000)
        self.doubleSpinBox_Ramp_time_16.setSingleStep(0.100000000000000)
        self.doubleSpinBox_Ramp_time_16.setValue(5.000000000000000)

        self.gridLayout_18.addWidget(self.doubleSpinBox_Ramp_time_16, 3, 0, 1, 1)

        self.doubleSpinBox_Signal_amp_16 = QDoubleSpinBox(self.groupBox_17)
        self.doubleSpinBox_Signal_amp_16.setObjectName(u"doubleSpinBox_Signal_amp_16")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_amp_16.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_amp_16.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_amp_16.setDecimals(3)
        self.doubleSpinBox_Signal_amp_16.setMinimum(-7.000000000000000)
        self.doubleSpinBox_Signal_amp_16.setMaximum(7.000000000000000)
        self.doubleSpinBox_Signal_amp_16.setSingleStep(0.050000000000000)

        self.gridLayout_18.addWidget(self.doubleSpinBox_Signal_amp_16, 0, 0, 1, 1)

        self.doubleSpinBox_SwNoise_amp_16 = QDoubleSpinBox(self.groupBox_17)
        self.doubleSpinBox_SwNoise_amp_16.setObjectName(u"doubleSpinBox_SwNoise_amp_16")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_SwNoise_amp_16.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_SwNoise_amp_16.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_SwNoise_amp_16.setMaximum(1.000000000000000)
        self.doubleSpinBox_SwNoise_amp_16.setSingleStep(0.005000000000000)

        self.gridLayout_18.addWidget(self.doubleSpinBox_SwNoise_amp_16, 5, 0, 1, 1)

        self.doubleSpinBox_Signal_freq_16 = QDoubleSpinBox(self.groupBox_17)
        self.doubleSpinBox_Signal_freq_16.setObjectName(u"doubleSpinBox_Signal_freq_16")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_Signal_freq_16.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_Signal_freq_16.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_Signal_freq_16.setDecimals(1)
        self.doubleSpinBox_Signal_freq_16.setMinimum(0.000000000000000)
        self.doubleSpinBox_Signal_freq_16.setMaximum(200.000000000000000)
        self.doubleSpinBox_Signal_freq_16.setValue(50.000000000000000)

        self.gridLayout_18.addWidget(self.doubleSpinBox_Signal_freq_16, 1, 0, 1, 1)

        self.doubleSpinBox_WhiteNoise_amp_16 = QDoubleSpinBox(self.groupBox_17)
        self.doubleSpinBox_WhiteNoise_amp_16.setObjectName(u"doubleSpinBox_WhiteNoise_amp_16")
        sizePolicy4.setHeightForWidth(self.doubleSpinBox_WhiteNoise_amp_16.sizePolicy().hasHeightForWidth())
        self.doubleSpinBox_WhiteNoise_amp_16.setSizePolicy(sizePolicy4)
        self.doubleSpinBox_WhiteNoise_amp_16.setMaximum(1.000000000000000)
        self.doubleSpinBox_WhiteNoise_amp_16.setSingleStep(0.010000000000000)

        self.gridLayout_18.addWidget(self.doubleSpinBox_WhiteNoise_amp_16, 4, 0, 1, 1)

        self.pushButton_Channel0_set_16 = QPushButton(self.groupBox_17)
        self.pushButton_Channel0_set_16.setObjectName(u"pushButton_Channel0_set_16")
        sizePolicy4.setHeightForWidth(self.pushButton_Channel0_set_16.sizePolicy().hasHeightForWidth())
        self.pushButton_Channel0_set_16.setSizePolicy(sizePolicy4)
        self.pushButton_Channel0_set_16.setCheckable(False)

        self.gridLayout_18.addWidget(self.pushButton_Channel0_set_16, 7, 0, 1, 1)


        self.gridLayout_3.addWidget(self.groupBox_17, 1, 8, 1, 1)


        self.verticalLayout.addLayout(self.gridLayout_3)

        self.gridLayout_20 = QGridLayout()
        self.gridLayout_20.setObjectName(u"gridLayout_20")
        self.gridLayout_20.setSizeConstraint(QLayout.SetFixedSize)
        self.spinBox_selPlot_3 = QSpinBox(self.layoutWidget)
        self.spinBox_selPlot_3.setObjectName(u"spinBox_selPlot_3")
        self.spinBox_selPlot_3.setEnabled(False)
        sizePolicy4.setHeightForWidth(self.spinBox_selPlot_3.sizePolicy().hasHeightForWidth())
        self.spinBox_selPlot_3.setSizePolicy(sizePolicy4)
        self.spinBox_selPlot_3.setMaximum(15)

        self.gridLayout_20.addWidget(self.spinBox_selPlot_3, 1, 5, 1, 1)

        self.label = QLabel(self.layoutWidget)
        self.label.setObjectName(u"label")

        self.gridLayout_20.addWidget(self.label, 1, 6, 1, 1)

        self.pushButton_EnablePlot = QPushButton(self.layoutWidget)
        self.pushButton_EnablePlot.setObjectName(u"pushButton_EnablePlot")
        sizePolicy4.setHeightForWidth(self.pushButton_EnablePlot.sizePolicy().hasHeightForWidth())
        self.pushButton_EnablePlot.setSizePolicy(sizePolicy4)
        self.pushButton_EnablePlot.setCheckable(True)

        self.gridLayout_20.addWidget(self.pushButton_EnablePlot, 1, 2, 1, 1)

        self.verticalSpacer = QSpacerItem(20, 5, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.gridLayout_20.addItem(self.verticalSpacer, 0, 0, 1, 1)

        self.pushButton_ChannelGlobal_en = QPushButton(self.layoutWidget)
        self.pushButton_ChannelGlobal_en.setObjectName(u"pushButton_ChannelGlobal_en")
        sizePolicy4.setHeightForWidth(self.pushButton_ChannelGlobal_en.sizePolicy().hasHeightForWidth())
        self.pushButton_ChannelGlobal_en.setSizePolicy(sizePolicy4)
        self.pushButton_ChannelGlobal_en.setCheckable(True)

        self.gridLayout_20.addWidget(self.pushButton_ChannelGlobal_en, 1, 0, 1, 1)

        self.spinBox_selPlot_2 = QSpinBox(self.layoutWidget)
        self.spinBox_selPlot_2.setObjectName(u"spinBox_selPlot_2")
        self.spinBox_selPlot_2.setEnabled(False)
        sizePolicy4.setHeightForWidth(self.spinBox_selPlot_2.sizePolicy().hasHeightForWidth())
        self.spinBox_selPlot_2.setSizePolicy(sizePolicy4)
        self.spinBox_selPlot_2.setMaximum(15)

        self.gridLayout_20.addWidget(self.spinBox_selPlot_2, 1, 4, 1, 1)

        self.horizontalSpacer = QSpacerItem(200, 20, QSizePolicy.Fixed, QSizePolicy.Minimum)

        self.gridLayout_20.addItem(self.horizontalSpacer, 1, 1, 1, 1)

        self.spinBox_selPlot_1 = QSpinBox(self.layoutWidget)
        self.spinBox_selPlot_1.setObjectName(u"spinBox_selPlot_1")
        sizePolicy4.setHeightForWidth(self.spinBox_selPlot_1.sizePolicy().hasHeightForWidth())
        self.spinBox_selPlot_1.setSizePolicy(sizePolicy4)
        self.spinBox_selPlot_1.setMaximum(15)

        self.gridLayout_20.addWidget(self.spinBox_selPlot_1, 1, 3, 1, 1)

        self.spinBox_selTrig = QSpinBox(self.layoutWidget)
        self.spinBox_selTrig.setObjectName(u"spinBox_selTrig")
        sizePolicy4.setHeightForWidth(self.spinBox_selTrig.sizePolicy().hasHeightForWidth())
        self.spinBox_selTrig.setSizePolicy(sizePolicy4)
        self.spinBox_selTrig.setMaximum(15)

        self.gridLayout_20.addWidget(self.spinBox_selTrig, 1, 7, 1, 1)


        self.verticalLayout.addLayout(self.gridLayout_20)

        self.groupBox_Plot = QGroupBox(self.layoutWidget)
        self.groupBox_Plot.setObjectName(u"groupBox_Plot")
        sizePolicy2.setHeightForWidth(self.groupBox_Plot.sizePolicy().hasHeightForWidth())
        self.groupBox_Plot.setSizePolicy(sizePolicy2)
        self.groupBox_Plot.setMinimumSize(QSize(0, 150))
        self.groupBox_Plot.setBaseSize(QSize(0, 150))

        self.verticalLayout.addWidget(self.groupBox_Plot)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 984, 21))
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
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"RTBox GUI", None))
        self.action_Exit.setText(QCoreApplication.translate("MainWindow", u"&Exit", None))
        self.action_About.setText(QCoreApplication.translate("MainWindow", u"&About...", None))
        self.action_Settings.setText(QCoreApplication.translate("MainWindow", u"&Settings", None))
#if QT_CONFIG(tooltip)
        self.action_Settings.setToolTip(QCoreApplication.translate("MainWindow", u"Launch Settings Dialog", None))
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        self.action_Settings.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+F", None))
#endif // QT_CONFIG(shortcut)
        self.groupBox.setTitle(QCoreApplication.translate("MainWindow", u"Settings Ch.0 - Ch.7", None))
        self.label_14.setText(QCoreApplication.translate("MainWindow", u"Switching Noise Freq [Hz]", None))
        self.label_9.setText(QCoreApplication.translate("MainWindow", u"Signal RampT [s]", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"Signal Peak [V]", None))
        self.label_13.setText(QCoreApplication.translate("MainWindow", u"Signal Phase [deg]", None))
        self.label_10.setText(QCoreApplication.translate("MainWindow", u"Switching Noise Ampl [V]", None))
        self.label_6.setText(QCoreApplication.translate("MainWindow", u"White Noise Ampl [V]", None))
        self.label_12.setText(QCoreApplication.translate("MainWindow", u"Signal Freq [Hz]", None))
        self.label_15.setText(QCoreApplication.translate("MainWindow", u"Enable Channel", None))
        self.label_21.setText(QCoreApplication.translate("MainWindow", u"Set Channel", None))
        self.groupBox_2.setTitle(QCoreApplication.translate("MainWindow", u"Channel 0", None))
        self.pushButton_Channel0_en.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_3.setTitle(QCoreApplication.translate("MainWindow", u"Channel 1", None))
        self.pushButton_Channel0_en_2.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_2.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_4.setTitle(QCoreApplication.translate("MainWindow", u"Channel 2", None))
        self.pushButton_Channel0_en_3.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_3.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_5.setTitle(QCoreApplication.translate("MainWindow", u"Channel 3", None))
        self.pushButton_Channel0_en_4.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_4.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_6.setTitle(QCoreApplication.translate("MainWindow", u"Channel 4", None))
        self.pushButton_Channel0_en_5.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_5.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_7.setTitle(QCoreApplication.translate("MainWindow", u"Channel 5", None))
        self.pushButton_Channel0_en_6.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_6.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_8.setTitle(QCoreApplication.translate("MainWindow", u"Channel 6", None))
        self.pushButton_Channel0_en_7.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_7.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_9.setTitle(QCoreApplication.translate("MainWindow", u"Channel 7", None))
        self.pushButton_Channel0_en_8.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_8.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_18.setTitle(QCoreApplication.translate("MainWindow", u"Settings Ch.8 - Ch.15", None))
        self.label_16.setText(QCoreApplication.translate("MainWindow", u"Signal Freq [Hz]", None))
        self.label_18.setText(QCoreApplication.translate("MainWindow", u"Switching Noise Ampl [V]", None))
        self.label_20.setText(QCoreApplication.translate("MainWindow", u"Channel Enable", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"Signal Peak [V]", None))
        self.label_11.setText(QCoreApplication.translate("MainWindow", u"Signal RampT [s]", None))
        self.label_7.setText(QCoreApplication.translate("MainWindow", u"White Noise Ampl [V]", None))
        self.label_17.setText(QCoreApplication.translate("MainWindow", u"Signal Phase [deg]", None))
        self.label_19.setText(QCoreApplication.translate("MainWindow", u"Switching Noise Freq [Hz]", None))
        self.label_22.setText(QCoreApplication.translate("MainWindow", u"Set Channel", None))
        self.groupBox_10.setTitle(QCoreApplication.translate("MainWindow", u"Channel 8", None))
        self.pushButton_Channel0_en_9.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_9.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_11.setTitle(QCoreApplication.translate("MainWindow", u"Channel 9", None))
        self.pushButton_Channel0_en_10.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_10.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_12.setTitle(QCoreApplication.translate("MainWindow", u"Channel 10", None))
        self.pushButton_Channel0_en_11.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_11.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_13.setTitle(QCoreApplication.translate("MainWindow", u"Channel 11", None))
        self.pushButton_Channel0_en_12.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_12.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_14.setTitle(QCoreApplication.translate("MainWindow", u"Channel 12", None))
        self.pushButton_Channel0_en_13.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_13.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_15.setTitle(QCoreApplication.translate("MainWindow", u"Channel 13", None))
        self.pushButton_Channel0_en_14.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_14.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_16.setTitle(QCoreApplication.translate("MainWindow", u"Channel 14", None))
        self.pushButton_Channel0_en_15.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_15.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.groupBox_17.setTitle(QCoreApplication.translate("MainWindow", u"Channel 15", None))
        self.pushButton_Channel0_en_16.setText(QCoreApplication.translate("MainWindow", u"Channel Off", None))
        self.pushButton_Channel0_set_16.setText(QCoreApplication.translate("MainWindow", u"Set", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"Channel Trigger:", None))
        self.pushButton_EnablePlot.setText(QCoreApplication.translate("MainWindow", u"Plot Off", None))
        self.pushButton_ChannelGlobal_en.setText(QCoreApplication.translate("MainWindow", u"Channel Global Enable Off", None))
        self.groupBox_Plot.setTitle(QCoreApplication.translate("MainWindow", u"Plot", None))
        self.menu_File.setTitle(QCoreApplication.translate("MainWindow", u"&File", None))
        self.menu_Edit.setTitle(QCoreApplication.translate("MainWindow", u"Options", None))
        self.menu_Help.setTitle(QCoreApplication.translate("MainWindow", u"&Help", None))
        self.toolBar.setWindowTitle(QCoreApplication.translate("MainWindow", u"toolBar", None))
    # retranslateUi

