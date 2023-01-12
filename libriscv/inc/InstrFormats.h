//-----------------------------------------------------------------------------------------------------
// Documentation: "The RISC-V Instruction Set Manual, Volume I: User-Level ISA, Document Version 2.2"
// Chapter 2.3 "Immediate Encoding Variants"
// Figure 2.3: "RISC-V base instruction formats showing immediate variants.", page 12.
//-----------------------------------------------------------------------------------------------------

#ifndef INSTRFORMATS_H
#define INSTRFORMATS_H

#include <stdint.h>

struct instrRType
{
    uint32_t opcode : 7; // bits [6, 0]
    uint32_t rd     : 5; // bits [11, 7]
    uint32_t funct3 : 3; // bits [14, 12]
    uint32_t rs1    : 5; // bits [19, 15]
    uint32_t rs2    : 5; // bits [24, 20]
    uint32_t funct7 : 7; // bits [31, 25]
};

struct instrIType
{
    uint32_t opcode : 7;  // bits [6, 0]
    uint32_t rd     : 5;  // bits [11, 7]
    uint32_t funct3 : 3;  // bits [14, 12]
    uint32_t rs1    : 5;  // bits [19, 15]
    uint32_t imm11_0: 12; // bits [31, 20]
};

struct instrSType
{
    uint32_t opcode : 7; // bits [6, 0]
    uint32_t imm4_0 : 5; // bits [11, 7]
    uint32_t funct3 : 3; // bits [14, 12]
    uint32_t rs1    : 5; // bits [19, 15]
    uint32_t rs2    : 5; // bits [24, 20]
    uint32_t imm11_5: 7; // bits [31, 25]
};

struct instrBType
{
    uint32_t opcode : 7; // bits [6, 0]
    uint32_t imm11  : 1; // bits [7]
    uint32_t imm4_1 : 4; // bits [11, 8]
    uint32_t funct3 : 3; // bits [14, 12]
    uint32_t rs1    : 5; // bits [19, 15]
    uint32_t rs2    : 5; // bits [24, 20]
    uint32_t imm10_5: 6; // bits [30, 25]
    uint32_t imm20  : 1; // bits [31]
};

struct instrUType
{
    uint32_t opcode  : 7; // bits [6, 0]
    uint32_t rd      : 5; // bits [11, 7]
    uint32_t imm31_12: 20;// bits [31, 12]
};

struct instrJType
{
    uint32_t opcode  : 7;  // bits [6, 0]
    uint32_t rd      : 5;  // bits [11, 7]
    uint32_t imm19_12: 8;  // bits [12, 19]
    uint32_t imm11   : 1;  // bits [20]
    uint32_t imm10_1 : 10; // bits [30, 21]
    uint32_t imm20   : 1;  // bits [31]
};

union instr
{
    // Struct "common" is meant to simplify access to common fields. For example, all instructions have "opcode" field. Before determining
    // instruction's type, we can get it's opcode and then determine the type by that opcode (and "funct" fields).
    // Particular case is sign bit common for all immediate values. It is always 31-st bit. According to documentation:
    // "In particular, the sign bit for all immediates is always in bit 31 of the instruction to speed sign-extension circuitry.", page 11
    struct
    {
        uint32_t opcode : 7;
        uint32_t rd     : 5;
        uint32_t funct3 : 3;
        uint32_t rs1    : 5;
        uint32_t rs2    : 5;
        uint32_t        : 6;
        uint32_t sign   : 1;
    } common;
    uint32_t u32;
    instrRType rType;
    instrIType iType;
    instrSType sType;
    instrBType bType;
    instrUType uType;
    instrJType jType;
};

#endif // INSTRFORMATS_H