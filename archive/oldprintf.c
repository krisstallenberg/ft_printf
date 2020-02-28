/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:08:28 by kstallen      #+#    #+#                 */
/*   Updated: 2020/01/25 15:45:44 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

#define INPUT "Hallo, %s", "wereld"

/*
** [PARAMETER] receives format string and var arguments from main.
** [FUCNTION] prints everything other than conversions, flags, width, length
** and precision, all of which it forwards.
** [RETURN] 1 if error occurs and 0 if successful.
*/

int	print_c(va_list var_list)
{
	va_end(var_list);
	return (0);
}

int	print_s(va_list var_list)
{	
	va_end(var_list);
	int i;
	char *str;
}

int	print_p(va_list var_list)
{
	va_end(var_list);
	return (0);
}

int	print_d(va_list var_list)
{
	va_end(var_list);
	return (0);
}

int	print_i(va_list var_list)
{
	va_end(var_list);
	return (0);
}

int	print_u(va_list var_list)
{
	va_end(var_list);
	return (0);
}

int	print_x_low(va_list var_list)
{
	va_end(var_list);
	return (0);
}

int			print_x_upp(va_list var_list)
{
	va_end(var_list);
	return (0);
}

t_printer	init_printer_array(void)
{
	const	t_printer	printer_array[9] =
	{
		{'c', print_c},
		{'s', print_s},
		{'p', print_p},
		{'d', print_d},
		{'i', print_i},
		{'u', print_u},
		{'x', print_x_low},
		{'X', print_x_upp},
		{'\0', NULL}
	return (printer_array);
}

int			init_data_arg(t_data_arg *data)
{
	data = malloc(sizeof(t_data_arg));
	if(!data)
		return (0);
	data->flag = '0';
	data->width = 0;
	data->precision = 0;
	data->conversion = 0; // mogelijk hier een link	naar t_printer
}

int			per_parser(string, i, var_list)
{
	t_printer	printer_array;
	t_data_arg	data;

	init_data_arg(&data);	
	printer_array = init_printer_array(void);
	i++;
	while (string[i])
	{
		
	}
}

int 		parser(const char *string, va_list var_list, int count_chars)
{
	int i;
	int ret_value;

	i = 0;
	ret_value = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			ret_value = per_parser(string, i, var_list);
			if (ret_value == -1)
				return (-1);
			count_chars += ret_value;
		}
		if (string[i] != '%')
		{
			count_chars += format_printer(string, i);
			
		}
		i++;
	}
	return (count_chars);
}

/*
** [PARAMETER] main receives format string and variable arguments.
** [FUNCTION] passes argument to centre and ends the va_list.
** [RETURN] count of characters printed, -1 if no format string.
*/

int init_data_arg(t_data_arg *data)
{
	data = malloc(sizeof(t_data_arg));
	if(!data)
		return (0);
	data->flag = '0';
	data->width = 0;
	data->precision = 0;
}
int	ft_printf(const char *format, ...)
{
	t_data_arg data;

	data = NULL;
	init_data_arg(&data);

	va_list		var_list;
	va_start(var_list, format);
	int			count_chars;
	const char	*string;

	count_chars = 0;
	if (format == NULL)
		return (-1);
	va_start(var_list, format);
	string = format;
	count_chars = parser(string, var_list, data_arg, count_chars);
	va_end(var_list);
	return (count_chars > 0 ? count_chars : 0);
}

/*
** TESTING MAIN
*/

int	main(void)
{
	char *str;
	char *str2;
	str = "wereld.";
	str2 = "poep";
	int count;
	count = 0;
	count = ft_printf("%sHallo, %s", str2, str);
	printf("\n%d", count);
	return (0);
}
