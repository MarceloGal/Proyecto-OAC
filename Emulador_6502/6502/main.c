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
#include "InputOutput.h"
#include "InputOutput2.h"
///////////////////////////////////////////////
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>
#include <unistd.h>
//////////////////////////////////////////////
/*
 * 
 */

  
int main(int argc, char** argv) {
    char J;
    MOS6502 cpu;
    MEMORIA mem;
    ////////////////////////
    srand(time(NULL));
    ///////////////////////////
    void (*set_de_instrucciones[0xFF])(MOS6502*,MEMORIA*);
    cargar_instrucciones(set_de_instrucciones); //CARGAMOS LAS INSTRUCCIONES AL ARREGLO DE FUNCIONES
    //INICIZALIZAR RAM
    inicializar_memoria(&mem);
    //PUNTO DE INICIO DEL PROGRAMA
    mem.ram[RESET_VAL_MSB] = 0x06;
    mem.ram[RESET_VAL_LSB] = 0x00;
    // ACTUALIZAR EL PC
    reset_MOS6502(&cpu,&mem);
    printf("---------------------------\n");
    printf("    EMULADOR PARA 6502\n");
    printf("---------------------------\n");
    printf("        1. Snake\n");
    printf("        2. Pong\n");
    printf("---------------------------\n");
    printf("Ingrese la opcion a jugar: ");
    scanf("%d", &J);
    if(J == 1)
        scan_codigo(&cpu,&mem,"snake.txt");
    if(J == 2)
        scan_codigo(&cpu,&mem,"Pong.txt");
    //FUNCION PARA LEER LAS INSTRUCCIONES DE UN TXT
    
    ///////////////////////////////////
    mem.ram[0x00FE] = rand()%256;
    ///////////////////////////////////
    
    //print_MOS6502(&cpu);
    cpu.sr = 0x20;//&= 0xEF;
    while(1){
        mem.ram[0xfe] = (uint8_t)rand()%28;
            //InputOutput(&mem);
        // *********************** FETCH ************************ //
        cpu.ins = mem.ram[cpu.pc];
        // *********************** DECODE *********************** //
        //if(cpu.ins == (uint8_t)0x9) InputOutput(&mem);
        //print_MOS6502(&cpu);
        //if(cpu.pc=0x737) print_MOS6502(&cpu);
        //InputOutput(&mem);
        set_de_instrucciones[cpu.ins](&cpu,&mem); //************** EXECUTE / WRITEBACK ******************///
        //InputOutput2(&mem);

        if(cpu.sr & 0x10) break; //************ BANDERA BREAK ********************//
    }
    //printf("%d\n",mem.ram[0x99]);
    //print_MOS6502(&cpu);
    return (EXIT_SUCCESS);
}