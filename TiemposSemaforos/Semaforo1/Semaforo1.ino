<<<<<<< HEAD
#define V1  1
#define A1  2
#define R1  3

=======
#define V1
#define A1
#define R1
<<<<<<< Updated upstream
=======
>>>>>>> b93787a0376b3b474621a4f0ac7f089fe47ace8e
>>>>>>> Stashed changes

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
  int AutosTotales = Autos1 - Autos2;
  // CASO NORMAL SEMAFORO 1
<<<<<<< Updated upstream
  if (AutosTotales > -2 && AutosTotales < 2)
  {
    Serial.print("Caso normal");
=======
  if (AutosTotales >= -2 && AutosTotales <= 2)
  {
<<<<<<< HEAD
    Serial.print("Caso 1");
=======
    Serial.print("Caso normal");
>>>>>>> b93787a0376b3b474621a4f0ac7f089fe47ace8e
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    Serial.print("FAVORABLE PARA SEMAFORO 1");
=======
<<<<<<< HEAD
    Serial.print("Caso 2");
=======
    Serial.print("FAVORABLE PARA SEMAFORO 1");
>>>>>>> b93787a0376b3b474621a4f0ac7f089fe47ace8e
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    Serial.print("MUY FAVORABLE PARA SEMAFORO 1");
=======
<<<<<<< HEAD
    Serial.print("Caso 3");
=======
    Serial.print("MUY FAVORABLE PARA SEMAFORO 1");
>>>>>>> b93787a0376b3b474621a4f0ac7f089fe47ace8e
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    Serial.print("POCO PARA SEMAFORO 1");
=======
<<<<<<< HEAD
    Serial.print("Caso 4");
=======
    Serial.print("POCO PARA SEMAFORO 1");
>>>>>>> b93787a0376b3b474621a4f0ac7f089fe47ace8e
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    Serial.print("MUY POCO FAVORABLE PARA SEMAFORO 1");
=======
<<<<<<< HEAD
    Serial.print("Caso 5");
=======
    Serial.print("MUY POCO FAVORABLE PARA SEMAFORO 1");
>>>>>>> b93787a0376b3b474621a4f0ac7f089fe47ace8e
>>>>>>> Stashed changes
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
