/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: FRANCO CHIROQUE SANTINI 20173126
 *
 * Created on 10 de octubre de 2020, 02:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "Estructuras_basicas.h"
#include "Set_instrucciones.h"
#include "Operaciones_principales.h"

/*
 * 
 */

  
int main(int argc, char** argv) {
    MOS6502 cpu;
    MEMORIA mem;
    
    void (*set_de_instrucciones[0xFF])(MOS6502*,MEMORIA*);
    cargar_instrucciones(set_de_instrucciones); //CARGAMOS LAS INSTRUCCIONES AL ARREGLO DE FUNCIONES
    //INICIZALIZAR RAM
    inicializar_memoria(&mem);
    //PUNTO DE INICIO DEL PROGRAMA
    mem.ram[RESET_VAL_MSB] = 0x20;
    mem.ram[RESET_VAL_LSB] = 0x00;
    // ACTUALIZAR EL PC
    reset_MOS6502(&cpu,&mem);
    //FUNCION PARA LEER LAS INSTRUCCIONES DE UN TXT
    scan_codigo(&cpu,&mem,"Array-len-code.txt");
    
    print_MOS6502(&cpu);
    cpu.sr &= 0xEF;
    while(1){
        // *********************** FETCH ************************ //
        cpu.ins = mem.ram[cpu.pc];
        // *********************** DECODE *********************** //
        set_de_instrucciones[cpu.ins](&cpu,&mem); //************** EXECUTE / WRITEBACK ******************///
        print_MOS6502(&cpu);
        if(cpu.sr & 0x10) break; //************ BANDERA BREAK ********************//
    }
    print_MOS6502(&cpu);
   
   return (EXIT_SUCCESS);
}