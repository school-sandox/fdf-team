/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:38:32 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:38:34 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*a;

	i = 0;
	a = (char*)s;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[i] == (char)c)
			return (a + i);
		i++;
	}
	a = NULL;
	return (a);
}
