#ifndef MPU_6050_H_
#define MPU_6050_H_


#include <Arduino.h>
#include <Adafruit_MPU6050.h>


class Mpu_6050 {
    Adafruit_MPU6050 _mpu;
    mpu6050_accel_range_t _accel_range;
    static Mpu_6050 *instance;
    Mpu_6050(mpu6050_accel_range_t accel_range);
public:
    static Mpu_6050 *getInstance(mpu6050_accel_range_t accel_range);
    void setup();
    void update();
};


#endif // MPU_6050_H_