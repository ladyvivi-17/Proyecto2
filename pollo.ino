#include <LiquidCrystal.h>



//************************
//FUZZYFICATION
//***********************
float pertenenciaTriangulo(float limInferior, float limSuperior, float valorX){
      float valorModal,lResultado;
      valorModal =(limInferior + limSuperior)/2.0;
      if(valorX < limInferior){
        lResultado = 0.0;
      }else{
           if(valorX > limSuperior){
              lResultado = 0.0;
           }else{
                if(valorX <= valorModal){
                    lResultado = (valorX - limInferior)/(valorModal - limInferior);
                }else{
                    lResultado = (limSuperior - valorX)/(limSuperior - valorModal);
                }

           }

      }

      return lResultado;
}

//funciones de pertenencia - Membresia
float tempMuyBaja(float valorAbrupto){
      return pertenenciaTriangulo(-3,30,valorAbrupto);
}


float tempBaja(float valorAbrupto){
      return pertenenciaTriangulo(25,60,valorAbrupto);
}

float tempMedia(float valorAbrupto){
      return pertenenciaTriangulo(50,90,valorAbrupto);
}
float tempNormal(float valorAbrupto){
      return pertenenciaTriangulo(80,110,valorAbrupto);
}
float tempAlta(float valorAbrupto){
      return pertenenciaTriangulo(100,130,valorAbrupto);
}
float tempMuyAlta(float valorAbrupto){
      return pertenenciaTriangulo(120,150,valorAbrupto);
}


//********************
//REGLAS EVALUACION
//********************
float minimo(float valorA, float valorB){
      float lResultado;
      if(valorA < valorB){
         lResultado = valorA;
      }else{
           lResultado = valorB;
      }
      return lResultado;
}
float maximo(float valorA, float valorB){
      float lResultado;
      if(valorA > valorB){
         lResultado = valorA;
      }else{
           lResultado = valorB;
      }
      return lResultado;
}

float fuzzySystem(float valorAbrupto){
      float entFuzzy,entFuzzyA,entFuzzyB;
      float velocidadBM,velocidadBP,velocidadM,velocidadAP,velocidadAM;
      float dividendo, divisor, lSalida;
       //FUZZYFICACION
      entFuzzy = tempMuyBaja(valorAbrupto);
      //REGLA 1)SI LA TEMPERATURA ES MUY BAJA ENTONCES BAJAR MUCHO VELOCIDAD
      velocidadBM=0;
      if(entFuzzy){
          velocidadBM=entFuzzy;
      }
      //FUZZYFICACION
      entFuzzy = tempBaja(valorAbrupto);
      //REGLA 1)SI LA TEMPERATURA ES BAJA ENTONCES BAJAR UN POCO VELOCIDAD
      velocidadBP=0;
      if(entFuzzy){
          velocidadBP=entFuzzy;
      }
       //FUZZYFICACION
      entFuzzyA = tempMedia(valorAbrupto);
      //REGLA 2)SI LA TEMPERATURA ES MEDIA O ES NORMAL ENTONCES MANTENER VELOCIDAD
      entFuzzyB = tempNormal(valorAbrupto);
      velocidadM=0;
      if(entFuzzyA || entFuzzyB){
          velocidadM= maximo(entFuzzyA,entFuzzyB);
      }
       //FUZZYFICACION
      entFuzzy = tempAlta(valorAbrupto);
      //REGLA 3)SI LA TEMPERATURA ES ALTA ENTONCES AUMENTAR UN POCO LA VELOCIDAD
      velocidadAP=0;
      if(entFuzzy){
          velocidadAP=entFuzzy;
      }
       //FUZZYFICACION
      entFuzzy = tempMuyAlta(valorAbrupto);
      //REGLA 4)SI LA TEMPERATURA ES MUY ALTA ENTONCES AUMENTAR MUCHO LA VELOCIDAD
      velocidadAM=0;
      if(entFuzzy){
          velocidadAM=entFuzzy;
      }
      //DEFUZZYIFICACION - METODO ENTRO MAXIMO
      dividendo= (velocidadBM * -8.5 + velocidadBP * -5 + velocidadM * -1.0 + velocidadAP * 3.5 + velocidadAM * 8.5);
      divisor= (velocidadBM+velocidadBP+velocidadM+velocidadAP+velocidadAM);
      lSalida = 0;
        if(divisor > 0.0){
            lSalida = dividendo/divisor;
      }
      return lSalida;

}





// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int motor = 6;
int velocidad =10;
float ajustevelocidad;

int Ana1 = A1; //Entrada analogica de LM35
LiquidCrystal lcd(12,11,5,4,3,2); //Definimos la pantalla LCD
int Temp = 0;
char Grados = 'Âº';
int a;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  
  lcd.begin(16,2);
pinMode(13,OUTPUT);
digitalWrite(13, HIGH); //Activamos la retroiluminacion
}

// the loop routine runs over and over again forever:
void loop() {
  Temp = analogRead(Ana1); //Leemos el valor de la entrada analogica
  // Primero transformamos la lectura analógica de tensión a un valor de temperatura
Temp = (5.0 * Temp * 5.30)/1024.0;
ajustevelocidad = fuzzySystem(Temp);
  
Serial.print("Grados: ");//Mostramos los grados en el serial
Serial.print(Temp);
Serial.print(Grados);
Serial.println("C");
 
 
 
//Mostramos los grados en la pantalla LCD
lcd.setCursor(0,0); //Con este comando decimos en que linea queremos escribir
lcd.print("Temperat: ");
lcd.setCursor(10,0);
lcd.print(Temp);
 lcd.print(" G");
lcd.setCursor(0,1);
lcd.print("Aj Vel  :"); 
lcd.setCursor(10,1);
lcd.print(ajustevelocidad);

  a =5;
  velocidad = map(a,1,5,1,10);
  analogWrite(motor,velocidad);
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
