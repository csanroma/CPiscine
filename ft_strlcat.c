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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = 0;
	while (*(src + src_len) != 0)
		src_len++;
	dest_len = 0;
	while (*(dest + dest_len) != 0)
		dest_len++;
	i = 0;
	if (dest_len + 1 < size)
	{
		size = size - dest_len - 1;
		while ((src[i] != 0) && (i < size))
		{
			dest[i + dest_len] = src[i];
			i++;
		}
	}	
	if (size != 0 && dest_len < size)
		dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}
