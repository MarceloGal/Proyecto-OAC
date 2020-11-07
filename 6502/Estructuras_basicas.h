/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estructuras_basicas.h
 * Author: Dell
 *
 * Created on 10 de octubre de 2020, 05:11 PM
 */

#ifndef ESTRUCTURAS_BASICAS_H
#define ESTRUCTURAS_BASICAS_H

#define RESET_VAL_MSB 0xffdd
#define RESET_VAL_LSB 0xfffc
#include <inttypes.h>
typedef struct mos6502{
    uint8_t a;          //acomulador
    uint8_t x;           //reg indice x
    uint8_t y;           //reg indice y
    uint16_t pc;         //contador de programa
    uint8_t sp;          //puntero a pila
    uint8_t sr;          //registro de banderas
    uint8_t ins;         //registro de instrucciones
    uint16_t addr;       //registro de direeciones
}MOS6502;

typedef struct memory{
    uint8_t* ram;
}MEMORIA;



#endif /* ESTRUCTURAS_BASICAS_H */
