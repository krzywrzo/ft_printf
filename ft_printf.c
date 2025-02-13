/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:39:09 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/31 15:57:28 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_type(*(++format), args);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

/*
int main ()
{
	ft_printf("%c\n", 'x');
}*/
