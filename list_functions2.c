/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcitons2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:46:01 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/07 18:53:00 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "./libft/libft.h"

void	reverse(t_l **head)
{
	t_l		*prev;
	t_l		*current;
	t_l		*next;

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

t_l		*pop(t_l *head)
{
	t_l		*temp;

	temp = head;
	head = head->n;
	free(temp);
	return (head);
}

t_l		*push_front(int *p, t_l *head, int col, int row)
{
	t_l		*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_l));
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

int		count_res(t_l **head)
{
	int		i;
	t_l		*cur;

	i = 0;
	cur = *head;
	while (cur)
	{
		i++;
		cur = cur->n;
	}
	return (i);
}

int		count_elem(t_m *curq)
{
	t_m		*cur;
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
