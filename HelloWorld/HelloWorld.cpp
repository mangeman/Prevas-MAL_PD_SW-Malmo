#define ARDUINO_MAIN
#include "Arduino.h"

int speed = 0; // [-255..255]

#define pwmPinRA1 13
#define pwmPinRA2 12
#define pwmPinRB1 8
#define pwmPinRB2 11
#define pwmPinLA1 4
#define pwmPinLA2 5
#define pwmPinLB1 2
#define pwmPinLB2 3

void set_speed(int spe);
void stop(void);
void turn_left(void);
void turn_left2(void);
void turn_right(void);
void turn_right2(void);

//____________________________________________________________
int main() 
{
    init();

    delay(1);

    //    unsigned short pin1 = 12;
    unsigned short pin2 = 51;
    int sensorPin = A0;
    int sensorValue = 0;
    //    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pwmPinRA1, OUTPUT);
    pinMode(pwmPinRA2, OUTPUT);
    pinMode(pwmPinRB1, OUTPUT);
    pinMode(pwmPinRB2, OUTPUT);
    pinMode(pwmPinLA1, OUTPUT);
    pinMode(pwmPinLA2, OUTPUT);
    pinMode(pwmPinLB1, OUTPUT);
    pinMode(pwmPinLB2, OUTPUT);
    //    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);


#if defined(USBCON)
    USBDevice.attach();
#endif

    // initialize serial:
    Serial.begin(115200);

    int delay1 = 3000;

    //    for (;;) 
        {
            static int bPP = 0;
 
            //            sensorValue = analogRead(sensorPin);

            stop();

            set_speed(255);
            delay(delay1);

            turn_right2();
            delay(delay1);

            set_speed(127);
            delay(delay1);

            set_speed(255);
            turn_left2();
            delay(delay1);

            set_speed(-255);
            delay(delay1);

            turn_right2();
            delay(delay1);

            set_speed(-127);
            delay(delay1);

            set_speed(-255);
            turn_left2();
            delay(delay1);

            stop();
            

//!!!            if (bPP%100 == 0)
//!!!                {
//!!!                    Serial.print("Hello Wold: \r\n");
//!!!                }

            ++bPP;
        }
    
    return 0;
}
//____________________________________________________________
void stop(void)
{
    analogWrite(pwmPinRA1, 0);
    analogWrite(pwmPinRA2, 0);
    analogWrite(pwmPinRB1, 0);
    analogWrite(pwmPinRB2, 0);
    analogWrite(pwmPinLA1, 0);
    analogWrite(pwmPinLA2, 0);
    analogWrite(pwmPinLB1, 0);
    analogWrite(pwmPinLB2, 0);
}
//____________________________________________________________
void set_speed(int spe)
{
    speed = spe;

    // speed must be [-255..255]
    if (speed < 0)
        {
            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, -speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, -speed);

            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, -speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, -speed);
        }
    else
        {
            analogWrite(pwmPinRA1, speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, speed);
            analogWrite(pwmPinRB2, 0);

            analogWrite(pwmPinLA1, speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, speed);
            analogWrite(pwmPinLB2, 0);
        }    
}
//____________________________________________________________
void turn_left(void)
{
    if (speed < 0)
        {
            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, -speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, -speed);

            analogWrite(pwmPinLA1, -speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, -speed);
            analogWrite(pwmPinLB2, 0);
        }
    else
        {
            analogWrite(pwmPinRA1, speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, speed);
            analogWrite(pwmPinRB2, 0);

            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, speed);
        }    
}
//____________________________________________________________
void turn_left2(void)
{
    if (speed < 0)
        {
            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, -speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, -speed);

            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, 0);
        }
    else
        {
            analogWrite(pwmPinRA1, speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, speed);
            analogWrite(pwmPinRB2, 0);

            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, 0);
        }    
}
//____________________________________________________________
void turn_right(void)
{
    if (speed < 0)
        {
            analogWrite(pwmPinRA1, -speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, -speed);
            analogWrite(pwmPinRB2, 0);

            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, -speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, -speed);
        }
    else
        {
            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, speed);

            analogWrite(pwmPinLA1, speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, speed);
            analogWrite(pwmPinLB2, 0);
        }
}
//____________________________________________________________
void turn_right2(void)
{
    if (speed < 0)
        {
            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, 0);

            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, -speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, -speed);
        }
    else
        {
            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, 0);

            analogWrite(pwmPinLA1, speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, speed);
            analogWrite(pwmPinLB2, 0);
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
