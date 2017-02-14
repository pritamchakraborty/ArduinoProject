int ledPin1 = 13;
int ledPin2 = 4;
unsigned int buttonPress1 = 8;
unsigned int buttonPress2 = 7;
int lastKnownButtonState1 = LOW;
int lastKnownButtonState2 = LOW;
long ledStatechange1 = 0;
long ledStatechange2 = 0;
long currentTimeOfLed1 = 0;
long currentTimeOfLed2 = 0;
int LedTimeDelay1 = 1000;
int LedTimeDelay2 = 2000;

unsigned long lastTimeButtonChanged1 = 0;
unsigned long lastTimeButtonChanged2 = 0;
unsigned int debounceDelay = 50;
int buttonState1 = LOW;
int buttonState2 = LOW;
int blinkMode1 = LOW;
int blinkMode2 = LOW;
int ledState1 = LOW;
int ledState2 = LOW;


void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPress1, INPUT);
  pinMode(buttonPress2, INPUT);
}

void loop() {
  unsigned int buttonValue1 = digitalRead(buttonPress1);
  unsigned int buttonValue2 = digitalRead(buttonPress2);

 if (buttonValue1 != lastKnownButtonState1) {
  
  lastTimeButtonChanged1 = millis();
 }
  
  if ((millis() - lastTimeButtonChanged1) > debounceDelay) {
  // whatever the reading is at, it's been there for longer
  // than the debounce delay, so take it as the actual current state:

  // if the button state has changed:

  if (buttonValue1 != buttonState1) {
    // Record the new button state.
    buttonState1 = buttonValue1;

    // only toggle the LED if the new button state is HIGH
    if (buttonState1 == HIGH) {
      blinkMode1 = !blinkMode1;
      }
    }
  }
      if(blinkMode1)
      {
        currentTimeOfLed1 = millis();

        if((currentTimeOfLed1 - ledStatechange1)>= LedTimeDelay1){
          ledState1 = !ledState1;

          ledStatechange1 = currentTimeOfLed1;
          digitalWrite(ledPin1, ledState1);
          
        }
      
      } 
      else
      {
       digitalWrite(ledPin1, LOW);      
      }
      
 
  
  if (buttonValue2 != lastKnownButtonState2) {
  
  lastTimeButtonChanged2 = millis();
 }
  
  if ((millis() - lastTimeButtonChanged2) > debounceDelay) {
  // whatever the reading is at, it's been there for longer
  // than the debounce delay, so take it as the actual current state:

  // if the button state has changed:

  if (buttonValue2 != buttonState2) {
    // Record the new button state.
    buttonState2 = buttonValue2;

    // only toggle the LED if the new button state is HIGH
    if (buttonState2 == HIGH) {
      blinkMode2 = !blinkMode2;
      }
    }
  }
     
     if(blinkMode2)
     {
      currentTimeOfLed2 = millis();

        if((currentTimeOfLed2 - ledStatechange2)>= LedTimeDelay2){
          ledState2 = !ledState2;

          ledStatechange2 = currentTimeOfLed2;
          digitalWrite(ledPin2, ledState2);
     }
 
     }
     else
      {
       digitalWrite(ledPin2, LOW);      
      }     
  lastKnownButtonState1 = buttonValue1;
  lastKnownButtonState2 = buttonValue2;
  
}