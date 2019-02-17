//
// Created by kirill on 15.02.19.
//

#include "SerialPort.h"

using namespace SP;

SerialPort::SerialPort(const char *path) {
    sp = new boost::asio::serial_port(ios,path);
    sp->set_option(boost::asio::serial_port::baud_rate(baud_rate));
}

SerialPort::~SerialPort() {
    delete sp;
}

/* method for readwrite to controller */
void SerialPort::readwrite(char *req, char *res, size_t *size_req, size_t *size_res){
    // request, return the number of write bytes
    if(*size_req!=0) *size_req = sp->write_some(boost::asio::buffer(req, *size_req));
    // responsabal, return the number of read bytes
    if(*size_res!=0) *size_res = sp->read_some(boost::asio::buffer(res, *size_res));
}

/* methods for set and get private baud_rate */
void SerialPort::setBaudRate(int br) {
    baud_rate = br;
    sp->set_option(boost::asio::serial_port::baud_rate(baud_rate));
}

int SerialPort::getBaudRate() {
    return baud_rate;
}

/* method for close port */
void SerialPort::Close(){
    sp->close();
}
