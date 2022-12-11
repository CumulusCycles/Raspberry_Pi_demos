// Vars for Pins
int LED  = 13;
int Trig = 7;
int Echo = 8;

// Vars for calculating distance
int value;
int Time;


void setup()
{
	pinMode(LED, OUTPUT);
	pinMode(Trig, OUTPUT);
	pinMode(Echo, INPUT);
}


void loop()
{
	// Clear Trig
	digitalWrite(Trig, LOW);
	delayMicroseconds(2);

	// Send Pulse
	digitalWrite(Trig, HIGH); 
	delayMicroseconds(10);
	digitalWrite(Trig, LOW);

	// Calc dist
	Time = pulseIn(Echo, HIGH);
	value = Time * 0.034 / 2;

	if (value <= 10)
	{
		// Dis <= 10cm
		digitalWrite(LED, HIGH); 
	}
	else
	{
		// Dis < 10cm
		digitalWrite(LED, LOW); 
	}
}