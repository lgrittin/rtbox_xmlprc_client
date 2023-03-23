# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'settings.ui'
##
## Created by: Qt User Interface Compiler version 6.4.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QDialog, QGridLayout, QLabel,
    QLineEdit, QPushButton, QSizePolicy, QSpacerItem,
    QWidget)

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(699, 230)
        self.layoutWidget = QWidget(Dialog)
        self.layoutWidget.setObjectName(u"layoutWidget")
        self.layoutWidget.setGeometry(QRect(13, 12, 681, 211))
        self.gridLayout_3 = QGridLayout(self.layoutWidget)
        self.gridLayout_3.setObjectName(u"gridLayout_3")
        self.gridLayout_3.setContentsMargins(0, 0, 0, 0)
        self.gridLayout = QGridLayout()
        self.gridLayout.setObjectName(u"gridLayout")
        self.label_Ipv4Result = QLabel(self.layoutWidget)
        self.label_Ipv4Result.setObjectName(u"label_Ipv4Result")

        self.gridLayout.addWidget(self.label_Ipv4Result, 1, 1, 1, 1)

        self.label_DataCaptureBlocks = QLabel(self.layoutWidget)
        self.label_DataCaptureBlocks.setObjectName(u"label_DataCaptureBlocks")

        self.gridLayout.addWidget(self.label_DataCaptureBlocks, 5, 0, 1, 1)

        self.label_Status = QLabel(self.layoutWidget)
        self.label_Status.setObjectName(u"label_Status")

        self.gridLayout.addWidget(self.label_Status, 2, 0, 1, 1)

        self.label_MacAddress = QLabel(self.layoutWidget)
        self.label_MacAddress.setObjectName(u"label_MacAddress")

        self.gridLayout.addWidget(self.label_MacAddress, 0, 0, 1, 1)

        self.lineEdit_DesignFilePath = QLineEdit(self.layoutWidget)
        self.lineEdit_DesignFilePath.setObjectName(u"lineEdit_DesignFilePath")

        self.gridLayout.addWidget(self.lineEdit_DesignFilePath, 6, 1, 1, 1)

        self.label_DeviceStatus = QLabel(self.layoutWidget)
        self.label_DeviceStatus.setObjectName(u"label_DeviceStatus")

        self.gridLayout.addWidget(self.label_DeviceStatus, 3, 0, 1, 1)

        self.lineEdit_MacResult = QLineEdit(self.layoutWidget)
        self.lineEdit_MacResult.setObjectName(u"lineEdit_MacResult")

        self.gridLayout.addWidget(self.lineEdit_MacResult, 0, 1, 1, 1)

        self.label_NumProgrValueBlocks = QLabel(self.layoutWidget)
        self.label_NumProgrValueBlocks.setObjectName(u"label_NumProgrValueBlocks")

        self.gridLayout.addWidget(self.label_NumProgrValueBlocks, 4, 0, 1, 1)

        self.label_StatusResult = QLabel(self.layoutWidget)
        self.label_StatusResult.setObjectName(u"label_StatusResult")

        self.gridLayout.addWidget(self.label_StatusResult, 2, 1, 1, 1)

        self.label_DeviceStatusResult = QLabel(self.layoutWidget)
        self.label_DeviceStatusResult.setObjectName(u"label_DeviceStatusResult")

        self.gridLayout.addWidget(self.label_DeviceStatusResult, 3, 1, 1, 1)

        self.label_DesignFilePath = QLabel(self.layoutWidget)
        self.label_DesignFilePath.setObjectName(u"label_DesignFilePath")

        self.gridLayout.addWidget(self.label_DesignFilePath, 6, 0, 1, 1)

        self.label_Ipv4 = QLabel(self.layoutWidget)
        self.label_Ipv4.setObjectName(u"label_Ipv4")

        self.gridLayout.addWidget(self.label_Ipv4, 1, 0, 1, 1)

        self.pushButton_BrowseDesignFilePath = QPushButton(self.layoutWidget)
        self.pushButton_BrowseDesignFilePath.setObjectName(u"pushButton_BrowseDesignFilePath")

        self.gridLayout.addWidget(self.pushButton_BrowseDesignFilePath, 6, 2, 1, 1)

        self.label_NumProgrValueBlocksResult = QLabel(self.layoutWidget)
        self.label_NumProgrValueBlocksResult.setObjectName(u"label_NumProgrValueBlocksResult")

        self.gridLayout.addWidget(self.label_NumProgrValueBlocksResult, 4, 1, 1, 1)

        self.label_DataCaptureBlocksResult = QLabel(self.layoutWidget)
        self.label_DataCaptureBlocksResult.setObjectName(u"label_DataCaptureBlocksResult")

        self.gridLayout.addWidget(self.label_DataCaptureBlocksResult, 5, 1, 1, 1)


        self.gridLayout_3.addLayout(self.gridLayout, 0, 0, 1, 1)

        self.gridLayout_2 = QGridLayout()
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.pushButton_Find = QPushButton(self.layoutWidget)
        self.pushButton_Find.setObjectName(u"pushButton_Find")

        self.gridLayout_2.addWidget(self.pushButton_Find, 0, 0, 1, 1)

        self.pushButton_Connect = QPushButton(self.layoutWidget)
        self.pushButton_Connect.setObjectName(u"pushButton_Connect")

        self.gridLayout_2.addWidget(self.pushButton_Connect, 1, 0, 1, 1)

        self.pushButton_LoadDesign = QPushButton(self.layoutWidget)
        self.pushButton_LoadDesign.setObjectName(u"pushButton_LoadDesign")

        self.gridLayout_2.addWidget(self.pushButton_LoadDesign, 2, 0, 1, 1)

        self.pushButton_Stop = QPushButton(self.layoutWidget)
        self.pushButton_Stop.setObjectName(u"pushButton_Stop")

        self.gridLayout_2.addWidget(self.pushButton_Stop, 4, 0, 1, 1)

        self.verticalSpacer = QSpacerItem(20, 20, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_2.addItem(self.verticalSpacer, 5, 0, 1, 1)

        self.pushButton_Cancel = QPushButton(self.layoutWidget)
        self.pushButton_Cancel.setObjectName(u"pushButton_Cancel")

        self.gridLayout_2.addWidget(self.pushButton_Cancel, 6, 0, 1, 1)

        self.pushButton_Start = QPushButton(self.layoutWidget)
        self.pushButton_Start.setObjectName(u"pushButton_Start")

        self.gridLayout_2.addWidget(self.pushButton_Start, 3, 0, 1, 1)


        self.gridLayout_3.addLayout(self.gridLayout_2, 0, 2, 1, 1)

        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Fixed, QSizePolicy.Minimum)

        self.gridLayout_3.addItem(self.horizontalSpacer, 0, 1, 1, 1)

        QWidget.setTabOrder(self.pushButton_Find, self.pushButton_Cancel)

        self.retranslateUi(Dialog)
        self.pushButton_Cancel.clicked.connect(Dialog.reject)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Find and Replace", None))
        self.label_Ipv4Result.setText(QCoreApplication.translate("Dialog", u"000.000.000.000", None))
        self.label_DataCaptureBlocks.setText(QCoreApplication.translate("Dialog", u"Number of DataCaptureBlocks:", None))
        self.label_Status.setText(QCoreApplication.translate("Dialog", u"Connection Status:", None))
        self.label_MacAddress.setText(QCoreApplication.translate("Dialog", u"MAC:", None))
        self.label_DeviceStatus.setText(QCoreApplication.translate("Dialog", u"Device Status:", None))
        self.label_NumProgrValueBlocks.setText(QCoreApplication.translate("Dialog", u"Number of ProgrammableValueBlocks:", None))
        self.label_StatusResult.setText(QCoreApplication.translate("Dialog", u"Not Connected", None))
        self.label_DeviceStatusResult.setText(QCoreApplication.translate("Dialog", u"Not Running", None))
        self.label_DesignFilePath.setText(QCoreApplication.translate("Dialog", u"Design File Path:", None))
        self.label_Ipv4.setText(QCoreApplication.translate("Dialog", u"IP v4:", None))
        self.pushButton_BrowseDesignFilePath.setText(QCoreApplication.translate("Dialog", u"Browse", None))
        self.label_NumProgrValueBlocksResult.setText(QCoreApplication.translate("Dialog", u"0", None))
        self.label_DataCaptureBlocksResult.setText(QCoreApplication.translate("Dialog", u"0", None))
        self.pushButton_Find.setText(QCoreApplication.translate("Dialog", u"&Find", None))
        self.pushButton_Connect.setText(QCoreApplication.translate("Dialog", u"Connect", None))
        self.pushButton_LoadDesign.setText(QCoreApplication.translate("Dialog", u"Load", None))
        self.pushButton_Stop.setText(QCoreApplication.translate("Dialog", u"Stop", None))
        self.pushButton_Cancel.setText(QCoreApplication.translate("Dialog", u"&Cancel", None))
        self.pushButton_Start.setText(QCoreApplication.translate("Dialog", u"Start", None))
    # retranslateUi

