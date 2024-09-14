/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:18:07 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/06/19 15:55:22 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_element(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*helper(int n, int count)
{
	char	*result;
	int		isneg;

	isneg = 0;
	if (n < 0)
	{
		isneg = 1;
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = -n;
	}
	result = (char *)malloc((count + isneg + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[count + isneg] = '\0';
	while (count > 0)
	{
		result[--count + isneg] = n % 10 + '0';
		n /= 10;
	}
	if (isneg)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		count;

	count = count_element(n);
	ret = helper(n, count);
	return (ret);
}
