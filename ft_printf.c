/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <ajewell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:39:14 by ajewell           #+#    #+#             */
/*   Updated: 2025/11/10 16:20:12 by ajewell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	ft_handle_type(const char c, va_list args, int * pcount);
void	ft_print_str(char * str, int * pcount);
void	ft_print_ptr(void * ptr, int * pcount);
void	ft_print_nbr_decimal(int * nbr, int * pcount);
void	ft_print_nbr_int(int * nbr, int * pcount);
void	ft_print_nbr_unsigned_int(unsigned int * nbr, int * pcount);
void	ft_print_nbr_hexa_lower(int * nbr, int * pcount);
void	ft_print_nbr_hexa_upper(int * nbr, int * pcount);
void	ft_print_char(char c, int * count);

int	ft_printf(const char * format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			ft_handle_type(format[i++], args, &count);
		else
			ft_print_char(format[i++], &count);
	}
	va_end(args);
	return (count);
}

void	ft_handle_type(const char c, va_list args, int * pcount)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int), pcount);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), pcount);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, void *), pcount);
	else if (c == 'd')
		ft_print_nbr_decimal(va_arg(args, int), pcount);
	else if (c == 'i')
		ft_print_nbr_int(va_arg(args, int), pcount);
	else if (c == 'u')
		ft_print_nbr_unsigned_int(va_arg(args, unsigned int), pcount);
	else if (c == 'x')
		ft_print_nbr_hexa_lower(va_arg(args, int), pcount);
	else if (c == 'X')
		ft_print_nbr_hexa_upper(va_arg(args, int), pcount);
	else
		ft_print_char(c, pcount);
}

void	ft_print_char(const char c, int * pcount)
{
	write(1, &c, 1);
	pcount++;
}
