/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Set_instrucciones.c
 * Author: Dell
 * 
 * Created on 10 de octubre de 2020, 05:13 PM
 */

#include "Set_instrucciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "Estructuras_basicas.h"
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

void cargar_instrucciones(void (*set_de_instrucciones[0xFF])(MOS6502*,MEMORIA*)){
    set_de_instrucciones[0x69] = ADC_inmediate;
    set_de_instrucciones[0x65] = ADC_zero_page;
    set_de_instrucciones[0x75] = ADC_zero_page_X;
    set_de_instrucciones[0x6D] = ADC_absolute;
    set_de_instrucciones[0x7D] = ADC_absolute_X;
    set_de_instrucciones[0x79] = ADC_absolute_Y;
    set_de_instrucciones[0x61] = ADC_indirect_X;
    set_de_instrucciones[0x71] = ADC_indirect_Y;
    
    set_de_instrucciones[0x29] = AND_inmediate;
    set_de_instrucciones[0x25] = AND_zero_page;
    set_de_instrucciones[0x35] = AND_zero_page_X;
    set_de_instrucciones[0x2d] = AND_absolute;
    set_de_instrucciones[0x3D] = AND_absolute_X;
    set_de_instrucciones[0x39] = AND_absolute_Y;
    set_de_instrucciones[0x21] = AND_indirect_X;
    set_de_instrucciones[0x31] = AND_indirect_Y;
    
    set_de_instrucciones[0x0A] = ASL_accumulador;
    set_de_instrucciones[0x06] = ASL_zero_page;
    set_de_instrucciones[0x16] = ASL_zero_page_X;
    set_de_instrucciones[0x0E] = ASL_absolute;
    set_de_instrucciones[0x1E] = ASL_absolute_X;
    
    set_de_instrucciones[0x24] = BIT_zero_page;
    set_de_instrucciones[0x2C] = BIT_absolute;
    
    set_de_instrucciones[0x10] = BPL;
    set_de_instrucciones[0x30] = BMI;
    set_de_instrucciones[0x50] = BVC;
    set_de_instrucciones[0x70] = BVS;
    set_de_instrucciones[0x90] = BCC;
    set_de_instrucciones[0xB0] = BCS;
    set_de_instrucciones[0xD0] = BNE;
    set_de_instrucciones[0xF0] = BEQ;
    
    set_de_instrucciones[0x00] = BRK;
    
    set_de_instrucciones[0xC9] = CMP_inmediate;
    set_de_instrucciones[0xC5] = CMP_zero_page;
    set_de_instrucciones[0xD5] = CMP_zero_page_X;
    set_de_instrucciones[0xCD] = CMP_absolute;
    set_de_instrucciones[0xDD] = CMP_absolute_X;
    set_de_instrucciones[0xD9] = CMP_absolute_Y;
    set_de_instrucciones[0xC1] = CMP_indirect_X;
    set_de_instrucciones[0xD1] = CMP_indirect_Y;
    
    set_de_instrucciones[0xE0] = CPX_inmediate;
    set_de_instrucciones[0xE4] = CPX_zero_page;
    set_de_instrucciones[0xEC] = CPX_absolute;
    
    set_de_instrucciones[0xC0] = CPY_inmediate;
    set_de_instrucciones[0xC4] = CPY_zero_page;
    set_de_instrucciones[0xCC] = CPY_absolute;
    
    set_de_instrucciones[0xC6] = DEC_zero_page;
    set_de_instrucciones[0xD6] = DEC_zero_page_X;
    set_de_instrucciones[0xCE] = DEC_absolute;
    set_de_instrucciones[0xDE] = DEC_absolute_X;
    
    set_de_instrucciones[0x49] = EOR_inmediate;
    set_de_instrucciones[0x45] = EOR_zero_page;
    set_de_instrucciones[0x55] = EOR_zero_page_X;
    set_de_instrucciones[0x4D] = EOR_absolute;
    set_de_instrucciones[0x5D] = EOR_absolute_X;
    set_de_instrucciones[0x59] = EOR_absolute_Y;
    set_de_instrucciones[0x41] = EOR_indirect_X;
    set_de_instrucciones[0x51] = EOR_indirect_Y;
    
    set_de_instrucciones[0x18] = CLC;
    set_de_instrucciones[0x38] = SEC;
    set_de_instrucciones[0x58] = CLI;
    set_de_instrucciones[0x78] = SEI;
    set_de_instrucciones[0xB8] = CLV;
    set_de_instrucciones[0xD8] = CLD;
    set_de_instrucciones[0xF8] = SED;
    
    set_de_instrucciones[0xE6] = INC_zero_page;
    set_de_instrucciones[0xF6] = INC_zero_page_X;
    set_de_instrucciones[0xEE] = INC_absolute;
    set_de_instrucciones[0xFE] = INC_absolute_X;
    
    set_de_instrucciones[0x4C] = JMP_absolute;
    set_de_instrucciones[0x6C] = JMP_indirect;
    
    set_de_instrucciones[0x20] = JSR_absolute;
    
    set_de_instrucciones[0xA9] = LDA_inmediate;
    set_de_instrucciones[0xA5] = LDA_zero_page;
    set_de_instrucciones[0xB5] = LDA_zero_page_X;
    set_de_instrucciones[0xAD] = LDA_absolute;
    set_de_instrucciones[0xBD] = LDA_absolute_X;
    set_de_instrucciones[0xB9] = LDA_absolute_Y;
    set_de_instrucciones[0xA1] = LDA_indirect_X;
    set_de_instrucciones[0xB1] = LDA_indirect_Y;
    
    set_de_instrucciones[0xA2] = LDX_inmediate;
    set_de_instrucciones[0xA6] = LDX_zero_page;
    set_de_instrucciones[0xb6] = LDX_zero_page_Y;
    set_de_instrucciones[0xAE] = LDX_absolute;
    set_de_instrucciones[0xBE] = LDX_absolute_Y;
    
    set_de_instrucciones[0xA0] = LDY_inmediate;
    set_de_instrucciones[0xA4] = LDY_zero_page;
    set_de_instrucciones[0xB4] = LDY_zero_page_X;
    set_de_instrucciones[0xAC] = LDY_absolute;
    set_de_instrucciones[0xBC] = LDY_absolute_X;
    
    set_de_instrucciones[0x4A] = LSR_accomulator;
    set_de_instrucciones[0x46] = LSR_zero_page;
    set_de_instrucciones[0x56] = LSR_zero_page_X;
    set_de_instrucciones[0x4E] = LSR_absolute;
    set_de_instrucciones[0x5E] = LSR_absolute_X;
    
    set_de_instrucciones[0xEA] = NOP;
    
    set_de_instrucciones[0x09] = ORA_inmediate;
    set_de_instrucciones[0x05] = ORA_zero_page;
    set_de_instrucciones[0x15] = ORA_zero_page_X;
    set_de_instrucciones[0x0d] = ORA_absolute;
    set_de_instrucciones[0x1D] = ORA_absolute_X;
    set_de_instrucciones[0x19] = ORA_absolute_Y;
    set_de_instrucciones[0x01] = ORA_indirect_X;
    set_de_instrucciones[0x11] = ORA_indirect_Y;
    
    set_de_instrucciones[0xAA] = TAX;
    set_de_instrucciones[0x8A] = TXA;
    set_de_instrucciones[0xCA] = DEX;
    set_de_instrucciones[0xE8] = INX;
    set_de_instrucciones[0xA8] = TAY;
    set_de_instrucciones[0x98] = TYA;
    set_de_instrucciones[0x88] = DEY;
    set_de_instrucciones[0xC8] = INY;
    
    set_de_instrucciones[0x2A] = ROL_accumulator;
    set_de_instrucciones[0x26] = ROL_zero_page;
    set_de_instrucciones[0x36] = ROL_zero_page_X;
    set_de_instrucciones[0x2e] = ROL_absolute;
    set_de_instrucciones[0x3e] = ROL_absolute_X;
    
    set_de_instrucciones[0x6A] = ROR_accumulator;
    set_de_instrucciones[0x66] = ROR_zero_page;
    set_de_instrucciones[0x66] = ROR_zero_page_X;
    set_de_instrucciones[0x6e] = ROR_absolute;
    set_de_instrucciones[0x7e] = ROR_absolute_X;
    
    set_de_instrucciones[0x40] = RTI_implied;
    
    set_de_instrucciones[0x60] = RTS_implied;
    
    set_de_instrucciones[0xE9] = SBC_inmediate;
    set_de_instrucciones[0xe5] = SBC_zero_page;
    set_de_instrucciones[0xf5] = SBC_zero_page_X;
    set_de_instrucciones[0xed] = SBC_absolute;
    set_de_instrucciones[0xfd] = SBC_absolute_X;
    set_de_instrucciones[0xf9] = SBC_absolute_Y;
    set_de_instrucciones[0xe1] = SBC_indirect_X;
    set_de_instrucciones[0xf1] = SBC_indirect_Y;
    
    set_de_instrucciones[0x85] = STA_zero_page;
    set_de_instrucciones[0x95] = STA_zero_page_X;
    set_de_instrucciones[0x8D] = STA_absolute;
    set_de_instrucciones[0x9D] = STA_absolute_X;
    set_de_instrucciones[0x99] = STA_absolute_Y;
    set_de_instrucciones[0x81] = STA_indirect_X;
    set_de_instrucciones[0x91] = STA_indirect_Y;
    
    set_de_instrucciones[0x9A] = TXS;
    set_de_instrucciones[0xBA] = TSX;
    set_de_instrucciones[0x48] = PHA;
    set_de_instrucciones[0x68] = PLA;
    set_de_instrucciones[0x08] = PHP;
    set_de_instrucciones[0x28] = PLP;
    
    set_de_instrucciones[0x86] = STX_zero_page;
    set_de_instrucciones[0x96] = STX_zero_page_Y;
    set_de_instrucciones[0x8E] = STX_absolute;
    
    set_de_instrucciones[0x84] = STY_zero_page;
    set_de_instrucciones[0x94] = STY_zero_page_X;
    set_de_instrucciones[0x8c] = STY_absolute;
    
    //set_de_instrucciones[0xfa] = Interrupcion;
    
    ///////////////////////////////////////
    // I M P R I M E        S N A K E
    /////////////////////////////////////////
    /*set_de_instrucciones[0xFB] = IMP;
    ///////////////////////////////////////
    // L E E        
    /////////////////////////////////////////
    set_de_instrucciones[0xFA] = LEE;
    */
}


