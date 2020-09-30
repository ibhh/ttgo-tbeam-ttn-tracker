/*

  BME module

*/

// Barometer
#include <Adafruit_BME280.h>
// Barometer setup
Adafruit_BME280 bme(I2C_SDA, I2C_SCL); // these pins are defined in configuration.h
void getBME280Values(void); // declaration for function below
float tmp, hum, pressure, alt_barometric; // BME280 data are saved here: Temperature, Humidity, Pressure, Altitude calculated from atmospheric pressure
bool bme280_status; // status after reading from BME280

void getBME280Values() {

  if (!bme280_status) { // we don't have BME280 connection, clear the values and exit
    tmp = 0.0f;
    pressure = 0.0f;
    alt_barometric = 0.0f;
    hum = 0.0f;
    return;
  }
  
  tmp = bme.readTemperature();
  pressure = bme.readPressure() / 100.0F;
  alt_barometric = bme.readAltitude(SEALEVELPRESSURE_HPA);
  hum = bme.readHumidity();
  
  Serial.print(F("Temperature = "));
  Serial.print(tmp);
  Serial.print("C, ");
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.print("hPa, ");
  Serial.print("Approx. Altitude = ");
  Serial.print(alt_barometric);
  Serial.print("m, ");
  Serial.print("Humidity = ");
  Serial.print(hum);
  Serial.println("%");

  delay(100);
}

void bme_setup() {
  bme280_status = bme.begin(BME280_ADDRESS);
  
  if (!bme280_status) {
    Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
  } else {
    Serial.println(F("BME280 initialized sucessfully"));
    delay(1000); // stabilize sensor readings
    Serial.println(F("BMP/BME280: normal mode, 16x pressure / 2x temperature / 1x humidity oversampling,"));
    Serial.println(F("0.5ms standby period, filter 16x"));
    bme.setSampling(Adafruit_BME280::MODE_NORMAL,
                    Adafruit_BME280::SAMPLING_X2,  // temperature
                    Adafruit_BME280::SAMPLING_X16, // pressure
                    Adafruit_BME280::SAMPLING_X1,  // humidity
                    Adafruit_BME280::FILTER_X16,
                    Adafruit_BME280::STANDBY_MS_0_5 );

    delay(500);
  }
}

#if defined(PAYLOAD_USE_FULL)

    // More data than PAYLOAD_USE_CAYENNE
    void bme_buildPacket(uint8_t txBuffer[10])
    {
        
    }

#elif defined(PAYLOAD_USE_CAYENNE)

    // CAYENNE DF
    void bme_buildPacket(uint8_t txBuffer[11])
    {
        
    }

#elif defined(PAYLOAD_USE_LOW_CAYENNE)
    // CAYENNE DF
    void bme_buildPacket()
    {
        lpp.addTemperature(5, tmp);
        lpp.addRelativeHumidity(6, hum);
        lpp.addBarometricPressure(7, pressure);
        //lpp.addAnalogInput(8, alt_barometric);
    }
#endif
