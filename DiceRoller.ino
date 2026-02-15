const int buttonPin = 2;

const int greenLED = 9;
const int redLED = 8;

const int dispArr[] = { 13, 12, 11, 10, 7, 6, 5, 4 };

const int numArr[7][8] = {
  { 1, 0, 0, 0, 0, 0, 1, 0 },
  { 1, 1, 0, 1, 1, 1, 0, 0 },
  { 1, 1, 0, 1, 0, 1, 1, 0 },
  { 1, 0, 1, 1, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 0, 1, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};



void numDisp(int diceNum) {
  if (diceNum < 1 || diceNum > 7) {
    Serial.println("Dice Number Error");
  } else {
    int diceIndex = diceNum - 1;
    for (int i = 0; i < 8; i += 1) {
      digitalWrite(dispArr[i], numArr[diceIndex][i]);
    }
  }
}

void rollAnimation(int x) {
  for (int j = 0; j < x; j++) {
    for (int i = 0; i < 7; i++) {
      if (dispArr[i] == 10) {
        continue;
      } else {
        digitalWrite(dispArr[i], HIGH);
        delay(100);
        digitalWrite(dispArr[i], LOW);
      }
    }
  }
}

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(dispArr[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {

  bool buttonState = !digitalRead(buttonPin);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);


  if (buttonState == HIGH) {

    numDisp(7);

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    Serial.println("Rolling...");

    int roll = random(1, 7);

    //delay(1000);

    rollAnimation(3);

    numDisp(roll);

    Serial.print("Your Roll is: ");
    Serial.println(roll);

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);


    delay(1000);
  }
}

