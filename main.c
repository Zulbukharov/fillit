/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:24:41 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/06 22:39:25 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"
#include <stdlib.h>
#include <stdio.h>

int		find(int x, int y, list **head, char *a)
{
	list	*cur;
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

void	set_char(list **head)
{
	list *cur;
	char i;

	i = 'A';
	cur = *head;
	while (cur)
	{
		cur->c = i;
		i++;
		cur = cur->n;
	}
}

void	reverse(list **head)
{
	list *prev;
	list *current;
	list *next;

	prev = NULL;
	current = *head;
	next = NULL;
	while (current != NULL)
	{
		next = current->n;
		current->n = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	set_char(head);
}

void	print(list **head, int n)
{
	int		x;
	int		y;
	char	a;
	list	*cur;

	x = 0;
	cur = *head;
	while (x < n - 1)
	{
		y = 0;
		while (y < n - 1)
		{
			if (find(x, y, head, &a))
				printf("%c", a);
			else
				printf(".");
			y++;
		}
		printf("\n");
		x++;
	}
}

list	*pop(list *head)
{
	list *temp;

	temp = head;
	head = head->n;
	free(temp);
	return (head);
}

list	*push_front(int *p, list *head, int col, int row)
{
	list	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(list));
	if (!new)
		return (NULL);
	while (i < 8)
	{
		new->pos[i] = p[i] + col;
		new->pos[i + 1] = p[i + 1] + row;
		i += 2;
	}
	new->n = head;
	return (new);
}

int		ft_is_contain(list *cur, list *next, int i, int square)
{
	int		n;
	list	*c;
	list	*ne;
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

int		ft_compare(list *head, int square)
{
	list	*cur;
	list	*next;
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

int		count_res(list **head)
{
	int		i;
	list	*cur;

	i = 0;
	cur = *head;
	while (cur)
	{
		i++;
		cur = cur->n;
	}
	return (i);
}

int		count_elem(t_elem *curq)
{
	t_elem	*cur;
	int		i;

	i = 0;
	cur = curq;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int		place_squad(t_elem *curq, int col, int row, list **res, num *he)
{
	*res = push_front(curq->pos, *res, col, row);
	if (ft_compare(*res, *(he->n)) && curq->next
			&& place_squad(curq->next, 0, 0, res, he))
		return (1);
	else
	{
		if (ft_compare(*res, *(he->n)) && count_res(res) == he->c)
			return (1);
		*res = pop(*res);
		if (row < *(he->n) && col < *(he->n))
			place_squad(curq, col + 1, row, res, he);
		else if (col >= *(he->n) && row < *(he->n))
			place_squad(curq, 0, row + 1, res, he);
	}
	return (0);
}

list	*find_squad(t_elem **q, list **res, int *n)
{
	t_elem	*curq;
	num		*he;
	
	curq = *q;
	he = malloc(sizeof(num));
	he->n = n;
	he->c = count_elem(*q);
	while (!*res)
	{
		place_squad(curq, 0, 0, res, he);
		*(he->n) += 1;
	}
	return (*res);
}
