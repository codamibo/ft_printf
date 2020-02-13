/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 17:24:36 by iboeters       #+#    #+#                */
/*   Updated: 2020/02/12 11:15:49 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_struct
{
	int			pre;
	int			width;
	char		flags;
	char		type;
	int			plus;
	int			hashtag;
	char		hex;
	int			ret;
	int			i;
	int			space;
}				t_struct;

int				ft_printf(const char *s, ...);
void			ptf_putchar(char c, t_struct *spec);
void			ptf_putstr(char *s, t_struct *spec);
void			ptf_putnbr(int n, t_struct *spec);
void			print_precision(int length, int number, t_struct *spec);
void			left_padding(int pad, int length, int number, t_struct *spec);
void			right_padding(int pad, t_struct *spec);
int				pad_amount(int length, int number, t_struct *spec);
void			clean_struct(t_struct *spec);
void			left_padding_c(int pad, t_struct *spec);
void			handle_int(va_list *args, t_struct *spec);
void			handle_hex(const char **s, va_list *args, t_struct *spec);
void			handle_char(va_list *args, t_struct *spec);
void			handle_n(va_list *args, t_struct *spec);
void			handle_ptr(va_list *args, t_struct *spec);
void			handle_str(va_list *args, t_struct *spec);
void			handle_uns(va_list *args, t_struct *spec);
void			handle_percent(t_struct *spec);
void			print_hashtag(t_struct *spec);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);

#endif
