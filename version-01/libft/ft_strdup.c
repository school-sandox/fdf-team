/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:39:49 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:39:51 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	n;
	char	*cop;

	n = ft_strlen(s1) + 1;
	i = 0;
	if ((cop = (char*)malloc(sizeof(char) * n)) == NULL)
		return (NULL);
	while (n--)
	{
		cop[i] = s1[i];
		i++;
	}
	return (cop);
}
