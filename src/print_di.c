/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_di.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:58:49 by kstallen       #+#    #+#                */
/*   Updated: 2020/02/27 16:59:39 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di_reg(t_data *data)
{
	int		len;
	int		field_width;
	char	fill;

	fill = data->flag_zero && data->precision < 0 ? '0' : ' ';
	len = intlen(data->arg.li);
	field_width = data->width > data->precision ?
		data->width : data->precision;
	data->precision = data->precision > len ?
		data->precision : len;
	while (field_width > data->precision)
	{
		putchar_printf(fill, data);
		field_width--;
	}
	while (field_width > len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg_zero(t_data *data)
{
	int		len;
	int		field_width;

	data->arg.li *= -1;
	len = intlen(data->arg.li) > data->precision ?
		intlen(data->arg.li) : data->precision;
	field_width = data->width - 1;
	if (data->precision >= data->width)
	{
		print_di_neg_zero_prec(data);
		return ;
	}
	putchar_printf('-', data);
	while (field_width > len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	while (field_width > intlen(data->arg.li))
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg_zero_prec(t_data *data)
{
	int		len;
	int		field_width;

	field_width = data->width;
	len = intlen(data->arg.li);
	putchar_printf('-', data);
	while (data->precision > len)
	{
		putchar_printf('0', data);
		data->precision--;
	}
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg(t_data *data)
{
	int		len;
	int		field_width;

	data->arg.li *= -1;
	len = intlen(data->arg.li) > data->precision ?
		intlen(data->arg.li) : data->precision;
	field_width = data->width - 1;
	while (field_width > len)
	{
		putchar_printf(' ', data);
		field_width--;
	}
	putchar_printf('-', data);
	while (field_width > intlen(data->arg.li))
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg_prec(t_data *data)
{
	int		len;
	int		field_width;

	field_width = data->width;
	len = intlen(data->arg.li);
	data->arg.li *= -1;
	putchar_printf('-', data);
	while (data->precision > len - 1)
	{
		putchar_printf('0', data);
		data->precision--;
	}
	putnbr_printf(data->arg.li, data);
}
