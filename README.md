# sal-stack-lwip-ublox-odin-w2
This module contains the lwIP stack. This version has been slightly modified to suit the ODIN-W2 network drivers.

The file async_socket.c implements the lwIP socket abstraction layer and has been adapted to the [socket abstraction layer of the ARM mbed yotta module](https://github.com/ARMmbed/sal). 

The default configuration can be overridden in lwipopts_conf.h and adaptations can be done in the [adaptation layer module](https://github.com/u-blox/ublox-odin-w2-lwip-adapt). The memory pools for lwIP lives in lwippools.h.
