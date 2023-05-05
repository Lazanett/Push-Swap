/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:14:33 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/05 13:20:43 by lazanett         ###   ########.fr       */
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
	ft_reader(a, b);
	ft_is_ok(a, b);
	free_lst(&a);
	free_lst(&b);
	return (0);
}

void	ft_is_ok(t_liste *lst1, t_liste *lst2)
{
	if (ft_already_class(lst1) == 1 || lst2 != NULL)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
}

void	ft_reader(t_liste *lst1, t_liste *lst2)
{
	char	*line;
	char	**tab_ope;
	int		i;

	i = 0;
	tab_ope = NULL;
	while (get_next_line(1))
	{
		if (&get_next_line == NULL)
			free(tab_ope);
		line = get_next_line(1);
		tab_ope[i] = strdup(line);
		i++;
	}
	tab_ope[i] = "\0";
	do_ope(lst1, lst2, tab_ope);
	ft_free(tab_ope);
}

void	do_ope(t_liste *lst1, t_liste *lst2, char **tab_ope)
{
	int	i;

	i = 0;
	while (tab_ope[i])
	{
		if (is_swap(lst1, lst2, tab_ope, i) == 0)
		{
			if (is_push(lst1, lst2, tab_ope, i) == 0)
			{
				if (is_rotate(lst1, lst2, tab_ope, i) == 0)
					is_reverse_rotate(lst1, lst2, tab_ope, i);
			}
		}
		i++;
	}
}
