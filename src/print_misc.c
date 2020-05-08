/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_misc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/22 13:27:58 by kris          #+#    #+#                 */
/*   Updated: 2020/05/08 22:15:17 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_di_zero(t_data *data)
{
	int	len;

	len = intlen(data->arg.li);
	data->arg.li < 0 ? putchar_printf('-', data) : 0;
	while (data->width > len)
	{
		putchar_printf('0', data);
		data->width--;
	}
	data->arg.li < 0 ? putnbr_printf(-data->arg.li, data) :
	putnbr_printf(data->arg.li, data);
}

int			is_specifier(char c)
{
	if (c == 's' || c == 'c' || c == 'p' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'd' || c == 'i' || c == '%')
		return (1);
	else
		return (0);
}

void		*null_pointer(void)
{
	char *ptr;

	ptr = ft_memmalloc(4);
	ft_memcpy(ptr, "0x0", 4);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = dst;
	s = src;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}