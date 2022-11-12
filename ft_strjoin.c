/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:43:25 by csanroma          #+#    #+#             */
/*   Updated: 2021/12/09 19:43:30 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	str_len(char *src)
{
	int	len;

	len = 0;
	while (src[len] != 0)
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != 0)
		i++;
	while (*src != 0)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str_join;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + str_len(strs[i]);
		i++;
	}
	len = len + str_len(sep) * (size - 1);
	str_join = malloc(sizeof(strs) * (len + 1));
	i = 0;
	while (i < size)
	{
		str_join = ft_strcat(str_join, strs[i]);
		if (i != size - 1)
			str_join = ft_strcat(str_join, sep);
		i++;
	}
	return (str_join);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*chars[3] = {"H O L A", " ", "S I"};
	char	*xx;

	xx = ft_strjoin(0, chars, " ");
	printf("%s", xx);
	free(xx);
	return (0);
}*/