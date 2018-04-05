/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:21:44 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/05 21:49:52 by azulbukh         ###   ########.fr       */
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

void	reverse(list **head);
list	*find_squad(t_elem **q, list **res, int *n);
void	print(list **head, int n);

#endif
