// Registrando variáveis 
const int ledsPin[] = {2,3,4,5,6,7,8,9,10,11};
int pinPoten = A2;
int valorPoten;

void setup()
{
  Serial.begin(9600);
  
  // Configurando os leds
  for(int i = 0; i < 10; i++) {
    pinMode(ledsPin[i], OUTPUT);  
  }    
}

void loop()
{
  // Armazenando o valor do potenciômetro 
  valorPoten = analogRead(pinPoten);
  Serial.println(valorPoten);
  
  // Calcula o intervalo para cada LED
  int interval = 1024 / 10;

  // Sistema para ligar os LEDs baseado no potenciômetro
  for (int i = 0; i < 10; i++) {
    if (valorPoten <= interval * (9 - i)) {
      digitalWrite(ledsPin[i], HIGH);
    } else {
      digitalWrite(ledsPin[i], LOW);
    }
  }
}
