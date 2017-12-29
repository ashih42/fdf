/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:09:51 by ashih             #+#    #+#             */
/*   Updated: 2017/12/22 00:11:05 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the str doesn't even have a valid digit;
** Otherwise, return 0, and store the int value at *n;
*/

int		ft_atoi_check(char *str, int *n)
{
	int		total;
	int		sign;

	total = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == 'r')
		str++;
	if (*str == '-')
		sign = -1;
	else if (*str == '+')
		sign = 1;
	else
		str--;
	str++;
	if (!ft_isdigit(*str))
		return (1);
	while (ft_isdigit(*str))
		total = total * 10 + (*str++ - '0');
	*n = total * sign;
	return (0);
}
