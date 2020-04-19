#include <DHT.h>
#include <DHT_U.h>
#include <IRremote.h>

#define DHTPIN A7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

    int R1 = 22;
    int G1 = 23;
    int buzzer = 24;

    int Flame1 = A0 ;

    int R2 = 27;
    int G2 = 28;
    int Flame2 = A1;

    int R3 = 29;
    int G3 = 30;
    int Flame3 = A2;

    int R4 = 31;
    int G4 = 32;
    int Flame4 = A3;

    int R5 = 33;
    int G5 = 34;
    int Flame5 = A4;
    
    int sensorThreshold = 150;

    
    int ResetButton = 53;
    int PushOrPull = 0;

    int SoilMoisture = A5;


    int WaterLevel = A6;

    int RedPool = 37;
    int YellowPool = 38;
    int GreenPool = 39;


    int HeaterLight = 41;

    int Reciver = 42;
    #define code1 16724175    // code received from button no. 1
    #define code2 16718055    // code received from button no. 2
    #define code3 16743045    // code received from button no. 3
    #define code4 16716015    // code received from button no. 4
    IRrecv irrecv(Reciver);
    decode_results results;
//  int relay1 = 2;
//  int relayState[] = {0,0,0,0,0};

     int PIR = 43;  

     // lowest and highest sensor readings:
     const int sensorMin = 0;     // sensor minimum
     const int sensorMax = 1024;  // sensor maximum
     int RainDetector = A8;

     int TouchSensor = 44;

    int pump = 25;
    int RelayElectricitySource = 26;
    int RelayAC = 40;
    int RelayPoolWaterFlow = 36;
    int RelayWaterFlow = 35;
    int RelayLEDLivingRoom = 45;
    int RelayLEDKitchen = 46;
    int RelayLEDGarage = 47;
    int RelayLEDBathroom = 48;
    int RelayLEDBedroom = 49;
    int RelayLEDAttic = 50;
    int RelayLEDBalcony = 51;
    int RelayLEDOutside = 52;
    int RelayFanAttic = 53;
    int RelayFanKitchen = 2;

    int in1A = 3;
    int in2A = 4;
    int SpeedMainEntranceDoor = 5;
    
    int in3A = 6;
    int in4A = 7;
    int SpeedMainDoor = 8;
    
    int in1B = 9;
    int in2B = 10;
    int SpeedGarageDoor = 11;
    
    int in3B = 12;
    int in4B = 13;
    int SpeedPoolDoor = 14;


    int SmokeSensor = A9;

    int GasSensor = A10;

    int ServoLivingRoom = 15;
    int ServoKitchen = 16;
    int ServoBedroom = 17;
    int ServoBathroom = 18;

    int IRGarage1 = 19;
    int IRGarage2 = 20;
    int IRMainEntrance1 = 21;
  //  int IRMainEntrance2 = 22;

  //  int PhotocellSensor = 23;

  //   int RFID = 24,25,26,27,28,29,30;

 //    int Steppier = 31,32,33,34;
  
                

