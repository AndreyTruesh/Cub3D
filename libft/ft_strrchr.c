/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 01:19:38 by abibi             #+#    #+#             */
/*   Updated: 2020/05/14 09:06:17 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != (char)c && --i > 0)
		;
	if (i > 0 || s[0] == (char)c)
		return ((char *)&s[i]);
	else
		return ((char *)0);
}
