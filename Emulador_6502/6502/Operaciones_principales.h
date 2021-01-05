/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Operaciones_principales.h
 * Author: Dell
 *
 * Created on 10 de octubre de 2020, 05:18 PM
 */

#ifndef OPERACIONES_PRINCIPALES_H
#define OPERACIONES_PRINCIPALES_H
#include <stdio.h>

#include "Estructuras_basicas.h"

//FUNCION PARA INICIALIZAR LA MEMORIA RAM
void inicializar_memoria(MEMORIA* mem);

//FUNCION PARA INICIALIZAR EL 
void reset_MOS6502(MOS6502* cpu, MEMORIA* mem);

void print_MOS6502(MOS6502* cpu);

void scan_codigo(MOS6502* cpu, MEMORIA* mem, const char* nombre);

//void printBits(size_t const size, void const * const ptr);

#endif /* OPERACIONES_PRINCIPALES_H */
