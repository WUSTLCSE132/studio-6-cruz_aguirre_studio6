const int buttonPin = 2;
int count = 0;
int buttonState;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
//unsigned long currentTime = millis();


void buttonPressed(){
  
  if(digitalRead(buttonPin) != lastButtonState){
    lastDebounceTime = millis();
  }

  if((millis()-lastDebounceTime)>debounceDelay){

    if(digitalRead(buttonPin)!=buttonState){
      buttonState = digitalRead(buttonPin);
    }

    count++;
    Serial.println(count);  
  }

  lastButtonState = digitalRead(buttonPin);
  
  
  
}

void setup(){
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING);
  Serial.begin(9600);
}


void loop(){

  
  
}

