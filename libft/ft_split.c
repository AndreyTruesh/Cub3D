/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:18:57 by abibi             #+#    #+#             */
/*   Updated: 2020/05/16 17:17:12 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int wordscount;

	if (!str)
		return (-1);
	i = 0;
	wordscount = 0;
	while (str[i] != '\0')
		if (str[i] != c)
		{
			wordscount++;
			if (!ft_strchr(&str[i], c))
				return (wordscount);
			else
				i += ft_strchr(&str[i], c) - &str[i];
		}
		else
			i++;
	return (wordscount);
}

static char	*buildbox(const char *str, int beg, int end)
{
	int		i;
	char	*box;

	i = 0;
	box = (char *)malloc(sizeof(char) * (end - beg + 2));
	if (!box)
		return ((char *)0);
	while (beg <= end)
	{
		box[i] = str[beg];
		i++;
		beg++;
	}
	box[i] = '\0';
	return (box);
}

static char	**arraystr_free(char **arstr, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(arstr[k]);
		i++;
	}
	free(arstr);
	return ((char **)0);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		i2;
	char	**buf;

	if (!(s && (buf = (char **)malloc(sizeof(char *)
						* (count_words(s, c) + 1)))))
		return ((char **)0);
	i = 0;
	k = 0;
	while (s[i] != '\0')
		if (s[i] != c)
		{
			i2 = ft_strchr(&s[i], c) ? i + (int)(ft_strchr(&s[i], c) -
					&s[i]) - 1 : (int)ft_strlen(s) - 1;
			buf[k++] = buildbox(s, i, i2);
			if (!buf[k - 1])
				return (arraystr_free(buf, k));
			i = i2 + 1;
		}
		else
			i++;
	buf[k] = (char *)0;
	return (buf);
}
