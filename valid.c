/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:28:29 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/06 21:14:02 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"
#include <math.h>

int	min_sqrsize(t_elem *l)
{
	int	elems;
	int	min;

	min = 2;
	elems = 0;
	while (l && ++elems)
		l = l->next;
	while (min * min < elems * 4)
		min++;
	return (min);
}

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

void	ft_elemdel(t_elem **alst)
{
	t_elem	*temp;

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

t_elem	*ft_elemnew(int *content)
{
	t_elem	*new;
	int		i;

	if (!(new = malloc(sizeof(t_elem))))
		return (0);
	i = -1;
	while (++i < 8)
		new->pos = content;
	new->next = 0;
	return (new);
}

int	push(t_elem **begin_list, int *content)
{
	t_elem	*tmp;

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

int	*key(int *map)
{
	int minc;
	int minr;
	int i;
	int *k;
	int j;

	if (!map || !(k = malloc(8 * 4)))
		return (0);
	j = 16;
	minr = 3;
	minc = 3;
	i = 0;
	while (j--)
		if (map[15 - j])
		{
			k[i] = (15 - j) % 4;
			minc = minc > k[i] ? k[i] : minc;
			k[++i] = (15 - j) / 4;
			minr = minr > k[i] ? k[i] : minr;
			i++;
		}
	while (i--)
		k[i] = (i % 2) ? k[i] - minr : k[i] - minc;
	return (k);
}

int	*mp(int *map)
{
	int i;
	int b;
	int max;

	i = -1;
	b = 0;
	max = 0;
	while (++i < 16)
	{
		b += map[i];
		map[i] += (i - 4 > 0 && map[i] > 0) ? map[i - 4] : 0;
		map[i] += (i - 1 > 0 && map[i] > 0) ? map[i - 1] : 0;
		map[i] += (i + 4 < 16 && map[i] > 0) ? map[i + 4] : 0;
		map[i] += (i + 1 < 16 && map[i] > 0) ? map[i + 1] : 0;
		max = map[i] > max ? map[i] : max;
		if (map[i] == 1)
			return (0);
	}
	if (b != 4 || max < 4)
		return (0);
	return (map);
}

int	chk_input(int *map, t_elem **elem, char *s)
{
	char	buf[20];
	int		j;
	int		fd;
	int		i;

	ft_memset(buf, 0, 20);
	fd = open(s, O_RDONLY);
	while ((i = read(fd, buf, 20)) == 20)
	{
		j = 20;
		while (buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n' &&
			buf[19] == '\n' && j--)
			if (buf[19 - j] == '.' || buf[19 - j] == '#')
				*map++ = (buf[19 - j] == '.') ? 0 : 1;
			else if (buf[19 - j] != '\n')
				return (1);
		if (push(elem, key(mp(map -= 16))) || (read(fd, buf, 1) && *buf != 10))
				return (1);
		if (*buf == 10)
			ft_memset(buf, 0, 20);
	}
	if (!(read(fd, buf, 1)) && i == 0 && *buf != 0)
		return (0);
	return (1);
}

/*###########################################################*/
#include <stdio.h>
/*###########################################################*/

int	count_all_elem(t_elem **head)
{
	t_elem *cur;
	int i;

	i = 0;
	cur = *head;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		*map;
	t_elem	*elem;
	list *res;
	int n;

	n = 2;
	if (argc != 2 )
	{
		write(1, "usage:	source_file target_file\n", 32);
		exit (0);
	}
	elem = 0;
	if (!(map = malloc(sizeof(int) * 16)) || chk_input(map, &elem, argv[1]))
	{
		write(1, "error\n", 7);
		ft_elemdel(&elem);
		exit(0);
	}
	if (count_elem(elem) > 26)
	{
		write(1, "error\n", 7);
		return (0);
	}
	n = sqrt(count_all_elem(&elem) * 4);
	res = find_squad(&elem, &res, &n);
	reverse(&res);
	print(&res, n);
	return (0);
}
