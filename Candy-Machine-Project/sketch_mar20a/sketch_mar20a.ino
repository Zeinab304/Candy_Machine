#include <Stepper.h>
#include <Servo.h>

Stepper selector(200, 22, 24, 23, 25); 
Servo gate;

const int dc1 = 4, dc2 = 2, enA = 13;
const int trig = 26, echo = 33;
const int led = 28;      
const int buzzer = 27;   

//ultrasonic
int getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;
}

//dc
void dcMotor(){
  analogWrite(enA, 200);
  digitalWrite(dc1, HIGH); 
  digitalWrite(dc2, LOW);
  delay(1000); 
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, LOW);
  analogWrite(enA, 0);

}

//servo
void openningGate(){
  Serial.println("Opening Gate...");
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  gate.write(90);
}
void closingGate(){
  Serial.println("Closing Gate...");
  gate.write(0);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
}


void setup() {
  Serial.begin(115200);
  
  selector.setSpeed(30);
  gate.attach(12);    
  gate.write(0); 

  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.println("System Ready!");
}

void loop() {
  int distance = getDistance();

  if (distance <= 10) { 
    Serial.println("Choose Candy: 1, 2, or 3:");

    while (Serial.available() > 0) { Serial.read(); }
    while (Serial.available() == 0) { delay(10); }    
    
    char choice = Serial.read();
    
    switch(choice) {
      case '1':
        Serial.println("Candy 1 Coming!");
        selector.step(50); 
        break;
      case '2':
        Serial.println("Candy 2 Coming!");
        selector.step(100); 
        break;
      case '3':
        Serial.println("Candy 3 Coming!");
        selector.step(150); 
        break;
      default:
        Serial.println("Invalid choice!!");
        goto end; 
    }
    
    openningGate();
    delayMicroseconds(2);
    dcMotor();
    Serial.println("ENJOY ^-^");
    delay(2000);
    closingGate();

    end:
    delayMicroseconds(2);
    Serial.println("Ready for next order!");
  }
  delay(3000); 
}