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
		count += print_digit(va_arg(args, unsigned int));
	else if (type == 'x')
		count += print_smol_hex(va_arg(args, unsigned int));
//	else if (type == 'X')
//		count += print_large_hex(va_arg(args, unsigned int));
	else if (type == '%')
		count += write(1, "%", 1);
	return (count);
}
int     ft_strlen(const char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                i++;
        }
        return (i);
}

int	print_smol_hex(unsigned int nb)
{
	int	temp;
	char	hex[9];
	int	i;

	i = 0;
	if (nb == 0)
	{
		print_str("0x0");
		return (3);
	}
	while (nb > 0 && i < 8)
	{
		temp = nb % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 87;
		nb = nb / 16;
		i++;
	}
	hex[i] = '\0';
	int j = 0;
	while (j < i / 2)
	{
		char swap = hex[j];
		hex[j] = hex[i - j - 1];
		hex[i - j - 1] = swap;
		j++;
	}
	print_str("0x");
	print_str(hex);
	return (ft_strlen(hex)+2); 
}


/*
int	print_large_hex(unsigned long nb)
{
        int     i;  
        int     temp;
        char *hex;
        int     len;

        i = 0;
        temp = 0;
        hex = (char *)malloc(17 * sizeof(char));
        if (!hex)
                return (0);
        while (nb != 0 && i < 16)
        {   
                temp = nb % 16; 
                if (temp < 10) 
                        temp = temp + 48; 
                else
                        temp = temp + 55; 
                hex[i++] = temp;
                nb = nb / 16; 
        }   
        hex[i] = '\0';

        for (int j = 0; j < i / 2; j++) {
        char swap = hex[j];
        hex[j] = hex[i - j - 1]; 
        hex[i - j - 1] = swap;
    }   

        len = ft_strlen(hex);
        print_str(hex);
        free(hex);
        return (len);

}
*/
int	print_digit(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		print_char('-');
		print_digit(-nb);
		count++;
	}
	else if (nb >= 10)
	{
		print_digit(nb / 10);
		print_digit(nb % 10);
		count++;
	}
	else
	{
		nb += '0';
		print_char(nb);
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
