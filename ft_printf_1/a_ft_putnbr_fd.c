/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ft_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 11:33:15 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/10 17:49:13 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr_fd(int n, int fd, int *counter)
{
	if (n == -2147483648)
	{
		if (counter[8])
			ft_putstr_fd("2147483648", fd, counter);
		else
			ft_putstr_fd("-2147483648", fd, counter);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		counter[3]++;
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd, counter);
	ft_putchar_fd((n % 10) + '0', fd, counter);
}
