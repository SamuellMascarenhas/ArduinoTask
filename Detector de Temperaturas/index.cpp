// Definindo pinos
int potPin = A0;             // Potenciômetro para ajuste de temperatura
int ldrPin = A1;             // LDR para simulação do aquecimento
int ledVerde = 7;            // LED Verde (temperatura baixa)
int ledAmarelo = 6;          // LED Amarelo (temperatura média)
int ledVermelho = 5;         // LED Vermelho (temperatura alta)
int buzzerPin = 4;           // Buzzer para alerta de superaquecimento
int buttonPin = 8;           // Botão de controle ligar/desligar

bool sistemaLigado = false;  // Estado do sistema (desligado no início)

void setup() {
  // Configurando pinos
  pinMode(potPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Usando resistor pull-up interno no botão

  Serial.begin(9600);  // Inicializa a comunicação serial para monitora
}

void loop() {
  // Verificar o botão para ligar/desligar o sistema
  if (digitalRead(buttonPin) == LOW) {
    sistemaLigado = !sistemaLigado;  // Alterna o estado do sistema
    Serial.print("Sistema Ligado: ");
    Serial.println(sistemaLigado);
    delay(1000);  // Debounce (tempo para evitar múltiplos acionamentos)
  }

  if (sistemaLigado) {
    // Leitura do potenciômetro e do LDR
    int valorPot = analogRead(potPin);
    int valorLDR = analogRead(ldrPin);

    // Invertendo a leitura do potenciômetro (se necessário)
    valorPot = 1023 - valorPot;  // Inverte a leitura do potenciômetro

    // Mapeamento da leitura do potenciômetro para uma faixa de temperatura
    int temperatura = map(valorPot, 0, 1023, 20, 40);  // Faixa de 20 a 40°C
    int ajusteAquecimento = map(valorLDR, 0, 1023, 0, 5);  // Simulação de aquecimento de 0 a 5°C
    int temperaturaFinal = temperatura + ajusteAquecimento;  // Temperatura ajustada com "aquecimento"

    Serial.print("Temperatura Final: ");
    Serial.println(temperaturaFinal);

    // Controle dos LEDs com base na faixa de temperatura
    if (temperaturaFinal <= 30) {  // Faixa de temperatura baixa
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
      noTone(buzzerPin);  // Desliga o buzzer
    } else if (temperaturaFinal > 30 && temperaturaFinal <= 35) {  // Faixa de temperatura média
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVermelho, LOW);
      noTone(buzzerPin);  // Desliga o buzzer
    } else {  // Temperatura alta, com alerta de superaquecimento
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, HIGH);
      tone(buzzerPin, 500);  // Ativa o buzzer com som de 500 Hz (mais baixo)
    }
  } else {
    // Desliga todos os LEDs e o buzzer quando o sistema está desligado
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzerPin);  // Desliga o buzzer
  }

  delay(100);  // Delay para estabilidade do loop
}
