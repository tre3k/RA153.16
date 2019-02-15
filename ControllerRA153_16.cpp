//
// Created by kirill on 15.02.19.
//

#include "ControllerRA153_16.h"

using namespace CTRL_RA_153_16;

ControllerRA153_16::ControllerRA153_16(SP::SerialPort *sport){
    sp = sport;
};

ControllerRA153_16::~ControllerRA153_16() {

}

void ControllerRA153_16::SendCommand(CTRL_RA_153_16::ControllerRA153_16::s_command *cmd, char *recv, size_t recv_size) {
    size_t send_size = 8;
    sp->readwrite((char *)cmd, recv,&send_size, &recv_size);
}