/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:04:39 by csanroma          #+#    #+#             */
/*   Updated: 2021/12/05 10:04:53 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && (i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
