/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:49:29 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/06/19 14:40:39 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
	{
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		len = ft_strlen(s) - start;
	}
	else
		sub = (char *)malloc(sizeof(char) * (len +1));
	if (!sub)
		return (NULL);
	i = 0;
	while ((len--) > 0 && s[i] != '\0')
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
