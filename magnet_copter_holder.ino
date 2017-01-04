int magnets[] = {9, 8};
int input = 4;

const int threshold = 1600;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(57600);
  // initialize the magnet as an output.
  for(int magnet : magnets) {
    pinMode(magnet, OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  int input_value = pulseIn(input, HIGH, 25000);
  Serial.println(input_value);
  delay(100);
  if(input_value >= 900 && input_value <= 2100) { // only proceed for valid values
    if(input_value <= threshold) {
      switch_magnets(LOW);
      Serial.println("LOW");
    }

    else {
      switch_magnets(HIGH);
      Serial.println("HIGH");
    }
  }
}

void switch_magnets(int state) {
  for(int magnet : magnets) {
    digitalWrite(magnet, state);
  }
}
