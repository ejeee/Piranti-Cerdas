// latihan 1 koneksi otomatis 
// #include <WiFi.h>

// const char* ssid = "IYE";
// const char* password = "Moluscaaurelia";

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }

//   Serial.println("Connected to WiFi");
// }

// void loop() {
  
// }

// latihan 2 orientasi gerak
// #include <MPU6050_tockn.h>
// #include <Wire.h>

// MPU6050 mpu6050(Wire);

// void setup() {  
//   Serial.begin(115200);
//   Wire.begin();
//   mpu6050.begin();
//   mpu6050.calcGyroOffsets();
// }

// void loop() {
//   mpu6050.update();
//   Serial.print("Angle X : ");
//   Serial.print(mpu6050.getAngleX());
//   Serial.print(" Angle Y : ");
//   Serial.print(mpu6050.getAngleY());
//   Serial.print(" Angle Z : ");
//   Serial.println(mpu6050.getAngleZ());
//   delay(1000);
// }

// prak kegiatan 1 connect wifi with pass and without pass
#include <WiFi.h>

const char* ssid = "IYE";
const char* password = "Moluscaaurelia";

void setup() {
  Serial.begin(115200);
  connectToWiFi();
}

void loop() {
}

void connectToWiFi() {
  Serial.print("connecting to Wifi... ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Not Connected");
    Serial.println("Trying Connect to OpenSource Network...");
    
    const char* openSsid = "ABC";

    WiFi.begin(openSsid);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Not Connected");
      Serial.println("Trying Connect to OpenSource Network Again...");
    }

    Serial.print("Connected to ");
    Serial.println(openSsid);
  }

  Serial.print("Connected to ");
  Serial.println(ssid);
}

//prak kegiatan 2 buzzer
#include <Wire.h>
#include <MPU6050_tockn.h>
#include <WiFi.h>

MPU6050 mpu6050(Wire);

const char* ssid = "IYE";
const char* password = "Moluscaaurelia";
const int buzzerPin = 13; 
const int angleThreshold = 20; 

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets();
}

void loop() {
  mpu6050.update();
  Serial.print("Angle X: ");
  float angleX = mpu6050.getAngleX();
  Serial.print(angleX);
  Serial.print("\tAngle Y: ");
  float angleY = mpu6050.getAngleY();
  Serial.println(angleY);

  if (abs(angleX) > angleThreshold) {
    tone(buzzerPin, 1000); 
    Serial.println("Tilted to the Right");
  } else if (abs(angleX) < -angleThreshold) {
    tone(buzzerPin, 1500); 
    Serial.println("Tilted to the Left");
  } else if (abs(angleY) > angleThreshold) {
    tone(buzzerPin, 2000); 
    Serial.println("Tilted Forward");
  } else if (abs(angleY) < -angleThreshold) {
    tone(buzzerPin, 2500); 
    Serial.println("Tilted Back");
  } else {
    noTone(buzzerPin); 
  }
  delay(1000);
}
