/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:26:47 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/23 17:32:43 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(size_t x)
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

char		*dtoex(size_t x, t_data *data)
{
	char	*str;
	char	*s;

	s = "0123456789abcdef";
	data->size = (data->specif == 'p') ? ft_size(x) + 2 : ft_size(x);
	if (!(str = malloc(data->size + 1)))
		return (NULL);
	data->index1 = data->size;
	str[data->index1--] = 0;
	if (x == 0 && data->dot && data->specif == 'p')
		str[data->index1--] = 0;
	else if (x == 0)
		str[data->index1--] = '0';
	while (x)
	{
		str[data->index1] = s[x % 16];
		x = x / 16;
		data->index1--;
	}
	if (data->specif == 'p')
	{
		str[data->index1--] = 'x';
		str[data->index1] = '0';
	}
	return (str);
}
