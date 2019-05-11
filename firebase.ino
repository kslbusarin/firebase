#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Config Firebase
#define FIREBASE_HOST "......"
#define FIREBASE_AUTH "......"

// Config connect WiFi
#define WIFI_SSID "......."
#define WIFI_PASSWORD "......."

int i;
int all;
int trigPin1=D1;
int echoPin1=D2;
int trigPin2=D3;
int echoPin2=D4;
int trigPin3=D5;
int echoPin3=D6;
int trigPin4=D7;
int echoPin4=D8;
long duration1,distance1,duration2,distance2,duration3,distance3,duration4,distance4;

void setup() {
  Serial.begin(115200);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  i = 0;
  all = 4;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  if (distance1 < 7) {
    i++;
    Serial.print("building_a1 ");
    Serial.println(distance1);
    Firebase.setString("building_a/a07", "busy");
    if (Firebase.failed()) {
      Serial.print("set building_a/a07 failed: ");
      Serial.println(Firebase.error());
      return;
    }
  } else {
    Serial.print("building_a7 ");
    Serial.println(distance1);
    Firebase.setString("building_a/a07", "empty");
    if (Firebase.failed()) {
      Serial.print("set building_a/a07 failed: ");
      Serial.println(Firebase.error());
      return;
    }
  }
  delay(500);

  
 digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  if (distance2 < 7) {
    i++;
    Serial.print("building_a1 ");
    Serial.println(distance2);
    Firebase.setString("building_a/a08", "busy");
    if (Firebase.failed()) {
      Serial.print("set building_a/a08 failed: ");
      Serial.println(Firebase.error());
      return;
    }
  } else {
    Serial.print("building_a1 ");
    Serial.println(distance2);
    Firebase.setString("building_a/a08", "empty");
    if (Firebase.failed()) {
      Serial.print("set building_a/a08 failed: ");
      Serial.println(Firebase.error());
      return;     
    }
  }
  delay(500);

  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3/2) / 29.1;
  if (distance3 < 7) {
    i++;
    Serial.print("building_a1 ");
    Serial.println(distance3);
    Firebase.setString("building_a/a09", "busy");
    if (Firebase.failed()) {
      Serial.print("set building_a/a09 failed: ");
      Serial.println(Firebase.error());
      return;
    }
  } else {
    Serial.print("building_a1 ");
    Serial.println(distance3);
    Firebase.setString("building_a/a09", "empty");
    if (Firebase.failed()) {
      Serial.print("set building_a/a09 failed: ");
      Serial.println(Firebase.error());
      return;     
    }
  }
  delay(500);

  digitalWrite(trigPin4, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = (duration4/2) / 29.1;
  if (distance4 < 7) {
    i++;
    Serial.print("building_a1 ");
    Serial.println(distance4);
    Firebase.setString("building_a/a10", "busy");
    if (Firebase.failed()) {
      Serial.print("set building_a/a10 failed: ");
      Serial.println(Firebase.error());
      return;
    }
  } else {
    Serial.print("building_a1 ");
    Serial.println(distance4);
    Firebase.setString("building_a/a10", "empty");
    if (Firebase.failed()) {
      Serial.print("set building_a/a10 failed: ");
      Serial.println(Firebase.error());
      return;     
    }
  }
  delay(500);

  if(i == 4){
    Firebase.setString("building_a/a00", "Not Available"); }
  else{Firebase.setString("building_a/a00", "Available");}
all = all - i;
Firebase.setInt("building_a/a01",all);
  
}
