/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:50:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/30 12:25:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void print_pile_index(t_liste **lst)
{
    int i;
    t_liste *tmp;

    if (*lst == NULL) {
        ft_printf("[ Empty ]\n");
        return;
    }
    i = 0;
    tmp = (*lst);
    //ft_printf("|");
    while ((*lst)->next)
    {
        ft_printf("[ %i ]  ",(*lst)->content);
        ft_printf("[ %i ]\n",(*lst)->index);
        (*lst) = (*lst)->next;
        i++;
    }
    ft_printf("[ %i ]  ",(*lst)->content);
    ft_printf("[ %i ]\n\n",(*lst)->index);
    (*lst) = tmp;
}

void print_pile_pos(t_liste **lst)
{
    int i;
    t_liste *tmp;

    if (*lst == NULL) {
        ft_printf("[ Empty ]\n");
        return;
    }
    i = 0;
    tmp = (*lst);
    //ft_printf("|");
    while ((*lst)->next)
    {
        ft_printf("[ %i ]  ",(*lst)->content);
        ft_printf("[ %i ]\n",(*lst)->pos);
        (*lst) = (*lst)->next;
        i++;
    }
    ft_printf("[ %i ]  ",(*lst)->content);
    ft_printf("[ %i ]\n\n",(*lst)->pos);
    (*lst) = tmp;
}

void print_pile(t_liste **lst)
{
    int i;
    t_liste *tmp;

    if (*lst == NULL) 
    {
        ft_printf("[ Empty ]\n");
        return;
    }
    i = 0;
    tmp = (*lst);
    while ((*lst)->next)
    {
        ft_printf("[ %i ] \n ",(*lst)->content);
        (*lst) = (*lst)->next;
        i++;
    }
    ft_printf("[ %i ]\n  ",(*lst)->content);
    (*lst) = tmp;
}

void print_all_pile(t_liste **a, t_liste **b)
{
    t_liste *tmp_a;
    t_liste *tmp_b;

    tmp_a = (*a);
    tmp_b = (*b);

    printf("\t[ A ]\t|   [ B ]\n");
    printf("       --------------------\n");
    while (tmp_a || tmp_b)
    {
        if (tmp_a && tmp_b)
        {
            printf("\t[ %i ]\t|",tmp_a->content);
            printf("  [ %i ]\n",tmp_b->content);
            tmp_a = tmp_a->next;
            tmp_b = tmp_b->next;
        }
        else if (tmp_a && !tmp_b)
        {
            printf("\t[ %i ]\t|\t\n",tmp_a->content);
            tmp_a = tmp_a->next;
        }
        else if (!tmp_a && tmp_b)
        {
            printf("\t\t|  [ %i ]\n",tmp_b->content);
            tmp_b = tmp_b->next;
        }
        else
            printf("[ Empty ]\t|\t[ Empty ]\n");
    }
    printf("       --------------------\n\n");
}

/*void    ft_show(t_liste *lst)
{
    while (lst)
    {
        printf("index=%d-nb=%d\n", lst->index, lst->content);
        lst = lst->next;
    }
}*/

void ft_push_swap(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
    ft_printf("%d size debut ps\n", nb->size);
    if (nb->size == 2 && ft_already_class((*lst1)) == 0)
        ft_sa((*lst1));
    else if (nb->size == 3 && ft_already_class((*lst1)) == 0)
        ft_sort_3(lst1);
    else if ((nb->size > 3 && ft_already_class((*lst1)) == 0))
        ft_sort(lst1, lst2, nb);

}

int main(int ac, char **av)
{
    t_liste *a = NULL;
    t_liste *b = NULL;
    t_list_param    argument;
    
    argument.size = 0;
    ft_check_args(ac, av, &argument);
    while (argument.tab[argument.size])
    {
        ft_lstadd_back_p(&a, ft_lstnew_p(ft_atoi(argument.tab[argument.size])));
        argument.size++;
    }
    print_all_pile(&a, &b);
    ft_push_swap(&a, &b, &argument);
    print_all_pile(&a, &b);
    return(0);
}