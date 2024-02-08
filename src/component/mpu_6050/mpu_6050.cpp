#include "mpu_6050.h"


Mpu_6050::Mpu_6050(mpu6050_accel_range_t accel_range) 
{
    _mpu = Adafruit_MPU6050();
    _accel_range = accel_range;
}

void Mpu_6050::setup()
{

    while (!_mpu.begin()) {
        Serial1.println("Failed to find MPU6050 chip");
        delay(1000);
    }
    Serial1.println("MPU6050 Found!");

    Serial1.print("Accelerometer range set to: ");
    switch (_mpu.getAccelerometerRange()) {
        case MPU6050_RANGE_2_G:
            Serial1.println("+-2G");
            break;
        case MPU6050_RANGE_4_G:
            Serial1.println("+-4G");
            break;
        case MPU6050_RANGE_8_G:
            Serial1.println("+-8G");
            break;
        case MPU6050_RANGE_16_G:
            Serial1.println("+-16G");
            break;
    }
}

void Mpu_6050::update()
{
    sensors_event_t a, g, temp;
    _mpu.getEvent(&a, &g, &temp);

    Serial1.print("Acceleration X: ");
    Serial1.print(a.acceleration.x);
    Serial1.print(", Y: ");
    Serial1.print(a.acceleration.y);
    Serial1.print(", Z: ");
    Serial1.print(a.acceleration.z);
    Serial1.println(" m/s^2");

    Serial1.print("Rotation X: ");
    Serial1.print(g.gyro.x);
    Serial1.print(", Y: ");
    Serial1.print(g.gyro.y);
    Serial1.print(", Z: ");
    Serial1.print(g.gyro.z);
    Serial1.println(" rad/s");

    Serial1.println("");
}