/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:16:23 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/23 16:27:21 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width_p(char *s, t_data *data)
{
	char	*arg;

	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	arg = dtoex(va_arg(data->arg, size_t), data);
	data->len = ft_strlen(arg);
	if (data->width < 0)
	{
		data->width = -1 * data->width;
		data->minus = 1;
	}
	data->max = (data->len < data->width) ? data->width : data->len;
	if (!(data->string = malloc(data->max + 1)))
		return (NULL);
	filling_spaces(data->string, 0, data->max);
	data->string = flag_minus(arg, data);
	return (data->string);
}

int			ft_p(char *s, t_data *data)
{
	char	*arg;
	size_t	l;

	data->len = 0;
	data->dot = ft_strchr(s, '.');
	if (*s == 0 || (*s == '-' && *(s + 1) == 0) || (*s == '0' && *(s + 1) == 0))
	{
		l = va_arg(data->arg, size_t);
		arg = dtoex(l, data);
	}
	else
	{
		data->minus = (*s == '-') ? 1 : 0;
		while (*s == '-')
			s++;
		data->star = ft_stars(s, data);
		arg = ft_width_p(s, data);
	}
	data->ret = ft_print(arg, data);
	return (data->ret);
}
