/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:14:33 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/15 13:33:24 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list_param	argument;
	t_liste			*a;
	t_liste			*b;

	a = NULL;
	b = NULL;
	argument.size = 0;
	ft_check_args(argc, argv, &argument);
	while (argument.tab[argument.size])
	{
		ft_lstadd_back_p(&a, ft_lstnew_p(ft_atoi(argument.tab[argument.size])));
		argument.size++;
	}
	if (argument.split == 1)
		ft_free(argument.tab);
	else
		free(argument.tab);
	ft_reader(&a, &b);
	ft_is_ok(a, b);
	free_lst(&a);
	free_lst(&b);
	return (0);
}

void	ft_is_ok(t_liste *lst1, t_liste *lst2)
{
	if (ft_already_class(lst1) == 1 && lst2 == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void	ft_reader(t_liste **lst1, t_liste **lst2)
{
	char	*line;
	int		i;

	line = get_next_line(0);
	while (line)
	{
		i = ft_strlen(line);
		if (do_ope(lst1, lst2, line, i) == 1)
		{
			free(line);
			ft_putendl_fd("Error", 2);
			free_lst(lst1);
			free_lst(lst2);
			exit(0);
		}	
		free(line);
		line = get_next_line(0);
	}
	if (&get_next_line == NULL)
		free(line);
}

int	do_ope(t_liste **lst1, t_liste **lst2, char *line, int i)
{
	if (ft_strncmp(line, "sa\n", i) == 0)
		sa(*lst1);
	else if (ft_strncmp(line, "sb\n", i) == 0)
		sb(*lst2);
	else if (ft_strncmp(line, "ss\n", i) == 0)
		ss(*lst1, *lst2);
	else if (ft_strncmp(line, "pa\n", i) == 0)
		pa(lst1, lst2);
	else if (ft_strncmp(line, "pb\n", i) == 0)
		pb(lst1, lst2);
	else if (ft_strncmp(line, "ra\n", i) == 0)
		ra(*lst1);
	else if (ft_strncmp(line, "rb\n", i) == 0)
		rb(*lst2);
	else if (ft_strncmp(line, "rr\n", i) == 0)
		rr(*lst1, *lst2);
	else if (ft_strncmp(line, "rra\n", i) == 0)
		rra(lst1);
	else if (ft_strncmp(line, "rrb\n", i) == 0)
		rrb(lst2);
	else if (ft_strncmp(line, "rrr\n", i) == 0)
		rrr(lst1, lst2);
	else
		return (1);
	return (0);
}

void	rrr(t_liste **liste_a, t_liste **liste_b)
{
	ft_reverse_rotate(liste_a);
	ft_reverse_rotate(liste_b);
}
