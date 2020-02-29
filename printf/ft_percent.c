/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 03:50:26 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/23 16:31:38 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_width_percent(char *s, t_data *data)
{
	int	end;

	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	data->minus = (data->width < 0) ? 1 : data->minus;
	if (data->width < 0)
		data->width = -1 * data->width;
	if (!(data->string = malloc(data->width + 1)))
		return (NULL);
	end = (data->minus == 1) ? data->width : data->width - 1;
	data->index1 = 0;
	if (data->minus)
		data->string[data->index1++] = '%';
	while (data->index1 < end)
	{
		if (data->zero && !data->minus)
			data->string[data->index1] = '0';
		else
			data->string[data->index1] = ' ';
		data->index1++;
	}
	if (!data->minus)
		data->string[data->index1++] = '%';
	data->string[data->index1] = 0;
	return (data->string);
}

int				ft_percent(char *s, t_data *data)
{
	char	*arg;

	arg = NULL;
	data->zero = (*s == '0') ? 1 : 0;
	data->dot = ft_strchr(s, '.');
	data->minus = (*s == '-' || *(s + 1) == '-') ? 1 : 0;
	while (*s == '-' || *s == '0')
		s++;
	data->star = ft_stars(s, data);
	if ((*s > '0' && *s <= '9') || *s == '*')
	{
		arg = ft_width_percent(s, data);
		data->ret = ft_print(arg, data);
	}
	else
	{
		ft_putchar('%');
		data->ret = 1;
	}
	return (data->ret);
}
