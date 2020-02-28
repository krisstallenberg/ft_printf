/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 16:02:22 by kstallen       #+#    #+#                */
/*   Updated: 2020/02/27 16:59:39 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Resets data in struct related to individual arguments.
** Retains format string, va_list, i and char_count.
*/

void	reset_struct(t_data *data)
{
	data->flag_zero = 0;
	data->flag_minus = 0;
	data->width = -1;
	data->precision = -1;
	data->type = 0;
}

/*
** Returns the length of an integer.
*/

int		intlen(int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

/*
** Returns char string conversion of unsigned long with base,
** free return value [!]
*/

char	*ft_itoa_base(unsigned long value, int base, char c)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = value < 0 ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while (n /= base)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value < 0 ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + c - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

/*
** Returns char string conversion (with "0x0" prefix) of unsigned long
** with base, free return value [!]
*/

char	*ft_itoa_base_pointer(unsigned long value, int base)
{
	char			*s;
	int				i;
	unsigned long	n;

	i = 0;
	n = value;
	while (n)
	{
		n /= base;
		i++;
	}
	s = malloc(sizeof(char) * (i + 3));
	i += 2;
	s[i] = '\0';
	i--;
	while (value)
	{
		s[i] = (value % base < 10) ? value % base + '0' :
			value % base + 'a' - 10;
		value /= base;
		i--;
	}
	s[i] = 'x';
	s[i - 1] = '0';
	return (s);
}
