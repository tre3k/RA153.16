//
// Created by kirill on 15.02.19.
//

#ifndef RA153_16_CONTROLLERRA153_16_H
#define RA153_16_CONTROLLERRA153_16_H

#include <cstdint>

#include "SerialPort.h"

namespace CTRL_RA_153_16{
    class ControllerRA153_16 {
    private:
        SP::SerialPort *sp;

    public:
        /* Constructor */
        explicit ControllerRA153_16(SP::SerialPort *sport);
        ~ControllerRA153_16(void);

    public:

        /* struct for send and recv command (please read Documentation)*/
        struct s_command {
            char addr[3];
            char code;
            char data[4];
        };

        /* method for send command */
        void SendCommand(s_command *cmd,char *recv=NULL,size_t recv_size=0);

        /* method for set frequency */
        void setFreq(u_int16_t freq);
    };



}

#endif //RA153_16_CONTROLLERRA153_16_H
