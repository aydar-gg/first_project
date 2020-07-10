/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:27:52 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/03 15:27:54 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_printout(int sign, int numb)
{
	if (sign == 1)
	{
		numb = -numb;
		return (numb);
	}
	else
		return (numb);
}

int				ft_atoi(char *str)
{
	int i;
	int sign;
	int numb;

	numb = 0;
	sign = 0;
	i = 0;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign += 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		numb = numb * 10 + (str[i] - '0');
		i++;
	}
	return (ft_printout(sign, numb));
}
