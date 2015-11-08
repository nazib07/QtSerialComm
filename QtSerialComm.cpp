#include <QTextStream>
#include <qextserialport.h>
#include "QtSerialComm.h"



QtSerialComm::QtSerialComm(const char* portName, QObject* parent)
             :QObject(parent)
{

    port = new QextSerialPort(portName,QextSerialPort::EventDriven);
    connect(port ,SIGNAL(readyRead()), this, SLOT(receive()));
}

QtSerialComm::~QtSerialComm()
{
if(port != NULL)
    {
        port->close();
    }
}

void QtSerialComm::close()
{
if(port != NULL)
    {
        port->close();
    }
}

void QtSerialComm::configure(BaudRateType baudrate, DataBitsType dataBit, ParityType parity, StopBitsType stopBit)
{



    QTextStream out(stdout);

    port->setBaudRate(baudrate);
    port->setFlowControl(FLOW_OFF);
    port->setParity(parity);
    port->setDataBits(dataBit);
    port->setStopBits(stopBit);

    if(!port->open(QIODevice::ReadWrite))
    {
       out << "warning: device is not turned on" << endl;
       delete port;
       port = NULL;
       return;
    }




}
void QtSerialComm::receive()
{

	QTextStream out(stdout);
        QByteArray byteArray = port->readAll();
	
	out << "data received: ";

        emit signalRecievedSerialData(byteArray);

}


void QtSerialComm::sendData(const char* data , int length)
{
    if(port != NULL)
    {
        port->write(data , length);
    }
}


