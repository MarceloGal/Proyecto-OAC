/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Set_instrucciones.h
 * Author: Dell
 *
 * Created on 10 de octubre de 2020, 05:13 PM
 */

#ifndef SET_INSTRUCCIONES_H
#define SET_INSTRUCCIONES_H
#include "Estructuras_basicas.h"

void cargar_instrucciones(void (*set_de_instrucciones[0xFF])(MOS6502*,MEMORIA*));

void ADC_inmediate(MOS6502* cpu, MEMORIA* mem);
void ADC_zero_page(MOS6502* cpu, MEMORIA* mem);
void ADC_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void ADC_absolute(MOS6502* cpu, MEMORIA* mem);
void ADC_absolute_X(MOS6502* cpu, MEMORIA* mem);
void ADC_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void ADC_indirect_X(MOS6502* cpu, MEMORIA* mem);
void ADC_indirect_Y(MOS6502* cpu, MEMORIA* mem);

void AND_inmediate(MOS6502* cpu, MEMORIA* mem);
void AND_zero_page(MOS6502* cpu, MEMORIA* mem);
void AND_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void AND_absolute(MOS6502* cpu, MEMORIA* mem);
void AND_absolute_X(MOS6502* cpu, MEMORIA* mem);
void AND_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void AND_indirect_X(MOS6502* cpu, MEMORIA* mem);
void AND_indirect_Y(MOS6502* cpu, MEMORIA* mem);

void ASL_accumulador(MOS6502* cpu, MEMORIA* mem);
void ASL_zero_page(MOS6502* cpu, MEMORIA* mem);
void ASL_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void ASL_absolute(MOS6502* cpu, MEMORIA* mem);
void ASL_absolute_X(MOS6502* cpu, MEMORIA* mem);

void BIT_zero_page(MOS6502* cpu, MEMORIA* mem);
void BIT_absolute(MOS6502* cpu, MEMORIA* mem);

void BPL(MOS6502* cpu, MEMORIA* mem);
void BMI(MOS6502* cpu, MEMORIA* mem);
void BVC(MOS6502* cpu, MEMORIA* mem);
void BVS(MOS6502* cpu, MEMORIA* mem);
void BCC(MOS6502* cpu, MEMORIA* mem);
void BCS(MOS6502* cpu, MEMORIA* mem);
void BNE(MOS6502* cpu, MEMORIA* mem);
void BEQ(MOS6502* cpu, MEMORIA* mem);

void BRK(MOS6502* cpu, MEMORIA* mem);

void CMP_inmediate(MOS6502* cpu, MEMORIA* mem);
void CMP_zero_page(MOS6502* cpu, MEMORIA* mem);
void CMP_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void CMP_absolute(MOS6502* cpu, MEMORIA* mem);
void CMP_absolute_X(MOS6502* cpu, MEMORIA* mem);
void CMP_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void CMP_indirect_X(MOS6502* cpu, MEMORIA* mem);
void CMP_indirect_Y(MOS6502* cpu, MEMORIA* mem);

void CPX_inmediate(MOS6502* cpu, MEMORIA* mem);
void CPX_zero_page(MOS6502* cpu, MEMORIA* mem);
void CPX_absolute(MOS6502* cpu, MEMORIA* mem);

void CPY_inmediate(MOS6502* cpu, MEMORIA* mem);
void CPY_zero_page(MOS6502* cpu, MEMORIA* mem);
void CPY_absolute(MOS6502* cpu, MEMORIA* mem);

void DEC_zero_page(MOS6502* cpu, MEMORIA* mem);
void DEC_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void DEC_absolute(MOS6502* cpu, MEMORIA* mem);
void DEC_absolute_X(MOS6502* cpu, MEMORIA* mem);

void EOR_inmediate(MOS6502* cpu, MEMORIA* mem);
void EOR_zero_page(MOS6502* cpu, MEMORIA* mem);
void EOR_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void EOR_absolute(MOS6502* cpu, MEMORIA* mem);
void EOR_absolute_X(MOS6502* cpu, MEMORIA* mem);
void EOR_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void EOR_indirect_X(MOS6502* cpu, MEMORIA* mem);
void EOR_indirect_Y(MOS6502* cpu, MEMORIA* mem);

void CLC(MOS6502* cpu, MEMORIA* mem);
void SEC(MOS6502* cpu, MEMORIA* mem);
void CLI(MOS6502* cpu, MEMORIA* mem);
void SEI(MOS6502* cpu, MEMORIA* mem);
void CLV(MOS6502* cpu, MEMORIA* mem);
void CLD(MOS6502* cpu, MEMORIA* mem);
void SED(MOS6502* cpu, MEMORIA* mem);


void INC_zero_page(MOS6502* cpu, MEMORIA* mem);
void INC_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void INC_absolute(MOS6502* cpu, MEMORIA* mem);
void INC_absolute_X(MOS6502* cpu, MEMORIA* mem);

void JMP_absolute(MOS6502* cpu, MEMORIA* mem);
void JMP_indirect(MOS6502* cpu, MEMORIA* mem);

void JSR_absolute(MOS6502* cpu, MEMORIA* mem);


void LDA_inmediate(MOS6502* cpu, MEMORIA* mem);
void LDA_zero_page(MOS6502* cpu, MEMORIA* mem);
void LDA_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void LDA_absolute(MOS6502* cpu, MEMORIA* mem);
void LDA_absolute_X(MOS6502* cpu, MEMORIA* mem);
void LDA_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void LDA_indirect_X(MOS6502* cpu, MEMORIA* mem);
void LDA_indirect_Y(MOS6502* cpu, MEMORIA* mem);

