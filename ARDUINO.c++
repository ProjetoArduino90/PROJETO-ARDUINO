#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

#define ENA 10
#define ENB 11

#define POT 180

#define SensorD A1
#define SensorE A0

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(SensorD, INPUT);
  pinMode(SensorE, INPUT);

  analogWrite(ENA, POT);
  analogWrite(ENB, POT);

  // Inicializa os motores parados
  pararMotores();
}

void loop() {
  modoSeguidorLinha();
}

void modoSeguidorLinha() {
  int sensorEsquerdo = digitalRead(SensorE);
  int sensorDireito = digitalRead(SensorD);

  Serial.print("Esquerdo: ");
  Serial.print(sensorEsquerdo);
  Serial.print(" | Direito: ");
  Serial.println(sensorDireito);

  if (sensorEsquerdo == HIGH && sensorDireito == HIGH) {
    pararMotores();
  } else if (sensorEsquerdo == HIGH && sensorDireito == LOW) {
    moverDireita();
  } else if (sensorEsquerdo == LOW && sensorDireito == HIGH) {
    moverEsquerda();
  } else {
    moverFrente();
  }

  delay(50); // Ajuste no tempo para resposta mais estável
}

void moverFrente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moverEsquerda() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moverDireita() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void pararMotores() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}