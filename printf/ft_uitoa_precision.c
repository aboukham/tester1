/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:20:46 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/21 22:20:49 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_str(char *str, unsigned int nb, t_data *data)
{
	while (--data->max >= 0)
	{
		if (nb == '0')
			str[data->max] = '0';
		else
		{
			str[data->max] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
}

char		*ft_uitoa_precision(unsigned int n, t_data *data)
{
	char			*str;
	int				digit;

	digit = ft_nb_digit(n);
	data->max = (digit < data->precision) ? data->precision : digit;
	if (!(str = (char *)malloc(sizeof(char) * (data->max + 1))))
		return (NULL);
	str[data->max] = 0;
	fill_str(str, n, data);
	return (str);
}
