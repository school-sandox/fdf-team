/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:26:36 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:26:38 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*buf;

	if (alst != 0)
	{
		while (*alst)
		{
			buf = (**alst).next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = buf;
		}
	}
}
