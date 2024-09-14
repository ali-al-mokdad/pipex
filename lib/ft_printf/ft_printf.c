/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:20 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/07/31 18:07:37 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include	"libft/libft.h"

void	check_print(char format, va_list args, int *count)
{
	if (format == 'd')
		*count += print_d(va_arg(args, int));
	if (format == 'c')
		*count += print_c((char)va_arg(args, int));
	if (format == 's')
		*count += print_s(va_arg(args, char *));
	if (format == 'p')
		*count += print_p(va_arg(args, void *));
	if (format == 'i')
		*count += print_i(va_arg(args, int));
	if (format == 'u')
		*count += (int)print_u(va_arg(args, unsigned int));
	if (format == 'x')
		*count += (int)print_x(va_arg(args, unsigned int));
	if (format == 'X')
		*count += (int)print_x2(va_arg(args, unsigned int));
	if (format == '%')
	{
		ft_putchar_fd('%', 1);
		*count += 1;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			check_print(format[i], args, &count);
		}
		else
		{
			write (1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
