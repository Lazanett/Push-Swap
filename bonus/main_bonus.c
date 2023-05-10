/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:14:33 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/10 15:02:08 by lazanett         ###   ########.fr       */
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
	char	*ope;

	ope = NULL;
	line = get_next_line(0);
	while (line)
	{
		do_ope(lst1, lst2, line);
		free(line);
		line = get_next_line(0);
	}
	if (&get_next_line == NULL)
		free(line);
}

int	do_ope(t_liste **lst1, t_liste **lst2, char *ope)
{
	if (is_swap(lst1, lst2, ope) == 0)
		return (0);
	else if (is_push(lst1, lst2, ope) == 0)
		return (0);
	else if (is_rotate(lst1, lst2, ope) == 0)
		return (0);
	else if (is_reverse_rotate(lst1, lst2, ope) == 0)
		return (0);
	return (1);
}

void	rrr(t_liste **liste_a, t_liste **liste_b)
{
	ft_reverse_rotate(liste_a);
	ft_reverse_rotate(liste_b);
}
