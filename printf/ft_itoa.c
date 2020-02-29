/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:43:46 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/22 21:29:51 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(int n)
{
	char			*str;
	int				digit;
	int				sign;
	unsigned int	nb;

	sign = ((n < 0) ? 1 : 0);
	nb = (n < 0) ? -1 * n : n;
	digit = ft_nb_digit(nb) + sign;
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[digit] = 0;
	while (--digit >= sign)
	{
		str[digit] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
