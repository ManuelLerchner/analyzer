// PARAM: --enable ana.int.bitfield
// Shifts in Bitfields need to be impl. correctly for this to work
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define ANY_ERROR 2 // 2
#define ANY_ERROR2 8 // 2
int main()
{
    int shiftLeft = 4;
    shiftLeft = shiftLeft << 1;
    // {shiftLeft 8 → [0b0111; 0b1000]}
    __goblint_check((shiftLeft & ANY_ERROR) == 0);

    int shiftRight = 4;
    shiftRight >>= 1;
    // {shiftRight 2 → [0b1101, 0b0010]}
    __goblint_check((shiftRight & ANY_ERROR) == 0);



    shiftLeft = 0;
    shiftRight = 0;
    int r = rand() % 3;
    switch (r)
    {
    case 0:
        shiftRight = shiftLeft = 2; /* 0 */
        break;
    case 1:
        shiftRight = shiftLeft = 4; /* 8 */
        break;
    case 2:
        shiftLeft = 6; /* 10 */
        shiftRight = 8;
        break;
    }
    shiftLeft <<= 1;
    shiftRight >>= 1;

    // {shiftLeft → [0b1111; 0b1100]}
    __goblint_check((shiftLeft & ANY_ERROR) == 0);
    __goblint_check((shiftLeft & 15) <= 13); //should allways succeed but somehow leq brings the check to crash
    
    // {shiftRight → [0b1111; 0b0111]}
    __goblint_check((shiftRight & ANY_ERROR2));

}