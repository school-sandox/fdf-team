/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:09:03 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/18 18:18:14 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_atoi_hex(const char *str)
{
	long long int	result;
	
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '0' || *str == 'x' || *str == 'X')
		++str;
	while ((*str >= '0' && *str <= '9') ||
    (*str >= 'A' && *str <= 'F') || (*str >= 'a' && *str <= 'f'))
	{
		if (*str >= 'A' && *str <= 'F')
			result = (*str - 'A' + 10) + (16 * result);
		else if (*str >= 'a' && *str <= 'f')
			result = (*str - 'a' + 10) + (16 * result);
		else
			result = (*str - '0') + (16 * result);
		++str;
	}
	return (result);
}
