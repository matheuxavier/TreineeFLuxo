int trig = 13; // pino de trigger do ultrassom
int echo = 12; // pino de echo do ultrassom
float distancia; // variavel para a distancia lida
float temperatura; //variavel para a temperatura lida

void setup()	
{
  pinMode (trig, OUTPUT); //TRIGGER ULTRASSOM
  pinMode (echo,INPUT); // ECHO ULTRASSOM
  pinMode (A0, INPUT);// PINO DE LEITURA DO SENSOR DE TEMPERATURA
  
  pinMode (6,OUTPUT); // RODA DIREITA
  pinMode (5,OUTPUT); // RODA DIREITA
  
  pinMode (3,OUTPUT); //RODA ESQUERDA
  pinMode (2,OUTPUT);//RODA ESQUERDA
  
  pinMode (9,OUTPUT);//RODA FRONTAL
  pinMode (8,OUTPUT);//RODA FRONTAL
  
  analogWrite (7,0); // definindo a velocidade incial do motor 1 como 0
  analogWrite (4,0);// definindo a velocidade inicial do motor 2 como 0
  analogWrite (10,0);// definindo a velocidade inicial do motor 3 como 0

  Serial.begin (9600);
}

void loop() {
  analogWrite(7,255); // velocidade motor 1
  analogWrite(4,255); // velocidade motor 2
  analogWrite(10,255);//velocidade motor 3
  
  digitalWrite(6,HIGH); //aciona motor 1 para trás
  digitalWrite(2,HIGH); //aciona motor 2 para trás
  digitalWrite(8,HIGH); //aciona motor 3 para trás
  delay(1000);
  
  digitalWrite(6,LOW); //para motor 1
  digitalWrite(2,LOW); //para motor 2
  digitalWrite(8,LOW); //para motor 3
  delay(1000);
  
  digitalWrite(5,HIGH); //aciona motor 1 para frente
  digitalWrite(3,HIGH); //aciona motor 2 para frente
  digitalWrite(9,HIGH);// aciona motor 3 para frente
  delay(1000);
  
  digitalWrite(5,LOW); // para motor 1
  digitalWrite(3,LOW); // para motor 2
  digitalWrite(9,LOW); // para motor 3
  
  temperatura = analogRead(A0); // guarda a leitura do A0 dentro da variavel temperatura
  Serial.print("Temperatura: ");// escreve "temperatura" no serial monitor
  Serial.println(temperatura); // mostra o valor da variável em C°
  delay(1000);
  
  digitalWrite(trig, LOW); // acionamento do ultrassom
  delay(500); 
  digitalWrite(trig, HIGH); // acionamento do ultrassom
  delay(500); 
  digitalWrite(trig, LOW); // acionamento do ultrassom
  
  distancia = pulseIn (echo, HIGH);
  distancia /= 58; //divide a distancia lida por 58
  Serial.print("Distancia: "); // printa "distancia"
  Serial.println (distancia); //printa o valor da variável distância
	}