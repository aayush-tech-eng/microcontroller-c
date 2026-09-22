#include <stdint.h>
#include "e1_prototypes.h"

int main(void)
{
    if (is_overTemp(1000))
    {
        printf("Over temperature detected!\n");
    }

    return 0;
}