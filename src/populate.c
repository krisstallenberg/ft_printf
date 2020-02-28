/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:47:52 by kstallen       #+#    #+#                */
/*   Updated: 2020/02/27 16:59:39 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_printer(t_data *data)
{
	int					j;
	const t_function	function_pointer[9] =
	{
		{'%', print_per},
		{'d', print_di},
		{'i', print_di},
		{'u', print_u},
		{'x', print_hex},
		{'X', print_hex},
		{'s', print_s},
		{'c', print_c},
		{'p', print_p}
	};

	j = 0;
	data->type = data->format[data->i];
	while (j < (int)(sizeof(function_pointer) / sizeof(t_function)))
	{
		if (function_pointer[j].type == data->type)
			(function_pointer[j].print)(data);
		j++;
	}
}

void	pop_width_precision(t_data *data)
{
	if (data->format[data->i] == '*')
	{
		data->width = va_arg(data->var, int);
		data->i++;
	}
	else if (ft_atoi(&data->format[data->i]))
	{
		data->width = ft_atoi(&data->format[data->i]);
		data->i += data->width >= 0 ? intlen(data->width) : 0;
	}
	if (data->format[data->i] == '.')
	{
		data->precision = 0;
		data->i++;
		if (data->format[data->i] == '*')
		{
			data->precision = va_arg(data->var, int);
			data->i++;
		}
		if (ft_atoi(&data->format[data->i]) > 0)
		{
			data->precision = ft_atoi(&data->format[data->i]);
			data->i += data->precision >= 0 ? intlen(data->precision) : 0;
		}
	}
}

void	pop_flag(t_data *data)
{
	while (data->format[data->i] == '0' || data->format[data->i] == '-')
	{
		if (data->format[data->i] == '0')
			data->flag_zero = 1;
		if (data->format[data->i] == '-')
			data->flag_minus = 1;
		data->i++;
	}
}

/*
** Populates struct for every variable argument to print.
** Once printed, resets values of variable argument.
*/

void	populate_execute_struct(t_data *data)
{
	data->i++;
	pop_flag(data);
	pop_width_precision(data);
	select_printer(data);
	reset_struct(data);
}
