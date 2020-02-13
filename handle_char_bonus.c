/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_char_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:54:58 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 13:01:09 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	left_padding_c(int pad, t_struct *spec)
{
	char	c;

	c = 'a';
	if (pad > 0 && spec->flags != '-')
	{
		if (spec->flags == '0')
			c = '0';
		else if (spec->flags == 'a')
			c = ' ';
		if (spec->type == 'p')
			c = ' ';
		while (pad > 0)
		{
			ptf_putchar(c, spec);
			pad--;
		}
	}
}

void	handle_char(va_list *args, t_struct *spec)
{
	int		pad;

	pad = 0;
	if (spec->width > 0)
		pad = spec->width - 1;
	left_padding_c(pad, spec);
	ptf_putchar(va_arg(*args, int), spec);
	right_padding(pad, spec);
}