void LDX_inmediate(MOS6502* cpu, MEMORIA* mem);
void LDX_zero_page(MOS6502* cpu, MEMORIA* mem);
void LDX_zero_page_Y(MOS6502* cpu, MEMORIA* mem);
void LDX_absolute(MOS6502* cpu, MEMORIA* mem);
void LDX_absolute_Y(MOS6502* cpu, MEMORIA* mem);

void LDY_inmediate(MOS6502* cpu, MEMORIA* mem);
void LDY_zero_page(MOS6502* cpu, MEMORIA* mem);
void LDY_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void LDY_absolute(MOS6502* cpu, MEMORIA* mem);
void LDY_absolute_X(MOS6502* cpu, MEMORIA* mem);

void LSR_accomulator(MOS6502* cpu, MEMORIA* mem);
void LSR_zero_page(MOS6502* cpu, MEMORIA* mem);
void LSR_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void LSR_absolute(MOS6502* cpu, MEMORIA* mem);
void LSR_absolute_X(MOS6502* cpu, MEMORIA* mem);


void NOP(MOS6502* cpu, MEMORIA* mem);

void ORA_inmediate(MOS6502* cpu, MEMORIA* mem);
void ORA_zero_page(MOS6502* cpu, MEMORIA* mem);
void ORA_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void ORA_absolute(MOS6502* cpu, MEMORIA* mem);
void ORA_absolute_X(MOS6502* cpu, MEMORIA* mem);
void ORA_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void ORA_indirect_X(MOS6502* cpu, MEMORIA* mem);
void ORA_indirect_Y(MOS6502* cpu, MEMORIA* mem);


void TAX(MOS6502* cpu, MEMORIA* mem);
void TXA(MOS6502* cpu, MEMORIA* mem);
void DEX(MOS6502* cpu, MEMORIA* mem);
void INX(MOS6502* cpu, MEMORIA* mem);
void TAY(MOS6502* cpu, MEMORIA* mem);
void TYA(MOS6502* cpu, MEMORIA* mem);
void DEY(MOS6502* cpu, MEMORIA* mem);
void INY(MOS6502* cpu, MEMORIA* mem);

void ROL_accumulator(MOS6502* cpu, MEMORIA* mem);
void ROL_zero_page(MOS6502* cpu, MEMORIA* mem);
void ROL_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void ROL_absolute(MOS6502* cpu, MEMORIA* mem);
void ROL_absolute_X(MOS6502* cpu, MEMORIA* mem);

void ROR_accumulator(MOS6502* cpu, MEMORIA* mem);
void ROR_zero_page(MOS6502* cpu, MEMORIA* mem);
void ROR_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void ROR_absolute(MOS6502* cpu, MEMORIA* mem);
void ROR_absolute_X(MOS6502* cpu, MEMORIA* mem);

void RTI_implied(MOS6502* cpu, MEMORIA* mem);

void RTS_implied(MOS6502* cpu, MEMORIA* mem);

void SBC_inmediate(MOS6502* cpu, MEMORIA* mem);
void SBC_zero_page(MOS6502* cpu, MEMORIA* mem);
void SBC_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void SBC_absolute(MOS6502* cpu, MEMORIA* mem);
void SBC_absolute_X(MOS6502* cpu, MEMORIA* mem);
void SBC_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void SBC_indirect_X(MOS6502* cpu, MEMORIA* mem);
void SBC_indirect_Y(MOS6502* cpu, MEMORIA* mem);


void STA_zero_page(MOS6502* cpu, MEMORIA* mem);
void STA_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void STA_absolute(MOS6502* cpu, MEMORIA* mem);
void STA_absolute_X(MOS6502* cpu, MEMORIA* mem);
void STA_absolute_Y(MOS6502* cpu, MEMORIA* mem);
void STA_indirect_X(MOS6502* cpu, MEMORIA* mem);
void STA_indirect_Y(MOS6502* cpu, MEMORIA* mem);

void TXS(MOS6502* cpu, MEMORIA* mem);
void TSX(MOS6502* cpu, MEMORIA* mem);
void PHA(MOS6502* cpu, MEMORIA* mem);
void PLA(MOS6502* cpu, MEMORIA* mem);
void PHP(MOS6502* cpu, MEMORIA* mem);
void PLP(MOS6502* cpu, MEMORIA* mem);

void STX_zero_page(MOS6502* cpu, MEMORIA* mem);
void STX_zero_page_Y(MOS6502* cpu, MEMORIA* mem);
void STX_absolute(MOS6502* cpu, MEMORIA* mem);

void STY_zero_page(MOS6502* cpu, MEMORIA* mem);
void STY_zero_page_X(MOS6502* cpu, MEMORIA* mem);
void STY_absolute(MOS6502* cpu, MEMORIA* mem);

void Interrupcion(MOS6502* cpu, MEMORIA* mem);

/////////////////////////////////
//      I / O 
////////////////////////////////
//void IMP(MOS6502* cpu, MEMORIA* mem);
//void gotoxy(int x,int y);
//void LEE(MOS6502* cpu, MEMORIA* mem);

#endif /* SET_INSTRUCCIONES_H */
