/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfcom2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:11:58 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/07/31 18:07:57 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"libft/libft.h"

int	print_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += print_u(n / 10);
	}
	count ++;
	ft_putchar_fd(n % 10 + '0', 1);
	return (count);
}

int	print_x(unsigned int str)
{
	unsigned int	count;
	char			*base;

	count = 0;
	base = "0123456789abcdef";
	if (str >= 16)
	{
		count += print_x(str / 16);
	}
	ft_putchar_fd(base[str % 16], 1);
	return (count + 1);
}

int	print_x2(unsigned int str)
{
	unsigned int	count;
	char			*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (str >= 16)
	{
		count += print_x2(str / 16);
	}
	ft_putchar_fd(base[str % 16], 1);
	return (count + 1);
}

int	p_helper(unsigned long value)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (value >= 16)
	{
		count += p_helper(value / 16);
	}
	ft_putchar_fd(base[value % 16], 1);
	return (count + 1);
}
