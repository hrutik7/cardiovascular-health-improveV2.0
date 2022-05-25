

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
int Breathe = 0;
int stepcount = 0; 
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int buttonPin = 22;
const int buttonPin_1 = 23;
// variables will change:
int buttonState = 0; 
int buttonState_1 = 0; 
int i = 1;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
 pinMode(buttonPin_1, INPUT);
 
}

void loop() {
  
    display.setTextColor(WHITE); // 'inverted' text
  display.setCursor(0,0);
  display.clearDisplay();
display.println("Hit Start");

int intensity = analogRead(A4);
Serial.println(intensity);

buttonState = digitalRead(buttonPin);
buttonState_1 = digitalRead(buttonPin_1);
Serial.println(buttonState_1);
if(buttonState){

  if(intensity<350){
    low();
    }else if(intensity < 700){
      low();
      }else{
        low();
        }
  
}

 
}

void low(){
  
  
      buttonState = digitalRead(buttonPin);
buttonState_1 = digitalRead(buttonPin_1);
for(;;){
  int sound_input = analogRead(A0);
  int x = analogRead(A1);
  int y = analogRead(A3);
  int z = analogRead(A2);
  
  display.setTextColor(WHITE); // 'inverted' text
  display.setCursor(0,0);
  if(sound_input > 260){
  Breathe++;
   //Serial.println("breath :" + String(Breathe)); 
  }
  Serial.println("x :" +  String(x)); 
  Serial.println("y :" +  String(y)); 
   Serial.println("z :" +  String(z)); 
   Serial.println("soundInput :" + String(sound_input));
 delay(200);

    if ( x <= 409 && y<=340 ){
    Serial.println("forward step");
     stepcount = stepcount + 1 ;
     delay(100);
      
    }

    
    if ( x <= 405 && y>=345){

Serial.println("backward step");
     stepcount = stepcount + 1 ;
          delay(100);

      
    }
   display.println("stepcount  :" + String(stepcount));
   display.println("Breathe :" + String(Breathe));
//   Serial.println("stepcount  :" + String(stepcount));
   
  display.display();
  
  display.clearDisplay();
   if(buttonState_1){
    

  
 
  display.display();
    break;
    }
    
    }
  return ;
 }


 void medium(){
  buttonState_1 = digitalRead(buttonPin_1);
  for(;;){
  Serial.println("In medium");
  if(buttonState_1){

    break;
    }
  }

  return;
  }

  void high(){
     for(;;){
  Serial.println("In High");
  if(buttonState_1){

    break;
    }
  }

  return;
    }
