/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *transmitPath;
    QPushButton *transmitBrowse;
    QPushButton *transmitButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QProgressBar *transmitProgress;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comPort;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *comBaudRate;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *comButton;
    QLabel *label_rak;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(600, 400);
        Widget->setMinimumSize(QSize(600, 400));
        Widget->setMaximumSize(QSize(600, 400));
        Widget->setStyleSheet(QStringLiteral(""));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 150, 511, 181));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        transmitPath = new QLineEdit(groupBox_2);
        transmitPath->setObjectName(QStringLiteral("transmitPath"));
        transmitPath->setReadOnly(true);

        horizontalLayout_2->addWidget(transmitPath);

        transmitBrowse = new QPushButton(groupBox_2);
        transmitBrowse->setObjectName(QStringLiteral("transmitBrowse"));
        transmitBrowse->setEnabled(false);

        horizontalLayout_2->addWidget(transmitBrowse);

        transmitButton = new QPushButton(groupBox_2);
        transmitButton->setObjectName(QStringLiteral("transmitButton"));
        transmitButton->setEnabled(false);

        horizontalLayout_2->addWidget(transmitButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        transmitProgress = new QProgressBar(groupBox_2);
        transmitProgress->setObjectName(QStringLiteral("transmitProgress"));
        transmitProgress->setValue(0);

        horizontalLayout_3->addWidget(transmitProgress);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 40, 511, 101));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFont(font);
        groupBox->setMouseTracking(false);
        groupBox->setTabletTracking(false);
        groupBox->setContextMenuPolicy(Qt::ActionsContextMenu);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comPort = new QComboBox(groupBox);
        comPort->setObjectName(QStringLiteral("comPort"));
        comPort->setMaxVisibleItems(12);

        horizontalLayout->addWidget(comPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comBaudRate = new QComboBox(groupBox);
        comBaudRate->setObjectName(QStringLiteral("comBaudRate"));
        comBaudRate->setMaxVisibleItems(12);

        horizontalLayout->addWidget(comBaudRate);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        comButton = new QPushButton(groupBox);
        comButton->setObjectName(QStringLiteral("comButton"));

        horizontalLayout->addWidget(comButton);

        label_rak = new QLabel(Widget);
        label_rak->setObjectName(QStringLiteral("label_rak"));
        label_rak->setGeometry(QRect(290, 350, 271, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Andalus"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_rak->setFont(font1);

        retranslateUi(Widget);

        comBaudRate->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "RAK_Ymodem", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Widget", "File transmit", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">File path</span></p></body></html>", Q_NULLPTR));
        transmitBrowse->setText(QApplication::translate("Widget", "Browse...", Q_NULLPTR));
        transmitButton->setText(QApplication::translate("Widget", "Transmit", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">Transfer progress:</span></p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "Serial configuration", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#ffffff;\">Port:</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">Baudrate:</span></p></body></html>", Q_NULLPTR));
        comBaudRate->clear();
        comBaudRate->insertItems(0, QStringList()
         << QApplication::translate("Widget", "921600", Q_NULLPTR)
         << QApplication::translate("Widget", "460800", Q_NULLPTR)
         << QApplication::translate("Widget", "230400", Q_NULLPTR)
         << QApplication::translate("Widget", "115200", Q_NULLPTR)
         << QApplication::translate("Widget", "57600", Q_NULLPTR)
         << QApplication::translate("Widget", "38400", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "4800", Q_NULLPTR)
         << QApplication::translate("Widget", "2400", Q_NULLPTR)
         << QApplication::translate("Widget", "1200", Q_NULLPTR)
        );
        comBaudRate->setCurrentText(QApplication::translate("Widget", "115200", Q_NULLPTR));
        comButton->setText(QApplication::translate("Widget", "Open", Q_NULLPTR));
        label_rak->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
