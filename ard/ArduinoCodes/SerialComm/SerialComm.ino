
void setPin(void);

void setup()
{
	Serial.begin(9600);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(11,OUTPUT);
}
int i = 0;
void loop()
{
	
	if(Serial.available() > 0)
	{
		setPin();
	}
	
}


void setPin()
{
	
	int pinNum = Serial.parseInt();
	char pinType = Serial.read();
	int pinLevel = Serial.parseInt();
	if (pinType == 'a')
	{
		if(pinLevel < 0) pinLevel = 0;
		if(pinLevel > 255) pinLevel = 255;

		analogWrite(pinNum, pinLevel);
	}
	else if(pinType == 'd')
	{
		digitalWrite(pinNum,pinLevel);
	}
}
