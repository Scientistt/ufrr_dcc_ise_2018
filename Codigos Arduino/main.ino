#include <IRremote.h>


int pinoSensorDeLuz = 0;
int valorLidoSensorDeLuz = 0;
int pinoBotaoSensorDeLuzMais = 13;
int pinoBotaoSensorDeLuzMenos = 12;
int valorPadraoSensorDeLuz = 800;



int pinoSensorDeVibracao = 1;
int pinoBotaoSensorDeVibracaoMais = 11;
int pinoBotaoSensorDeVibracaoMenos = 10;
int valorPadraoSensorDeVibracao = 100;
int valorLidoSensorDeVibracao = 0;

int pinoEmissorInfraVermelho = 3;
IRsend controleRemoto;
int frequenciaDeEmissao = 38;

int pinoSensorDePresenca = 6;
int valorLidoSensorDePresenca = 0;
 
void setup() {
 Serial.begin(9600); //Inicia a comunicação serial

 pinMode(pinoBotaoSensorDeLuzMais, INPUT);
 pinMode(pinoBotaoSensorDeLuzMenos, INPUT);
 
 pinMode(pinoBotaoSensorDeVibracaoMais, INPUT);
 pinMode(pinoBotaoSensorDeVibracaoMenos, INPUT);

 pinMode(pinoSensorDePresenca, INPUT);

 
}

void infraRed()
{
  unsigned int codigoInfraVermelhoParaDesligar[] = {8936, 4572, 488, 632, 508, 628, 508, 1724, 516, 628, 512, 628, 508, 628, 508, 628, 508, 648, 508, 628, 508, 1724, 516, 632, 508, 628, 508, 1724, 516, 628, 508, 628, 512, 644, 508, 628, 508, 632, 508, 628, 508, 628, 508, 628, 512, 628, 508, 628, 508, 648, 508, 628, 508, 628, 508, 632, 508, 628, 508, 628, 508, 628, 508, 632, 508, 644, 508, 628, 512, 628, 508, 628, 508, 628, 508, 632, 508, 628, 508, 628, 508, 648, 508, 628, 508, 628, 512, 628, 508, 1724, 516, 628, 508, 628, 508, 632, 508, 1740, 516, 628, 508, 628, 512, 628, 508, 628, 508, 628, 508, 1728, 516, 1724, 516, 1740, 516, 628, 508, 632, 508, 628, 508, 628, 508, 1724, 516, 628, 512, 628, 508, 632, 508};
  unsigned int codigoInfraVermelhoParaLigar[] = {8936, 4580, 488, 628, 508, 632, 504, 1728, 512, 632, 508, 1724, 516, 628, 508, 628, 508, 648, 508, 628, 508, 1728, 512, 632, 504, 632, 508, 1724, 516, 628, 508, 632, 508, 644, 508, 628, 508, 632, 508, 628, 508, 628, 508, 632, 504, 632, 508, 628, 508, 648, 504, 632, 508, 628, 508, 632, 504, 632, 508, 628, 508, 632, 504, 632, 508, 648, 504, 632, 504, 632, 508, 628, 508, 628, 508, 632, 508, 628, 508, 632, 504, 648, 508, 1724, 516, 628, 508, 632, 504, 1728, 512, 632, 508, 628, 508, 632, 504, 1744, 516, 628, 508, 632, 508, 628, 508, 628, 508, 632, 504, 1728, 512, 1728, 512, 1744, 516, 628, 512, 628, 504, 632, 508, 628, 508, 1724, 516, 628, 508, 632, 508, 632, 508};

Serial.println("");
  Serial.println("CMD: DESL");
  controleRemoto.sendRaw(codigoInfraVermelhoParaDesligar, sizeof(codigoInfraVermelhoParaDesligar) / sizeof(codigoInfraVermelhoParaDesligar[0]), frequenciaDeEmissao); 
  delay(20000);
  Serial.println("CMD: LIGR");
  controleRemoto.sendRaw(codigoInfraVermelhoParaLigar, sizeof(codigoInfraVermelhoParaLigar) / sizeof(codigoInfraVermelhoParaLigar[0]), frequenciaDeEmissao); 
  delay(20000);  
  Serial.println("");
}

void sensorDeVibracao()
{
  if(digitalRead(pinoBotaoSensorDeVibracaoMais) == HIGH && digitalRead(pinoBotaoSensorDeVibracaoMenos) == LOW)
  {
    valorPadraoSensorDeVibracao+=10;
  }
  else if(digitalRead(pinoBotaoSensorDeVibracaoMenos) == HIGH && digitalRead(pinoBotaoSensorDeVibracaoMais) == LOW)
  {
    valorPadraoSensorDeVibracao-=10;
  }
  else if(digitalRead(pinoBotaoSensorDeVibracaoMenos) == HIGH && digitalRead(pinoBotaoSensorDeVibracaoMais) == HIGH)
  {
    valorPadraoSensorDeVibracao = 100;
  }
  
  valorLidoSensorDeVibracao = analogRead(pinoSensorDeVibracao); 
  Serial.print(" PIEZO:");
  Serial.print(valorLidoSensorDeVibracao);
  Serial.print(" CONST:");
  Serial.print(valorPadraoSensorDeVibracao);
  Serial.print(" CENTRAL:");
  if(valorLidoSensorDeVibracao >= valorPadraoSensorDeVibracao)
  {
    Serial.print("ON");
  }
  else
  {
    Serial.print("OFF");
  }
}

void sensorDeLuz()
{
  if(digitalRead(pinoBotaoSensorDeLuzMais) == HIGH && digitalRead(pinoBotaoSensorDeLuzMenos) == LOW)
  {
    valorPadraoSensorDeLuz+=10;
  }
  else if(digitalRead(pinoBotaoSensorDeLuzMenos) == HIGH && digitalRead(pinoBotaoSensorDeLuzMais) == LOW)
  {
    valorPadraoSensorDeLuz-=10;
  }
  else if(digitalRead(pinoBotaoSensorDeLuzMenos) == HIGH && digitalRead(pinoBotaoSensorDeLuzMais) == HIGH)
  {
    valorPadraoSensorDeLuz = 800;
  }
  valorLidoSensorDeLuz = analogRead(pinoSensorDeLuz); 
  Serial.print(" LDR:");
  Serial.print(valorLidoSensorDeLuz);
  Serial.print(" CONST:");
  Serial.print(valorPadraoSensorDeLuz);
  Serial.print(" LIGHT:");
  if(valorLidoSensorDeLuz > valorPadraoSensorDeLuz)
  {
    Serial.print("OFF");
  }
  else
  {
    Serial.print("ON");  
  }
}

void sensorDePresenca()
{
  valorLidoSensorDePresenca = digitalRead(pinoSensorDePresenca);
  Serial.print(" PIR:");
  Serial.print(valorLidoSensorDePresenca);
  Serial.print(" THERE-IS:");
  if(valorLidoSensorDePresenca == LOW)
  {
    Serial.print("NOBODY");
  }
  else
  {
    Serial.print("SOMEBODY");
  }
}
 
void loop()
{
  sensorDeLuz();
  sensorDePresenca();
  sensorDeVibracao();
  infraRed();
 
  Serial.println(" XXX");
  delay(100);
}
