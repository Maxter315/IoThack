// for the door

const int buttonPin = 2;     
int buttonState = 0;  

//photo resistor 
int LDR = 0;

// for humidity 
#include <dht.h>
dht DHT;
#define DHT11_PIN 8


void setup () 
{
  // humidity 
  
  // for the humidty loop 
  Serial.begin(115200);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
   // photo resistor : 
  pinMode(LDR, INPUT);
  // for the door 
  pinMode(buttonPin, INPUT); 
  
}

void loop () 
{
  // for the humidity loop : 
  
   // READ DATA
  //Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  /*switch (chk)
  {
    case DHTLIB_OK:  
                Serial.print("OK,\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
  }
  */
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.print(DHT.temperature, 1);

  //delay(1000);
  
  // for the photo resistor : 
  
  int v = analogRead(LDR);
  //Serial.print("the photo resistor reading : ") ; 
   //Serial.println(v);
   //delay(1000);
   
   // for the button loop 
   
     buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     
     
    //Serial.print("\nthe door is closed\n ");
  } 
  else {
    //Serial.print(" \nWATCH OUT !!!\n ");
    
  }
 Serial.print(",\t");
 Serial.print(v);
 Serial.print(",\t");
 Serial.println(buttonState);
 delay(5000);
 
 
 // Sending the data to C# application through the port : :  
 
   
  
}

