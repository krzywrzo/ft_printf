/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:23:43 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/01/27 18:52:22 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_type(char type, va_list args);
int	print_char(char c);
int	print_str(char *str);
#endif
