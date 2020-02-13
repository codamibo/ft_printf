/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 17:35:22 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 13:00:58 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		find_conversion(const char **s, va_list *args, t_struct *spec)
{
	if ((*s)[spec->i] == 'c')
		handle_char(args, spec);
	else if ((*s)[spec->i] == 's')
		handle_str(args, spec);
	else if ((*s)[spec->i] == 'd' || (*s)[spec->i] == 'i')
		handle_int(args, spec);
	else if ((*s)[spec->i] == 'u')
		handle_uns(args, spec);
	else if ((*s)[spec->i] == 'x' || (*s)[spec->i] == 'X')
		handle_hex(s, args, spec);
	else if ((*s)[spec->i] == 'p')
		handle_ptr(args, spec);
	else if ((*s)[spec->i] == 'n')
		handle_n(args, spec);
	else if ((*s)[spec->i] == '%')
		handle_percent(spec);
	else
		return (0);
	return (1);
}

void	find_flags(const char **s, t_struct *spec)
{
	clean_struct(spec);
	while ((*s)[spec->i] == '0' || (*s)[spec->i] == '-' || (*s)[spec->i] == ' '
	|| (*s)[spec->i] == '+' || (*s)[spec->i] == '#')
	{
		if ((*s)[spec->i] == '0' && spec->flags != '-')
			spec->flags = '0';
		else if ((*s)[spec->i] == '-')
			spec->flags = '-';
		else if ((*s)[spec->i] == ' ')
			spec->space = 1;
		else if ((*s)[spec->i] == '+')
			spec->plus = 1;
		else if ((*s)[spec->i] == '#')
			spec->hashtag = 1;
		spec->i++;
	}
}

void	find_specifiers(const char **s, va_list *args, t_struct *spec)
{
	find_flags(s, spec);
	if ((*s)[spec->i] == '*')
	{
		spec->width = va_arg(*args, int);
		spec->flags = (spec->width < 0) ? '-' : spec->flags;
		spec->width = (spec->width < 0) ? -spec->width : spec->width;
		spec->i++;
	}
	else if (ft_isdigit((*s)[spec->i]))
		spec->width = ft_atoi(&(*s)[spec->i]);
	while (ft_isdigit((*s)[spec->i]))
		spec->i++;
	spec->i = ((*s)[spec->i] == '.') ? spec->i + 1 : spec->i;
	if ((*s)[spec->i] == '*')
	{
		spec->pre = va_arg(*args, int);
		spec->pre = (spec->pre < 0) ? -1 : spec->pre;
		spec->i++;
	}
	else if (ft_isdigit((*s)[spec->i]))
		spec->pre = ft_atoi(&(*s)[spec->i]);
	else if ((*s)[spec->i - 1] == '.')
		spec->pre = 0;
	while (ft_isdigit((*s)[spec->i]))
		spec->i++;
}

void	iterate_string(const char **s, va_list *args, t_struct *spec)
{
	int	found;

	found = 0;
	while ((*s)[spec->i])
	{
		if ((*s)[spec->i] != '%')
		{
			ptf_putchar((*s)[spec->i], spec);
			spec->i++;
		}
		else if ((*s)[spec->i] == '%')
		{
			spec->i++;
			find_specifiers(s, args, spec);
			found = find_conversion(s, args, spec);
			if (found)
				spec->i++;
		}
	}
}

int		ft_printf(const char *s, ...)
{
	va_list		args;
	t_struct	spec;

	va_start(args, s);
	spec.ret = 0;
	spec.i = 0;
	iterate_string(&s, &args, &spec);
	va_end(args);
	return (spec.ret);
}
