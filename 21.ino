/*PROGRAMA PARA SIMULAR LA FUNCION DE UNA VENTANA DE AUTOMOVIL 
DE MANERA SIMPLIFICADA. EL PULSADOR ACCIONA EL MOTOR DE SUBIDA AL SER PRESIONADO
  UNA SEGUNDA PULSACION PROVOCA QUE EL MOTOR DE BAJADA SE ACCIONE. 
  MIENTRAS LOS MOTORES ESTAN ACCIONADOS DEBEN RESPONDER AL ACCIONAMIENTO DEL PULSADOR (RESPONSIVE)
  EN LA SEGUNDA PARTE DEL PROBLEMA HAY QUE FORZAR QUE EL PULSADOR TENGA 3 ESTADOS (ARRIBA 0. PARADA 1 Y ABAJO 2 , PARADA 3)
  Y QUE DESPUES DE CADA ACCIONAMIENTO DEL PULSADOR PASE POR "0" O PARADA .
  
  
  ENTRADA: 1 PULSADOR (SEÑAL DIGITAL)
    
  SAlIDAS: 2 RELÉS (SEÑAL DIGITAL)
     
  AUTOR:¨Anxo Ramallo¨
  DATA:  0/02/2023 */
   
    
#define motorArriba 11
#define motorAbaixo 12   
#define pulsador  7

	int estado = 1;
	int contador = 0; 

void setup() {
 		 pinMode(motorArriba,OUTPUT);
 		 pinMode(motorAbaixo,OUTPUT);
 		 pinMode(pulsador,INPUT);
  
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
        delay(1);
      //espera 1milesegundos mentres esta premido e reinicia o bucle
}
}
  
  Serial.print(" valor del contador:");
  Serial.print(contador);
  Serial.print(" | estado:");
  Serial.println(estado);

  // esta parte a partir do cometario son os metodos de accionamiento dos motores
  if (contador > 0) {
    if(estado == 0) {    
      digitalWrite(motorArriba, HIGH); 
      //activamos o rele motor arriba
      digitalWrite(motorAbaixo, LOW);
      delay (70);
      contador--;
      //restamos ¨1¨ al contador 
}
    //si o estado e ¨2¨ repetimos o msmo accionamiento dos motores invertindo o estado dos reles
  else if(estado == 2)  {
     	 digitalWrite(motorArriba, LOW);
     	 digitalWrite(motorAbaixo, HIGH);
     	 delay(70);
    	 contador--;
}
    //establecemos os paros
    else {
     	  digitalWrite(motorArriba, LOW);
    	  digitalWrite(motorAbaixo, LOW);
    	  delay(70);
		  contador--;
}
}
  else{			
    	digitalWrite(motorAbaixo, LOW);
    	digitalWrite(motorArriba, LOW);  
    	delay(10); 
    //si o motor non esta accionado,lee o pulsador 10 veces
}
}
