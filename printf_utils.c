/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:40:23 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/27 19:27:59 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
	else if (type == 'x')
		count += print_hex(va_arg(args, int));

	else if (type == '%')
		count += write(1, '%', 1);
	return (count);
}
int	print_digit(int num)
{
        if (nb == -2147483648)
        {
                write(1, "-2147483648", 11);
        }
        else if (nb < 0)
        {
                ft_putchar('-');
                ft_putnbr(-nb);
        	count ++;
	}
        else if (nb >= 10)
        {
                ft_putnbr(nb / 10);
                ft_putnbr(nb % 10);
        	count++;
	}
        else
        {
                nb += '0';
                ft_putchar(nb);
        	count++;
	}
	return (count);
	
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (*str == 0)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += print_char(*str);
		str++;
	}
	return (count);
}
