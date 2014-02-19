int ledpin = 13;
int beat_led = 10, beat_delta = 5;
int bpm_min = 60, bpm_max = 180, bpm = 0;

void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  bpm = random(bpm_min, bpm_max);
}

void loop() {
  //change beat freq
  bpm += random(-beat_delta, beat_delta);
  if(bpm > bpm_max) {
    bpm = bpm_max;
  } 
  else if(bpm < bpm_min) {
    bpm = bpm_min;
  }

  //write to serial
  Serial.println(bpm);
  Serial.flush();

  //beat!
  flashLed(beat_led);

  //wait for the next beat
  delay((60000/bpm)-beat_led);
}

void flashLed(int time) {
  digitalWrite(ledpin, HIGH);
  delay(time);
  digitalWrite(ledpin, LOW);
}

