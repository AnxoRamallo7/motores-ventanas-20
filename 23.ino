
#define LDR A0
#define Rele 12 

int releON = false;
int contador = 100;
int umbral = 960;
int entrada = 0;



void setup() {
	pinMode(LDR, INPUT); 				
    pinMode(Rele,OUTPUT);
  	Serial.begin(9600); 
}

void loop() {
   Serial.print(contador);
 Serial.println("  contador");
   entrada = analogRead(LDR);      
 Serial.print(entrada);
  Serial.print("Entrada LDR: ");
  delay (70);
  	
  
  
  
  if (entrada > umbral) {
  	  releON = true;
      contador--;      
  }
 	 else {
    releON = false;
 }
  	if (contador > 0) {
   delay (70);
  }
 	 else  {
    releON = false;
    contador = 0;
    
}   
    digitalWrite(Rele, releON);    
}
