#define V2 5
#define A2 6
#define R2 7

#define Autos1 6
#define Autos2 9

void setup() 
{
  Serial.begin(115200);
  pinMode(V2, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(R2, OUTPUT);
}

void loop() 
{
  //SEMAFORO 2
  int AutosTotales = Autos1 - Autos2;
  // CASO NORMAL SEMAFORO 2
  if (AutosTotales > -2 && AutosTotales < 2)
  {
    Serial.print("Caso normal");
    digitalWrite(V2, LOW);
    digitalWrite(R2, HIGH);
    delay(28000);
    digitalWrite(R2, LOW);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A2, LOW);
    digitalWrite(V2, HIGH);
    delay(28000);
  }

  // POCO FAVORABLE PARA SEMAFORO 2
  if (AutosTotales >= 2 && AutosTotales < 5)
  {
    Serial.print("Caso 2");
    digitalWrite(V2, LOW);
    digitalWrite(R2, HIGH);
    delay(34000);
    digitalWrite(R2, LOW);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A2, LOW);
    digitalWrite(V2, HIGH);
    delay(22000);
  }

  // MUY POCO FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales >= 5)
  {
    Serial.print("Caso 3");
    digitalWrite(V2, LOW);
    digitalWrite(R2, HIGH);
    delay(42000);
    digitalWrite(R2, LOW);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A2, LOW);
    digitalWrite(V2, HIGH);
    delay(14000);
  }

  // FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales > -5 && AutosTotales <= -2)
  {
    Serial.print("Caso 4");
    digitalWrite(V2, LOW);
    digitalWrite(R2, HIGH);
    delay(22000);
    digitalWrite(R2, LOW);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A2, LOW);
    digitalWrite(V2, HIGH);
    delay(34000);
  }

  //MUY FAVORABLE PARA SEMAFORO 1
  else if (AutosTotales <= -5)
  {
    Serial.print("Caso 5");
    digitalWrite(V2, LOW);
    digitalWrite(R2, HIGH);
    delay(14000);
    digitalWrite(R2, LOW);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A2, LOW);
    digitalWrite(V2, HIGH);
    delay(42000);
  }


}
