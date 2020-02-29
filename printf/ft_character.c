/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:28:50 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/23 17:38:15 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_zero_c(char c, t_data *data)
{
	int	i;
	int	end;

	end = (data->minus == 1) ? data->width : data->width - 1;
	if (data->width == 0)
		write(1, &c, 1);
	else
	{
		i = 0;
		if (data->minus)
		{
			write(1, &c, 1);
			i++;
		}
		while (i++ < end)
			write(1, " ", 1);
		if (!data->minus)
		{
			write(1, &c, 1);
			i++;
		}
	}
}

static void		ft_width_c(char *s, t_data *data)
{
	char	c;

	if (*s == '*')
		data->width = va_arg(data->arg, int);
	if (*s > '0' && *s <= '9')
		data->width = ft_atoi(s);
	if (data->width < 0)
	{
		data->width = -1 * data->width;
		data->minus = 1;
	}
	c = va_arg(data->arg, int);
	print_zero_c(c, data);
}

int				ft_character(char *s, t_data *data)
{
	char	c;

	if (*s == 0 || (*s == '-' && *(s + 1) == 0))
	{
		c = va_arg(data->arg, int);
		ft_putchar(c);
		return (1);
	}
	data->minus = (*s == '-') ? 1 : 0;
	while (*s == '-')
		s++;
	ft_width_c(s, data);
	data->ret = (data->width != 0) ? data->width : data->width + 1;
	return (data->ret);
}
