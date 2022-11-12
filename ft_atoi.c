/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:00:07 by csanroma          #+#    #+#             */
/*   Updated: 2021/12/05 11:00:16 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num(char *str);

int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
		{
			sign = -sign;
		}
		str++;
	}
	while (ft_num(str) != 0 && *str != '\0')
	{
		n = ft_num(str) + n * 10;
		str++;
	}
	return (sign * n);
}

int	ft_num(char *str)
{
	if (*str > 47 && *str < 58)
		return (*str - 48);
	return (0);
}
