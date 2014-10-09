
int Espejo_1 = 0;
int Umbral = 0;

const int LED_D =  6;
const int LED_I =  7;

//Entradas analogicas
int Var_acoplo = A0;
int Entrada_A1 = A1;

//Entradas motor
int A = 8;
int B = 9;
int C = 10;
int D = 11;

void Estado_Pasivo(void){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);

  Umbral = analogRead(Var_acoplo);
  Espejo_1 = analogRead(Entrada_A1);  
 
  delay(500);
  
  if(Espejo_1 > (512 + Umbral)){
  
    digitalWrite(LED_D, HIGH);
    Manual_D();
    digitalWrite(LED_D, LOW);
 
  }
  
  if (Espejo_1 < (512 -Umbral)){
  
    digitalWrite(LED_I, HIGH);
    Manual_I();
    digitalWrite(LED_I, LOW); 
 
 }

}

void Manual_D(void){
do{
   Serial.println("----Derecha----");
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  Espejo_1 = analogRead(Entrada_A1);
  }while(Espejo_1 > (512 + Umbral));

}

void Manual_I(void){
do{
    Serial.println("----Izquierda----");
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  Espejo_1 = analogRead(Entrada_A1);  
  }while(Espejo_1 < (512 + Umbral));
}
 
 void setup() {
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);    
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);  
  pinMode(LED_D, OUTPUT);
  pinMode(LED_I, OUTPUT);
  pinMode(Entrada_A1, INPUT);
  pinMode(Var_acoplo, INPUT);
  pinMode(Espejo_1, INPUT);  
  pinMode(Umbral, INPUT); 
}

void loop() {
  Serial.println("----INICIO----");
  Estado_Pasivo(); 

 }
