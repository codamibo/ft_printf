/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_percent_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:59:24 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 13:01:30 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_percent(t_struct *spec)
{
	int		pad;

	pad = 0;
	pad = spec->width - 1;
	if (spec->flags != '-')
	{
		while (pad > 0)
		{
			if (spec->flags == '0')
				ptf_putchar('0', spec);
			else
				ptf_putchar(' ', spec);
			pad--;
		}
	}
	ptf_putchar('%', spec);
	while (pad > 0)
	{
		ptf_putchar(' ', spec);
		pad--;
	}
}
