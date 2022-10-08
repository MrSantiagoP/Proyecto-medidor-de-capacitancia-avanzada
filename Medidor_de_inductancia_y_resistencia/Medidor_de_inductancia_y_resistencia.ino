
double Pulso, Frecuencia, Capacitancia, Inductancia; //...Declaramos variables
void setup(){
 
  Serial.begin(115200);//Definimos el puerto
  pinMode(11, INPUT);//Entrada de la salida del comparador
  pinMode(13, OUTPUT);//Salida a través de una resistencia de 150 ohmios a través del circuito LC
  Serial.println("MEDIDOR DE INDUCTANCIA Y RESISTENCIA");//...Imprimimos por pantalla
  delay(200);//Retardo que se utiliza
  Serial.println("BIENVENIDO AL PROGRAMA");//...Imprimimos por pantalla
  delay(200);// Retardo que se utiliza
}
void loop(){
  digitalWrite(13, HIGH);//Aplicamos un pulso en alto al pin digital 13 para cargar el circuito con 5 milisegundos
  delay(5);// Tiempo que se da para cargar el inductor
  digitalWrite(13,LOW);//Aplicamos un pulso en bajo al pin digital 13 
  delayMicroseconds(100); //Se le da un retardo para asegurarnos que el circuito este ocilando 
  Pulso = pulseIn(11,HIGH,5000);//Medimos el periodo del pulso de entrada de ocilacion correspondiente a la del circuito
  if(Pulso > 0.1){ // se crea un if si no se produjo un tiempo de espera y tomó una lectura
    
    
  
  Capacitancia = 2.E-6; // Definimos el valor del condesador-se utilizo dos condensadores de 1uF
  
  
  Frecuencia = 1.E6/(2*Pulso);//Operacion para hallar la frecuencia del inductor
  Inductancia = 1./(Capacitancia*Frecuencia*Frecuencia*4.*3.14159*3.14159);//Operacion para hallar la inductanica del inductor 
  Inductancia *= 1E6; //Resultados 

  //Serial print
  Serial.print("Su pulso es:");//Imprimimos por pantalla el pulso 
  Serial.print( Pulso );//Aqui es donde se muestran los datos de pulso
  Serial.print("\tFrecuencia Hz:");// Imprimimos por pantalla la frecuencia
  Serial.print( Frecuencia);//Aqui es donde se muestran los datos de frecuencia
  Serial.print("\tInductancia uH:");// Imprimimos por pantalla la inductancia 
  Serial.println( Inductancia );//Aqui es donde se muestran los datos de inductancia
  delay(10);// Se utiliza un retraso de 10 milisegundos el cual imprimira por pantalla los datos 

  
  }
}


 
