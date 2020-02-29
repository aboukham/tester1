/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:48:50 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/23 23:47:54 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*flag_zero(char *arg, t_data *data)
{
	if (data->string[data->index1] == '-' && data->index1 != 0)
		data->string[data->index1] = '0';
	while (--data->index1 >= 1)
		data->string[data->index1] = '0';
	if (arg[0] == '-')
		data->string[data->index1] = '-';
	else
		data->string[data->index1] = '0';
	return (data->string);
}

static char		*flag_not_minus(char *arg, t_data *data)
{
	data->index2 = data->len;
	data->index1 = ft_strlen(data->string) - 1;
	while (--data->index2 >= 0)
	{
		data->string[data->index1] = arg[data->index2];
		data->index1--;
	}
	data->index1++;
	if (data->specif != 's' && data->specif != 'c' && data->specif != 'p' &&\
	data->zero && (!data->dot || data->precision < 0))
		data->string = flag_zero(arg, data);
	return (data->string);
}

char			*flag_minus(char *arg, t_data *data)
{
	if (data->minus == 1)
	{
		data->index1 = -1;
		while (++data->index1 < data->len)
			data->string[data->index1] = arg[data->index1];
		if (data->width < data->len)
			data->string[data->index1] = 0;
	}
	else
		data->string = flag_not_minus(arg, data);
	//if (data->dot && data->precision >= 0)
	//	free(arg);
	return (data->string);
}
