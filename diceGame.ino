// include the library code:
#include <LiquidCrystal.h>
int button_pin = 10;
long dice_one, dice_two;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  pinMode(button_pin, INPUT_PULLUP);
  lcd.begin(16, 2);            // set up the LCD's number of columns and rows:
  lcd.print("Press Button To Roll Dice!");  // Print a message to the LCD.
  lcd.setCursor(0, 1);
  lcd.print("Roll Dice..");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  readButton();
}
void diceRoll() {
  lcd.clear();
  dice_one = random(1, 6);
  dice_two = random(1, 6);
  Serial.println("Dice 1: " + String(dice_one));
  Serial.println("Dice 1: " + String(dice_two));
  lcd.print("Player Dice: " + String(dice_one));
  lcd.setCursor(0, 1);
  lcd.print("Computer Dice: " + String(dice_two));
}

void readButton() {
  if (digitalRead(button_pin) == LOW) {
    delay(1000);
    diceRoll();
  }
}
