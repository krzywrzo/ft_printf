/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:40:23 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/29 20:12:39 by kwrzosek         ###   ########.fr       */
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
	else if (type == 'x')
		count += print_smol_hex(va_arg(args, unsigned int));
//	else if (type == 'X')
//		count += print_large_hex(va_arg(args, unsigned int));
	else if (type == '%')
		count += write(1, "%", 1);
	return (count);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_digit(int nb)
{
    int count;
   
   count = 0;
    if (nb == -2147483648)
    {
        return write(1, "-2147483648", 11);
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

    return count;
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

int	print_unsigned_digit (unsigned int nb)
{
    int count;

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

    return count;
}
/*
int	print_smol_hex(unsigned int nb)
{
	int	count = 0;
	char hex_digits[] = "0123456789abcdef";
	if (nb == 0)
	{
		return (write(1, "0x0", 3));
	}
	count += print_str("0x");
	while (nb > 0)
	{
		count +=print_char(hex_digits[nb % 16]);
		nb = nb / 16;
	}
	return (count);
}*/
static int print_hex_recursive(unsigned int nb) {
    char hex_digits[] = "0123456789abcdef";
    int count = 0;

    if (nb >= 16) {
        count += print_hex_recursive(nb / 16);
    }
    count += print_char(hex_digits[nb % 16]);

    return count;
}

// Wrapper function to handle the 0x prefix and special case when nb is 0
int print_smol_hex(unsigned int nb) {
    int count = 0;

    if (nb == 0) {
        return write(1, "0x0", 3);
    }

    count += print_str("0x");
    count += print_hex_recursive(nb);

    return count;
}