//////////////////
//// ADC
//////////////////

void ADC_inmediate(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[cpu->addr] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    //if((cpu->a & 0x80) && (mem->ram[cpu->addr] & 0x80) && !(aux & 0x80)) cpu->sr |= 0x40; //MODIFICAR OVERFLOW
    //else if(!(cpu->a & 0x80) && !(mem->ram[cpu->addr] & 0x80) && (aux & 0x80)) cpu->sr |= 0x40;
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;

    cpu->pc += 2;
}
void ADC_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[mem->ram[cpu->addr]] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;
}
void ADC_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[mem->ram[cpu->addr] + cpu->x] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    else cpu->sr &= 0xFE;
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;    
}
void ADC_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    else cpu->sr &= 0xFE;
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 3;
}
void ADC_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    else cpu->sr &= 0xFE;
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 3;
}
void ADC_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    else cpu->sr &= 0xFE;
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 3;
}
void ADC_indirect_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[mem->ram[cpu->addr] + cpu->x] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    else cpu->sr &= 0xFE;
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;   
}
void ADC_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = mem->ram[mem->ram[cpu->addr] + cpu->y] + cpu->a;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    else cpu->sr &= 0xFE;
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;
}

//////////////////////
//  AND: // N/Z  
//////////////////////
void AND_inmediate(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a &= mem->ram[cpu->addr];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void AND_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a &= mem->ram[mem->ram[cpu->addr]]; //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void AND_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1; 
    cpu->a &= mem->ram[mem->ram[cpu->addr] + cpu->x]; 
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void AND_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a &= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void AND_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a &= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void AND_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a &= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void AND_indirect_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a &= mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void AND_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a &= mem->ram[mem->ram[cpu->addr] + cpu->y];
    //EXECUTE
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}

