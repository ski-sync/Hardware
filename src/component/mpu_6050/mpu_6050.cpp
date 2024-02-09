#include "mpu_6050.h"


Mpu_6050::Mpu_6050(mpu6050_accel_range_t accel_range) 
{
    _mpu = Adafruit_MPU6050();
    _accel_range = accel_range;
}

void Mpu_6050::setup()
{

    while (!_mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        delay(1000);
    }
    Serial.println("MPU6050 Found!");

    Serial.print("Accelerometer range set to: ");
    switch (_mpu.getAccelerometerRange()) {
        case MPU6050_RANGE_2_G:
            Serial.println("+-2G");
            break;
        case MPU6050_RANGE_4_G:
            Serial.println("+-4G");
            break;
        case MPU6050_RANGE_8_G:
            Serial.println("+-8G");
            break;
        case MPU6050_RANGE_16_G:
            Serial.println("+-16G");
            break;
    }
}

void Mpu_6050::update()
{
    sensors_event_t a, g, temp;
    _mpu.getEvent(&a, &g, &temp);

    Serial.print("Acceleration X: ");
    Serial.print(a.acceleration.x);
    Serial.print(", Y: ");
    Serial.print(a.acceleration.y);
    Serial.print(", Z: ");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2");

    Serial.print("Rotation X: ");
    Serial.print(g.gyro.x);
    Serial.print(", Y: ");
    Serial.print(g.gyro.y);
    Serial.print(", Z: ");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");

    Serial.println("");
}