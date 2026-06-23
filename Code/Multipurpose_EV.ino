#define BLYNK_TEMPLATE_ID "TEMPLATE_ID_FROM_BLYNK_APP"
#define BLYNK_TEMPLATE_NAME "NAME_FROM_BLYNK_APP"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN_FROM_BLYNK_APP"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char ssid[] = "YOUR_WIFI";
char pass[] = "YOUR_WIFI_PASSWORD";
char auth[] = "BLYNK_AUTH_TOKEN"; //From Blynkk App

Servo myservo;

// -------------------- LOCOMOTION MOTOR CONTROL --------------------
BLYNK_WRITE(V1) // speed
{
  int pinval = param.asInt();
  analogWrite(D2, pinval);
}

BLYNK_WRITE(V2) // forward
{
  int forward = param.asInt();
  digitalWrite(D3, forward);
  digitalWrite(D5, forward);
}

BLYNK_WRITE(V3) // reverse
{
  int reverse = param.asInt();
  digitalWrite(D6, reverse);
  digitalWrite(D4, reverse);
}

BLYNK_WRITE(V4) // right
{
  int right = param.asInt();
  digitalWrite(D5, right);
  digitalWrite(D4, right);
}

BLYNK_WRITE(V5) // left
{
  int left = param.asInt();
  digitalWrite(D3, left);
  digitalWrite(D6, left);
}

// ---------------------- SERVO CONTROL ----------------------
BLYNK_WRITE(V7)
{
  int val = param.asInt();
  if (val == 1)
    myservo.write(90);
  else
    myservo.write(0);
}

// ---------------------- 12V DC MOTOR ----------------------
#define MOTOR2_PIN D1  // IN3 of L298N #2
BLYNK_WRITE(V8)
{
  int motorState = param.asInt();
  digitalWrite(MOTOR2_PIN, motorState);  // HIGH = ON, LOW = OFF
}

// ---------------------- 5V SUBMERSIBLE WATER PUMP ----------------------
#define PUMP_PIN D0  // IN4 of L298N #2
BLYNK_WRITE(V9)
{
  int pumpState = param.asInt();
  digitalWrite(PUMP_PIN, pumpState);  // HIGH = ON, LOW = OFF
}

// ---------------------- SETUP ----------------------
void setup()
{
  Serial.begin(9600);

  // Locomotion motors
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

  // 12V geared motor
  pinMode(MOTOR2_PIN, OUTPUT);
  digitalWrite(MOTOR2_PIN, LOW);

  // 5V submersible pump
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);

  // Servo
  myservo.attach(13);  // D7
  myservo.write(0);

  // Start Blynk
  Blynk.begin(auth, ssid, pass);
}

// ---------------------- LOOP ----------------------
void loop()
{
  Blynk.run();
}
