#include <stdio.h>

#include "InstrFormats.h"

void testRegs32I();
void testInstr();

int main(int argc, char** argv)
{
    testRegs32I();
    testInstr();
    printf("Tests OK\n");
    return 0;
}