/////////////////////////
///     ASL/ C-N-Z
/////////////////////////
void ASL_accumulador(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    uint8_t aux = cpu->a&0x80;
    aux >>= 7;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    //MODIFICAR OPERANDO
    cpu->a <<= 1;
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc++;
}
void ASL_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = (mem->ram[mem->ram[cpu->addr]])&0x80;
    aux >>=7;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    mem->ram[mem->ram[cpu->addr]] <<= 1;
    //WRITEBACK
    if(!mem->ram[mem->ram[cpu->addr]]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr]] & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    
    cpu->pc+=2;
}
void ASL_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = (mem->ram[mem->ram[cpu->addr]+cpu->x])&0x80;
    aux >>=7;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    mem->ram[mem->ram[cpu->addr] + cpu->x] <<= 1;
    //WRITEBACK
    if(!mem->ram[mem->ram[cpu->addr]+cpu->x]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr]+cpu->x] & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    
    cpu->pc+=2;
}
void ASL_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = (mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]])&0x80;
    aux >>=7;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] <<= 1;
    //WRITEBACK
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if((mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    
    cpu->pc+=3;
}
void ASL_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = (mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x])&0x80;
    aux >>=7;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] <<= 1;
    //WRITEBACK
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc+=3;
}

///////////
//  BIT
///////////
void BIT_zero_page(MOS6502* cpu, MEMORIA* mem){
     //EXECUTE
    cpu->addr = cpu->pc + 1;
    //BANDERA Z 
    if(!(cpu->a & mem->ram[mem->ram[cpu->addr]])) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    uint8_t bit7_6 = mem->ram[mem->ram[cpu->addr]] & 0xC0;
    cpu->sr &= 0x3F;
    cpu->sr |= bit7_6; //MODIFICAR N-V
    cpu->pc += 2;

    
/*
 *  antiguo
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    uint8_t zeroflag = cpu->a & mem->ram[mem->ram[cpu->addr]];
    zeroflag &= 1;
    uint8_t bit7_6 = 0xC0 & mem->ram[mem->ram[cpu->addr]];//1100 0000
    
    //WRITEBACK
    bit7_6 |= zeroflag;
    cpu->sr ^= bit7_6;
    cpu->pc += 2;
*/
}

