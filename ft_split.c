/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:44:58 by csanroma          #+#    #+#             */
/*   Updated: 2021/12/16 18:45:04 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	sep_check(char str, char *charset)
{
	int	i;

	i = 0;
	while (str != 0 && charset[i] != 0)
	{
		if (str == charset[i])
			return (i);
		i++;
	}
	return (-1);
}

int	str_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != 0 && sep_check(*(str + i), charset) == -1)
		i++;
	return (i);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	wc;

	i = 0;
	wc = 1;
	if (str[i] != 0)
	{
		while (str[i + 1] != 0)
		{
			if (sep_check(*(str + i), charset) >= 0)
			{
				i++;
				if (sep_check(*(str + i), charset) == -1)
					wc++;
			}
			else
				i++;
		}
	}
	return (wc);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**split;

	while (sep_check(*str, charset) >= 0)
		str++;
	split = malloc(sizeof(char *) * (word_count(str, charset) + 1));
	i = 0;
	while (i < word_count(str, charset))
	{
		j = 0;
		split[i] = malloc(sizeof(char) * (str_len(str, charset) + 1));
		while (*str != 0 && sep_check(*str, charset) == -1)
		{
			split[i][j] = *str;
			str++;
			j++;
		}
		split[i][j] = 0;
		while (sep_check(*str, charset) >= 0)
			str++;
		i++;
	}
	return (split);
}

/*int main()
{
	char	*str = "hola que tal:";
	char	*charset = ": ";
	char **split;
	int wc;
   
	wc = word_count(str, charset);
	printf("wc=%d\n", wc);
	//printf("wc %d\n", word_count(str, charset));
	split = ft_split(str, charset);
	int i;
	i = 0;
	while (i < wc)
	{
		printf("%s\n", split[i]);
		i++;
	}
	printf("-");
	return (0);
}*/
