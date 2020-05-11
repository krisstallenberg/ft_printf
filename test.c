#include <stdio.h>
#include "inc/ft_printf.h"

int     main(void)
{
    int ret1;
    int ret2;
    
    ret1 = ft_printf("[%d]", 0);
    printf("\n");
    ret2 = printf("[%d]", 0);
    printf("\nmy printf: %d\nsy printf:%d", ret1, ret2);

    printf("\n");
    ret1 = ft_printf("[%-d]", 0);
    printf("\n");
    ret2 = printf("[%-d]", 0);
    printf("\nmy printf: %d\nsy printf:%d", ret1, ret2);

    printf("\n");
    ret1 = ft_printf("[%-2.9d]", 0);
    printf("\n");
    ret2 = printf("[%-2.9d]", 0);
    printf("\nmy printf: %d\nsy printf:%d", ret1, ret2);
    
    printf("\n");
    ret1 = ft_printf("[%u]", 0);
    printf("\n");
    ret2 = printf("[%u]", 0);
    printf("\nmy printf: %d\nsy printf:%d", ret1, ret2);

    printf("\n");
    ret1 = ft_printf("[%-u]", 0);
    printf("\n");
    ret2 = printf("[%-u]", 0);
    printf("\nmy printf: %d\nsy printf:%d", ret1, ret2);

    return (0);
}