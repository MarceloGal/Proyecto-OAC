/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <inttypes.h>
#include <windows.h>
#include "Estructuras_basicas.h"

int X2=61,Y2=11;

/*
typedef struct memory{
uint8_t* ram;
}MEMORIA;
*/

/*
 * coord x de manzana:      0x00
 * coord y de manzana:      0x01
 * byte de tecla:           0xff
 * coord x de serpiente:    0x10
 * coord y de serpiente:    0x11
 * inicio pares de cuerpo:  0x12
 * direccion serpiente:     0x02
 * tamaño serpiente:        0x03
*/



void imprimirPantalla2(MEMORIA mem){
    int x,y,tam,a,dir,est;
    char c;
    tam = mem.ram[0x03];
    for(y=0;y<=Y2;y++){
        for(x=0;x<=X2;x++){
            c=' ';
            if((x==0 && y==(int)mem.ram[0x03])||(x==0 && y==(int)mem.ram[0x04])||(x==0 && y==(int)mem.ram[0x05])){
                c='|';
            }
            if((x==X2-1 && y==(int)mem.ram[0x06])||(x==X2-1 && y==(int)mem.ram[0x07])||(x==X2-1 && y==(int)mem.ram[0x08])){
                c='|';
            }
            if(x==mem.ram[0x01] && y==mem.ram[0x02]){
                c='O';
            }
            if(x==X2){
                c='X';
            }
            if(y==Y2){
                c='X';
            }
            printf("%c",c);
        }printf("\n");
    }
    
/*
    printf("coord Cabeza X:%d\n",(int)mem.ram[0x10]);
    printf("coord Cabeza Y:%d\n",(int)mem.ram[0x11]);
*/
}



void InputOutput2(MEMORIA *mem) {
    
    char tecla;    

        if(kbhit()){
            system("cls");
            tecla = getch();
            switch(tecla){
                case 72:{
                    mem->ram[0xff]=72;
                    break;
                }
                case 80:{
                    mem->ram[0xff]=80;
                    
                    break;
                }
                case 119:{
                    mem->ram[0xff]=119;
                    break;
                }
                case 115:{
                    mem->ram[0xff]=115;
                    break;
                }
                default:{
                    mem->ram[0xff]=40;
                    break;
                }
              
            }
            imprimirPantalla2(*mem);
        }else{
            system("cls");
            mem->ram[0xff]=40;
            imprimirPantalla2(*mem);
            
        }
    

              

}