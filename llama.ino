
int ledRojo = 3;
int ledVerde = 11;
int ledAzul = 10;
const int sensorPin = A0;

void setup() {
   pinMode(ledRojo,OUTPUT);
   pinMode(ledVerde,OUTPUT);
   pinMode(ledAzul,OUTPUT); 
   Serial.begin(9600);
   
}
void loop() 
{
   int measure = analogRead(sensorPin);
   Serial.println(measure);

   if (measure<500){
     Serial.println("Deteccion");   
     delay(10);
     digitalWrite(ledRojo,0);
     digitalWrite(ledVerde,0);
     digitalWrite(ledAzul,0);       
}   
   else{
     digitalWrite(ledRojo,255);
     digitalWrite(ledVerde,0);
     digitalWrite(ledAzul,127);    
   }  
}

