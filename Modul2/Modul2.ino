// latihan 1 sensor cahaya
#define LIGHT 32
void setup(){
  Serial.begin(9600);
}

void loop(){
  int analogValue = analogRead(LIGHT);
  Serial.print("Analog Value= ");
  Serial.print(analogValue);
  Serial.print("");
}

// latihan 2 buzzer
#define LED 2
#define BUZZER 13

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  digitalWrite(LED,HIGH);
  digitalWrite(BUZZER,HIGH);
  delay(100);
  digitalWrite(LED,LOW);
  digitalWrite(BUZZER,LOW);
  delay(100);
}


// prak kegiatan 1 led gelap, redup, terang
#define LDR 34
#define LED 5

void setup() {
  // Inisialisasi komunikasi serial untuk debugging
  Serial.begin(9600);
  
  // Set pin LED sebagai output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Membaca nilai dari sensor cahaya (LDR)
  int val = analogRead(LDR);
  Serial.print("Value: ");
  Serial.println(val);
  
  if (val < 500) {
    analogWrite(LED, 0); // Gelap
    Serial.println("Lampu Mati");
  } else if (val >= 500 && val < 1000) {
    analogWrite(LED, 100); // Redup
    Serial.println("Lampu Redup");
  } else if (val >= 1000) {
    analogWrite(LED, 255); // Terang
    Serial.println("Lampu Terang");
  } else {
    // digitalWrite(LED, LOW);
  }
  
  delay(1000); 
}


// prak kegiatan 2 buzzer mati=terang, bunyi=gelap
#define BUZZER 13  // Misalkan buzzer terhubung ke pin GPIO 5

#define LDR 34 // Pin digital yang terhubung ke sensor LDR

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = digitalRead(LDR);

  if (ldrValue == LOW) {
    digitalWrite(BUZZER, LOW); // Buzzer Mati
    Serial.println("TERANG");
  } else {
    digitalWrite(BUZZER, HIGH); // Buzzer Bersuara
    Serial.println("GELAP");
  }

  delay(1000);
}
