#include <stdio.h>
#include <cassert>
#include "InstrFormats.h"

void testInstrRType()
{
    instr instr;
    instr.u32 = 0;
    instr.rType.opcode = 0b1111111;
    assert(instr.u32 == 0b00000000000000000000000001111111);
    instr.u32 = 0;
    instr.rType.rd = 0b11111;
    assert(instr.u32 == 0b00000000000000000000111110000000);
    instr.u32 = 0;
    instr.rType.funct3 = 0b111;
    assert(instr.u32 == 0b00000000000000000111000000000000);
    instr.u32 = 0;
    instr.rType.rs1 = 0b11111;
    assert(instr.u32 == 0b00000000000011111000000000000000);
    instr.u32 = 0;
    instr.rType.rs2 = 0b11111;
    assert(instr.u32 == 0b00000001111100000000000000000000);
    instr.u32 = 0;
    instr.rType.funct7 = 0b1111111;
    assert(instr.u32 == 0b11111110000000000000000000000000);
}

void testInstrIType()
{
    instr instr;
    instr.u32 = 0;
    instr.iType.opcode = 0b1111111;
    assert(instr.u32 == 0b00000000000000000000000001111111);
    instr.u32 = 0;
    instr.iType.rd = 0b11111;
    assert(instr.u32 == 0b00000000000000000000111110000000);
    instr.u32 = 0;
    instr.iType.funct3 = 0b111;
    assert(instr.u32 == 0b00000000000000000111000000000000);
    instr.u32 = 0;
    instr.iType.rs1 = 0b11111;
    assert(instr.u32 == 0b00000000000011111000000000000000);
    instr.u32 = 0;
    instr.iType.imm11_0 = 0b111111111111;
    assert(instr.u32 == 0b11111111111100000000000000000000);
}

void testInstrSType()
{
    instr instr;
    instr.u32 = 0;
    instr.sType.opcode = 0b1111111;
    assert(instr.u32 == 0b00000000000000000000000001111111);
    instr.u32 = 0;
    instr.sType.imm4_0 = 0b11111;
    assert(instr.u32 == 0b00000000000000000000111110000000);
    instr.u32 = 0;
    instr.sType.funct3 = 0b111;
    assert(instr.u32 == 0b00000000000000000111000000000000);
    instr.u32 = 0;
    instr.sType.rs1 = 0b11111;
    assert(instr.u32 == 0b00000000000011111000000000000000);
    instr.u32 = 0;
    instr.sType.rs2 = 0b11111;
    assert(instr.u32 == 0b00000001111100000000000000000000);
    instr.u32 = 0;
    instr.sType.imm11_5 = 0b111111;
    assert(instr.u32 == 0b1111110000000000000000000000000);
}

void testInstrBType()
{
    instr instr;
    instr.u32 = 0;
    instr.bType.opcode = 0b1111111;
    assert(instr.u32 == 0b00000000000000000000000001111111);
    instr.u32 = 0;
    instr.bType.imm11 = 0b1;
    assert(instr.u32 == 0b00000000000000000000000010000000);
    instr.u32 = 0;
    instr.bType.imm4_1 = 0b1111;
    assert(instr.u32 == 0b00000000000000000000111100000000);
    instr.u32 = 0;
    instr.bType.funct3 = 0b111;
    assert(instr.u32 == 0b00000000000000000111000000000000);
    instr.u32 = 0;
    instr.bType.rs1 = 0b11111;
    assert(instr.u32 == 0b00000000000011111000000000000000);
    instr.u32 = 0;
    instr.bType.rs2 = 0b11111;
    assert(instr.u32 == 0b00000001111100000000000000000000);
    instr.u32 = 0;
    instr.bType.imm10_5 = 0b111111;
    assert(instr.u32 == 0b01111110000000000000000000000000);
    instr.u32 = 0;
    instr.bType.imm20 = 0b1;
    assert(instr.u32 == 0b10000000000000000000000000000000);
}

void testInstrUType()
{
    instr instr;
    instr.u32 = 0;
    instr.uType.opcode = 0b1111111;
    assert(instr.u32 == 0b00000000000000000000000001111111);
    instr.u32 = 0;
    instr.uType.rd = 0b11111;
    assert(instr.u32 == 0b00000000000000000000111110000000);
    instr.u32 = 0;
    instr.uType.imm31_12 = 0b11111111111111111111;
    assert(instr.u32 == 0b11111111111111111111000000000000);
}

void testInstrJType()
{
    instr instr;
    instr.u32 = 0;
    instr.jType.opcode = 0b1111111;
    assert(instr.u32 == 0b00000000000000000000000001111111);
    instr.u32 = 0;
    instr.jType.rd = 0b11111;
    assert(instr.u32 == 0b00000000000000000000111110000000);
    instr.u32 = 0;
    instr.jType.imm19_12 = 0b11111111;
    assert(instr.u32 == 0b00000000000011111111000000000000);
    instr.u32 = 0;
    instr.jType.imm11 = 0b1;
    assert(instr.u32 == 0b00000000000100000000000000000000);
    instr.u32 = 0;
    instr.jType.imm10_1 = 0b1111111111;
    assert(instr.u32 == 0b01111111111000000000000000000000);
    instr.u32 = 0;
    instr.jType.imm20 = 0b1;
    assert(instr.u32 == 0b10000000000000000000000000000000);
}

void testCommon()
{
    instr instr;
    instr.u32 = 0;
    instr.common.opcode = 0b1111111;
    assert(instr.u32 == 0b00000000000000000000000001111111);
    instr.u32 = 0;
    instr.common.rd = 0b11111;
    assert(instr.u32 == 0b00000000000000000000111110000000);
    instr.u32 = 0;
    instr.common.funct3 = 0b111;
    assert(instr.u32 == 0b00000000000000000111000000000000);
    instr.u32 = 0;
    instr.common.rs1 = 0b11111;
    assert(instr.u32 == 0b00000000000011111000000000000000);
    instr.u32 = 0;
    instr.common.rs2 = 0b11111;
    assert(instr.u32 == 0b00000001111100000000000000000000);
    instr.u32 = 0;
    instr.common.sign = 0b1;
    assert(instr.u32 == 0b10000000000000000000000000000000);
}

void testInstr()
{
    testInstrRType();
    testInstrIType();
    testInstrSType();
    testInstrBType();
    testInstrUType();
    testInstrJType();
    testCommon();
}