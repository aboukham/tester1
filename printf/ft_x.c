/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:37:14 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/23 17:39:07 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_width_x(char *s, t_data *data, char *arg)
{
	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	if (arg == NULL)
		arg = dtoex((size_t)va_arg(data->arg, unsigned int), data);
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
	//free(arg);
	return (data->string);
}

static char		*ft_precision_x(char *s, t_data *data, char *arg)
{
	unsigned int	x;

	if (*s == 0)
		data->precision = 0;
	else if (data->star == 0 || data->star == 1)
		data->precision = ft_atoi(s);
	if (data->precision < 0)
		return (arg);
	x = va_arg(data->arg, unsigned int);
	if (x == 0 && data->precision == 0)
		arg = ft_strdup("");
	else
		arg = dtoex_prec(x, data);
	return (arg);
}

int				ft_x(char *s, t_data *data)
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
		arg = ft_precision_x(data->dot + 1, data, arg);
	if (s && ((*s > '0' && *s <= '9') || *s == '*'))
		arg = ft_width_x(s, data, arg);
	if (*s == 0 || arg == NULL)
		arg = dtoex((size_t)va_arg(data->arg, unsigned int), data);
	if (data->specif == 'X')
		arg = ft_to_upper(arg, data);
	data->ret = ft_print(arg, data);
	return (data->ret);
}
