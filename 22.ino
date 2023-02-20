/*
programa para simular a ventanilla dun coche,de forma simplificada.
O pulsador acciona o motor de subida ao ser premido.
Unha segunda pulsación fai que se accione o motor de baixada.
entrada: Pulsador (dixital)
saidas: Relé (2x dixital)
Autor: ''anxo ramallo'' (veanse las comillas)
data: Febrero de 20223
*/

#define motorArriba 11
#define motorAbaixo 12   
#define pulsador  7
#define fcArriba  8
#define fcAbaixo  9

	int estado = 1;					 
	int contador = 0; 				

	void setup() {
 		 pinMode(motorArriba,OUTPUT);
 		 pinMode(motorAbaixo,OUTPUT);
 		 pinMode(pulsador,INPUT);
  		 pinMode(fcArriba,INPUT);
 		 pinMode(fcAbaixo,INPUT);
      
         Serial.begin(9600);
       //neste paso identificamos a funcion de cada pin para que o arduino os asosie ao seu nome
}
    
	void loop() {
 									                            
  		if(digitalRead(pulsador)) { 
          //lee o pulsador se este esta premido comeza ca funcion de abaixo
    			estado = (estado + 1) % 4;   						
   	   	   	    contador = 100;	
    	while(digitalRead(pulsador)) {	
           //le se esta premido o pulsador
            delay(10);
           //espera 1milesegundos mentres esta premido e reinicia o bucle
}	 
}

       Serial.print("valor del contador: ");
  Serial.print(contador);
  Serial.print(" | estado:  ");
  Serial.println(estado);
    // esta parte a partir do cometario son os metodos de accionamiento dos motores
      
      
if(digitalRead(fcArriba)) {    						 
if(estado |= 2 )  {
    estado = 1;    								 
    delay(10); 
  //si cando o motor esta subindo se preme este boton para a accion
}
}

if(digitalRead(fcAbaixo)) {   					    
if(estado |= 0 ) {									
     estado = 3;
     delay(10);
   //si cando o motor esta baixando se preme este boton para a accion
}
}
  		
   		 if(estado == 0) {   		 
    		  digitalWrite(motorArriba, HIGH); 		
    		  digitalWrite(motorAbaixo, LOW);  		
     		  delay (70);
        						
}
         else if(estado == 2){
      		digitalWrite(motorAbaixo, HIGH);
      		digitalWrite(motorArriba, LOW);
     	    delay(70); 
   
      
}   
         else {			
    			digitalWrite(motorAbaixo, LOW);
    			digitalWrite(motorArriba, LOW);  
    			delay(70);
}
}
