/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:19:30 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/18 16:48:36 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void ft_tob1(t_pslist *all)
{
    int i;

    i = -1;
    while (++i < all->nbrs.nbr_entry)
    {
        if (all->stack_a[0] < all->nbrs.s_moy)
        {
            ft_pb(all);
        }
        else
        {
            if (all->stack_a[0] < all->stack_b[all->nbrs.nbr_in_b])
                ft_rr(all);
            else
                ft_ra(all, 1);
        }
        // ft_print_stack(all);
    }
}

void ft_first_class(t_pslist *all)
{
    all->ct.ii = all->nbrs.nbr_in_b + 1;
    all->ct.kk = all->nbrs.nbr_entry / 2 - 1;
    while (--all->ct.ii > 0)
    {
        while (all->stack_b[0] != all->save_moy[all->ct.kk])
        {
            if (ft_wside(all) == true)
            {
                ft_rrb(all, 1);
            }
            else
                ft_rb(all, 1);
            // ft_print_stack(all);
        }
        if (all->stack_b[0] == all->save_moy[all->ct.kk])
        {
            ft_pa(all);
            // ft_print_stack(all);
        }
        all->ct.kk--;
    }
    // ft_printf("HELP\n");
}

void ft_tob2(t_pslist *all)
{
    int i;

    all->ct.x = all->nbrs.nbr_entry / 2 - 1;
    i = -1;
    while (++i <= all->ct.x)
    {
        if (all->stack_a[0] < all->stack_b[all->nbrs.nbr_in_b])
            ft_rr(all);
        else
            ft_ra(all, 1);
        // ft_print_stack(all);
    }
    i = -1;
    while (++i <= all->ct.x)
    {
        ft_pb(all);
        // ft_print_stack(all);
    }
    if (ft_p_or_imp(all->nbrs.nbr_entry) == 0)
    {
        ft_pb(all);
        // ft_print_stack(all);
    }
    // ft_print_stack(all);
}

void ft_second_class(t_pslist *all)
{
    all->ct.ii = all->nbrs.nbr_in_b + 1;
    all->ct.kk = all->nbrs.nbr_entry - 1;
    if (!ft_p_or_imp(all->nbrs.nbr_entry))
    {
        ft_imp(all);
        all->ct.kk = all->nbrs.nbr_entry - 2;
    }
    while (--all->ct.ii > 0)
    {
        while (all->stack_b[0] != all->save_moy[all->ct.kk])
        {
            if (ft_wside(all) == true)
                ft_rrb(all, 1);
            else
                ft_rb(all, 1);
            // ft_print_stack(all);
        }
        if (all->stack_b[0] == all->save_moy[all->ct.kk])
        {
            ft_pa(all);
            // ft_print_stack(all);
        }
        all->ct.kk--;
    }
    while (all->ct.x-- > -1)
    {
        ft_ra(all, 1);
        // ft_print_stack(all);
    }
    if (!ft_p_or_imp(all->nbrs.nbr_entry))
    {
        ft_ra(all, 1);
        // ft_print_stack(all);
    }
}