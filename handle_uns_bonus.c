/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_uns_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 09:13:35 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 13:01:42 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ptf_putnbr_u(unsigned int n, t_struct *spec)
{
	if ((n / 10) > 0)
		ptf_putnbr_u(n / 10, spec);
	ptf_putchar(n % 10 + '0', spec);
}

void	handle_uns(va_list *args, t_struct *spec)
{
	unsigned int	number;
	unsigned int	tmp_number;
	int				length;
	int				pad;

	spec->type = 'u';
	number = va_arg(*args, unsigned int);
	tmp_number = number;
	length = 0;
	while (tmp_number != 0)
	{
		tmp_number = tmp_number / 10;
		length++;
	}
	if (number == 0)
		length++;
	pad = pad_amount(length, number, spec);
	left_padding(pad, length, number, spec);
	if (!(spec->pre == 0 && number == 0))
		ptf_putnbr_u(number, spec);
	right_padding(pad, spec);
}
