#include <cassert>
#include "Regs32I.h"

void test2Aliases(uint32_t &alias1, uint32_t& alias2)
{
    assert(alias1 == 0);
    assert(alias2 == 0);
    alias1 = 1;
    assert(alias2 == 1);
    alias2 = 2;
    assert(alias1 == 2);
}

void test3Aliases(uint32_t &alias1, uint32_t& alias2, uint32_t& alias3)
{
    assert(alias1 == 0);
    assert(alias2 == 0);
    assert(alias3 == 0);
    alias1 = 1;
    assert(alias2 == 1);
    assert(alias3 == 1);
    alias2 = 2;
    assert(alias1 == 2);
    assert(alias3 == 2);
    alias3 = 3;
    assert(alias1 == 3);
    assert(alias2 == 3);
}

void testRegs32I()
{
    regs32I regs32i;
    assert(regs32i.x0 == 0);
    assert(regs32i.zero == 0);
    test2Aliases(regs32i.x1, regs32i.ra);
    test2Aliases(regs32i.x2, regs32i.sp);
    test2Aliases(regs32i.x3, regs32i.gp);
    test2Aliases(regs32i.x4, regs32i.tp);
    test2Aliases(regs32i.x5, regs32i.t0);
    test2Aliases(regs32i.x6, regs32i.t1);
    test2Aliases(regs32i.x7, regs32i.t2);
    test3Aliases(regs32i.x8, regs32i.s0, regs32i.fp);
    test2Aliases(regs32i.x9, regs32i.s1);
    test2Aliases(regs32i.x10, regs32i.a0);
    test2Aliases(regs32i.x11, regs32i.a1);
    test2Aliases(regs32i.x12, regs32i.a2);
    test2Aliases(regs32i.x13, regs32i.a3);
    test2Aliases(regs32i.x14, regs32i.a4);
    test2Aliases(regs32i.x15, regs32i.a5);
    test2Aliases(regs32i.x16, regs32i.a6);
    test2Aliases(regs32i.x17, regs32i.a7);
    test2Aliases(regs32i.x18, regs32i.s2);
    test2Aliases(regs32i.x19, regs32i.s3);
    test2Aliases(regs32i.x20, regs32i.s4);
    test2Aliases(regs32i.x21, regs32i.s5);
    test2Aliases(regs32i.x22, regs32i.s6);
    test2Aliases(regs32i.x23, regs32i.s7);
    test2Aliases(regs32i.x24, regs32i.s8);
    test2Aliases(regs32i.x25, regs32i.s9);
    test2Aliases(regs32i.x26, regs32i.s10);
    test2Aliases(regs32i.x27, regs32i.s11);
    test2Aliases(regs32i.x28, regs32i.t3);
    test2Aliases(regs32i.x29, regs32i.t4);
    test2Aliases(regs32i.x30, regs32i.t5);
    test2Aliases(regs32i.x31, regs32i.t6);
    assert(regs32i.pc == 0);
}