#ifndef TCS34725_h
#define TCS34725_h

#include "Arduino.h"
#include "Adafruit_TCS34725.h"

class TCS34725
{
  public:
    TCS34725();
    boolean begin(void);
    void Read();
    void ToSerial();
    String ToString();
    int GetRedComponent();
    int GetGreenComponent();
    int GetBlueComponent();
  private:
    Adafruit_TCS34725 _colorSensor;
    int GetColorComponent(uint16_t color);
    int _red;
    int _green;
    int _blue;
	int _clear;
};

#endif