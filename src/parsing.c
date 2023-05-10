/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:42:35 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/10 15:05:26 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv, t_list_param *argument)
{
	int	i;

	i = 0;
	if (argc == 1)
		exit(0);
	ft_args_valid(argc, argv, argument, i);
	ft_check_list(argument, i);
}

void	ft_args_valid(int argc, char **argv, t_list_param *argument, int i)
{
	int	j;

	j = 0;
	argument->split = 0;
	if (argc == 2)
	{
		argument->tab = ft_split(argv[1], ' ');
		argument->split = 1;
	}
	else
	{
		i = 1;
		argument->tab = malloc(sizeof(char *) * argc);
		if (!argument->tab)
			ft_error("Error", argument);
		while (argv[i])
			argument->tab[j++] = argv[i++];
		argument->tab[j] = NULL;
	}	
}

void	ft_check_list(t_list_param *argument, int i)
{
	long	tmp;

	i = 0;
	while (argument->tab[i])
	{
		if (ft_strlen(argument->tab[i]) > 11
			|| ft_strlen(argument->tab[i]) == 0)
			ft_error("Error", argument);
		tmp = ft_atoi(argument->tab[i]);
		if (!ft_isnum(argument->tab[i]))
			ft_error("Error", argument);
		else if (tmp > INT_MAX || tmp < INT_MIN)
			ft_error("Error", argument);
		i++;
	}
	if (ft_check_double(argument))
		ft_error("Error", argument);
}
