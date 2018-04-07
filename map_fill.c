/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:19:19 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/07 19:48:54 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "./libft/libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	void *temp;

	temp = b;
	while (n-- > 0)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
	}
	return (temp);
}

void	ft_elemdel(t_m **alst)
{
	t_m	*temp;

	if (alst && *alst)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			free((*alst)->pos);
			free(*alst);
			*alst = temp;
		}
		*alst = 0;
	}
}

t_m		*ft_elemnew(int *content)
{
	t_m		*new;
	int		i;

	if (!(new = malloc(sizeof(t_m))))
		return (0);
	i = -1;
	while (++i < 8)
		new->pos = content;
	new->next = 0;
	return (new);
}

int		push(t_m **begin_list, int *content)
{
	t_m		*tmp;

	if (content == 0)
		return (1);
	if (!*begin_list)
	{
		*begin_list = ft_elemnew(content);
		return (0);
	}
	if (!(tmp = *begin_list))
		return (1);
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = ft_elemnew(content);
	return (0);
}
