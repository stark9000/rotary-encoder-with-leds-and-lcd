#include  <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);

#define DT A0
#define CLK A1

int COUNTER = 0;
int PREVIOUS_STATE;
int CURRENT_STATE;
int LED_STATE = 0;

void setup() {
  pinMode (DT, INPUT);
  pinMode (CLK, INPUT);
  Serial.begin (9600);
  lcd.begin();
  CURRENT_STATE = digitalRead(DT);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  PREVIOUS_STATE = digitalRead(DT);
  if (PREVIOUS_STATE != CURRENT_STATE) {
    if (digitalRead(CLK) != PREVIOUS_STATE) {
      if (COUNTER < 100) {
        COUNTER ++;
        lcd.clear();
      }
    } else {
      if (COUNTER > 0) {
        COUNTER --;
        lcd.clear();
      }
    }


    LED_STATE = map(COUNTER, 1, 100, 0, 8);
    switch (LED_STATE) {
      case 0: digitalWrite(5, LOW);
        break;
      case 1: digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        break;
      case 2: digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        break;
      case 3: digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        break;
      case 4: digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        break;
      case 5: digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        break;
      case 6: digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        break;
      case 7: digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        break;
      case 8: digitalWrite(12, HIGH);
        break;
    }

    Serial.print("Position: ");
    Serial.println(COUNTER);
    lcd.setCursor(0, 0);
    lcd.print("Position: ");
    lcd.setCursor(10, 0);
    lcd.print(COUNTER);

  }
  CURRENT_STATE = PREVIOUS_STATE;
}
