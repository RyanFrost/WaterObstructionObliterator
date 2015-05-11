
void setPin(void);
int readPin(void);

void setup()
{
	Serial.begin(9600);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
}
int i = 0;
void loop()
{
	
	if(Serial.available() > 0)
	{
		char operationType = Serial.read();
		switch( operationType )
		{
			case 'r':
				Serial.write(readPin());
				break;
			case 's':
				setPin();
				break;
			case default:
				break;
		}
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

int readPin()
{
	int pinNum = Serial.parseInt();
	char pinType = Serial.read();

	if (pintype == 'a')
	{
		return analogRead(pinNum);
	}
	else if (pinType == 'd')
	{
		return digitalRead(pinNum);
	}
	else
	{
		return -1;
	}
}
