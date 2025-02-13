/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:38 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/31 15:04:54 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_recursive(unsigned long nb, char type)
{
	char	*hex_digits;
	int		count;

	hex_digits = NULL;
	if (type == 'x')
		hex_digits = "0123456789abcdef";
	else if (type == 'X')
		hex_digits = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
	{
		count += print_hex_recursive((nb / 16), type);
	}
	count += print_char(hex_digits[nb % 16]);
	return (count);
}

int	print_hex(unsigned int nb, char type)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		return (write(1, "0", 1));
	}
	count += print_hex_recursive(nb, type);
	return (count);
}

int	print_pointer(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (print_str("(nil)"));
	count += print_str("0x");
	count += print_hex_recursive(nb, 'x');
	return (count);
}
