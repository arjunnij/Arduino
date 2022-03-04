#include <dht.h>


dht DHT;

#define DHT11_PIN 0


int seven_segment_pin_1 = 2;
int seven_segment_pin_2 = 3;
int seven_segment_pin_3 = 4;
int seven_segment_pin_4 = 5;
int seven_segment_pin_5 = 6;
int seven_segment_pin_6 = 13;
int seven_segment_pin_7 = 7;
int seven_segment_pin_8 = 8;
int seven_segment_pin_9 = 9;
int seven_segment_pin_10 = 10;
int seven_segment_pin_11 = 11;
int seven_segment_pin_12 = 12;

int seven_segment_A = seven_segment_pin_11;
int seven_segment_B = seven_segment_pin_7;
int seven_segment_C = seven_segment_pin_4;
int seven_segment_D = seven_segment_pin_2;
int seven_segment_E = seven_segment_pin_1;
int seven_segment_F = seven_segment_pin_10;
int seven_segment_G = seven_segment_pin_5;

void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void set_seven_segment_numerical_value(int value) {
  if (value == 0) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, HIGH);
    digitalWrite(seven_segment_E, HIGH);
    digitalWrite(seven_segment_F, HIGH);
    digitalWrite(seven_segment_G, LOW);
  }

  if (value == 1) {
    digitalWrite(seven_segment_A, LOW);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, LOW);
    digitalWrite(seven_segment_E, LOW);
    digitalWrite(seven_segment_F, LOW);
    digitalWrite(seven_segment_G, LOW);
  }

  if (value == 2) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, LOW);
    digitalWrite(seven_segment_D, HIGH);
    digitalWrite(seven_segment_E, HIGH);
    digitalWrite(seven_segment_F, LOW);
    digitalWrite(seven_segment_G, HIGH);
  }

  if (value == 3) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, HIGH);
    digitalWrite(seven_segment_E, LOW);
    digitalWrite(seven_segment_F, LOW);
    digitalWrite(seven_segment_G, HIGH);
  }

  if (value == 4) {
    digitalWrite(seven_segment_A, LOW);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, LOW);
    digitalWrite(seven_segment_E, LOW);
    digitalWrite(seven_segment_F, HIGH);
    digitalWrite(seven_segment_G, HIGH);
  }

  if (value == 5) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, LOW);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, HIGH);
    digitalWrite(seven_segment_E, LOW);
    digitalWrite(seven_segment_F, HIGH);
    digitalWrite(seven_segment_G, HIGH);
  }

  if (value == 6) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, LOW);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, HIGH);
    digitalWrite(seven_segment_E, HIGH);
    digitalWrite(seven_segment_F, HIGH);
    digitalWrite(seven_segment_G, HIGH);
  }

  if (value == 7) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, LOW);
    digitalWrite(seven_segment_E, LOW);
    digitalWrite(seven_segment_F, LOW);
    digitalWrite(seven_segment_G, LOW);
  }

  if (value == 8) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, HIGH);
    digitalWrite(seven_segment_E, HIGH);
    digitalWrite(seven_segment_F, HIGH);
    digitalWrite(seven_segment_G, HIGH);
  }

  if (value == 9) {
    digitalWrite(seven_segment_A, HIGH);
    digitalWrite(seven_segment_B, HIGH);
    digitalWrite(seven_segment_C, HIGH);
    digitalWrite(seven_segment_D, LOW);
    digitalWrite(seven_segment_E, LOW);
    digitalWrite(seven_segment_F, HIGH);
    digitalWrite(seven_segment_G, HIGH);
  }
}


void set_seven_segment_digit(int digit, int value) {

  if (digit == 0) {
    digitalWrite(seven_segment_pin_12, LOW);
    digitalWrite(seven_segment_pin_9, HIGH);
    digitalWrite(seven_segment_pin_8, HIGH);
    digitalWrite(seven_segment_pin_6, HIGH);
  }

  if (digit == 1) {
    digitalWrite(seven_segment_pin_12, HIGH);
    digitalWrite(seven_segment_pin_9, LOW);
    digitalWrite(seven_segment_pin_8, HIGH);
    digitalWrite(seven_segment_pin_6, HIGH);
  }

  if (digit == 2) {
    digitalWrite(seven_segment_pin_12, HIGH);
    digitalWrite(seven_segment_pin_9, HIGH);
    digitalWrite(seven_segment_pin_8, LOW);
    digitalWrite(seven_segment_pin_6, HIGH);
  }

  if (digit == 3) {
    digitalWrite(seven_segment_pin_12, HIGH);
    digitalWrite(seven_segment_pin_9, HIGH);
    digitalWrite(seven_segment_pin_8, HIGH);
    digitalWrite(seven_segment_pin_6, LOW);
  }

  set_seven_segment_numerical_value(value);

}

void loop() {
  // put your main code here, to run repeatedly:

  int chk = DHT.read11(DHT11_PIN);

  int humidity = DHT.humidity;

  int ones = humidity % 10;
  int tens = (humidity / 10) % 10;
  int hundreds = (humidity / 100) % 10;
  int thousands = (humidity / 1000) % 10;

  int counter = 100;

  while(counter--) {
 
    delay(3);
  
    if (thousands > 0) { 
     set_seven_segment_digit(0, thousands);
    }
  
    delay(3);
  
    if (hundreds > 0) { 
     set_seven_segment_digit(1, hundreds);
    }
  
    delay(3);
  
    if (tens >= 0) { 
     set_seven_segment_digit(2, tens);
    }
  
    delay(3);
  
    if (ones >= 0) { 
     set_seven_segment_digit(3, ones);
    }

  }

}
