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
#include <string.h>
#include <inttypes.h>

//FUNCION PARA INICIALIZAR LA MEMORIA RAM
void inicializar_memoria(MEMORIA* mem){
    mem->ram = (uint8_t*)malloc(sizeof(uint8_t)*256*256);
}


void reset_MOS6502(MOS6502* cpu, MEMORIA* mem){
    int8_t pch = mem->ram[RESET_VAL_MSB];
    int8_t pcl = mem->ram[RESET_VAL_LSB];
    cpu->pc = (pch*256) + pcl;
    cpu->sp = (int8_t)0xaf;
    cpu->a = 0;
    cpu->x = 0;
    cpu->y = 0;
    cpu->addr = cpu->pc;
    cpu->ins = 0;
}
int contador = 1;
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
    printf("Reg. Addr: %04x\n",cpu->addr);
    printf("Instruccion numero: %d\n",contador++);
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
            mem->ram[aux] = var;
            aux++;
        }
        if(strcmp(nombre,"Pong.txt") == 0)
            mem->ram[0x99] = (uint8_t)1;
        if(strcmp(nombre,"snake.txt") == 0)
            mem->ram[0x99] = (uint8_t)0;
    }else{
        printf("Terrible error de concepto.\n");
        exit(1);
    }
    fclose(archivo);
}


