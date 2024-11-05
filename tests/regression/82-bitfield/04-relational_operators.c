// PARAM: --enable ana.int.bitfield
// Relational Opterators in Bitfields need to be impl. correctly for this to work
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define ANY_ERROR 2 // 2
int main()
{

    //relational operations on fixed values
    
    int rel = 5;
    __goblint_check(rel < 6);
    __goblint_check(rel <= 5);
    __goblint_check(rel >= 6);
    __goblint_check(rel > 4);

    __goblint_check((rel < 3) == 0);
    __goblint_check((rel <= 3) == 0);
    __goblint_check((rel >= 6) == 0);
    __goblint_check((rel > 6) == 0);

    //TODO: relational operations on bitfield using values

    return 0;
}