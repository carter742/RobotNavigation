#include <Wire.h>
#include <Adafruit_TCS34725.h>

const uint16_t LEGAL_FISH_DETECTION_TOLERENCE = 50;
const uint16_t ENVIRONMENT_DETECTION_TOLERENCE = 50;

uint16_t MIN_LEGAL_FISH_LIGHT_INTENSITY = 8; //do not change value. (must not be constant for program callibration)
uint16_t MAX_LEGAL_FISH_COLOR_TEMP = 2500;   //do not change value. (must not be constant for program callibration)

uint16_t legalFishDetectedNum = 0;
uint16_t environmentDetectedNum = 0;

bool legalFishDetected = false;

Adafruit_TCS34725 tcs = Adafruit_TCS34725();

void initColorSensor() {
  if (tcs.begin()) {
    Serial.println("Found Sensor");
  } else {
    Serial.println("No TCS34735 found ... check your connections");
  }
}

void resetDetection() {
  legalFishDetectedNum = 0;
  environmentDetectedNum = 0;
}

void updateColorSensor() {
  uint16_t r, g, b, c, colorTemp; //, lux;

  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  // lux = tcs.calculateLux(r, g, b);

  if (c > MIN_LEGAL_FISH_LIGHT_INTENSITY && colorTemp < MAX_LEGAL_FISH_COLOR_TEMP) {
    legalFishDetectedNum++;
  } else {
    environmentDetectedNum++;
  }

  if (LEGAL_FISH_DETECTION_TOLERENCE < legalFishDetectedNum) {
    legalFishDetected = true;
    resetDetection();
  } else if (ENVIRONMENT_DETECTION_TOLERENCE < environmentDetectedNum) {
    resetDetection();
  }
}

bool isDetectingLegalFish() {
  if (legalFishDetected) {
    legalFishDetected = false;
    return true;
  }

  return false;
}