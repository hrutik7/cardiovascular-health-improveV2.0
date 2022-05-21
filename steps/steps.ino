
const int xpin = A1;
const int ypin = A2;
const int zpin = A3;
int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor
  int breath_count = 0;

int steps, flag = 0;
void setup()
{
  Serial.begin(9600);
 


}
void loop()
{
 int x = analogRead(xpin);
    int y = analogRead(ypin);
    int sensorValue = analogRead(sensorPin);
 
  if( sensorValue > 285 ){
    breath_count += 1;
    Serial.println(String(breath_count) + ": breath");
    delay(360);
    }

if(x <= 450 && y >= 390){
    steps++;
    delay(100);
  }

if(x >= 460 && y <= 370){
    steps++;
    delay(100);
  }

Serial.println(steps);

}
