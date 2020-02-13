/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 10:11:32 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 11:29:44 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(unsigned long int number, int *i, t_struct *spec)
{
	char			*c;

	c = "0123456789abcdef";
	if (number / 16)
		print_ptr(number / 16, i, spec);
	ptf_putchar(c[(number % 16)], spec);
	*i += 1;
}

void	handle_ptr(va_list *args, t_struct *spec)
{
	unsigned long int	number;
	unsigned long int	tmp_number;
	int					length;
	int					pad;
	int					i;

	i = 0;
	spec->type = 'p';
	number = va_arg(*args, unsigned long int);
	tmp_number = number;
	length = 0;
	while (tmp_number != 0)
	{
		tmp_number = tmp_number / 16;
		length++;
	}
	if (number == 0)
		length = 1;
	length += 2;
	pad = spec->width - length;
	left_padding_c(pad, spec);
	ptf_putstr("0x", spec);
	print_ptr(number, &i, spec);
	right_padding(pad, spec);
}
