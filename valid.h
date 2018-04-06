/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:21:44 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/06 22:22:58 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_elem
{
	struct s_elem	*next;
	int		*pos;
}				t_elem;

typedef struct	s_list
{
	int			pos[8];
	char		c;
	struct s_list *n;
}				list;

typedef struct	list_count
{
	int			c;
	int			*n;
}				num;

typedef	struct	list_queen
{
	t_elem		*curq;
	list		**res;
}				list_q;

void	reverse(list **head);
list	*find_squad(t_elem **q, list **res, int *n);
void	print(list **head, int n);
int		count_elem(t_elem *curq);

#endif
