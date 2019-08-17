/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:56:18 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:56:19 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	if ((alst != NULL) && (new != NULL))
	{
		if ((*alst)->next == 0)
			(*alst)->next = new;
		else
			while (*alst != 0)
			{
				*alst = (*alst)->next;
				if ((*alst)->next == 0)
					(*alst)->next = new;
			}
	}
}
