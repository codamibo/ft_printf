/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 17:05:32 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 12:46:02 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precision(int length, int number, t_struct *spec)
{
	int l;

	l = length;
	if (spec->pre > length)
	{
		if (spec->type == 'h' && spec->hashtag == 1)
			print_hashtag(spec);
		if ((number < 0 || spec->plus == 1) && spec->type == 'i')
			(number < 0) ? ptf_putchar('-', spec) : ptf_putchar('+', spec);
		while (spec->pre > l)
		{
			ptf_putchar('0', spec);
			l++;
		}
	}
	if ((number < 0 || spec->plus == 1) && spec->type == 'i' && (spec->pre <=
	length && !(spec->flags == '0' && spec->width > (length + 1))))
		(number < 0) ? ptf_putchar('-', spec) : ptf_putchar('+', spec);
}

void	left_padding(int pad, int length, int number, t_struct *spec)
{
	char	c;

	c = 'a';
	if (spec->pre >= 0 && spec->flags == '0')
		spec->flags = 'a';
	if (pad > 0)
	{
		if (spec->flags == 'a')
			c = ' ';
		else if (spec->flags == '0')
		{
			if ((number < 0 || spec->plus == 1) && spec->type == 'i')
				(number < 0) ? ptf_putchar('-', spec) : ptf_putchar('+', spec);
			c = '0';
		}
		if (c == '0' || c == ' ')
		{
			while (pad > 0)
			{
				ptf_putchar(c, spec);
				pad--;
			}
		}
	}
	print_precision(length, number, spec);
}

void	right_padding(int pad, t_struct *spec)
{
	if (spec->flags == '-' && pad > 0)
	{
		while (pad > 0)
		{
			ptf_putchar(' ', spec);
			pad--;
		}
	}
}

int		pad_amount(int length, int number, t_struct *spec)
{
	int	pad;

	pad = 0;
	if ((spec->pre == 0 && number == 0) && spec->width > 0 && spec->plus != 1)
		pad = spec->width;
	else if (spec->type == 'i' && (number < 0 || spec->plus == 1))
	{
		if (spec->pre > length && spec->width > 0)
			pad = spec->width - spec->pre - 1;
		else if (spec->pre <= length && spec->width > 0)
			pad = spec->width - length - 1;
		if ((spec->pre == 0 && number == 0) && spec->width > 0)
			pad++;
	}
	else
	{
		if (spec->pre > length && spec->width > 0)
			pad = spec->width - spec->pre;
		else if (spec->pre <= length && spec->width > 0)
			pad = spec->width - length;
	}
	return (pad);
}

void	handle_int(va_list *args, t_struct *spec)
{
	int		number;
	int		tmp_number;
	int		length;
	int		pad;

	spec->type = 'i';
	number = va_arg(*args, int);
	tmp_number = number;
	length = (number == 0) ? 1 : 0;
	while (tmp_number != 0)
	{
		tmp_number = tmp_number / 10;
		length++;
	}
	pad = pad_amount(length, number, spec);
	if (spec->space == 1 && spec->plus != 1 && number >= 0)
	{
		ptf_putchar(' ', spec);
		pad--;
	}
	left_padding(pad, length, number, spec);
	if (!(spec->pre == 0 && number == 0))
		ptf_putnbr(number, spec);
	right_padding(pad, spec);
}
