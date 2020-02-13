/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 09:28:32 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/11 09:37:51 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptf_putchar(char c, t_struct *spec)
{
	write(1, &c, 1);
	spec->ret++;
}

void	ptf_putnbr(int n, t_struct *spec)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ptf_putchar('2', spec);
			n = 147483648;
		}
		else
			n = -n;
	}
	if ((n / 10) > 0)
		ptf_putnbr(n / 10, spec);
	ptf_putchar(n % 10 + '0', spec);
}

void	ptf_putstr(char *s, t_struct *spec)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ptf_putchar(s[i], spec);
		i++;
	}
}

void	clean_struct(t_struct *spec)
{
	spec->pre = -1;
	spec->width = 0;
	spec->flags = 'a';
	spec->type = 'a';
	spec->plus = 0;
	spec->hashtag = 0;
	spec->hex = 'a';
	spec->space = 0;
}