void BIT_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    uint8_t zeroflag = cpu->a & mem->ram[mem->ram[cpu->addr]];
    zeroflag &= 1;
    uint8_t bit7_6 = 0xC0 & mem->ram[mem->ram[cpu->addr]];//1100 0000
    //WRITEBACK
    bit7_6 |= zeroflag;
    cpu->sr ^= bit7_6;
    cpu->pc += 3;
}



////////////
// BRANCH
///////////
void BPL(MOS6502* cpu, MEMORIA* mem){
    //BRANCH Z = 0
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x80){
        cpu->pc += 2;
    }else{
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux + 2;
        }else{
            cpu->pc += mem->ram[cpu->addr] + 2;
        }
    }
}
void BMI(MOS6502* cpu, MEMORIA* mem){
    //BRANCH N = 1
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x80){
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux+2;
        }else{
            cpu->pc += mem->ram[cpu->addr]+2;
        }
    }else{
        cpu->pc += 2;
    }
}
void BVC(MOS6502* cpu, MEMORIA* mem){
    //BRANCH OV = 0
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x70){
        cpu->pc += 2;
    }else{
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux+2;
        }else{
            cpu->pc += mem->ram[cpu->addr]+2;
        }
    }    
}
void BVS(MOS6502* cpu, MEMORIA* mem){
    //BRANCH OV = 1
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x70){
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux+2;
        }else{
            cpu->pc += mem->ram[cpu->addr]+2;
        }
    }else{
        cpu->pc += 2;
    }
}
void BCC(MOS6502* cpu, MEMORIA* mem){
    //BRANCH C = 0
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x01){
        cpu->pc += 2;
    }else{
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux+2;
        }else{
            cpu->pc += mem->ram[cpu->addr]+2;
        }
    }
}
void BCS(MOS6502* cpu, MEMORIA* mem){
    //BRANCH C = 1
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x01){
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux+2;
        }else{
            cpu->pc += mem->ram[cpu->addr]+2;
        }
    }else{
        cpu->pc += 2;
    }
}
void BNE(MOS6502* cpu, MEMORIA* mem){
    //BRANCH Z = 0
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x02){
        cpu->pc += 2;
    }else{
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux+2;
        }else{
            cpu->pc += mem->ram[cpu->addr]+2;
        }
    }
}
void BEQ(MOS6502* cpu, MEMORIA* mem){
    //BRANCH Z = 1
    //WRITEBACK
    cpu->addr = cpu->pc + 1;
    if(cpu->sr & 0x02){
        if(mem->ram[cpu->addr]&0x80){
            uint16_t aux = 0xFF00;
            aux += mem->ram[cpu->addr];
            cpu->pc += aux+2;
        }else{
            cpu->pc += mem->ram[cpu->addr]+2;
        }
    }else{
        cpu->pc += 2;
    } 
}

void BRK(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->sr |= 0x10;
    //WRITEBACK
    cpu->pc++;
}

///////////////
//  CMP // N / Z / C
///////////////
void CMP_inmediate(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[cpu->addr];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[cpu->addr]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;
}

void CMP_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[mem->ram[cpu->addr]]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;
}
void CMP_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;        
}
void CMP_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 3;        
}
void CMP_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 3;       
}
void CMP_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 3;
}
void CMP_indirect_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;
}
void CMP_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a;
    aux -= mem->ram[mem->ram[cpu->addr] + cpu->y];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->a >= mem->ram[mem->ram[cpu->addr] + cpu->y]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;
}
/////////////
//  CPX
///////////
void CPX_inmediate(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->x;
    aux -= mem->ram[cpu->addr];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->x>=mem->ram[cpu->addr]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;
}
void CPX_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->x;
    aux -= mem->ram[mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->x >= mem->ram[mem->ram[cpu->addr]]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;     
}
void CPX_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->x;
    aux -= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->x >= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 3;        
}
//////////////
//  CPY
////////////
void CPY_inmediate(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->y;
    aux -= mem->ram[cpu->addr];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->y >= mem->ram[cpu->addr]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;        
}
void CPY_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->y;
    aux -= mem->ram[mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->y >= mem->ram[mem->ram[cpu->addr]]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 2;     
}
void CPY_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->y;
    aux -= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr |= 0x02; //ZERO = 1
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr |= 0x80; //NEGATIVE = 1;
    else cpu->sr &= 0x7F;
    if(cpu->y >= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) cpu->sr |= 0x01; //CARRY = 1
    else cpu->sr &= 0xFE;
    cpu->pc += 3;    
}

