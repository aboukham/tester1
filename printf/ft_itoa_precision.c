/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:21:27 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/22 23:42:25 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_str(char *str, unsigned int nb, int sign, t_data *data)
{
	while (--data->max >= sign)
	{
		str[data->max] = nb % 10 + '0';
		nb = nb / 10;
	}
}

char			*ft_itoa_precision(int n, t_data *data)
{
	char			*str;
	int				d;
	int				sg;
	unsigned int	nb;

	sg = ((n < 0) ? 1 : 0);
	nb = (n < 0) ? -1 * n : n;
	d = ft_nb_digit(nb);
	data->max = (d < data->precision) ? data->precision + sg : d + sg;
	if (!(str = (char *)malloc(sizeof(char) * (data->max + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[data->max] = 0;
	fill_str(str, nb, sg, data);
	return (str);
}
