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
#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;

	len = 0;
	while (src[len] != 0)
		len++;
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

/*int	main()
{
	char *src;
	char *str;
	char *strc;

	src = "HELLO";
	printf("src = %s ",src);
	printf("\nsize = %lu",sizeof(src));

	strc = strdup(src);
	printf("\nstrc = %s ",strc);
	printf("\nsize =%lu ",sizeof(strc));

	str = ft_strdup(src);
	printf("\nstr = %s ",str);
	printf("\nsize =%lu ",sizeof(str));

}*/
