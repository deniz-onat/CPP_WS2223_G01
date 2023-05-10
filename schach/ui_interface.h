/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QFrame *gridFrame;
    QVBoxLayout *verticalLayout;
    QWidget *Addr_Port;
    QHBoxLayout *Addrr_Port;
    QLabel *adrLab;
    QLineEdit *linAdr;
    QLabel *laPort;
    QLineEdit *linPort;
    QWidget *Serv_Clint;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *servButt;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *clintButt;
    QPushButton *Start;
    QPushButton *Stop;
    QPushButton *connButt;
    QPushButton *DiscButt;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->resize(821, 761);
        Interface->setStyleSheet(QString::fromUtf8(""));
        gridFrame = new QFrame(Interface);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(0, 0, 821, 761));
        QPalette palette;
        gridFrame->setPalette(palette);
        gridFrame->setStyleSheet(QString::fromUtf8("QFrame{background-image: url(:/Chess pieces/ChessSet.jpg);}"));
        verticalLayout = new QVBoxLayout(gridFrame);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Addr_Port = new QWidget(gridFrame);
        Addr_Port->setObjectName(QString::fromUtf8("Addr_Port"));
        Addrr_Port = new QHBoxLayout(Addr_Port);
        Addrr_Port->setObjectName(QString::fromUtf8("Addrr_Port"));
        adrLab = new QLabel(Addr_Port);
        adrLab->setObjectName(QString::fromUtf8("adrLab"));
        QPalette palette1;
        QBrush brush(QColor(85, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(165, 167, 169, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        adrLab->setPalette(palette1);

        Addrr_Port->addWidget(adrLab);

        linAdr = new QLineEdit(Addr_Port);
        linAdr->setObjectName(QString::fromUtf8("linAdr"));

        Addrr_Port->addWidget(linAdr);

        laPort = new QLabel(Addr_Port);
        laPort->setObjectName(QString::fromUtf8("laPort"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        laPort->setPalette(palette2);

        Addrr_Port->addWidget(laPort);

        linPort = new QLineEdit(Addr_Port);
        linPort->setObjectName(QString::fromUtf8("linPort"));

        Addrr_Port->addWidget(linPort);

        Addrr_Port->setStretch(0, 1);
        Addrr_Port->setStretch(1, 20);
        Addrr_Port->setStretch(3, 10);

        verticalLayout->addWidget(Addr_Port);

        Serv_Clint = new QWidget(gridFrame);
        Serv_Clint->setObjectName(QString::fromUtf8("Serv_Clint"));
        horizontalLayout_3 = new QHBoxLayout(Serv_Clint);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        servButt = new QRadioButton(Serv_Clint);
        servButt->setObjectName(QString::fromUtf8("servButt"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        servButt->setPalette(palette3);
        servButt->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(servButt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        clintButt = new QRadioButton(Serv_Clint);
        clintButt->setObjectName(QString::fromUtf8("clintButt"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        clintButt->setPalette(palette4);
        clintButt->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(clintButt);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 3);

        verticalLayout->addWidget(Serv_Clint);

        Start = new QPushButton(gridFrame);
        Start->setObjectName(QString::fromUtf8("Start"));
        QPalette palette5;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        Start->setPalette(palette5);
        Start->setAutoFillBackground(false);
        Start->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(0, 0, 0)}"));
        Start->setFlat(false);

        verticalLayout->addWidget(Start);

        Stop = new QPushButton(gridFrame);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        Stop->setPalette(palette6);
        Stop->setAutoFillBackground(false);
        Stop->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(0, 0, 0)}"));
        Stop->setFlat(false);

        verticalLayout->addWidget(Stop);

        connButt = new QPushButton(gridFrame);
        connButt->setObjectName(QString::fromUtf8("connButt"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        connButt->setPalette(palette7);
        connButt->setAutoFillBackground(false);
        connButt->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(0, 0, 0);}"));
        connButt->setFlat(false);

        verticalLayout->addWidget(connButt);

        DiscButt = new QPushButton(gridFrame);
        DiscButt->setObjectName(QString::fromUtf8("DiscButt"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        DiscButt->setPalette(palette8);
        DiscButt->setAutoFillBackground(false);
        DiscButt->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(0, 0, 0);}"));
        DiscButt->setFlat(false);

        verticalLayout->addWidget(DiscButt);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(6, 2);

        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QWidget *Interface)
    {
        Interface->setWindowTitle(QApplication::translate("Interface", "Form", nullptr));
        adrLab->setText(QApplication::translate("Interface", "Address", nullptr));
        laPort->setText(QApplication::translate("Interface", "Port", nullptr));
        servButt->setText(QApplication::translate("Interface", "Server", nullptr));
        clintButt->setText(QApplication::translate("Interface", "Client", nullptr));
        Start->setText(QApplication::translate("Interface", "Initialize", nullptr));
        Stop->setText(QApplication::translate("Interface", "Close", nullptr));
        connButt->setText(QApplication::translate("Interface", "Connect", nullptr));
        DiscButt->setText(QApplication::translate("Interface", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
