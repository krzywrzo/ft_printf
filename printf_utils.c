/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:40:23 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/31 15:06:05 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(args, int));
	else if (type == 's')
		count += print_str(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += print_digit(va_arg(args, int));
	else if (type == 'u')
		count += print_unsigned_digit(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += print_hex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += write(1, "%", 1);
	else if (type == 'p')
		count += print_pointer(va_arg(args, unsigned long));
	return (count);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_digit(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (nb < 0)
	{
		count += print_char('-');
		count += print_digit(-nb);
	}
	else if (nb <= 9 && nb >= 0)
	{
		count += print_char(nb + '0');
	}
	else
	{
		count += print_digit(nb / 10);
		count += print_digit(nb % 10);
	}
	return (count);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_unsigned_digit(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb <= 9)
	{
		count += print_char(nb + '0');
	}
	else
	{
		count += print_digit(nb / 10);
		count += print_digit(nb % 10);
	}
	return (count);
}
