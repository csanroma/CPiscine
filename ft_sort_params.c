/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:25:42 by csanroma          #+#    #+#             */
/*   Updated: 2021/12/09 15:28:25 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 || *s2 != 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = j + 1;
		while (i < argc)
		{
			if (ft_strcmp(argv[j], argv[i]) > 0)
			{
				ft_swap(&argv[j], &argv[i]);
			}
			i++;
		}
		ft_putstr(argv[j]);
		j++;
	}
}
