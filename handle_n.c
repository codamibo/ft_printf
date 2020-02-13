/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_n.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:08:54 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/06 09:23:42 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_n(va_list *args, t_struct *spec)
{
	int	*amount_printed;

	amount_printed = va_arg(*args, int *);
	if (amount_printed == NULL)
		return ;
	else
		*amount_printed = spec->ret;
}
