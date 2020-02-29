/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:16:20 by aaboukha          #+#    #+#             */
/*   Updated: 2020/02/21 22:16:53 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_uitoa(unsigned int n)
{
	char			*str;
	int				digit;

	digit = ft_nb_digit(n);
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit] = 0;
	while (--digit >= 0)
	{
		str[digit] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
