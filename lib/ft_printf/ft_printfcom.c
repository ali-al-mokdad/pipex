/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfcom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:24:14 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/07/31 18:07:59 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"libft/libft.h"

int	print_d(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	len = (int)ft_strlen(str);
	write (1, str, len);
	free(str);
	return (len);
}

int	print_c(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_s(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_p(void *str)
{
	int				count;
	unsigned long	value;

	if (str == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count = 2;
	value = (unsigned long)str;
	count += p_helper(value);
	return (count);
}

int	print_i(int num)
{
	return (print_d(num));
}
