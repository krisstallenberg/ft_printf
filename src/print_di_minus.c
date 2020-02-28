/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_di_minus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:57:35 by kstallen       #+#    #+#                */
/*   Updated: 2020/02/27 16:59:39 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di_min(t_data *data)
{
	char	fill;
	int		len;
	int		field_width;

	field_width = data->width;
	fill = ' ';
	len = intlen(data->arg.li);
	while (field_width + data->precision > data->width + len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_printf(data->arg.li, data);
	while (field_width > len)
	{
		putchar_printf(fill, data);
		field_width--;
	}
}

void	print_di_min_neg(t_data *data)
{
	int		len;
	int		field_width;

	field_width = 0;
	data->arg.li *= -1;
	len = intlen(data->arg.li);
	putchar_printf('-', data);
	while (field_width < data->precision - len)
	{
		putchar_printf('0', data);
		field_width++;
	}
	putnbr_printf(data->arg.li, data);
	while (field_width < data->width - len - 1)
	{
		putchar_printf(' ', data);
		field_width++;
	}
}