void setup() 
{
    Serial.begin(9600);
    
    irrecv.enableIRIn();
    
    pinMode(G1, OUTPUT);
    pinMode(R1, OUTPUT);
    
    pinMode(G2, OUTPUT);
    pinMode(R2, OUTPUT);
    
    pinMode(G3, OUTPUT);
    pinMode(R3, OUTPUT);
    
    pinMode(G4, OUTPUT);
    pinMode(R4, OUTPUT);
    
    pinMode(G5, OUTPUT);
    pinMode(R5, OUTPUT);

    pinMode(RedPool, OUTPUT);
    pinMode(YellowPool,OUTPUT);
    pinMode(GreenPool,OUTPUT);
    
    pinMode(buzzer, OUTPUT);
    
    pinMode(RelayElectricitySource, OUTPUT);
    pinMode(pump, OUTPUT);
    pinMode(RelayWaterFlow,OUTPUT);
    pinMode(RelayPoolWaterFlow,OUTPUT);
    pinMode(RelayFanKitchen,OUTPUT);
    
    pinMode(ResetButton, INPUT);
    
    pinMode(Flame1, INPUT) ;
    pinMode(Flame2, INPUT) ;
    pinMode(Flame3, INPUT) ;
    pinMode(Flame4, INPUT) ;
    pinMode(Flame5, INPUT) ;

    pinMode(RelayAC, OUTPUT);
    pinMode(HeaterLight, OUTPUT);

    pinMode(PIR, INPUT);

    pinMode(RainDetector, INPUT);

    pinMode(TouchSensor, INPUT);

    pinMode(in1A,OUTPUT);
    pinMode(in2A,OUTPUT);
    pinMode(SpeedMainEntranceDoor,OUTPUT);
    pinMode(in3A,OUTPUT);
    pinMode(in4A,OUTPUT);
    pinMode(SpeedMainDoor,OUTPUT);
    pinMode(in1B,OUTPUT);
    pinMode(in2B,OUTPUT);
    pinMode(SpeedGarageDoor,OUTPUT);
    pinMode(in3B,OUTPUT);
    pinMode(in4B,OUTPUT);
    pinMode(SpeedPoolDoor,OUTPUT);

    pinMode(SmokeSensor, INPUT);

    pinMode(GasSensor, INPUT);
    
    dht.begin();
    digitalWrite(RelayAC, LOW);
    digitalWrite(HeaterLight, LOW);
    
    digitalWrite(G1, HIGH);
    digitalWrite(G2, HIGH);
    digitalWrite(G3, HIGH);
    digitalWrite(G4, HIGH);
    digitalWrite(G5, HIGH);
    
    digitalWrite(RelayElectricitySource, HIGH);
    digitalWrite(pump, LOW);
    digitalWrite(RelayWaterFlow, LOW);
    digitalWrite(RelayPoolWaterFlow, LOW);
    pinMode(RelayFanKitchen,LOW);

    pinMode(in1A,LOW);
    pinMode(in2A,LOW);
    pinMode(SpeedMainEntranceDoor,LOW);
    pinMode(in3A,LOW);
    pinMode(in4A,LOW);
    pinMode(SpeedMainDoor,LOW);
    pinMode(in1B,LOW);
    pinMode(in2B,LOW);
    pinMode(SpeedGarageDoor,LOW);
    pinMode(in3B,LOW);
    pinMode(in4B,LOW);
    pinMode(SpeedPoolDoor,LOW);

}

