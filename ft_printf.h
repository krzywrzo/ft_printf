/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:23:43 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/31 15:05:43 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_strlen(const char *str);
int	ft_printf(const char *format, ...);
int	ft_type(char type, va_list args);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(int nb);
int	print_hex(unsigned int nb, char type);
int	print_unsigned_digit(unsigned int nb);
int	print_pointer(unsigned long nb);
#endif
