/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:58:28 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/06/17 15:02:35 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t		i;
	const char	*a;

	i = 0;
	a = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			a = &s[i];
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else
		return ((char *)&a[0]);
}
