/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Operaciones_principales.c
 * Author: Dell
 * 
 * Created on 10 de octubre de 2020, 05:18 PM
 */

#include "Operaciones_principales.h"
#include "Estructuras_basicas.h"
#include "Set_instrucciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

//FUNCION PARA INICIALIZAR LA MEMORIA RAM
void inicializar_memoria(MEMORIA* mem){
    mem->ram = (uint8_t*)malloc(sizeof(uint8_t)*256*256);
}


void reset_MOS6502(MOS6502* cpu, MEMORIA* mem){
    int8_t pch = mem->ram[RESET_VAL_MSB];
    int8_t pcl = mem->ram[RESET_VAL_LSB];
    cpu->pc = (pch*256) + pcl;
}

void print_MOS6502(MOS6502* cpu){
    printf("*******************************\n");
    printf("Ac:        %04x\n",cpu->a);
    printf("Reg X:     %04x\n",cpu->x);
    printf("Reg Y:     %04x\n",cpu->y);
    printf("PC:        %04x\n",cpu->pc);
    printf("SP:        %04x\n",cpu->sp);
    printf("SR:        NV-BDIZC\n");
    printf("           ");
    printBits(sizeof(cpu->sr), &cpu->sr);
    printf("Reg. Inst: %04x\n",cpu->ins);
    printf("Reg. Add:  %04x\n",cpu->addr);    
    printf("*******************************\n");    
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void scan_codigo(MOS6502* cpu, MEMORIA* mem, const char* nombre){
    FILE* archivo = fopen(nombre,"r");
    if(archivo != NULL){
        int var;
        uint16_t aux = cpu->pc;
        while(1){
            fscanf(archivo,"%x",&var);
            if(feof(archivo)) break;
            mem->ram[aux++] = var;
        }
    }else{
        printf("Terrible error de concepto.\n");
    }
}


