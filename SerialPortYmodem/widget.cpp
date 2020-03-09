#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QSerialPortInfo>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    serialPort(new QSerialPort),
    ymodemFileTransmit(new YmodemFileTransmit),
    ymodemFileReceive(new YmodemFileReceive)
{
    transmitButtonStatus = false;
    receiveButtonStatus  = false;

    ui->setupUi(this);

    QSerialPortInfo serialPortInfo;

    foreach(serialPortInfo, QSerialPortInfo::availablePorts())
    {
        ui->comPort->addItem(serialPortInfo.portName());
    }

    serialPort->setPortName("COM1");
    serialPort->setBaudRate(115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    connect(ymodemFileTransmit, SIGNAL(transmitProgress(int)), this, SLOT(transmitProgress(int)));
    connect(ymodemFileReceive, SIGNAL(receiveProgress(int)), this, SLOT(receiveProgress(int)));
    connect(ymodemFileTransmit, SIGNAL(transmitStatus(YmodemFileTransmit::Status)), this, SLOT(transmitStatus(YmodemFileTransmit::Status)));
    connect(ymodemFileReceive, SIGNAL(receiveStatus(YmodemFileReceive::Status)), this, SLOT(receiveStatus(YmodemFileReceive::Status)));


    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/image/rak600_400.png")));
    pal.setColor(QPalette::WindowText, Qt::white);
    setPalette(pal);

    QPalette pal2 = this->palette();
    pal2.setColor(QPalette::WindowText, Qt::white);
    ui->groupBox->setPalette(pal2);
    ui->groupBox_2->setPalette(pal2);

    ui->groupBox->setStyleSheet("QGroupBox{border:none}");

    ui->label_rak->setOpenExternalLinks(true);
    ui->label_rak->setText(tr("<a href=\"https://www.rakwireless.com/en-int/\">https://www.rakwireless.com/en-int/"));


    setWindowTitle(tr("RAK Ymodem V1.0"));


}

Widget::~Widget()
{
    delete ui;
    delete serialPort;
    delete ymodemFileTransmit;
    delete ymodemFileReceive;
}

void Widget::on_comButton_clicked()
{
    static bool button_status = false;

    if(button_status == false)
    {
        serialPort->setPortName(ui->comPort->currentText());
        serialPort->setBaudRate(ui->comBaudRate->currentText().toInt());

        if(serialPort->open(QSerialPort::ReadWrite) == true)
        {
            button_status = true;

            ui->comPort->setDisabled(true);
            ui->comBaudRate->setDisabled(true);
            ui->comButton->setText(u8"Close");

            ui->transmitBrowse->setEnabled(true);
//            ui->receiveBrowse->setEnabled(true);

            if(ui->transmitPath->text().isEmpty() != true)
            {
                ui->transmitButton->setEnabled(true);
            }

//            if(ui->receivePath->text().isEmpty() != true)
//            {
//               ui->receiveButton->setEnabled(true);
//            }
        }
        else
        {
            QMessageBox::warning(this, u8"Serial port failed to open", u8"Please check if the serial port is occupied！", u8"closed");
        }
    }
    else
    {
        button_status = false;

        serialPort->close();

        ui->comPort->setEnabled(true);
        ui->comBaudRate->setEnabled(true);
        ui->comButton->setText(u8"Open");

        ui->transmitBrowse->setDisabled(true);
        ui->transmitButton->setDisabled(true);

//        ui->receiveBrowse->setDisabled(true);
//        ui->receiveButton->setDisabled(true);
    }
}

void Widget::on_transmitBrowse_clicked()
{
    ui->transmitPath->setText(QFileDialog::getOpenFileName(this, u8"open file", ".", u8"All file (*.bin)"));

    if(ui->transmitPath->text().isEmpty() != true)
    {
        ui->transmitButton->setEnabled(true);
    }
    else
    {
        ui->transmitButton->setDisabled(true);
    }
}

void Widget::on_receiveBrowse_clicked()
{
//    ui->receivePath->setText(QFileDialog::getExistingDirectory(this, u8"Select directory", ".", QFileDialog::ShowDirsOnly));

//    if(ui->receivePath->text().isEmpty() != true)
//    {
//        ui->receiveButton->setEnabled(true);
//    }
//    else
//    {
//        ui->receiveButton->setDisabled(true);
//    }
}

void Widget::on_transmitButton_clicked()
{
    if(transmitButtonStatus == false)
    {
        serialPort->close();

        ymodemFileTransmit->setFileName(ui->transmitPath->text());
        ymodemFileTransmit->setPortName(ui->comPort->currentText());
        ymodemFileTransmit->setPortBaudRate(ui->comBaudRate->currentText().toInt());

        if(ymodemFileTransmit->startTransmit() == true)
        {
            qDebug()<<"StartTransmit"<<endl;
            transmitButtonStatus = true;

            ui->comButton->setDisabled(true);

//            ui->receiveBrowse->setDisabled(true);
//            ui->receiveButton->setDisabled(true);

            ui->transmitBrowse->setDisabled(true);
            ui->transmitButton->setText(u8"cancel");
            ui->transmitProgress->setValue(0);
        }
        else
        {
            QMessageBox::warning(this, u8"fail", u8"File sending failed！", u8"closed");
        }
    }
    else
    {
        ymodemFileTransmit->stopTransmit();
    }
}

void Widget::on_receiveButton_clicked()
{
    if(receiveButtonStatus == false)
    {
        serialPort->close();

//       ymodemFileReceive->setFilePath(ui->receivePath->text());
        ymodemFileReceive->setPortName(ui->comPort->currentText());
        ymodemFileReceive->setPortBaudRate(ui->comBaudRate->currentText().toInt());

        if(ymodemFileReceive->startReceive() == true)
        {
            receiveButtonStatus = true;

            ui->comButton->setDisabled(true);

            ui->transmitBrowse->setDisabled(true);
            ui->transmitButton->setDisabled(true);

//            ui->receiveBrowse->setDisabled(true);
//            ui->receiveButton->setText(u8"取消");
//            ui->receiveProgress->setValue(0);
        }
        else
        {
            QMessageBox::warning(this, u8"failure", u8"File reception failed！", u8"closed");
        }
    }
    else
    {
        ymodemFileReceive->stopReceive();
    }
}

void Widget::transmitProgress(int progress)
{
    ui->transmitProgress->setValue(progress);
}

void Widget::receiveProgress(int progress)
{
////    ui->receiveProgress->setValue(progress);
}

void Widget::transmitStatus(Ymodem::Status status)
{
    switch(status)
    {
        case YmodemFileTransmit::StatusEstablish:
        {
            break;
        }

        case YmodemFileTransmit::StatusTransmit:
        {
            break;
        }

        case YmodemFileTransmit::StatusFinish:
        {
            transmitButtonStatus = false;

            ui->comButton->setEnabled(true);

//            ui->receiveBrowse->setEnabled(true);

//           if(ui->receivePath->text().isEmpty() != true)
            {
//                ui->receiveButton->setEnabled(true);
            }

            ui->transmitBrowse->setEnabled(true);
            ui->transmitButton->setText(u8"transmit");

            QMessageBox::warning(this, u8"success", u8"File sent successfully！", u8"closed");

            break;
        }

        case YmodemFileTransmit::StatusAbort:
        {
            transmitButtonStatus = false;

            ui->comButton->setEnabled(true);

//           ui->receiveBrowse->setEnabled(true);

//            if(ui->receivePath->text().isEmpty() != true)
            {
//                ui->receiveButton->setEnabled(true);
            }

            ui->transmitBrowse->setEnabled(true);
            ui->transmitButton->setText(u8"transmit");

            QMessageBox::warning(this, u8"failure", u8"File sending failed！", u8"closed");

            break;
        }

        case YmodemFileTransmit::StatusTimeout:
        {
            transmitButtonStatus = false;

            ui->comButton->setEnabled(true);

//            ui->receiveBrowse->setEnabled(true);

//            if(ui->receivePath->text().isEmpty() != true)
//            {
//                ui->receiveButton->setEnabled(true);
//            }

            ui->transmitBrowse->setEnabled(true);
            ui->transmitButton->setText(u8"transmit");
            QMessageBox::warning(this, u8"failure", u8"File sending failed！", u8"closed");

            break;
        }

        default:
        {
            transmitButtonStatus = false;

            ui->comButton->setEnabled(true);

//            ui->receiveBrowse->setEnabled(true);

//            if(ui->receivePath->text().isEmpty() != true)
//            {
//                ui->receiveButton->setEnabled(true);
//            }

            ui->transmitBrowse->setEnabled(true);
            ui->transmitButton->setText(u8"transmit");
            QMessageBox::warning(this, u8"failure", u8"File sending failed！", u8"closed");
        }
    }
}

void Widget::receiveStatus(YmodemFileReceive::Status status)
{
    switch(status)
    {
        case YmodemFileReceive::StatusEstablish:
        {
            break;
        }

        case YmodemFileReceive::StatusTransmit:
        {
            break;
        }

        case YmodemFileReceive::StatusFinish:
        {
            receiveButtonStatus = false;

            ui->comButton->setEnabled(true);

            ui->transmitBrowse->setEnabled(true);

            if(ui->transmitPath->text().isEmpty() != true)
            {
                ui->transmitButton->setEnabled(true);
            }

//           ui->receiveBrowse->setEnabled(true);
//           ui->receiveButton->setText(u8"接收");

            QMessageBox::warning(this, u8"成功", u8"文件接收成功！", u8"关闭");

            break;
        }

        case YmodemFileReceive::StatusAbort:
        {
            receiveButtonStatus = false;

            ui->comButton->setEnabled(true);

            ui->transmitBrowse->setEnabled(true);

            if(ui->transmitPath->text().isEmpty() != true)
            {
                ui->transmitButton->setEnabled(true);
            }

//            ui->receiveBrowse->setEnabled(true);
//            ui->receiveButton->setText(u8"接收");

            QMessageBox::warning(this, u8"失败", u8"文件接收失败！", u8"关闭");

            break;
        }

        case YmodemFileReceive::StatusTimeout:
        {
            receiveButtonStatus = false;

            ui->comButton->setEnabled(true);

            ui->transmitBrowse->setEnabled(true);

            if(ui->transmitPath->text().isEmpty() != true)
            {
                ui->transmitButton->setEnabled(true);
            }

//            ui->receiveBrowse->setEnabled(true);
//            ui->receiveButton->setText(u8"接收");

            QMessageBox::warning(this, u8"失败", u8"文件接收失败！", u8"关闭");

            break;
        }

        default:
        {
            receiveButtonStatus = false;

            ui->comButton->setEnabled(true);

            ui->transmitBrowse->setEnabled(true);

            if(ui->transmitPath->text().isEmpty() != true)
            {
                ui->transmitButton->setEnabled(true);
            }

//            ui->receiveBrowse->setEnabled(true);
//            ui->receiveButton->setText(u8"接收");

            QMessageBox::warning(this, u8"失败", u8"文件接收失败！", u8"关闭");
        }
    }
}


