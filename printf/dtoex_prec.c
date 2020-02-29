/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoex_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:27:39 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/22 15:47:41 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(long long int x)
{
	int		i;

	i = 1;
	while (x / 16)
	{
		i++;
		x = x / 16;
	}
	return (i);
}

static void	fill_str_x(char *str, unsigned int x, t_data *data)
{
	char	*s;

	s = "0123456789abcdef";
	while (--data->index1 >= 0)
	{
		if (x == 0)
			str[data->index1] = '0';
		else
		{
			str[data->index1] = s[x % 16];
			x = x / 16;
		}
	}
}

char		*dtoex_prec(unsigned int x, t_data *data)
{
	char			*str;

	data->size = ft_size(x);
	data->max = (data->precision < data->size) ? data->size : data->precision;
	if (!(str = malloc(data->max + 1)))
		return (NULL);
	data->index1 = data->max;
	str[data->index1] = 0;
	fill_str_x(str, x, data);
	return (str);
}
