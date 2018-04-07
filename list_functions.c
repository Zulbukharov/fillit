/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:45:45 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/07 18:52:26 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "./libft/libft.h"

void	set_char(t_l **head)
{
	t_l		*cur;
	char	i;

	i = 'A';
	cur = *head;
	while (cur)
	{
		cur->c = i;
		i++;
		cur = cur->n;
	}
}

void	print(t_l **head, int n)
{
	int		x;
	int		y;
	char	a;
	t_l		*cur;

	x = 0;
	cur = *head;
	while (x < n - 1)
	{
		y = 0;
		while (y < n - 1)
		{
			if (find(x, y, head, &a))
				ft_putchar(a);
			else
				ft_putchar('.');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
