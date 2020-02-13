/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 18:41:46 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/11 09:20:06 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int number, int *i, char *c, t_struct *spec)
{
	if (number / 16)
		print_hex(number / 16, i, c, spec);
	ptf_putchar(c[(number % 16)], spec);
	*i += 1;
}

int		length_hex(unsigned int number)
{
	int				length;

	length = 0;
	if (number == 0)
		length = 1;
	while (number != 0)
	{
		number = number / 16;
		length++;
	}
	return (length);
}

char	*type_hex(const char **s, t_struct *spec)
{
	char			*c;

	if ((*s)[spec->i] == 'X')
	{
		c = "0123456789ABCDEF";
		spec->hex = 'X';
	}
	else
	{
		c = "0123456789abcdef";
		spec->hex = 'x';
	}
	return (c);
}

void	print_hashtag(t_struct *spec)
{
	if (spec->hex == 'x')
		ptf_putstr("0x", spec);
	else
		ptf_putstr("0X", spec);
	spec->hashtag = 0;
}

void	handle_hex(const char **s, va_list *args, t_struct *spec)
{
	int				i;
	unsigned int	number;
	int				length;
	int				pad;
	char			*c;

	i = 0;
	spec->type = 'h';
	number = va_arg(*args, unsigned int);
	length = length_hex(number);
	pad = pad_amount(length, number, spec);
	c = type_hex(s, spec);
	if (number == 0)
		spec->hashtag = 0;
	if (spec->hashtag == 1)
		pad -= 2;
	if (spec->hashtag == 1 && (pad > 0 && spec->flags == '0' && spec->pre < 0))
		print_hashtag(spec);
	left_padding(pad, length, number, spec);
	if (spec->hashtag == 1)
		print_hashtag(spec);
	if (!(spec->pre == 0 && number == 0))
		print_hex(number, &i, c, spec);
	right_padding(pad, spec);
}
