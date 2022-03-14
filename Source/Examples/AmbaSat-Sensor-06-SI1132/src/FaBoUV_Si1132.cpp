/**
@file FaBoUV_Si1132.cpp
@brief This is a library for the FaBo UV I2C Brick.

  http://fabo.io/206.html

  Released under APACHE LICENSE, VERSION 2.0

  http://www.apache.org/licenses/

@author FaBo<info@fabo.io>
*/

#include "FaBoUV_Si1132.h"

/**
 @brief Constructor
*/
FaBoUV::FaBoUV(uint8_t addr){
  _i2caddr = addr;
  Wire.begin();
}

/**
 @brief Begin Device
 @retval true normaly done
 @retval false device error
*/
bool FaBoUV::begin()
{
  if(searchDevice()){
    reset();
    configuration();
    return true;
  } else{
    return false;
  }
}

/**
 @brief Search Device
 @retval true device connected
 @retval false device error
*/
bool FaBoUV::searchDevice()
{
  uint8_t device = 0x00;
  readI2c(SI1132_WHO_AM_I_REG, 1, &device);

  if(device == SI1132_DEVICE){
    return true;
  } else{
    return false;
  }
}

/**
 @brief Set Config
*/
void FaBoUV::configuration()
{
  // Reset
  writeI2c(0x22, 0x01);
  delay(100);
  writeI2c(SI1132_UCOEF0_REG, 0x7B);
  writeI2c(SI1132_UCOEF1_REG, 0x6B);
  writeI2c(SI1132_UCOEF2_REG, 0x01);
  writeI2c(SI1132_UCOEF3_REG, 0x00);

  // SET PARAM_WR(Chiplist)
  writeI2c(SI1132_PARAM_WR_REG, SI1132_EN_UV|SI1132_EN_AUX|SI1132_EN_ALS_IR|SI1132_EN_ALS_VIS);
  // COMMAND(Set Chiplist)
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_CHIPLIST_PARAM_OFFSET);

  // Select HW_KEY register
  writeI2c(SI1132_HW_KEY_REG, SI1132_HW_KEY_DEFAULT);

  // Rate setting
  writeI2c(SI1132_MEASRATE0_REG, 0xff);

  // SET PARAM_WR(ALS_ENCODING)
  writeI2c(SI1132_PARAM_WR_REG, SI1132_ALS_VIS_ALIGN | SI1132_ALS_IR_ALIGN);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_ENCODING_PARAM_OFFSET);

  /* Visible */
  // SET ALS_VIS_ADC_COUNTER
  writeI2c(SI1132_PARAM_WR_REG, SI1132_511_ADC_CLOCK);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_VIS_ADC_COUNTER_PARAM_OFFSET);

  // SET ALS_VIS_ADC_GAIN
  writeI2c(SI1132_PARAM_WR_REG, SI1132_1_DIVIDED_ADC_CLOCK);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_VIS_ADC_GAIN_PARAM_OFFSET);

  // SET ALS_VIS_ADC_MISC
  writeI2c(SI1132_PARAM_WR_REG, SI1132_HIGH_SIGNAL_RANGE);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_VIS_ADC_MISC_PARAM_OFFSET);

  /* IR */
  // SET ALS_IR_ADC_COUNTER
  writeI2c(SI1132_PARAM_WR_REG, SI1132_511_ADC_CLOCK);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_IR_ADC_COUNTER_PARAM_OFFSET);

  // SET ALS_IR_ADC_GAIN
  writeI2c(SI1132_PARAM_WR_REG, SI1132_1_DIVIDED_ADC_CLOCK);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_IR_ADC_GAIN_PARAM_OFFSET);

  // SET ALS_IR_ADC_MISC
  writeI2c(SI1132_PARAM_WR_REG, SI1132_HIGH_SIGNAL_RANGE);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_IR_ADC_MISC_PARAM_OFFSET);

  // SET ALS_IR_ADCMUX
  writeI2c(SI1132_PARAM_WR_REG, SI1132_ALS_IR_ADCMUX_SMALLIR);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_ALS_IR_ADCMUX_PARAM_OFFSET);

  // SET AUX_ADCMUX
  //writeI2c(SI1132_PARAM_WR_REG, SI1132_AUX_ADCMUX_TEMPERATURE);
  writeI2c(SI1132_PARAM_WR_REG, SI1132_AUX_ADCMUX_VDD);
  writeI2c(SI1132_COMMAND_REG, SI1132_PARAM_SET|SI1132_AUX_ADCMUX_PARAM_OFFSET);

  // COMMAND
  writeI2c(SI1132_COMMAND_REG, SI1132_COMMAND_ALS_AUTO);
  delay(10);
}

/**
 @brief software reset Si1132
*/
void FaBoUV::reset()
{
  writeI2c(SI1132_COMMAND_REG, SI1132_COMMAND_RESET);
}

/**
 @brief Read UV
 @param [out] uv rawdata (rawdata/100 -> UV INDEX)
*/
uint16_t FaBoUV::readUV()
{
  uint16_t uv_index;
  uint8_t buffer[2];

  readI2c(SI1132_AUX_DATA_REG, 2, buffer);
  uv_index = (((uint16_t)buffer[1])<<8) | (uint16_t)buffer[0];
  uint16_t uv = uv_index/100;
  return uv;
}

/**
 @brief Read IR
 @param [out] IR data (lux)
*/
uint16_t FaBoUV::readIR()
{
  uint16_t ir;
  uint8_t buffer[2];

  readI2c(SI1132_IR_DATA_REG, 2, buffer);
  ir = (((uint16_t)buffer[1])<<8) | (uint16_t)buffer[0];
  ir = ((ir - 250)/2.44) * 14.5;
  return ir;
}


/**
 @brief Read Visible
 @param [out] Visible data (lux)
*/
uint16_t FaBoUV::readVisible()
{
  uint16_t visible;
  uint8_t buffer[2];

  readI2c(SI1132_VISIBLE_DATA_REG, 2, buffer);
  visible = (((uint16_t)buffer[1])<<8) | (uint16_t)buffer[0];
  visible= ((visible -256)/0.282) * 14.5;
  return visible;
}

/**
 @brief Write I2C Data
 @param [in] register_addr Write Register Address
 @param [in] value Write Data
*/
void FaBoUV::writeI2c(uint8_t register_addr, uint8_t value) {
  Wire.beginTransmission(_i2caddr);
  Wire.write(register_addr);
  Wire.write(value);
  Wire.endTransmission();
}

/**
 @brief Read I2C Data
 @param [in] register_addr register address
 @param [in] num Data Length
 @param [out] *buf Read Data
*/
void FaBoUV::readI2c(uint8_t register_addr, int num, uint8_t *buf) {
  Wire.beginTransmission(_i2caddr);
  Wire.write(register_addr);
  Wire.endTransmission();
  Wire.requestFrom(_i2caddr, num);

  int i = 0;
  while (Wire.available())
  {
    buf[i] = Wire.read();
    i++;
  }
}