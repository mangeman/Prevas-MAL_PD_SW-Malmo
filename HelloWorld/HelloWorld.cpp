#define ARDUINO_MAIN
#include "Arduino.h"

byte speed = 0; // [0..255]

float distance = 100;

#define pwmPinRA1 13
#define pwmPinRA2 12
#define pwmPinRB1 8
#define pwmPinRB2 11
#define pwmPinLA1 4
#define pwmPinLA2 5
#define pwmPinLB1 2
#define pwmPinLB2 3

#define pinUltraEcho 51

void set_speed(byte spe);
void stop(void);
void stop_left(void);
void stop_right(void);
void forward(void);
void backward(void);
void left_forward(void);
void left_backward(void);
void right_forward(void);
void right_backward(void);
void turn_left_forward(void);
void turn_left_backward(void);
void turn_right_forward(void);
void turn_right_backward(void);

void measure_distance(void);

//____________________________________________________________
int main()
{
    init();

    delay(1);

    pinMode(pwmPinRA1, OUTPUT);
    pinMode(pwmPinRA2, OUTPUT);
    pinMode(pwmPinRB1, OUTPUT);
    pinMode(pwmPinRB2, OUTPUT);
    pinMode(pwmPinLA1, OUTPUT);
    pinMode(pwmPinLA2, OUTPUT);
    pinMode(pwmPinLB1, OUTPUT);
    pinMode(pwmPinLB2, OUTPUT);
    
    pinMode(pinUltraEcho, INPUT);


#if defined(USBCON)
    USBDevice.attach();
#endif

    // initialize serial:
    Serial.begin(115200);

    //int delay1 = 3000;

    set_speed(255);

    for (;;)
        {
            measure_distance();

            if (distance < 20)
            {
                turn_right_backward();
                for (int i=0; i<45; ++i)
                {
                  measure_distance();
                  delay(10);
                }
            }
            else
            {
                forward();
            }
        }
    
    return 0;
}
//__________________________________________________________________
void measure_distance(void)
{
  // PW DIGITAL IN
  long raw = pulseIn(pinUltraEcho, HIGH);
  distance = 0.75*distance + 0.25*(raw*0.017279); // 2.54 / 147 [cm]
}
//____________________________________________________________
void stop_left(void)
{
    analogWrite(pwmPinLA1, 0);
    analogWrite(pwmPinLA2, 0);
    analogWrite(pwmPinLB1, 0);
    analogWrite(pwmPinLB2, 0);
}
void stop_right(void)
{
    analogWrite(pwmPinRA1, 0);
    analogWrite(pwmPinRA2, 0);
    analogWrite(pwmPinRB1, 0);
    analogWrite(pwmPinRB2, 0);
}
//____________________________________________________________
void stop(void)
{
    stop_left();
    stop_right();
}
//____________________________________________________________
void set_speed(byte spe)
{
  speed = spe;
}
//____________________________________________________________
void forward()
{
  right_forward();
  left_forward();
}
//____________________________________________________________
void right_backward()
{
            analogWrite(pwmPinRA1, 0);
            analogWrite(pwmPinRA2, speed);
            analogWrite(pwmPinRB1, 0);
            analogWrite(pwmPinRB2, speed);
}
//____________________________________________________________
void left_backward()
{
            analogWrite(pwmPinLA1, 0);
            analogWrite(pwmPinLA2, speed);
            analogWrite(pwmPinLB1, 0);
            analogWrite(pwmPinLB2, speed);
}
//____________________________________________________________
void backward()
{
  right_backward();
  left_backward();
}
//____________________________________________________________
void right_forward()
{
            analogWrite(pwmPinRA1, speed);
            analogWrite(pwmPinRA2, 0);
            analogWrite(pwmPinRB1, speed);
            analogWrite(pwmPinRB2, 0);
}
//____________________________________________________________
void left_forward()
{
            analogWrite(pwmPinLA1, speed);
            analogWrite(pwmPinLA2, 0);
            analogWrite(pwmPinLB1, speed);
            analogWrite(pwmPinLB2, 0);
}
//____________________________________________________________
void turn_left_backward(void)
{
  stop_left();
  right_backward();  
}
//____________________________________________________________
void turn_left_forward(void)
{
  stop_left();
  right_forward();
}
//____________________________________________________________
void turn_right_backward(void)
{
  stop_right();
  left_backward();
}
//____________________________________________________________
void turn_right_forward(void)
{
  stop_right();
  left_forward();
}







// for (;;)
// {
// Serial.print("Hello Wold\r\n");
// static unsigned char bFlip = 0;
// ++bFlip;
// if (bFlip%2==0)
// {
// digitalWrite(pin1, HIGH);
// digitalWrite(pin2, LOW);
// analogWrite(pwmPin, 127);
// }
// else
// {
// digitalWrite(pin1, LOW);
// digitalWrite(pin2, HIGH);
// analogWrite(pwmPin, 255);
// }
// delay(5000);
// if (serialEventRun) serialEventRun();
// }
