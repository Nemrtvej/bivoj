// http://www.bajdi.com
// Rotating a continuous servo (tested with a SpringRC SM-S4306R)

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int servoDelay = 0;
int servo = 0;
int incomingByte = 0;
int parsedNumber = 0;

// 0: read delay
// 1: read servo
int mode = 0; 
int numberOfModes = 2;

void setup() 
{   
    Serial.begin(9600);

    myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
    // send data only when you receive data:
    if (Serial.available() > 0) {
        while (true) {
            incomingByte = Serial.read();

            if (incomingByte == '\n') {
                triggerServo();
                resetState();
                return;
            }

            if (incomingByte == '-') {
                nextMode();
                continue;
            }

            if (incomingByte < '0' || incomingByte > '9') {
                resetState();
                return;
            }

            parsedNumber = incomingByte - '0';
            processNumber(parsedNumber);
        }
    } else {
        delay(20);
    }
} 

void nextMode() 
{
    mode++;
    mode = mode % numberOfModes;
}

void resetState()
{
    mode = 0;
    servoDelay = 0;
    servo = 0;
}

void triggerServo()
{
    Serial.print("Delay: ");
    Serial.println(servoDelay);
    Serial.print("Servo: ");
    Serial.println(servo);  

    myservo.write(servo);
    delay(servoDelay);
    myservo.write(90);
}

void processNumber(int number)
{
    if (mode == 0) {
        servoDelay = (int) ((servoDelay * 10) + number);
    } else if (mode == 1) {
        servo = (int) ((servo * 10) + number);
    } else {
        return;
    }
}
