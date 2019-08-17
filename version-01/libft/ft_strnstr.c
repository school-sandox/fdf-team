/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:45:16 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:45:17 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		q;
	int		slen;

	q = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while ((haystack[i] != '\0') && (len--))
		if (haystack[i] == needle[0])
		{
			slen = ++len;
			j = i;
			while ((haystack[j] != 0) && (haystack[j++] == needle[q++])
			&& (slen--))
				if (needle[q] == 0)
					return ((char*)haystack + i);
			q = 0;
			i++;
		}
		else
			i++;
	return (NULL);
}