/////////////////////////
//      DEC
////////////////////////
void DEC_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    mem->ram[mem->ram[cpu->addr]]--;
    //WRITEBACK
    //MODIFICAR BANDERAS
    uint8_t aux = mem->ram[mem->ram[cpu->addr]];
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void DEC_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    mem->ram[mem->ram[cpu->addr] + cpu->x]--;
    //WRITEBACK
    uint8_t aux = mem->ram[mem->ram[cpu->addr] + cpu->x];
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void DEC_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]--;
    //WRITEBACK
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void DEC_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]--;
    //WRITEBACK
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x];
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
///////////////
//  EOR // N - Z
////////////
void EOR_inmediate(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[cpu->addr];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void EOR_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[mem->ram[cpu->addr]];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    
    cpu->pc += 2;    
}
void EOR_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void EOR_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[mem->ram[cpu->addr + 1]*256 + mem->ram[cpu->addr]];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void EOR_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[mem->ram[cpu->addr + 1]*256 + mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;    
}
void EOR_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[mem->ram[cpu->addr + 1]*256 + mem->ram[cpu->addr] + cpu->y];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;        
}
void EOR_indirect_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;    
}
void EOR_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTTE
    cpu->addr = cpu->pc + 1;
    cpu->a ^= mem->ram[mem->ram[cpu->addr] + cpu->y];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
//////////////////
//  
//////////////////
void CLC(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr &= 0xFE;
    cpu->pc++;
}
void SEC(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr |= 0x01;
    cpu->pc++;
}
void CLI(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr &= 0xFB;
    cpu->pc++;
}
void SEI(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr |= 0x04;
    cpu->pc++;
}
void CLV(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr &= 0xBF;
    cpu->pc++;
}
void CLD(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr &= 0xF7;
    cpu->pc++;
}
void SED(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr |= 0x08;
    cpu->pc++;
}
/////////////////////////
//     INC
////////////////////////
void INC_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = ++mem->ram[mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void INC_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = ++mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void INC_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = ++mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    //WRITEBACK
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void INC_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint8_t aux = ++mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!aux) cpu->sr|= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(aux & 0x80) cpu->sr|= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}

/////////////////////////
//     JMP
////////////////////////
void JMP_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->pc = mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr];
}
void JMP_indirect(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    uint16_t direccion;
    direccion = mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr];
    cpu->pc = mem->ram[direccion+1]*256 + mem->ram[direccion];
}

/////////////////////////
//     JSR
////////////////////////
void JSR_absolute(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    //InputOutput(mem);
    cpu->addr = cpu->pc+1;
    uint16_t aux_pc = cpu->pc + 2;
    uint8_t aux_l = aux_pc&0x00FF;
    uint8_t aux_m = aux_pc>>=8;
    mem->ram[cpu->sp--] = aux_m;
    mem->ram[cpu->sp--] = aux_l;
    cpu->pc = mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr];
}

/////////////////////////
//     LDA
////////////////////////
void LDA_inmediate(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->a = mem->ram[cpu->addr];
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}

void LDA_zero_page(MOS6502* cpu, MEMORIA* mem){
    
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    
    cpu->a = mem->ram[mem->ram[cpu->addr]];
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}

void LDA_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->a = mem->ram[mem->ram[cpu->addr]+cpu->x];
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}

void LDA_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->a = mem->ram[(mem->ram[cpu->addr+1])*256 + mem->ram[cpu->addr]];
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}

void LDA_absolute_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->a = mem->ram[(mem->ram[cpu->addr+1])*256 + mem->ram[cpu->addr] + cpu->x];
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}

void LDA_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->a = mem->ram[(mem->ram[cpu->addr+1])*256 + mem->ram[cpu->addr] + cpu->y];
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}

//FIXED
void LDA_indirect_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    uint16_t dir;
    dir = mem->ram[mem->ram[cpu->addr] + cpu->x + 1]*256 + mem->ram[mem->ram[cpu->addr] + cpu->x] ;
    cpu->a = mem->ram[dir];
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}


void LDA_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    uint16_t dir;
    dir = mem->ram[mem->ram[cpu->addr]+1]*256 + mem->ram[mem->ram[cpu->addr]];
    cpu->a = mem->ram[dir + cpu->y];
    
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}

