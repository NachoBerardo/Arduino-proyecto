#define V1 1
#define A1 2
#define R1 3
#define V2 4
#define A2 5
#define R2 6

#define Autos1 6
#define Autos2 4

void setup() 
{
  pinMode(V1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

void loop() 
{
  //SEMAFORO 2
  int AutosTotales = Autos1 - Autos2;
  // CASO NORMAL SEMAFORO 2
  if (AutosTotales > -2 && AutosTotales < 2)
  {
    digitalWrite(V1, LOW);
    digitalWrite(R1, HIGH);
    delay(28000);
    digitalWrite(R1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(V1, HIGH);
    delay(28000);
  }

  // POCO FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales > 2 && AutosTotales < 5)
  {
    digitalWrite(V1, LOW);
    digitalWrite(R1, HIGH);
    delay(34000);
    digitalWrite(R1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(V1, HIGH);
    delay(22000);
  }

  // MUY POCO FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales > 5)
  {
    digitalWrite(V1, LOW);
    digitalWrite(R1, HIGH);
    delay(42000);
    digitalWrite(R1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(V1, HIGH);
    delay(14000);
  }

  // FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales > -5 && AutosTotales < -2)
  {
    digitalWrite(V1, LOW);
    digitalWrite(R1, HIGH);
    delay(22000);
    digitalWrite(R1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(V1, HIGH);
    delay(34000);
  }

  //MUY FAVORABLE PARA SEMAFORO 1
  else if (AutosTotales < -5)
  {
    digitalWrite(V1, LOW);
    digitalWrite(R1, HIGH);
    delay(14000);
    digitalWrite(R1, LOW);
    digitalWrite(A1, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(V1, HIGH);
    delay(42000);
  }


}
