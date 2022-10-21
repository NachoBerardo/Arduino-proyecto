#define V1
#define A1
#define R1

#define Autos1 6
#define Autos2 4

void setup() 
{
  pinMode(V1, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(R1, OUTPUT);
}

void loop() 
{
  //SEMAFORO 1
  int AutosTotales = Autos1 - Autos2
  // CASO NORMAL SEMAFORO 1
  if (AutosTotales > -2 && AutosTotales < 2)
  {
    Serial.print("Caso normal");
    digitalWrite(R1, LOW);
    digitalWrite(V1, HIGH);
    delay(28000);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(28000);
  }

  // FAVORABLE PARA SEMAFORO 1
  else if (AutosTotales > 2 && AutosTotales < 5)
  {
    Serial.print("FAVORABLE PARA SEMAFORO 1");
    digitalWrite(R1, LOW);
    digitalWrite(V1, HIGH);
    delay(34000);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(22000);
  }

  // MUY FAVORABLE PARA SEMAFORO 1
  else if (AutosTotales > 5)
  {
    Serial.print("MUY FAVORABLE PARA SEMAFORO 1");
    digitalWrite(R1, LOW);
    digitalWrite(V1, HIGH);
    delay(42000);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(14000);
  }

  // POCO FAVORABLE PARA SEMAFORO 1
  else if (AutosTotales > -5 && AutosTotales < -2)
  {
    Serial.print("POCO PARA SEMAFORO 1");
    digitalWrite(R1, LOW);
    digitalWrite(V1, HIGH);
    delay(22000);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(34000);
  }

  //MUY POCO FAVORABLE PARA SEMAFORO 1
  else if (AutosTotales < -5)
  {
    Serial.print("MUY POCO FAVORABLE PARA SEMAFORO 1");
    digitalWrite(R1, LOW);
    digitalWrite(V1, HIGH);
    delay(14000);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(R1, HIGH);
    delay(42000);
  }


}
