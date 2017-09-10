#include "Arduino.h"
#include "TCS34725.h"
#include "Adafruit_TCS34725.h"

TCS34725::TCS34725()
{
    _colorSensor = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);
}

void TCS34725::ToSerial()
{
    Serial.println(ToString());
}

String TCS34725::ToString()
{
    String colorString = "{\"Protocol\":\"Bifrost\",\"Device\":\"TCS34725\",\"Properties\":{\"Red\":\"<RED>\",\"Green\":\"<GREEN>\",\"Blue\":\"<BLUE>\"}}";

    colorString.replace("<RED>", String(GetRedComponent(), HEX));
    colorString.replace("<GREEN>", String(GetGreenComponent(), HEX));
    colorString.replace("<BLUE>", String(GetBlueComponent(), HEX));

    return colorString;
}

boolean TCS34725::begin(void)
{
    return _colorSensor.begin();
}

void TCS34725::Read()
{
    uint16_t clear, red, green, blue;
    _colorSensor.getRawData(&red, &green, &blue, &clear);

    _red = red;
    _green = green;
    _blue = blue;
    _clear = clear;
}

int TCS34725::GetRedComponent()
{
    return GetColorComponent(_red);
}

int TCS34725::GetGreenComponent()
{
    return GetColorComponent(_green);
}

int TCS34725::GetBlueComponent()
{
    return GetColorComponent(_blue);
}

int TCS34725::GetColorComponent(uint16_t color)
{
    float c = 256 * color / _clear; 

    return (int)c;
}