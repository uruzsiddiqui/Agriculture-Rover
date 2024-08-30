int LMP = 3;
int LMN = 4;
int RMP = 2;
int RMN = 5;


void setup() {
  // put your setup code here, to run once:
   pinMode(LMP, OUTPUT);
   pinMode(LMN, OUTPUT);
   pinMode(RMP, OUTPUT);
   pinMode(RMN, OUTPUT);
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available())
   {
     String Direction = Serial.readString();
     if (Direction == "F")
     {
       digitalWrite(LMP, HIGH);
       digitalWrite(LMN,  LOW);
       digitalWrite(RMP, HIGH);
       digitalWrite(RMN, LOW);
     }
     else if (Direction == "B")
     {
        digitalWrite(LMP, LOW); 
        digitalWrite(LMN, HIGH); 
        digitalWrite(RMP, LOW); 
        digitalWrite(RMN, HIGH); 
     }
     else if (Direction == "R")
     {
        digitalWrite(LMP, HIGH);
        digitalWrite(LMP, LOW);
        digitalWrite(LMP, HIGH);
        digitalWrite(LMP, LOW);
     }
     else if (Direction == "L")
     {
        digitalWrite(LMP, LOW);
        digitalWrite(LMP, HIGH);
        digitalWrite(LMP, LOW);
        digitalWrite(LMP, HIGH);
     }
     else if (Direction == "S")
     {
       digitalWrite(LMP, LOW);
       digitalWrite(LMN, LOW);
       digitalWrite(RMP, LOW);
       digitalWrite(RMN, LOW);
     }
   }
}
