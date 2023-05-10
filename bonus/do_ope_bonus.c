/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:28:29 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/10 15:13:09 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_swap(t_liste **lst1, t_liste **lst2, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(*lst1);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(*lst2);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(*lst1, *lst2);
	return (1);
}

int	is_push(t_liste **lst1, t_liste **lst2, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa(lst1, lst2);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(lst1, lst2);
	return (1);
}

int	is_rotate(t_liste **lst1, t_liste **lst2, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(*lst1);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(*lst2);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(*lst1, *lst2);
	return (1);
}

int	is_reverse_rotate(t_liste **lst1, t_liste **lst2, char *line)
{
	if (ft_strcmp(line, "rra\n") == 0)
		rra(lst1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(lst2);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(lst1, lst2);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