void loop() {

    int DigitalFlame1 = analogRead(Flame1);
    int DigitalFlame2 = analogRead(Flame2);
    int DigitalFlame3 = analogRead(Flame3);
    int DigitalFlame4 = analogRead(Flame4);
    int DigitalFlame5 = analogRead(Flame5);
    
    PushOrPull = digitalRead(ResetButton);

    int AnalogRainDetector = analogRead(RainDetector);
    int range = map(AnalogRainDetector, sensorMin, sensorMax, 0, 3);

    int AnalogSmokeSensor = analogRead(SmokeSensor);
    int AnalogGasSensor = analogRead(GasSensor);

/*---------- Gas Leak System ----------*/
if ( AnalogGasSensor < sensorThreshold )
{
    digitalWrite(buzzer,HIGH);
    digitalWrite(RelayFanKitchen,HIGH);
}

/*---------- Smoke System ----------*/
if ( AnalogSmokeSensor < sensorThreshold )
{
    digitalWrite(buzzer,HIGH);
}
   
/*---------- Fire System ----------*/   
if ( DigitalFlame1 < sensorThreshold )
{
    
    digitalWrite(R1, HIGH);
    digitalWrite(G1, LOW);
    digitalWrite(buzzer,HIGH);

    digitalWrite(RelayElectricitySource, LOW);
    digitalWrite(pump, HIGH);
}
else
{
  if( DigitalFlame2 < sensorThreshold)
  {
    digitalWrite(R2, HIGH);
    digitalWrite(G2, LOW);
    digitalWrite(buzzer,HIGH);

    digitalWrite(RelayElectricitySource, LOW);
    digitalWrite(pump, HIGH);
  }
  else
  {
    if(DigitalFlame3 < sensorThreshold)
    {
     digitalWrite(R3, HIGH);
     digitalWrite(G3, LOW);
     digitalWrite(buzzer,HIGH);

     digitalWrite(RelayElectricitySource, LOW);
     digitalWrite(pump, HIGH);
    }
    else
    {
      if(DigitalFlame4 < sensorThreshold)
      {
       digitalWrite(R4, HIGH);
       digitalWrite(G4, LOW);
       digitalWrite(buzzer,HIGH);

       digitalWrite(RelayElectricitySource, LOW);
       digitalWrite(pump, HIGH);
      }
      else
      {
        if(DigitalFlame5 < sensorThreshold)
        {
         digitalWrite(R5, HIGH);
         digitalWrite(G5, LOW);
         digitalWrite(buzzer,HIGH);

         digitalWrite(RelayElectricitySource, LOW);
         digitalWrite(pump, HIGH);
        }
        else
        {
          digitalWrite(pump, LOW);
        }
      }
    }
  }
}

if(PushOrPull == HIGH)
{
    
    digitalWrite(RelayElectricitySource, HIGH);
    
    digitalWrite(R1, LOW);
    digitalWrite(G1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(G2, HIGH);
    digitalWrite(R3, LOW);
    digitalWrite(G3 , HIGH);
    digitalWrite(R4, LOW);
    digitalWrite(G4, HIGH);
    digitalWrite(R5, LOW);
    digitalWrite(G5 , HIGH);
    
}

/*---------- Irrigation System ----------*/
if (SoilMoisture > 50)
  {                
    digitalWrite(RelayWaterFlow, HIGH);
  }
  else 
  {       
    digitalWrite(RelayWaterFlow, LOW);          
  }

/*---------- Water Level System ----------*/
if(analogRead(A5)<25)
{
   Serial.println("Water Level: Empty");
   Serial.println(analogRead(A5));
   digitalWrite (RedPool,LOW);
   digitalWrite(YellowPool,LOW);
   digitalWrite(GreenPool,LOW);
   digitalWrite(RelayPoolWaterFlow, HIGH);
}
else
{
  if(analogRead(A5) > 25 && analogRead(A5) <=275)
  {
    Serial.println("Water Level: Low");
    Serial.println(analogRead(A5));
    digitalWrite (RedPool,LOW);
    digitalWrite(YellowPool,LOW);
    digitalWrite(GreenPool,HIGH);
    digitalWrite(RelayPoolWaterFlow, HIGH);
  }
  else
  {
    if(analogRead(A5) > 275 && analogRead(A5) <=330)
    {
      Serial.println("Water Level: Medium");
      Serial.println(analogRead(A5));
      digitalWrite (RedPool,LOW);
      digitalWrite(YellowPool,HIGH);
      digitalWrite(GreenPool,LOW);
      digitalWrite(RelayPoolWaterFlow, HIGH);
    }
    else
    {
      if(analogRead(A5) > 330)
      {
        Serial.println("Water Level: High");
        Serial.println(analogRead(A5));
        digitalWrite (RedPool,HIGH);
        digitalWrite(YellowPool,LOW);
        digitalWrite(GreenPool,LOW);
        digitalWrite(RelayPoolWaterFlow, LOW);
      }
    }
  }
}

/*---------- Cooling & Heating System ----------*/
   float h = dht.readHumidity();
   // Reading temperature or humidity takes about 250 milliseconds!
   float t = dht.readTemperature();
   // Read temperature as Celsius (the default)
   float f = dht.readTemperature(true);

   if (t >=25 && t<=30)
  {
      Serial.print("Temperature: ");
      Serial.print(t);
      digitalWrite(RelayAC, LOW);
      digitalWrite(HeaterLight, LOW);
    
  }
  else
  {
    if(t<25)
    {
       Serial.print("Temp: ");
       Serial.print(t);
       digitalWrite(RelayAC, LOW);
       digitalWrite(HeaterLight, HIGH);
    }
    else
    {
      if(t>31)
      {
       Serial.print("TEMP: ");
       Serial.print(t);
       digitalWrite(RelayAC, HIGH);
       digitalWrite(HeaterLight, LOW);
      }
    }
  }

/*---------- IR Remote Control ----------*/
/*  if (irrecv.decode(&results))
  {
   unsigned int value = results.value;
   switch(value)
   {
     case code1:
     if(relayState[1] == 0)
     {
       //digitalWrite(relay1, HIGH); // turn it off when button is pressed
       //relayState[1] = 1; // and set its state as off
     } 
     else
     {
      // digitalWrite(relay1, LOW); // turn it on when the button is pressed
      // relayState[1] = 0; // and set its state as on
     }
     break;
   }
     irrecv.resume(); // Receive the next value
}
*/

/*---------- Motion Detector Lights ----------*/
 if (digitalRead(PIR) == HIGH) { // check if the sensor is HIGH
    Serial.println("Motion detected!"); 
    delay(100);                   // delay 100 milliseconds 
  } 
  else {
    Serial.println("Motion stopped!");
    delay(100);                   // delay 100 milliseconds
  }

/*---------- Rain Detection ----------*/
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Flood");
    break;
 case 1:    // Sensor getting wet
    Serial.println("Rain Warning");
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.println("Not Raining");
    break;
  }
  delay(1);  // delay between reads
  
/*---------- Touch Sensor ----------*/
  if (digitalRead(2) == HIGH)
  {
      Serial.println("Sensor is touched");
  }
  else
  {
      Serial.println("Sensor is not touched");
  }
  delay(500);

/*----------  ----------*/

delay(1000);

}

