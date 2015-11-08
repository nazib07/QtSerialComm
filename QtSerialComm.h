
#ifndef QtSERIALCOMM_H_
#define QtSERIALCOMM_H_

#include <QObject>
#include <qextserialport.h>

class QextSerialPort;

class QtSerialComm : public QObject
{

Q_OBJECT

QextSerialPort * port;


public:

        QtSerialComm(const char* portName, QObject * parent = 0);
        ~QtSerialComm();

public slots:

        void receive();


public:
        void sendData(const char* , int);
        void configure(BaudRateType, DataBitsType, ParityType, StopBitsType);
        void close();



signals:
        void signalRecievedSerialData(QByteArray qPacket);

};


#endif
