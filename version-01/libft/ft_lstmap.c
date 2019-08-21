/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:27:56 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/08/21 19:53:51 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new;
	t_list	*snew;
	t_list	*buf;

	if ((lst == 0) || (f == 0))
		return (NULL);
	snew = f(lst);
	buf = snew;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		buf->next = new;
		buf = new;
		lst = lst->next;
	}
	return (snew);
}
