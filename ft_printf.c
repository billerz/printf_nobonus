/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:51:37 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/03 10:21:42 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_choose_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		ret_length;

	i = 0;
	ret_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret_length += ft_choose_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			ret_length += ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (ret_length);
}
