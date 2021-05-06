////////////////////////////////////////////////////////////////////////////
//
//  This file is part of RTIMULib
//
//  Copyright (c) 2014-2015, richards-tech, LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
//  Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
//  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef _AXISREMASP_H
#define _AXISREMAP_H


#include "RTIMULib.h"

// See datasheet p. 24

#define Z_AX_SHIFT                  4
#define Y_AX_SHIFT                  2
#define X_AX_SHIFT                  0

#define Z_SIGN_SHIFT                0
#define Y_SIGN_SHIFT                1
#define X_SIGN_SHIFT                2

#define AX_POS                      0b0
#define AX_NEG                      0b1

#define AX_X                        0b00
#define AX_Y                        0b01
#define AX_Z                        0b10

#define AXIS_MAP_DEFAULT            0b00100100
#define SIGN_MAP_DEFAULT            0b00000000


class AxisRemap
{

public:
    AxisRemap();
    ~AxisRemap();
    int remap(unsigned char axis_map, unsigned char sign_map);
    void newIMU();

private:
    unsigned char m_slaveAddr;                              // I2C address of BNO055
    RTIMUSettings *m_settings;

    RTIMU *m_imu;
};

#endif // _AxisRemap_H

