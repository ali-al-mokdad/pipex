/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:11:47 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/02 14:23:06 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*sum;
	char	*start;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	sum = (char *) malloc(sizeof(char) * (l1 + l2 +1));
	if (sum == NULL)
		return (NULL);
	start = sum;
	while (l1--)
		*sum++ = *s1++;
	while (l2--)
		*sum++ = *s2++;
	*sum = '\0';
	return (start);
}
