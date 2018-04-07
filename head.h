/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:21:44 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/07 19:17:25 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_m
{
	struct s_m	*next;
	int			*pos;
}				t_m;

typedef struct	s_l
{
	int			pos[8];
	char		c;
	struct s_l	*n;
}				t_l;

typedef struct	s_n
{
	int			c;
	int			*n;
}				t_n;

typedef	struct	s_q
{
	t_m			*curq;
	t_l			**res;
}				t_q;

int				min_sqrsize(t_m *l);
void			*ft_memset(void *b, int c, size_t n);
void			ft_elemdel(t_m **alst);
t_m				*ft_elemnew(int *content);
int				push(t_m **begin_list, int *content);
int				*key(int *map);
int				*mp(int *map);
int				chk_input(int *map, t_m **elem, char *s);
int				count_all_elem(t_m **head);
int				find(int x, int y, t_l **head, char *a);
int				ft_is_contain(t_l *cur, t_l *next, int i, int square);
t_l				*find_squad(t_m **q, t_l **res, int *n);
void			print(t_l **head, int n);
void			set_char(t_l **head);
void			reverse(t_l **head);
t_l				*push_front(int *p, t_l *head, int col, int row);
int				count_res(t_l **head);
int				count_elem(t_m *curq);
int				ft_ceil(float x);
float			ft_square_root(float n);
t_l				*pop(t_l *head);

#endif
