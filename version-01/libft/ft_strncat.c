/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:44:05 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:44:07 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ls1;

	i = 0;
	ls1 = ft_strlen(s1);
	while (n--)
	{
		s1[ls1 + i] = s2[i];
		if (s2[i] == '\0')
			return (s1);
		i++;
		if (n == 0)
			s1[ls1 + i] = 0;
	}
	return (s1);
}
