/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:19:03 by csanroma          #+#    #+#             */
/*   Updated: 2021/12/03 10:40:04 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len_base(char *base);
void	ft_rec(int nbr, char *base, int lbase);

void	ft_putnbr_base(int nbr, char *base)
{
	int	lbase;

	lbase = len_base(base);
	if (lbase == 0)
		return ;
	ft_rec(nbr, base, lbase);
}

int	len_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_rec(int nbr, char *base, int lbase)
{
	int				c;
	unsigned int	nbl;

	if (lbase == 0)
		return ;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbl = (-1) * nbr;
	}
	else
		nbl = nbr;
	if (nbl > (unsigned int)(lbase - 1))
	{
		ft_rec(nbl / lbase, base, lbase);
		c = nbl % lbase;
		write (1, &base[c], 1);
	}
	else
	{
		c = nbl % lbase;
		write(1, &base[c], 1);
	}
}
