/*#include "arduino.h"
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
int Arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &serial_portinfo,QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasproductIdentifier()){
            if(serial_port_info.vendorIdentifier() ==arduino_uno_vendor_id && serial_port_info.productIdentifier()== arduino_uno_producy_id)
            { arduino_is_available = true;
                arduino_port_name=serial_port_info.portName();

        }

    }
}
    qDebug ()<<"arduino_port_name is : "<< arduino_port_name;
    if (arduino_id_available)
    { serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite))
        {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort:Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop).
            serial->setFlowControl(QSerialPort::NotFlowControl);
            return 0;
        }
        return 1;
}

    int Arduino::close_arduino()
    {
        if(serial->isOpen()){
                serial->close();
                return 0;
    }
        return 1;
    }
QByteArray Arduino :: read_from_arduino()
{
    if(serial->isReadable()){
        data=serial->readAll();
        return data ;
    }
}
int Arduino ::write_toarduino(QByteArray d)
{
    if(serial->isWritable()){
        serial->write(d);
    }else
        qDebug()<<"couldnt write to serial !";
}}
*/
