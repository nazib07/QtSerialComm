# QtSerialComm
Serial Communication in Qt
1. Copy all files to project directory
2. Add the Header files to project
3. copy the following lines and paste to *.pro file


win32:LIBS += $$_PRO_FILE_PWD_/libqextserialport1.a
unix:DEFINES   = _TTY_POSIX_
win32:DEFINES  = _TTY_WIN_

4. Copy the following lines to project constructor

    m_pSerialComm = new QtSerialComm("COM1");
    m_pSerialComm ->configure(BAUD9600 , DATA_8 , PAR_NONE , STOP_1);
    connect(listener, SIGNAL(signalRecievedSerialData(QByteArray)), this, SLOT(OnDataReceived(QByteArray)));

5. Enjoy the Serial Communication from COM1 port at Baudrate 9600 at Data Bits/sec 8 with parity none and one stop bit.

N.B. It is possible to change the parameters of functions.

