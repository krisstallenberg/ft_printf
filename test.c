#include <stdio.h>
#include "inc/ft_printf.h"
#include <limits.h>

int     main(void)
{
    // printf("\n^act \\/exp\n");
    // printf("\nexp: (%d)", printf("!%30i!\n", 0));
    // printf("\nact: (%d)", ft_printf("!%30i!\n", 0));

    printf("\nexp: (%d)\n", printf("[Hello,%x]", 1236981));
    printf("\nact: (%d)\n", ft_printf("[Hello,%x]", 1236981));
}