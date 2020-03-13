#include <stdio.h>
#include "inc/ft_printf.h"

int     main(void)
{
    // printf("\n^act \\/exp\n");
    // printf("\nexp: (%d)", printf("!%30i!\n", 0));
    // printf("\nact: (%d)", ft_printf("!%30i!\n", 0));
  

    // printf("\n^act \\/exp\n");
    // printf("\nexp: (%d)", printf("!%42p!", NULL));
    // printf("\nact: (%d)", ft_printf("!%42p!", NULL));
    char *str = "Hello World";
    printf("str is: %s, address: %p\n", str, str);
    str = "Foo00000000lll";
    printf("str is: %s, address: %p\n", str, str);
}