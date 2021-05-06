
#include "AxisRemap.h"


AxisRemap::AxisRemap()
{
    m_imu = NULL;
    m_settings = new RTIMUSettings();  // just use default name (RTIMULib.ini) for settings file
}

AxisRemap::~AxisRemap()
{
    if (m_imu != NULL)
        delete m_imu;

    m_imu = NULL;

    delete m_settings;
}

/**
 * Seems unnecessary for changing settings.
 */
void AxisRemap::newIMU()
{
    if (m_imu != NULL) {
        delete m_imu;
        m_imu = NULL;
    }

    m_imu = RTIMU::createIMU(m_settings);

    if (m_imu == NULL)
        return;

    //  set up IMU
    m_imu->IMUInit();

}

int AxisRemap::remap(unsigned char axis_map, unsigned char sign_map)
{
    m_slaveAddr = m_settings->m_I2CSlaveAddress;

    if (!m_settings->HALWrite(m_slaveAddr, BNO055_AXIS_MAP_CONFIG, axis_map,
                                "Failed remap BNO055 axes"))
        return 1;


    if (!m_settings->HALWrite(m_slaveAddr, BNO055_AXIS_MAP_SIGN, sign_map,
                                "Failed to remap BNO055 axes signs"))
        return 1;

    return 0;
}

