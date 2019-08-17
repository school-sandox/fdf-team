/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:27:40 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/17 16:27:42 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*buf;

	if ((lst != 0) && (f != 0))
	{
		while (lst)
		{
			buf = lst->next;
			f(lst);
			lst = buf;
		}
	}
}
