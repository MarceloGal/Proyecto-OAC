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

/*
void fetch_IF(MOS6502* cpu, MEMORIA* mem){
    cpu->ins = mem->ram[cpu->pc];    
}

void decode_ID(MOS6502* cpu, MEMORIA* mem){
    if(0xa9 == cpu->ins){
        cpu->addr = cpu->pc+1;
    }else if(cpu->ins == 0x8d){
        cpu->addr = cpu->pc+1;
    }
    else if(cpu->ins == 0x69){
        //*************************************
        //          ADC
        //*************************************
        cpu->addr = cpu->pc+1;
    }else if(cpu->ins == 0x69){
        
    }
}

void execute_EX(MOS6502* cpu, MEMORIA* mem){
    if(0xa9 == cpu->ins){
        LDA(cpu,mem);
        cpu->pc += 2;
    }else if(cpu->ins == 0x8d){
        STA(cpu,mem);
        cpu->pc += 3;
    }else if(cpu->ins == 0xaa){
        TAX(cpu,mem);
        cpu->pc++;
    }else if(cpu->ins == 0x8a){
        TXA(cpu,mem);
        cpu->pc++;
    }else if(cpu->ins == 0xca){
        DEX(cpu,mem);
        cpu->pc++;
    }else if(cpu->ins == 0xe8){
        INX(cpu,mem);
        cpu->pc++;
    }else if(cpu->ins == 0xa8){
        TAY(cpu,mem);
        cpu->pc++;
    }else if(cpu->ins == 0x98){
        TYA(cpu,mem);
        cpu->pc++;
    }else if(cpu->ins == 0x88){
        DEY(cpu,mem);
        cpu->pc++;
    }else if(cpu->ins == 0xc8){
        INY(cpu,mem);
        cpu->pc++;
    }
    
}
*/

void print_MOS6502(MOS6502* cpu){
    printf("*******************************\n");
    printf("Ac: %04x\n",cpu->a);
    printf("Reg X: %04x\n",cpu->x);
    printf("Reg Y: %04x\n",cpu->y);
    printf("PC: %04x\n",cpu->pc);
    printf("SP: %04x\n",cpu->sp);
    printf("SR: %04x\n",cpu->sr);
    printf("Reg. Inst: %04x\n",cpu->ins);
    printf("Reg. Add: %04x\n",cpu->addr);    
    printf("*******************************\n");    
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
    }
}


