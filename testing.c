#include "ft_printf.h"
#include <stdio.h>

void	print_struct(t_data *data)
{
	printf("\nFlag zero:\t%d\n", data->flag_zero);
	printf("Flag minus:\t%d\n", data->flag_minus);
	printf("Width:\t\t%d\n", data->width);
	printf("Precision:\t%d\n", data->precision);
	printf("Type:\t\t%c\n", data->type);
	printf("Char count:\t%d\n", data->char_count);
	printf("Format:\t\t%s\n", data->format);
	printf("i:\t\t%i\n", data->i);
}

int		main(void)
{
	// int		input = 0;
	// int		intput = 123456789;
	int 	ft_count;
	int		count;
	// int		arg1 = 4;
	char	*strarg = "poepje"; 
	count = 0;
	ft_count = 0;
	// printf("format string is:\t\t[%s], %d", input, arg1);
	// printf("\nexpected output is:\t\t");
	// printf("%*s", arg1, input);
	// printf("\nactual output is:\t\t");
	ft_count = ft_printf("^.^/%30p^.^/", strarg);
	printf("\n");
	count = printf("^.^/%30p^.^/", strarg);

	printf("\ndifference in return value equals: %i", count - ft_count );
	return (0);
	}