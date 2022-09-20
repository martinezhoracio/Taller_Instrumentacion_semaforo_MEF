/*Programa realizado usando maquinas de estados 
/*realiza los cambios de estadso mediante un temporizador no bloqueante
/*Autor: Martinez Horacio
/*Taller de Instrumentacion 2do cuantrimestre 2022
/**/

#include <Arduino.h>

#define LED_VERDE       2
#define LED_AMARILLO    3
#define LED_ROJO        4
#define tiempoRojo      5000
#define tiempoAmarillo  5000
#define tiempoVerde     5000

typedef enum {rojo,amarillo,verde}tipo_semaforo;

unsigned long  tiempo=0;
unsigned long tiempo_aux=0;

tipo_semaforo Semaforo;

void setup() {
  pinMode(LED_VERDE,OUTPUT);
  pinMode(LED_AMARILLO,OUTPUT);
  pinMode(LED_ROJO,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
 switch (Semaforo)
    {
    case rojo:
        {
                                    
           if (tiempoRojo<millis()-tiempo_aux)
          {
            Semaforo=verde;
            digitalWrite(LED_ROJO,LOW);
            digitalWrite(LED_AMARILLO,LOW);
            digitalWrite(LED_VERDE,HIGH);
            Serial.println(tiempo_aux);  
            tiempo_aux=millis();
            
          }
        }
    break;

    case amarillo:
        {
          
           if (tiempoAmarillo<millis()-tiempo_aux)
          {
            Semaforo=rojo;
            digitalWrite(LED_ROJO,HIGH);
            digitalWrite(LED_AMARILLO,LOW);
            digitalWrite(LED_VERDE,LOW);
            Serial.println(tiempo_aux);
            tiempo_aux=millis();
          }

        }
    break;

    case verde:
        {
                    
           if (tiempoVerde<millis()-tiempo_aux)
          {
            Semaforo=amarillo;
            digitalWrite(LED_ROJO,LOW);
            digitalWrite(LED_AMARILLO,HIGH);
            digitalWrite(LED_VERDE,LOW);
            Serial.println(tiempo_aux);
            tiempo_aux=millis();
          
          }

        }
    break;

    default:
    break;
    }
}