//////////////////////////////////////////////////////////
//              LDX
/////////////////////////////////////////////////////////
void LDX_inmediate(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->x = mem->ram[cpu->addr];
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void LDX_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->x = mem->ram[mem->ram[cpu->addr]];
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void LDX_zero_page_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->x = mem->ram[mem->ram[cpu->addr] + cpu->y];
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void LDX_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->x = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] ];
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void LDX_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->x = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y];
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}

//////////////////////////////////////////////////////////
//                  LDY
/////////////////////////////////////////////////////////
void LDY_inmediate(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->y = mem->ram[cpu->addr];
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void LDY_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->y = mem->ram[mem->ram[cpu->addr]];
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void LDY_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->y = mem->ram[mem->ram[cpu->addr] + cpu->x];
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void LDY_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->y = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void LDY_absolute_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    cpu->y = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x];
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}

/////////////////////
//  LSR
//////////////////
void LSR_accomulator(MOS6502* cpu, MEMORIA* mem){
    uint8_t aux = cpu->a&0x01;
    if( aux != cpu->sr&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->sr |= 0x01; //CARRY = 1
        }else{
            cpu->sr &= 0xFE; //CARRY = 0
        }
    }
    //EXECUTE
    cpu->a >>= 1;
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    
    cpu->pc++;    
}
void LSR_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr]]&0x01;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    //MODIFICAR OPERANDO
    mem->ram[mem->ram[cpu->addr]] >>= 1;
    if(!mem->ram[mem->ram[cpu->addr]]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr]] & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    
    cpu->pc += 2;    
}
void LSR_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr] + cpu->x]&0x01;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    //EXECUTE
    mem->ram[mem->ram[cpu->addr] + cpu->x] >>= 1;
    //WRITEBACK
    if(!mem->ram[mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr] + cpu->x] & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 2;        
}
void LSR_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]&0x01;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    //EXECUTE
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] >>= 1;
    //WRITEBACK
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    cpu->pc += 3;    
}
void LSR_absolute_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]&0x01;
    if( aux != cpu->pc&0x01){
        if(aux){
            //AUX VALOR 1, 
            cpu->pc |= 0x01; //CARRY = 1
        }else{
            cpu->pc &= 0xFE; //CARRY = 0
        }
    }
    //EXECUTE
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] >>= 1;
    //WRITEBACK
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] & 0x80 ) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    
    cpu->pc += 3;        
}

void NOP(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->pc++;
}

///////////////
// ORA
//////////////
void ORA_inmediate(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram [cpu->addr];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void ORA_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram[mem->ram[cpu->addr]];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;    
}
void ORA_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;    
}
void ORA_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;    
}
void ORA_absolute_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;    
}
void ORA_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 3;
}
void ORA_indirect_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram[mem->ram[cpu->addr] + cpu->x];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
void ORA_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    //EXECUTE
    cpu->a |= mem->ram[mem->ram[cpu->addr] + cpu->y];
    //WRITEBACK
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc += 2;
}
//////////////
//  ROL
/////////////
void ROL_accumulator(MOS6502* cpu, MEMORIA* mem){
    uint8_t aux = cpu->a&0x80;
    aux >>= 7;
    //EXECUTE
    cpu->a <<= 1;
    //WRITEBACK
    if(cpu->sr&0x01) cpu->a++;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc++;
}

void ROL_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr]]&0x80;
    aux >>= 7;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr]] <<= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr]]++;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr]]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr]] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc+=2;
}

void ROL_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr] + cpu->x]&0x80;
    aux >>= 7;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr] + cpu->x] <<= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr] + cpu->x]++;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr] + cpu->x] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc+=2;    
}
void ROL_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]&0x80;
    aux >>= 7;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] <<= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]++;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc+=3;
}
void ROL_absolute_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]&0x80;
    aux >>= 7;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] <<= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]++;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc+=3;
}
////////////
//  ROR
///////////////
void ROR_accumulator(MOS6502* cpu, MEMORIA* mem){
    uint8_t aux = cpu->a&0x01;
    //EXECUTE
    cpu->a >>= 1;
    //WRITEBACK
    if(cpu->sr&0x01) cpu->a |= 0x80;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!cpu->a) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc++;    
}
void ROR_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr]]&0x01;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr]] >>= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr]] |= 0x80;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr]]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr]] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc+=2;
}
void ROR_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr] + cpu->x]&0x01;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr] + cpu->x] >>= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr] + cpu->x] |= 0x80;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr] + cpu->x] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc+=2;        
}
void ROR_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]&0x01;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] >>= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] |= 0x80;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    
    cpu->pc+=3;
}
void ROR_absolute_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc + 1;
    uint8_t aux = mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]&0x01;
    //EXECUTE
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] >>= 1;
    //WRITEBACK
    if(cpu->sr&0x01) mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] |= 0x80;
    if(aux != cpu->sr&0x01){
        if(aux) cpu->sr |= 0x01;
        else cpu->sr &= 0xFE;
    }
    if(!mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x]) cpu->sr |= 0x02;
    else cpu->sr &= 0xFD;
    if(mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] & 0x80) cpu->sr |= 0x80;
    else cpu->sr &= 0x7F;
    cpu->pc+=3;
}

