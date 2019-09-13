int Ultrasonic_trigPin = 9;
int Ultrasonic_echoPin = 10;
int Ultrasonic_led = 13;
int Ultrasonic_l = 0;

int pir_led = 11;
int pir_pin = 2;

int pir_value = 0;
int pir_State = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(Ultrasonic_led, OUTPUT);
  pinMode(Ultrasonic_trigPin, OUTPUT);
  pinMode(Ultrasonic_echoPin, INPUT);
  pinMode(pir_led, OUTPUT);
  pinMode(pir_pin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  pir_value = digitalRead(pir_pin);

  if (pir_value == HIGH) {
    digitalWrite(pir_led, HIGH);

    if (pir_State == LOW) {
      Serial.println("pir                                     Motion Detected!");
      pir_State = HIGH;
    }
  } else {
    digitalWrite(pir_led, LOW);

    if (pir_State == HIGH) {
      Serial.println("pir                                       Motion Ended!");
      pir_State = LOW;
    }

  }



  long duration, distance;
  digitalWrite(Ultrasonic_trigPin, HIGH);
  delayMicroseconds(10000000);
  digitalWrite(Ultrasonic_trigPin, LOW);
  duration = pulseIn(Ultrasonic_echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (Ultrasonic_l == distance) {

    Serial.println("none detected");


  }
  else {
    Serial.println("intrusion detected");

    Serial.print(distance);
    Serial.println("CM");
  }
  delay(100);
  Ultrasonic_l = distance;

  if ((distance <= 20))
  {
    digitalWrite(Ultrasonic_led, HIGH);
  }
  else if (distance > 20)
  {
    digitalWrite(Ultrasonic_led, LOW);
  }
}
