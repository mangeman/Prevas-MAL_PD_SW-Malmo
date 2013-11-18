/*
 Print Hello World on Serial Console
*/

#define ARDUINO_MAIN
#include "Arduino.h"

int main() {
    init();

    delay(1);

    unsigned short pin1 = 12;
    unsigned short pin2 = 51;
    unsigned short pwmPin = 10;
    int sensorPin = A0;
    int sensorValue = 0;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pwmPin, OUTPUT);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);


#if defined(USBCON)
    USBDevice.attach();
#endif


    // initialize serial:
    Serial.begin(115200);



    for (;;) 
        {
            sensorValue = analogRead(sensorPin);
            analogWrite(pwmPin, sensorValue/4);
            delay(10);
            static unsigned short bPP = 0;
            if (bPP%100 == 0)
                {
                    Serial.print("Hello Wold: \r\n");
                }
        }

//    for (;;) 
//        {
//            Serial.print("Hello Wold\r\n");
//            static unsigned char bFlip = 0;
//            ++bFlip;
//            if (bFlip%2==0)
//                {
//                    digitalWrite(pin1, HIGH);
//                    digitalWrite(pin2, LOW);
//                    analogWrite(pwmPin, 127);
//                }
//            else
//                {
//                    digitalWrite(pin1, LOW);
//                    digitalWrite(pin2, HIGH);
//                    analogWrite(pwmPin, 255);
//                }
//            delay(5000);
//            if (serialEventRun) serialEventRun();
//        }
    
    return 0;
}
