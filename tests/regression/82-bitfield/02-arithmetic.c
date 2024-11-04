// PARAM: --enable ana.int.bitfield
// Arithmetic (add, sub, mul, div) in Bitfields need to be impl. correctly for this to work
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define ANY_ERROR 5 // 5
int main()
{
    int add = 3;
    int sub = 8;
    int mul = 4;
    int div = 10;

    add = add + 2;
    sub -= 3;
    mul *= 2;
    div /= 2;

    // if arithmetic is impl. the following should always succeed
    // {add 5 → [0b1100; 0b0011]}
    __goblint_check((add & ANY_ERROR) == 5);
    // {sub 5 → [0b1100; 0b0011]}
    __goblint_check((sub & ANY_ERROR) == 5);
    // {mul 5 → [0b1100; 0b0011]}
    __goblint_check((mul & ANY_ERROR) == 5);
    // {div 5 → [0b1100; 0b0011]}
    __goblint_check((div & ANY_ERROR) == 5);


    //following is only a template right now
    add = 3;
    sub = 8;
    mul = 4;
    div = 10;

    int r = rand() % 2;
    if (r == 0) {
        add = add + 2;
        sub -= 3;
        mul *= 2;
        div /= 2;
    }

    // {r 7→ [0; 2],state 7→ [0; 10]}
    __goblint_check((add & ANY_ERROR) != 0); 
    __goblint_check((sub & ANY_ERROR) != 0);
    __goblint_check((mul & ANY_ERROR) != 0);
    __goblint_check((div & ANY_ERROR) != 0);
}