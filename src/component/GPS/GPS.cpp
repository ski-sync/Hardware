#include "GPS.h"

uint32_t timersss = millis();

GPS::GPS()
{
  GPSModule = Adafruit_GPS(&Serial2);
}

GPS *GPS::getInstance()
{
  if (!instance)
  {
    instance = new GPS();
  }
  return instance;
}

void GPS::setup()
{
  GPSModule.begin(9600); // Set the baud rate of GPS module

  // GPSModule.sendCommand(PMTK_SET_NMEA_OUTPUT_OFF);
  while (GPSModule.available())
  {
    Serial.println("Waiting for GPS data");
    GPSModule.read();
  }
  delay(1000);

  Serial.println("GPS is ready");
  // GPSModule.sendCommand("$PMTK622,1*29");
  GPSModule.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // turn on only the "minimum recommended" data
  GPSModule.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);    // 1 Hz update rate
  GPSModule.sendCommand(PGCMD_ANTENNA);               // Request updates on antenna status

  delay(1000);

  // Ask for firmware version
  GPSModule.println(PMTK_Q_RELEASE);
}

void GPS::update()
{
  char c = GPSModule.read();

  if (GPSECHO)
    if (c) Serial.print(c);

  if (GPSModule.newNMEAreceived()) {
    if (!GPSModule.parse(GPSModule.lastNMEA()))
      return;
  }

   // approximately every 2 seconds or so, print out the current stats
  if (millis() - timersss > 1000) {
    timersss = millis(); // reset the timer
    Serial.print("\nTime: ");
    if (GPSModule.hour < 10) { Serial.print('0'); }
    Serial.print(GPSModule.hour, DEC); Serial.print(':');
    if (GPSModule.minute < 10) { Serial.print('0'); }
    Serial.print(GPSModule.minute, DEC); Serial.print(':');
    if (GPSModule.seconds < 10) { Serial.print('0'); }
    Serial.print(GPSModule.seconds, DEC); Serial.print('.');
    if (GPSModule.milliseconds < 10) {
      Serial.print("00");
    } else if (GPSModule.milliseconds > 9 && GPSModule.milliseconds < 100) {
      Serial.print("0");
    }
    Serial.println(GPSModule.milliseconds);
    Serial.print("Date: ");
    Serial.print(GPSModule.day, DEC); Serial.print('/');
    Serial.print(GPSModule.month, DEC); Serial.print("/20");
    Serial.println(GPSModule.year, DEC);
    Serial.print("Fix: "); Serial.print((int)GPSModule.fix);
    Serial.print(" quality: "); Serial.println((int)GPSModule.fixquality);
    Serial.print("Location: ");
    Serial.print(GPSModule.latitude, 4); Serial.print(GPSModule.lat);
    Serial.print(", ");
    Serial.print(GPSModule.longitude, 4); Serial.println(GPSModule.lon);
    Serial.print("Speed (knots): "); Serial.println(GPSModule.speed);
    Serial.print("Angle: "); Serial.println(GPSModule.angle);
    Serial.print("Altitude: "); Serial.println(GPSModule.altitude);
    Serial.print("Satellites: "); Serial.println((int)GPSModule.satellites);
    Serial.print("Antenna status: "); Serial.println((int)GPSModule.antenna);
  }
}
