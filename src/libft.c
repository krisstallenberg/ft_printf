/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:34:36 by kstallen      #+#    #+#                 */
/*   Updated: 2020/04/22 13:56:18 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (str[i] - 48);
		i++;
	}
	return (sign * nbr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	while (i < (int)len)
	{
		((char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *string1;
	unsigned char *string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while ((*string1 != '\0' || *string2 != '\0') && n)
	{
		if (*string1 != *string2)
			return ((int)*string1 - (int)*string2);
		string1++;
		string2++;
		n--;
	}
	return (0);
}
