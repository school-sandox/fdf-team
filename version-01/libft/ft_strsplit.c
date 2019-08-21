/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:45:39 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:45:41 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		razmer(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
		if (s[i] != c)
		{
			while ((s[i] != '\0') && (s[i] != c))
				i++;
			k++;
		}
		else
			i++;
	return (k + 1);
}

static void		zaliv(char *in, const char *of, int metka, int much)
{
	int		i;

	metka = metka - much;
	i = 0;
	while (much--)
	{
		in[i] = *(of + metka);
		metka++;
		i++;
	}
	in[i] = '\0';
}

static	int		job(char **m, const char *s, char c, int *y)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = *y;
	while (s[i] != '\0')
		if (s[i] != c)
		{
			while ((s[i] != '\0') && (s[i] != c))
			{
				j++;
				i++;
			}
			if (!(m[x] = (char*)malloc(sizeof(char) * (j + 1))))
				return (0);
			zaliv(m[x], s, i, j);
			j = 0;
			x++;
		}
		else
			i++;
	m[x] = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**m;
	int		size;
	int		x;

	x = 0;
	if (s == NULL)
		return (NULL);
	size = razmer(s, c);
	if (!(m = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	if (size == 1)
	{
		m[0] = 0;
		return (m);
	}
	if (!(job(m, s, c, &x)))
	{
		while (0 >= x)
			free(m[x--]);
		free(m);
		return (NULL);
	}
	return (m);
}
