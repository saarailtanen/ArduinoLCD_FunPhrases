#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int previousSwitchState = 0;
int phrase;
//in these im saving the pharses
String currentPhrase;
String paddedPhrase;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  //welcome text
  lcd.print("hi! press button");
  lcd.setCursor(0,1);
}

void loop() {
  switchState = digitalRead(switchPin);
  
  //this detects when the button is pressed
  if (switchState != previousSwitchState) {
    if (switchState == LOW) {
      //random selects a random pharse
      phrase = random(5);
      
      //pharses
      switch (phrase) {
        case 0:
          currentPhrase = "today is going to be good";
          break;
        case 1:
          currentPhrase = "moominlimonade <3";
          break;
        case 2:
          currentPhrase = "have a great school day!";
          break;
        case 3:
          currentPhrase = "<3 <3 <3 <3 <3";
          break;
        case 4:
          currentPhrase = "vaikka ei jaksa ni koittakaa vaa jaksaa";
          break;
      }

      //this adds a couple of spaces because it is easier to read
      paddedPhrase = "   " + currentPhrase;

      //clearing the lcd screen
      lcd.clear();
      
      //new phrase
      lcd.setCursor(0, 0);
      lcd.print(paddedPhrase);

      //calculates the length of the phrase with spaces
      int phraseLength = paddedPhrase.length();
      
      //scrolls the phrase thourgh the screen 
      for (int positionCounter = 0; positionCounter < 16 + phraseLength; positionCounter++) {
        lcd.scrollDisplayLeft();
        delay(150);
      }
    }
    
    //updates the previous state
    previousSwitchState = switchState;
  }
}

