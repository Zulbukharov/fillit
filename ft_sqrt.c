/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:05:35 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/07 19:17:53 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "./libft/libft.h"

int		ft_ceil(float x)
{
	if ((x - (int)(x)) > 0)
		return ((int)(x + 1));
	return ((int)(x));
}

float	ft_square_root(float n)
{
	float x;
	float y;
	float e;

	x = n;
	y = 1;
	e = 0.000001;
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}
