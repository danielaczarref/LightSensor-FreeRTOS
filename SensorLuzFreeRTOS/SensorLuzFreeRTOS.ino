#include <Arduino_FreeRTOS.h>

void TaskLight( void *pvParameters );
void TaskAnalogRead( void *pvParameters );

const int pinoLDR = A0;
const int pinoLED = 7; 
int leitura = 0;

void setup() {
  Serial.begin(9600);
  
  while (!Serial) {
    ; 
  }
    
  xTaskCreate( TaskLight, "LED", 128, NULL, 1, NULL );
  xTaskCreate( TaskAnalogRead, "AnalogRead", 128, NULL, 2, NULL );
}

void TaskLight( void *pvParameters )
{
  (void) pvParameters;

  pinMode(pinoLDR, INPUT); 
  pinMode(pinoLED, OUTPUT);
}

void TaskAnalogRead(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
      leitura = analogRead(pinoLDR);

    if(leitura < 40){ 
      digitalWrite(pinoLED,HIGH);
    }
    else {
      digitalWrite(pinoLED,LOW);
    }
    vTaskDelay(100);
  }
}

void loop() {

}
