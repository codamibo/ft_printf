/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:09:17 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/25 13:53:37 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str;
	char		*str2;
	size_t		i;

	i = 0;
	str = (char *)src;
	str2 = (char *)dst;
	if ((str == '\0') && (str2 == '\0'))
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			str2[i] = str[i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
