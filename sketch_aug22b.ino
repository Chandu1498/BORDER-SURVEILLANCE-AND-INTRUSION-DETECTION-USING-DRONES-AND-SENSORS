int trigPin = 9;
int echoPin = 10;
int led = 13;

int l = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println("l is" );
  Serial.println(l);
  if (l == distance) {
    Serial.println("none detected");

  }
  else {
    Serial.println("intrusion detected");

    Serial.print(distance);
    Serial.println("CM away");

  }

  delay(100);
  l = distance;


  if ((distance <= 10))
  {
    digitalWrite(led, HIGH);
  }
  else if (distance > 10)
  {
    digitalWrite(led, LOW);
  }
}
