/*
 Print Hello World on Serial Console
*/

#define ARDUINO_MAIN
#include "Arduino.h"

int speed; // [-63..63]

unsigned short pwmPinLA1 = 13;
unsigned short pwmPinLA2 = 12;
unsigned short pwmPinLB1 = 10;
unsigned short pwmPinLB2 = 11;
unsigned short pwmPinRA1 = 4;
unsigned short pwmPinRA2 = 5;
unsigned short pwmPinRB1 = 2;
unsigned short pwmPinRB2 = 3;

void set_speed(int spe);
void turn_right(void);
void turn_left(void);

int main() {
    init();

    delay(1);

    unsigned short pin1 = 12;
    unsigned short pin2 = 51;
    int sensorPin = A0;
    int sensorValue = 0;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pwmPinLA1, OUTPUT);
    pinMode(pwmPinLA2, OUTPUT);
    pinMode(pwmPinLB1, OUTPUT);
    pinMode(pwmPinLB2, OUTPUT);
    pinMode(pwmPinRA1, OUTPUT);
    pinMode(pwmPinRA2, OUTPUT);
    pinMode(pwmPinRB1, OUTPUT);
    pinMode(pwmPinRB2, OUTPUT);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);


#if defined(USBCON)
    USBDevice.attach();
#endif


    // initialize serial:
    Serial.begin(115200);



    //    for (;;) 
        {
            static int bPP = 0;
 
            //            sensorValue = analogRead(sensorPin);
            int delay1 = 5000;

            set_speed(63);
            delay(delay1);

            turn_right();
            delay(delay1);

            set_speed(63);
            delay(delay1);

            turn_left();
            delay(delay1);

            set_speed(-63);
            delay(delay1);

            turn_right();
            delay(delay1);

            set_speed(-63);
            delay(delay1);

            turn_left();
            delay(delay1);

            set_speed(0);
            

//!!!            if (bPP%100 == 0)
//!!!                {
//!!!                    Serial.print("Hello Wold: \r\n");
//!!!                }

            ++bPP;
        }
    
    return 0;
}




void set_speed(int spe)
{
    speed = spe;

    // speed must be [-63..63]
    if (speed < 0)
        {
            analogWrite(pwmPinLA1, speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, speed);
            analogWrite(pwmPinLB2, 0);

            analogWrite(pwmPinRA1, speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, speed);
            analogWrite(pwmPinRB2, 0);
        }
    else
        {
            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, -speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, -speed);

            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, -speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, -speed);
        }    
}

void turn_right(void)
{
    if (speed < 0)
        {
            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, -speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, -speed);

            analogWrite(pwmPinRA1, speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, speed);
            analogWrite(pwmPinRB2, 0);
        }
    else
        {
            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, speed);

            analogWrite(pwmPinRA1, speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, speed);
            analogWrite(pwmPinRB2, 0);
        }    
}

void turn_left(void)
{
    if (speed < 0)
        {
            analogWrite(pwmPinLA1, -speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, -speed);
            analogWrite(pwmPinLB2, 0);

            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, -speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, -speed);
        }
    else
        {
            analogWrite(pwmPinLA1, speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, speed);
            analogWrite(pwmPinLB2, 0);

            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, speed);
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
