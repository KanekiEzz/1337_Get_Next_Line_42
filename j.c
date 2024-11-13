#include <string.h>
#include <stdio.h>

typedef struct ol 
{
    int i;
    struct ol *next;
} p_o;

int main ()
{
    p_o l;
    memset(&l.i , 57, 1 );
    memset((char*)&l.i+1 , 5, 1 );
    //memset((char*)&l.i+2 , 0, 1 );
    //memset((char*)&l.i+3 , 0, 1 );

    // if (l.i == 1337)
        printf("%d", l.i);
    // return 0;
}
