/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:47:50 by csanroma          #+#    #+#             */
/*   Updated: 2021/12/14 14:47:55 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	int	c;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		c = nb % 10 + 48;
		write(1, &c, 1);
	}
	else
	{
		c = nb % 10 + 48;
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		while (*par[i].str != 0)
		{
			write(1, par[i].str, 1);
			par[i].str++;
		}
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		while (*par[i].copy != 0)
		{
			write(1, par[i].copy, 1);
			par[i].copy++;
		}
		write(1, "\n", 1);
		i++;
	}
}
