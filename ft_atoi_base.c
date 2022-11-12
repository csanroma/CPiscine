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

int	get_num(int lbase, int pos_i);
int	get_len_base(char *base);
int	eq_in_base(char num, char *base);
int	get_first_i(char *str);

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	i;
	int	sign;
	int	lbase;
	int	lnbr;

	n = 0;
	sign = 1;
	lbase = get_len_base(base);
	if (lbase == 0)
		return (0);
	i = get_first_i(str);
	if (i < 0)
		sign = -1;
	lnbr = 0;
	while (eq_in_base(str[i + lnbr], base) >= 0 && str[i + lnbr] != '\0')
		lnbr++;
	while (lnbr > 0)
	{
		n = get_num(lbase, lnbr - 1) * eq_in_base(str[i], base) + n;
		lnbr--;
		i++;
	}
	return (sign * n);
}

int	get_first_i(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	return (i);
}

int	get_num(int lbase, int pos_i)
{
	int	i;
	int	n;

	i = 0;
	if (pos_i == 0)
		return (1);
	n = 1;
	while (i < pos_i)
	{
		n = n * lbase;
		i++;
	}
	return (n);
}

int	get_len_base(char *base)
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

int	eq_in_base(char num, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
