#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
// #include "utility/Adafruit_PWMServoDriver.h"

Adafruit_StepperMotor* stepper1 = nullptr;
Adafruit_StepperMotor* stepper2 = nullptr;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN , OUTPUT);
  Serial.begin(9600);
  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //Create tge Motor Sheild Obj
  AFMS.begin();

  stepper1 = AFMS.getStepper(200 , 2);
  stepper2 = AFMS.getStepper(200 , 1);
  // / which port it is connected to.If you're using M1 and M2, its port 1. If you're using M3and M4 indicate port 2
  stepper1 > setSpeed(20);
  stepper2->setSpeed(33);
  Serial.write("End Setup\n");
  }



void blink_count(int n) {
  // String out = "Blink " + num;
  // out = out + " times";
  // const* char[] a = "Blink ";
  // const* char[] b = " Times";
  // sprintf("Blink \d Times" , num);

  // Serial.write(sprintf("Blink \d Times" , num));
  // Serial.write("Blink \n");
  // Serial.write((const char*) num);
  // Serial.write("\n");
  for (int i = 0; i < n; i++)
    {
    digitalWrite(LED_BUILTIN , HIGH);   // turn the LED on (HIGH is the voltage 
    delay(50);
    digitalWrite(LED_BUILTIN , LOW);
    delay(50);
    }
  return;
  // Serial.write("End Blink \n");
  }

void loop() {
  // put your main code here, to run repeatedly:
   // turn the LED off by making the voltage LOW
  blink_count(1);
  stepper1 > step(100 , FORWARD , MICROSTEP);
  stepper2->step(40 , BACKWARD , MICROSTEP);
  stepper2->release();
  stepper1 > release();

  Serial.write("1\n");
  // delay(1000);
  blink_count(2);                       // wait for a second
  stepper1 > step(200 , BACKWARD , SINGLE);
  stepper2->step(200 , FORWARD , SINGLE);
  stepper2->release();
  stepper1 > release();
  Serial.write("2\n");
  blink_count(3);
  stepper1 > step(300 , FORWARD , INTERLEAVE);
  stepper2->step(100 , BACKWARD , INTERLEAVE);
  stepper2->release();
  stepper1 > release();
  Serial.write("3\n");
  blink_count(4);

  stepper2->step(300 , FORWARD , DOUBLE);
  stepper1 > step(100 , BACKWARD , DOUBLE);
  stepper2->release();
  stepper1 > release();
  Serial.write("4\n");
  // Serial.write("0");
  Serial.write("restarting\n");


  delay(500);
  }
/*
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2
---->	http://www.adafruit.com/products/1438
*/


// #include <Wire.h>
// #include <Adafruit_MotorShield.h>

// // Create the motor shield object with the default I2C address
// Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// // Or, create it with a different I2C address (say for stacking)
// // Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// // Connect a stepper motor with 200 steps per revolution (1.8 degree)
// // to motor port #2 (M3 and M4)
// Adafruit_StepperMotor* myMotor = AFMS.getStepper(200 , 2);


// void setup() {
//   Serial.begin(9600);           // set up Serial library at 9600 bps
//   Serial.println("Stepper test!");

//   AFMS.begin();  // create with the default frequency 1.6KHz
//   //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

//   myMotor->setSpeed(10);  // 10 rpm   
//   }

// void loop() {
//   Serial.println("Single coil steps");
//   myMotor->step(100 , FORWARD , SINGLE);
//   myMotor->step(100 , BACKWARD , SINGLE);

//   Serial.println("Double coil steps");
//   myMotor->step(100 , FORWARD , DOUBLE);
//   myMotor->step(100 , BACKWARD , DOUBLE);

//   Serial.println("Interleave coil steps");
//   myMotor->step(100 , FORWARD , INTERLEAVE);
//   myMotor->step(100 , BACKWARD , INTERLEAVE);

//   Serial.println("Microstep steps");
//   myMotor->step(50 , FORWARD , MICROSTEP);
//   myMotor->step(50 , BACKWARD , MICROSTEP);
//   }