/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:23:43 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/29 18:43:24 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_strlen(const char *str);
int	ft_printf(const char *format, ...);
int	ft_type(char type, va_list args);
int	print_char(char c);
int	print_str(char *str);
int	print_digit(int nb);
int	print_smol_hex(unsigned int nb);
int	print_large_hex(unsigned int nb);
#endif
