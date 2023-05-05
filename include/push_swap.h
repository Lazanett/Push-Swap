/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:42:01 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/05 13:10:04 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_list_param
{
	char	**tab;
	int		size;
	int		mediane;
	int		min;
	int		new_max;
	int		max;
	int		split;
}	t_list_param;

typedef struct s_liste
{
	int				content;
	int				index;
	int				pos;
	int				best_pos;
	int				cost_a;
	int				cost_b;
	struct s_liste	*next;
}	t_liste;

//---------------------------ALGO.C-----------------------------------------//
void	ft_sort(t_liste **lst1, t_liste **lst2, t_list_param *nb);
void	ft_final_sort(t_liste **lst1, t_list_param *nb);
void	push_all_save_three(t_liste **lst1, t_liste **lst2, t_list_param *nb);
//--------------------------------------------------------------------------//

//------------------------------COST.C--------------------------------------//
void	ft_get_cost(t_liste **a, t_liste **b);
void	ft_least_comb(t_liste **a, t_liste **b);
int		ft_nb_conv(int nb);
//--------------------------------------------------------------------------//

//------------------------------FREE.C-------------------------------------//
void	free_lst(t_liste **lst);
void	ft_free(char **free_me);
//--------------------------------------------------------------------------//

//----------------------------INDEX.C---------------------------------------//
void	ft_assign_index(t_liste *lst, t_list_param *nb);
t_liste	*ft_index(t_liste *temp, t_liste *highest, long valeur);
//--------------------------------------------------------------------------//

//-------------------------------MAIN.C-------------------------------------//
void	ft_push_swap(t_liste **lst1, t_liste **lst2, t_list_param *nb);
void	print_all_pile(t_liste **a, t_liste **b);
//--------------------------------------------------------------------------//

//-------------------------------MOVE.C-------------------------------------//
void	ft_rev_rotate_both(t_liste **a, t_liste **b, int *cost_a, int *cost_b);
void	ft_rotate_both(t_liste **a, t_liste **b, int *cost_a, int *cost_b);
void	ft_rotate_a(t_liste **a, int *cost);
void	ft_rotate_b(t_liste **b, int *cost);
void	ft_move(t_liste **a, t_liste **b, int cost_a, int cost_b);
//--------------------------------------------------------------------------//

//---------------------------------OPE.C------------------------------------//
void	ft_swap(t_liste *lst);
void	ft_sa(t_liste *liste_a);
void	ft_sb(t_liste *liste_b);
void	ft_ss(t_liste *liste_a, t_liste *liste_b);
//--------------------------------------------------------------------------//

//--------------------------------OPE2.C------------------------------------//
void	push(t_liste **src, t_liste **dest);
void	ft_pa(t_liste **liste_a, t_liste **liste_b);
void	ft_pb(t_liste **liste_a, t_liste **liste_b);
//--------------------------------------------------------------------------//

//-------------------------------OPE3.C-------------------------------------//
void	ft_rotate(t_liste *lst);
void	ft_ra(t_liste *liste_a);
void	ft_rb(t_liste *liste_b);
void	ft_rr(t_liste *liste_a, t_liste *liste_b);
//---------------------------------------------------------------------------//

//--------------------------------OPE4.C-------------------------------------//
void	ft_reverse_rotate(t_liste **lst);
void	ft_rra(t_liste **liste_a);
void	ft_rrb(t_liste **liste_b);
void	ft_rrr(t_liste **liste_a, t_liste **liste_b);
//--------------------------------------------------------------------------//

//--------------------------------PARSIN.C----------------------------------//
int		ft_check_double(t_list_param *argument);
int		ft_isnum(char *num);
void	ft_check_args(int argc, char **argv, t_list_param *argument);
void	ft_args_valid(int argc, char **argv, t_list_param *argument, int i);
void	ft_check_list(t_list_param *argument, int i);
//--------------------------------------------------------------------------//

//-------------------------------POS.C--------------------------------------//
void	ft_assign_position(t_liste **lst);
int		get_target(t_liste **a, int b_idx, int target_idx, int target_pos);
void	ft_best_pos(t_liste **a, t_liste **b);
int		get_lowest_index_position(t_liste **lst);
//--------------------------------------------------------------------------//

//------------------------------SMALL_SORT.C--------------------------------//
void	ft_sort_3(t_liste **lst);
void	ft_posibility_sort_3(t_liste **lst);
//--------------------------------------------------------------------------//

//--------------------------UTILS_STRUC.C------------------------------------//
int		ft_already_class(t_liste *lst);
void	ft_get_min(t_liste *lst, t_list_param *nb);
void	ft_get_max(t_liste *lst, t_list_param *nb);
int		ft_len(char **tab);
int		ft_len_list(t_liste *lst);
//--------------------------------------------------------------------------//

//---------------------------------UTILS_LIST.C-----------------------------//
t_liste	*ft_lstnew_p(int content);
t_liste	*ft_lstlast_p(t_liste *lst);
t_liste	*get_stack_bottom(t_liste *lst);
t_liste	*ft_lst_before_last(t_liste *lst);
void	ft_lstadd_back_p(t_liste **lst, t_liste *new);

//--------------------------------------------------------------------------//

//---------------------------------UTILS.C----------------------------------//
void	ft_lstadd_front_p(t_liste **lst, t_liste *new);
void	ft_lstdelone_p(t_liste *lst);
void	ft_error(char *msg, t_list_param *argument);
//-------------------------------------------------------------------------//

//--------------------------------BONUS------------------------------------//

//-------------------------------MAIN_BOMUS.C-----------------------------//
void	ft_is_ok(t_liste *lst1, t_liste *lst2);
void	ft_reader(t_liste *lst1, t_liste *lst2);
void	do_ope(t_liste *lst1, t_liste *lst2, char **tab_ope);
//-------------------------------------------------------------------------//

//-----------------------------DO_OPE_BONUS---------------------------------//
int		is_swap(t_liste *lst1, t_liste *lst2, char **tab_ope, int i);
int		is_push(t_liste *lst1, t_liste *lst2, char **tab_ope, int i);
int		is_rotate(t_liste *lst1, t_liste *lst2, char **tab_ope, int i);
int		is_reverse_rotate(t_liste *lst1, t_liste *lst2, char **tab_ope, int i);
int		ft_strcmp(char *s1, char *s2);
//---------------------------------------------------------------------------//

#endif
