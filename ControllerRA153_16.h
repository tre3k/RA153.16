//
// Created by kirill on 15.02.19.
//

#ifndef RA153_16_CONTROLLERRA153_16_H
#define RA153_16_CONTROLLERRA153_16_H

#include <cstdint>

#include "SerialPort.h"

namespace CTRL_RA_153_16{

    class ControllerRA153_16 {
    public:
        explicit ControllerRA153_16(void);
        ~ControllerRA153_16(void);

        /* struct for send and recv command (please read Documentation)*/
        struct s_command {
            char addr[3];
            char code;
            char data[4];
        };
    };

    typedef ControllerRA153_16::s_command command;

}

#endif //RA153_16_CONTROLLERRA153_16_H
