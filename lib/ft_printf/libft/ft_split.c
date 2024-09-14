/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:51:14 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/06/18 20:11:26 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	words_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (count);
}

static void	helper(char const *s, char c, char **array)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			array[k] = malloc((j + 1) * sizeof(char));
			ft_strlcpy(array[k++], (char *)s + i, j + 1);
			i = i + j;
		}
		else
			i++;
	}
	array[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)malloc((words_count(s, c) + 1) * sizeof(char *));
	if (array == NULL )
		return (NULL);
	helper(s, c, array);
	return (array);
}
