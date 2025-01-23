int ledPins[] = {2, 3, 4, 5, 6, 7};
int flexSignal;

void setup() {
 
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(9600); 
}

void loop() {
  flexSignal = analogRead(A0); 
  Serial.println(flexSignal); 

  
  if (flexSignal > 409) {
    lightLed(0); 
  } else if (flexSignal > 359) {
    lightLed(1); 
  } else if (flexSignal > 300) {
    lightLed(2); 
  } else if (flexSignal > 250) {
    lightLed(3); 
  } else if (flexSignal > 200) {
    lightLed(4); 
  } else {
    lightLed(5); 
  }

  delay(50); 


void lightLed(int ledIndex) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPins[i], i == ledIndex ? HIGH : LOW);
  }
}
