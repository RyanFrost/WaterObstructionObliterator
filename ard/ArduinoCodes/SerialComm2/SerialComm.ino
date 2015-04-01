
void setPins(int*);

int LmotorFWD = 3;
int RmotorFWD = 11;
int LmotorBCK = 5;
int RmotorBCK = 10;
int Logic1 = 4;
int Logic2 = 7;
int Logic3 = 8;


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


int comboVals[9][7] = { {0,0,0,0,1,1,1},
		      {255,255,0,0,1,1,1},
		      {0,0,255,255,1,1,1},
		      {0,255,255,0,1,1,1},
		      {255,0,0,255,1,1,1},
		      {128,255,0,0,1,1,1},
		      {255,128,0,0,1,1,1},
		      {0,0,128,255,1,1,1},
		      {0,0,255,128,1,1,1} };


void loop()
{
	
	if(Serial.available() > 0)
	{
		int state = Serial.parseInt();
		setPins(comboVals[state]);
	}
	
}

void setPins(int vals[7])
{
	analogWrite(LmotorFWD,vals[0]);
	analogWrite(RmotorFWD,vals[1]);
	analogWrite(LmotorBCK,vals[2]);
	analogWrite(RmotorBCK,vals[3]);
	digitalWrite(Logic1,vals[4]);
	digitalWrite(Logic2,vals[5]);
	digitalWrite(Logic3,vals[6]);
}	
