/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:42:35 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/28 18:55:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int	ft_check_double(t_list_param *argument)
{
	int	i;
	int	j;

	i = 0;
	while (argument->tab[i])
	{
		j = i + 1;
		while (argument->tab[j])
		{
			if (ft_atoi(argument->tab[i]) == ft_atoi(argument->tab[j]))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i; //index du num

	i = 0;
	if (num[0] == '-') // num negatif
		i++;
	while (num[i]) //tant pas a la fin du nb
	{
		if (!ft_isdigit(num[i])) //si c'est pas un nombre
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv, t_list_param *argument)
{
	int		i;
    int     j;
	long	tmp;

	i = 0;
    j = 0;
	if (argc == 1)
		exit(0);
	else if (argc == 2) //si la liste = "66 3 1 5 94 33 284"
		argument->tab = ft_split(argv[1], ' '); //args = liste de num a trier
	else
	{
		i = 1;
		argument->tab = malloc(sizeof(char *) * argc);
		while (argv[i])
			argument->tab[j++] = argv[i++];
		argument->tab[j] = NULL; // dernier case du tableau = null
	}
	i = 0;
	while (argument->tab[i])
		i++;
	i = 0;
	while (argument->tab[i])
	{
		tmp = ft_atoi(argument->tab[i]);
		if (tmp < -2147483648 || tmp > 2147483647) //verif les nb min et max
			ft_error("Error list");
		if (!ft_isnum(argument->tab[i])) //verif si c'est un nombre
			ft_error("Error list");
		i++;
	}
	if (ft_check_double(argument))// si pas de double renvoi 0
			ft_error("Error list");
}
