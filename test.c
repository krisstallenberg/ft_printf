#include <stdio.h>
#include "inc/ft_printf.h"

int     main(void)
{
    int ret1;
    int ret2;
    
    ret1 = ft_printf("[%p]", NULL);
    printf("\n");
    ret2 = printf("[%p]", NULL);
    printf("\nmy printf: %d\nsy printf:%d", ret1, ret2);
    return (0);
}