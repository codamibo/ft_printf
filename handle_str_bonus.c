/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_str_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 14:29:52 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 13:01:39 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		str_length(char **str)
{
	int	length;

	if (*str == NULL)
	{
		length = 6;
		*str = "(null)";
	}
	else
		length = ft_strlen(*str);
	return (length);
}

void	handle_str(va_list *args, t_struct *spec)
{
	int		i;
	int		pad;
	char	*str;
	int		length;

	i = 0;
	pad = 0;
	str = va_arg(*args, void *);
	length = str_length(&str);
	pad = (spec->pre >= 0 && spec->pre < length) ? (spec->width - spec->pre) :
	(spec->width - length);
	left_padding_c(pad, spec);
	if (spec->pre < 0)
		spec->pre = length;
	while (str[i] != '\0' && spec->pre > 0)
	{
		ptf_putchar(str[i], spec);
		i++;
		spec->pre--;
	}
	right_padding(pad, spec);
}
