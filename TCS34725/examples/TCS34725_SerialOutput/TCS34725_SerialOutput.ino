#include <TCS34725.h>

TCS34725 tcs34725;

void setup() {
    Serial.begin(9600);

    if (!tcs34725.begin()) {
        Serial.println("No TCS34725 found ... check your connections");
        while (1);
    }
}

void loop() {
    tcs34725.Read();

    Serial.println(tcs34725.ToString());

    delay(250);
}