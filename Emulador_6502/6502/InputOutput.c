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

int X=60,Y=30;

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

void actualizarValores(MEMORIA mem, int clave){
    switch(clave){
        case 1:{
            //mem.ram[0x11]--;
            //mem.ram[0x02] = (uint8_t)2;
            break;
        }
        case 2:{
            //mem.ram[0x11]++;
            //mem.ram[0x02] = (uint8_t)1;
            break;            
        }
        case 3:{
            //mem.ram[0x10]++;
            //mem.ram[0x02] = (uint8_t)1;
            break;            
        }
        case 4:{
            //mem.ram[0x10]--;
           // mem.ram[0x02] = (uint8_t)8;
            break;            
        }
    }
}

void revisarCuerpo(MEMORIA mem,int x,int y){
    int c,a,dir=0x12;
    c = (int)mem.ram[0x03];
    for(a=0;a<c;a++,dir+=2){
        if(x == mem.ram[dir] && y == mem.ram[dir+1]){
            printf("N");
        }
    }
}
float c;
void imprimirPantalla(MEMORIA mem){
    int x,y,tam,a,dir,est;
    tam = mem.ram[0x03];
    for(y=0;y<Y;y++){
        for(x=0;x<X;x++){
            if(x==X-1 || y==Y-1 || x==0 || y == 0){
                if(y==Y-1 || y == 0){
                    printf("-");
                }else{
                    printf("|");
                }
                
            }else{
                dir=0x12; est=1;
                for(a=0;a<tam/2;a++){
                    if(x == (int)mem.ram[dir] && y == (int)mem.ram[dir+1]){
                        printf("N");
                        est=0;
                        break;
                    }
                    dir+=2;
                }
                if(est){
                    if( x == (int)(mem.ram[0x10]) && y == (int)(mem.ram[0x11])){
                        printf("C");
                    }else{
                        if( x == (int)(mem.ram[0x00]) && y == (int)(mem.ram[0x01])){
                            printf("M");
                        }
                        else{
                            printf(" ");
                        }
                    }   
                }                   
            }
        }printf("\n");
    }
    
/*
    printf("coord Cabeza X:%d\n",(int)mem.ram[0x10]);
    printf("coord Cabeza Y:%d\n",(int)mem.ram[0x11]);
*/
}



void InputOutput(MEMORIA *mem) {
    
 
    //mem.ram = (uint8_t*)malloc(sizeof(uint8_t)*256*256);
    char tecla;
/*
    mem->ram[0x00]=(uint8_t)10; mem->ram[0x01]=(uint8_t)10;   //corrd manzana
    mem->ram[0x10]=(uint8_t) 3; mem->ram[0x11]=(uint8_t) 2;   //coord cabeza serp
    mem->ram[0x03]= (uint8_t)2;                              //tamaño inicial
    mem->ram[0x01]= (uint8_t)2;                              //direccion inicial a la derecha
    mem->ram[0x12]= (uint8_t)5; mem->ram[0x13]= (uint8_t)5;   //coord cuerp 1
    mem->ram[0x14]= (uint8_t)5; mem->ram[0x15]= (uint8_t)6;   //coord cuerp 1
*/
    
      
    
    

        if(kbhit()){
            system("cls");
            tecla = getch();
            switch(tecla){
                case 72:{
                    mem->ram[0xff]=72;
                    //actualizarValores(*mem,1);
                    break;
                }
                case 80:{
                    mem->ram[0xff]=80;
                    //actualizarValores(*mem,2);
                    break;
                }
                case 77:{
                    mem->ram[0xff]=77;
                    //actualizarValores(*mem,3);
                    break;
                }
                case 75:{
                    mem->ram[0xff]=75;
                    //actualizarValores(*mem,4);
                    break;
                }
                default:{
                    //mem->ram[0xff]=40;
                    break;
                }
              
            }
            imprimirPantalla(*mem);
        }else{
            system("cls");
            //mem->ram[0xff]=40;
            imprimirPantalla(*mem);
            
        }
    

              

}