/////////////////
//  SBC
////////////////
void SBC_inmediate(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[cpu->addr] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;
}
void SBC_zero_page(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[mem->ram[cpu->addr]] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;    
}
void SBC_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[mem->ram[cpu->addr] + cpu->x] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;    
}
void SBC_absolute(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 3;    
}
void SBC_absolute_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 3;    
}
void SBC_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 3;    
}
void SBC_indirect_X(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[mem->ram[cpu->addr] + cpu->x] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;        
}
void SBC_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->addr = cpu->pc+1;
    uint16_t aux = cpu->a - mem->ram[mem->ram[cpu->addr] + cpu->y] - 1;
    if(cpu->sr & 0x01) aux += 1;
    //WRITEBACK
    if(aux & 0x100) cpu->sr |= 0x01; //MODIFICAR CARRY
    cpu->a = aux;
    if(cpu->a & 0x80) cpu->sr |= 0x80; //MODIFICAR NEGATIVE
    else cpu->sr &= 0x7F;
    if(!cpu->a) cpu->sr |= 0x02; //MODIFICAR ZERO
    else cpu->sr &= 0xFD;
    cpu->pc += 2;        
}



/////////////////////////////////
//      REGISTRER INSTRUCTION
/////////////////////////////////

//TRANSFIERE DEL ACOMULADOR A AL X
void TAX(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
/*
    cpu->x = cpu->a;
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;
    else cpu->sr &= 0x7F;
*/  
    //for(a=0;a<320000;a++); 
    if(mem->ram[0x99] == 0)
        InputOutput(mem);
    if(mem->ram[0x99] == 1)
        InputOutput2(mem);
    cpu->pc++;
}
//TRANSFIERE DEL REG X AL AC A
void TXA(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->a = cpu->x;
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;  
    else cpu->sr &= 0x7F;
    cpu->pc++;
}
//DECREMEMNTA X
void DEX(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->x--;
    //WRITEBACK
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;  
    else cpu->sr &= 0x7F;
    cpu->pc++;
}
//INCREMENTA X
void INX(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->x++;
    //WRITEBACK
    if(!cpu->x) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->x & 0x80) cpu->sr|= 0x80;  
    else cpu->sr &= 0x7F;
    cpu->pc++;
}
//TRANSFIERE DEL ACOMULADOR A AL REG Y
void TAY(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->y = cpu->a;
    //WRITEBACK
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;  
    else cpu->sr &= 0x7F;
    cpu->pc++;
}
//TRANSFIERE DEL REG Y AL AC A
void TYA(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->a = cpu->y;
    //WRITEBACK
    if(!cpu->a) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->a & 0x80) cpu->sr|= 0x80;  
    else cpu->sr &= 0x7F;
    cpu->pc++;
}
//DECREMENTA REG Y
void DEY(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->y--;
    //WRITEBACK
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;  
    else cpu->sr &= 0x7F;
    cpu->pc++;
}
//INCREMENTA REG X
void INY(MOS6502* cpu, MEMORIA* mem){
    //EXECUTE
    cpu->y++;
    //WRITEBACK
    if(!cpu->y) cpu->sr|= 0x02;
    else cpu->sr &= 0xFD;
    if(cpu->y & 0x80) cpu->sr|= 0x80;  
    else cpu->sr &= 0x7F;
    cpu->pc++;
}


void RTI_implied(MOS6502* cpu, MEMORIA* mem){
    //************************************
    //          NO IMPLEMENTAR 
    //************************************
}
void RTS_implied(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    uint16_t aux_l = mem->ram[++cpu->sp]; //era prefijo
    uint16_t aux_m = mem->ram[++cpu->sp]*256; //era prefijo
    aux_m += aux_l; 
    cpu->pc = aux_m + 1; //era 1
}
//////////////////////////////
////    STA
/////////////////////////////
void STA_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr]] = cpu->a;
    cpu->pc += 2;
}
void STA_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[ (uint8_t)mem->ram[cpu->addr] +  (uint8_t)cpu->x] = cpu->a;
    cpu->pc += 2;
}
void STA_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] = cpu->a;
    cpu->pc += 3;
}
void STA_absolute_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->x] = cpu->a;
    cpu->pc += 3;
}
void STA_absolute_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y] = cpu->a;
    cpu->pc += 3;
}
void STA_indirect_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    uint16_t dir;
    dir = mem->ram[mem->ram[cpu->addr] + cpu->x + 1]*256 + mem->ram[mem->ram[cpu->addr] + cpu->x] ;
    mem->ram[dir] = cpu->a;

    cpu->pc += 2;
}
void STA_indirect_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr] + cpu->y] = cpu->a;
    cpu->pc += 2;
}

