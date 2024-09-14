/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:41:46 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/06/15 12:06:13 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*src;

	src = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (const char )c)
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}
