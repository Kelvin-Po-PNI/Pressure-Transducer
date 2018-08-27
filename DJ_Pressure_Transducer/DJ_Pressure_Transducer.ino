// Kelvin Po Jul 12, 2018
// For reading two DJ Instruments MOD DF2-SS-02-250-5V Pressure Transducers

#include "Definitions.h"

//Constants
const double RESOLUTION = 1023.0;
const double PTRANGE = 4.0;
const double REFERENCE = 5.0;
const int delayTime = 150;
double maxPSI = 250.0;
// double m = maxPSI*((PTRANGE/REFERENCE)*RESOLUTION);
double m1 = 70.166;
double b1 = -30.662;
double m2 = 71.429;
double b2 = -35.714;

//Pressure variables
double readVal1;
double readVal2;
double pressure1;
double pressure2;
double voltage1;
double voltage2;


void setup()
{

	pinMode(analogPin1, INPUT); //Pressure transducer 1
	pinMode(analogPin2, INPUT); //Pressure transducer 2
	pinMode(testLEDPin, OUTPUT);

  //ground other analog input to minimze interference
	  for (int i = A2; i <= A15; i++) {
	  pinMode(i, OUTPUT); 
	  digitalWrite(i, LOW);

	}
	Serial.begin(9600);
}

void loop()
{
	readVal1 = analogRead(analogPin1);
	readVal2 = analogRead(analogPin2);
	voltage1 = readVal1*REFERENCE/RESOLUTION;
	voltage2 = readVal2*REFERENCE/RESOLUTION;

	//For troubleshooting
		// Serial.print("read: ");
		// Serial.print(readVal1);
		// Serial.print(", ");
		// Serial.print(readVal2);
		// Serial.print(", voltage: ");	
		// Serial.print(voltage1);
		// Serial.print(", ");
		// Serial.print(voltage2);
	
	pressure1 = voltage1*m1 + b1;
	pressure2 = voltage2*m2 + b2;

	Serial.print(pressure1);
	Serial.print(", PSI, ");
	Serial.print(pressure2);
	Serial.println(" PSI");
	digitalWrite(testLEDPin, HIGH);
	delay(delayTime);
	digitalWrite(testLEDPin, LOW);
	delay(delayTime);

}