/*---------- Motor Driver A ----------*/
void MainEntranceDoorRight(){
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  analogWrite(SpeedMainEntranceDoor,100);
}
void MainEntranceDoorLeft(){
  digitalWrite(in1A,LOW);
  digitalWrite(in2A,HIGH);
  analogWrite(SpeedMainEntranceDoor,100);
}
void MainEntranceDoorOff(){
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  analogWrite(SpeedMainEntranceDoor,0);
}
void MainDoorRight(){
  digitalWrite(in3A, HIGH);
  digitalWrite(in4A, LOW);
  analogWrite(SpeedMainDoor,100);
}
void MainDoorLeft(){
  digitalWrite(in3A,LOW);
  digitalWrite(in4A,HIGH);
  analogWrite(SpeedMainDoor,100);
}
void MainDoorOff(){
  digitalWrite(in3A, LOW);
  digitalWrite(in4A, LOW);
  analogWrite(SpeedMainDoor,0);
}

/*---------- Motor Driver B ----------*/
void GarageDoorUp(){
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  analogWrite(SpeedGarageDoor,100);
}
void GarageDoorDown(){
  digitalWrite(in1B,LOW);
  digitalWrite(in2B,HIGH);
  analogWrite(SpeedGarageDoor,100);
}
void GarageDoorOff(){
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
  analogWrite(SpeedGarageDoor,0);
}
void PoolDoorFront(){
  digitalWrite(in3B, HIGH);
  digitalWrite(in4B, LOW);
  analogWrite(SpeedPoolDoor,100);
}
void PoolDoorBack(){
  digitalWrite(in3B,LOW);
  digitalWrite(in4B,HIGH);
  analogWrite(SpeedPoolDoor,100);
}
void PoolDoorOff(){
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, LOW);
  analogWrite(SpeedPoolDoor,0);
}