///////////////////////////
///     STACK INSTRUCTION
///////////////////////////
void TXS(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    mem->ram[cpu->sp--] = cpu->x;
    cpu->pc++;
}
void TSX(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->x = mem->ram[cpu->sp++];
    cpu->pc++;
}
void PHA(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    mem->ram[cpu->sp--] = cpu->a;
    cpu->pc++;
}
void PLA(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->a = mem->ram[cpu->sp++];
    cpu->pc++;
}
void PHP(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    mem->ram[cpu->sp--] = cpu->sr;
    cpu->pc++;
}
void PLP(MOS6502* cpu, MEMORIA* mem){
    //WRITEBACK
    cpu->sr = mem->ram[cpu->sp++];
    cpu->pc++;
}

/////////////////////////
//      STX
////////////////////////
void STX_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr]] = (uint8_t)cpu->x;
    cpu->pc += 2;
}
void STX_zero_page_Y(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr] + cpu->y] = cpu->x;
    cpu->pc += 2;
}
void STX_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] = cpu->x;
    cpu->pc += 3;
}

/////////////////////////
//      STX
////////////////////////
void STY_zero_page(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr]] = cpu->y;
    cpu->pc += 2;
}
void STY_zero_page_X(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr] + cpu->x] = cpu->y;
    cpu->pc += 2;
}
void STY_absolute(MOS6502* cpu, MEMORIA* mem){
    cpu->addr = cpu->pc+1;
    //WRITEBACK
    mem->ram[mem->ram[cpu->addr+1]*256 + mem->ram[cpu->addr]] = cpu->y;
    cpu->pc += 3;
}

void Interrupcion(MOS6502* cpu, MEMORIA* mem){
    int a;
    for(a=0;a<0x7ffffffff;a++);
    InputOutput(mem);
    for(a=0;a<0x7ffffffff;a++);
    cpu->pc ++;
}

/*
///////////////////////////////////////////////////////////
//              I M P R I M E
////////////////////////////////////////////////////////
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 


// OPCODE 0xFB;
void IMP(MOS6502* cpu, MEMORIA* mem){
    //LIMPIAR PANTALLA
    system("cls");
    //IMPRIMIR EL CUERPO DEL SNAKE
    int i,j,x,y;
    
    int len = (int)mem->ram[0x03]; //LEER LONGITUD ACT.
    for (i=0x10,j=0; j < len; i+=2, j+=2) {
        //CALCULAR LAS POSICIONES
        x = (int)((mem->ram[i+1]-2)*8 + + (mem->ram[i]/32));
	y = (int)(mem->ram[i]%32);
        //IMPRIME
	gotoxy(y,x); printf("*");
    }
    //IMPRIMIR MANZANA
    x = (int)((mem->ram[0x01]-2)*8 + + (mem->ram[0x00]/32));
    y = (int)(mem->ram[0x00]%32);
    gotoxy(y,x); printf("M");
    //IMPRIMIR
    gotoxy(32,32); printf("\n");
    cpu->pc++;
    //system("pause");
}

//////////////////////////////////////////////
//       L E E 
//////////////////////////////////////////
// OPCODE: 0xFA
void LEE(MOS6502* cpu, MEMORIA* mem){
    uint8_t car;
    Sleep(1);   //DEMORA DE UN SEGUNDO 
    if(kbhit()){
        //USUARIO INGRESO POR TECLADO
        car = getch(); //LEEMOS DESDE TECLADO (A/W/S/D)
        mem->ram[0xFF] = car; //GUARDAMOS EL VALOR EN RAM ('syslastkey')
    }
    //NOTA: CASO CONTRARIO, NO SE DBBE ACTUALIZAR 'syslastkey'
    //N2: GENERAR UN NÚMERO ALEATORIO ENTRE 0 a 256 PARA POSICIONAR LA PROX MANZANA
    car = rand()%256;
    mem->ram[0xFE] = car;   //GUARDAR EN 'sysRandom'
    cpu->pc++;
}
////////////////////////////////////////////////////////////
*/
