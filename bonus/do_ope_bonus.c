/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:28:29 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/05 13:04:38 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_swap(t_liste *lst1, t_liste *lst2, char **tab_ope, int i)
{
	if (strcmp(tab_ope[i], "sa") == 0)
		ft_sa(lst1);
	else if (strcmp(tab_ope[i], "sb") == 0)
		ft_sb(lst2);
	else if (strcmp(tab_ope[i], "ss") == 0)
		ft_ss(lst1, lst2);
	return (1);
}

int	is_push(t_liste *lst1, t_liste *lst2, char **tab_ope, int i)
{
	if (strcmp(tab_ope[i], "pa") == 0)
		ft_pa(&lst2, &lst1);
	else if (strcmp(tab_ope[i], "pb") == 0)
		ft_pb(&lst1, &lst2);
	return (1);
}

int	is_rotate(t_liste *lst1, t_liste *lst2, char **tab_ope, int i)
{
	if (strcmp(tab_ope[i], "ra") == 0)
		ft_ra(lst1);
	else if (strcmp(tab_ope[i], "rb") == 0)
		ft_rb(lst2);
	else if (strcmp(tab_ope[i], "rr") == 0)
		ft_rr(lst1, lst2);
	return (1);
}

int	is_reverse_rotate(t_liste *lst1, t_liste *lst2, char **tab_ope, int i)
{
	if (strcmp(tab_ope[i], "rra") == 0)
		ft_rra(&lst1);
	else if (strcmp(tab_ope[i], "rrb") == 0)
		ft_rrb(&lst2);
	else if (strcmp(tab_ope[i], "rrr") == 0)
		ft_rrr(&lst1, &lst2);
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