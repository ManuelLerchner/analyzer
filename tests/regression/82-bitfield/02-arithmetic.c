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

    add += 2;
    sub -= 3;
    mul *= 2;
    div /= 2; 

    // {r 7→ [0; 2],state 7→ [0; 10]}
    __goblint_check((add & ANY_ERROR) == 0);
    __goblint_check((sub & ANY_ERROR) == 0);
    __goblint_check((mul & ANY_ERROR) == 0);
    __goblint_check((div & ANY_ERROR) == 0);
}