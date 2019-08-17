/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:35:47 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:35:49 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int val, size_t num)
{
	int				i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char*)b;
	while (num--)
	{
		buf[i] = (unsigned char)val;
		i++;
	}
	return (b);
}
