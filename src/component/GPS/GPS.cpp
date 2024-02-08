#include "GPS.h"

GPS::GPS() {
    GPSModule = Adafruit_GPS(&Serial2);
}

void GPS::setup() {
    GPSModule.begin(9600);
    // GPSModule.sendCommand(PMTK_SET_NMEA_OUTPUT_OFF);
    while (GPSModule.available()){
        Serial1.println("Waiting for GPS data");
        GPSModule.read();
    }
    delay(1000);

    Serial1.println("GPS is ready");
    // GPSModule.sendCommand("$PMTK622,1*29");
    GPSModule.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);// turn on only the "minimum recommended" data
    GPSModule.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // 1 Hz update rate
    GPSModule.sendCommand(PGCMD_ANTENNA);// Request updates on antenna status

    delay(1000);

    // Ask for firmware version
    GPSModule.println(PMTK_Q_RELEASE);

}

void GPS::update() {
    // GPSModule.read();
    // if (GPSModule.newNMEAreceived()) {
    //     GPSModule.parse(GPSModule.lastNMEA());
    // }

    Serial1.println("Checking for NMEA data...");
    if (GPSModule.newNMEAreceived()) {
        auto nmea = GPSModule.lastNMEA();
        Serial1.print("Received NMEA: ");
        Serial1.println(nmea);
        if (!GPSModule.parse(nmea)) {
            Serial1.println("Parsing failed");
        }
    } else {
        Serial1.println("No new NMEA data received.");
    }

}

void GPS::printData()
{

    char c = GPSModule.read();//read data frin GPS main loop

    if (GPSECHO){
      if (c) Serial1.print(c);
    }

    if (GPSModule.newNMEAreceived()) // print the NMEA sentence, or data, cannot listen and catching new sentences
    {
      Serial1.print(GPSModule.lastNMEA()); // this also sets the newNMEAreceived() flag to false
      if (!GPSModule.parse(GPSModule.lastNMEA())) // this also sets the newNMEAreceived() flag to false
        return; // we can fail to parse a sentence in which case we should just wait for another
    }
    Serial1.print("\nTime: ");
    if (GPSModule.hour < 10) { Serial1.print('0'); }
    Serial1.print(GPSModule.hour, DEC); Serial1.print(':');
    if (GPSModule.minute < 10) { Serial1.print('0'); }
    Serial1.print(GPSModule.minute, DEC); Serial1.print(':');
    if (GPSModule.seconds < 10) { Serial1.print('0'); }
    Serial1.print(GPSModule.seconds, DEC); Serial1.print('.');
    if (GPSModule.milliseconds < 10) {
      Serial1.print("00");
    } else if (GPSModule.milliseconds > 9 && GPSModule.milliseconds < 100) {
      Serial1.print("0");
    }
    Serial1.println(GPSModule.milliseconds);
    Serial1.print("Date: ");
    Serial1.print(GPSModule.day, DEC); Serial1.print('/');
    Serial1.print(GPSModule.month, DEC); Serial1.print("/20");
    Serial1.println(GPSModule.year, DEC);
    Serial1.print("Fix: "); Serial1.print((int)GPSModule.fix);
    Serial1.print(" quality: "); Serial1.println((int)GPSModule.fixquality);
      //Print GPS location data to lcd
    if (GPSModule.fix) {
      Serial1.print("Location: ");
      Serial1.print(GPSModule.latitude, 4); Serial1.print(GPSModule.lat);
      Serial1.print(", ");
      Serial1.print(GPSModule.longitude, 4); Serial1.println(GPSModule.lon);
      Serial1.print("Speed (knots): "); Serial1.println(GPSModule.speed);
      Serial1.print("Angle: "); Serial1.println(GPSModule.angle);
      Serial1.print("Altitude: "); Serial1.println(GPSModule.altitude);
      Serial1.print("Satellites: "); Serial1.println((int)GPSModule.satellites);
      Serial1.print("Antenna status: "); Serial1.println((int)GPSModule.antenna);  
    }
}
