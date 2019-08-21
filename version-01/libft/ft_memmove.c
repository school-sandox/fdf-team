/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:35:32 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:35:34 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	if ((dst == 0) || (src == 0))
		return (0);
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	if (b < a)
		while (len)
		{
			len--;
			a[len] = b[len];
		}
	else
		while (len--)
		{
			a[i] = b[i];
			i++;
		}
	return (dst);
}
