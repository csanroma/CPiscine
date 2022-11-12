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

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(int len, char *src)
{
	char	*str;

	str = malloc (sizeof(*str) * (len + 1));
	len = 0;
	while (src[len] != 0)
	{
		str[len] = src[len];
		len++;
	}
	str[len] = 0;
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stocks;
	int			i;

	stocks = malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		stocks[i].size = str_len(av[i]);
		stocks[i].str = ft_strdup(stocks[i].size, av[i]);
		stocks[i].copy = ft_strdup(stocks[i].size, av[i]);
		i++;
	}
	stocks[i].str = 0;
	return (stocks);
}
