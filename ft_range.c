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

int	*ft_range(int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	arr = malloc(sizeof(int) * len);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

/*int	main()
{
	int *arr;

	arr = ft_range(0, 5);
	printf("%d %d %d %d ", arr[0], arr[1], arr[2], arr[3]);

}*/