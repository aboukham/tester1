/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:16:04 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/23 16:26:43 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_width_d(char *s, t_data *data, char *arg)
{
	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	if (arg == NULL)
		arg = ft_itoa(va_arg(data->arg, int));
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

static char		*ft_precision_d(char *s, t_data *data, char *arg)
{
	int	d;

	if (*s == 0)
		data->precision = 0;
	else if (data->star == 0 || data->star == 1)
		data->precision = ft_atoi(s);
	if (data->precision < 0)
		return (arg);
	d = va_arg(data->arg, int);
	if (d == 0 && data->precision == 0)
		arg = ft_strdup("");
	else
		arg = ft_itoa_precision(d, data);
	return (arg);
}

int				ft_integer(char *s, t_data *data)
{
	char	*arg;

	data->len = 0;
	arg = NULL;
	data->dot = ft_strchr(s, '.');
	data->minus = (*s == '-') ? 1 : 0;
	data->zero = (*s == '0') ? 1 : 0;
	while (*s == '-' || *s == '0')
		s++;
	data->star = ft_stars(s, data);
	if (data->dot)
		arg = ft_precision_d(data->dot + 1, data, arg);
	if (s && ((*s > '0' && *s <= '9') || *s == '*'))
		arg = ft_width_d(s, data, arg);
	if (*s == 0 || arg == NULL)
		arg = ft_itoa(va_arg(data->arg, int));
	data->ret = ft_print(arg, data);
	return (data->ret);
}
