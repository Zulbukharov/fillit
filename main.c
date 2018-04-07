/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:24:41 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/07 19:41:00 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "./libft/libft.h"

int		find(int x, int y, t_l **head, char *a)
{
	t_l		*cur;
	int		i;

	cur = *head;
	while (cur)
	{
		i = 0;
		while (i < 8)
		{
			if (y == cur->pos[i] && x == cur->pos[i + 1])
			{
				*a = cur->c;
				return (1);
			}
			i += 2;
		}
		cur = cur->n;
	}
	return (0);
}

int		ft_is_contain(t_l *cur, t_l *next, int i, int square)
{
	int		n;
	t_l		*c;
	t_l		*ne;
	int		s;

	s = square;
	n = 0;
	c = cur;
	ne = next;
	while (n < 8)
	{
		if ((c->pos[i] == ne->pos[n] && c->pos[i + 1] == ne->pos[n + 1])
				|| c->pos[i] >= square || c->pos[i + 1] >= square ||
				ne->pos[i] >= square || ne->pos[i + 1] >= square)
			return (0);
		n += 2;
	}
	return (1);
}

int		ft_c(t_l *head, int square)
{
	t_l		*cur;
	t_l		*next;
	int		i;

	i = 0;
	next = head->n;
	cur = head;
	if (!cur)
		return (1);
	while (i < 8 && next)
	{
		if (!ft_is_contain(cur, next, i, square))
			return (0);
		i += 2;
		if (i > 7 && next->n)
		{
			i = 0;
			next = next->n;
		}
	}
	return (1);
}

int		place_sq(t_m *curq, int *cr, t_l **r, t_n *he)
{
	int		crcr[2];

	crcr[0] = 0;
	crcr[1] = 0;
	*r = push_front(curq->pos, *r, cr[0], cr[1]);
	if (ft_c(*r, *(he->n)) && curq->next && place_sq(curq->next, crcr, r, he))
		return (1);
	else
	{
		if (ft_c(*r, *(he->n)) && count_res(r) == he->c)
			return (1);
		*r = pop(*r);
		if (cr[1] < *(he->n) && cr[0] < *(he->n))
		{
			crcr[0] = cr[0] + 1;
			crcr[1] = cr[1];
			place_sq(curq, crcr, r, he);
		}
		else if (cr[0] >= *(he->n) && cr[1] < *(he->n))
		{
			crcr[1] = cr[1] + 1;
			place_sq(curq, crcr, r, he);
		}
	}
	return (0);
}

t_l		*find_squad(t_m **q, t_l **res, int *n)
{
	t_m		*curq;
	t_n		*he;
	int		*cr;

	cr = malloc(sizeof(int) * 2);
	cr[0] = 0;
	cr[1] = 0;
	curq = *q;
	he = malloc(sizeof(t_n));
	he->n = n;
	he->c = count_elem(*q);
	while (!*res)
	{
		place_sq(curq, cr, res, he);
		*(he->n) += 1;
	}
	free(cr);
	return (*res);
}
