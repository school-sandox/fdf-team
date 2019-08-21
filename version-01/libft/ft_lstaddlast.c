/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:56:18 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/21 19:53:24 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
