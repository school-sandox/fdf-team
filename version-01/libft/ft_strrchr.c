/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:45:27 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:45:29 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	size_t	f;
	char	*a;
	int		z;

	a = (char*)s;
	i = 0;
	f = 0;
	z = 0;
	len = ft_strlen(a) + 1;
	while (len--)
	{
		if (a[i] == (char)c)
		{
			f = i;
			z = 1;
		}
		i++;
	}
	if (z == 1)
		return (a + f);
	return (NULL);
}
