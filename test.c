/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:57:04 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/17 12:31:52 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int ft_find_moy(t_pslist *all)
{
    all->save_moy = ft_calloc(sizeof(int), all->nbr_entry + 1);
    if (!all->save_moy)
    {
        free(all->save_moy);
        return (0);
    }
    all->i = -1;
    while (++all->i < all->nbr_in_a)
        all->save_moy[all->i] = all->stack_a[all->i];
    all->i = -1;
    while (++all->i < all->nbr_in_a)
    {
        all->k = all->i;
        while (++all->k < all->nbr_entry)
            if (all->save_moy[all->i] > all->save_moy[all->k])
                ft_swap(&all->save_moy[all->i], &all->save_moy[all->k]);
    }
    all->save_moy[all->i] = '\0';
    all->s_qrt = all->save_moy[all->nbr_entry / 4 - 1];
    // all->s_moy = all->save_moy[all->nbr_entry / 2 - 1];
    all->s_moy = all->save_moy[all->nbr_entry / 2];
    all->s_3_qrt = all->save_moy[all->nbr_entry / 4 * 3 - 1];
    ft_printf("QRT; %d\nMED: %d\n3QRT:%d\n", all->s_qrt, all->s_moy, all->s_3_qrt);
    all->i = -1;
    while (++all->i < all->nbr_entry)
        ft_printf("%d ", all->save_moy[all->i]);
    ft_printf("\n");
    return (0);
}

// void ft_tob1(t_pslist *all)
// {
// 	int i;

// 	i = -1;
// 	while (++i < all->nbr_entry)
// 	{
// 		if (all->stack_a[0] <= all->s_qrt)
// 		{
// 			ft_pb(all);
// 			ft_print_stack(all);
// 		}
// 		else
// 		{
// 			// ft_printf("HELP\n");
// 			if (all->stack_a[0] < all->stack_b[all->nbr_in_b])
// 			{
// 				ft_rr(all);
// 				ft_print_stack(all);
// 			}
// 			else
// 			{
// 				ft_ra(all, 1);
// 				ft_print_stack(all);
// 			}
// 		}
// 		if (all->nbr_in_a <= all->nbr_entry / 4 * 3)
// 			break ;
// 	}
// }

// void ft_first_class(t_pslist *all)
// {
// 	all->kk = all->nbr_entry / 4 - 1;
// 	while (all->nbr_in_b > 0)
// 	{

// 		ft_printf("HELP\n");
// 		while (all->stack_b[0] != all->save_moy[all->kk])
// 		{
// 			ft_rb(all, 1);
// 			// ft_print_stack(all);
// 		}
// 		if (all->stack_b[0] == all->save_moy[all->kk])
// 		{
// 			ft_pa(all);
// 			ft_print_stack(all);
// 		}
// 		all->kk--;
// 		ft_printf("K: %d\n", all->kk);
// 	}
// }

// void ft_tob2(t_pslist *all)
// {
// 	int i;

// 	all->x = all->nbr_entry / 2 - 1;
// 	i = -1;
// 	while (++i <= all->x)
// 	{
// 		if (all->stack_a[0] < all->stack_b[all->nbr_in_b])
// 			ft_rr(all);
// 		else
// 			ft_ra(all, 1);
// 		ft_print_stack(all);
// 	}
// 	i = -1;
// 	while (++i <= all->x)
// 	{
// 		ft_pb(all);
// 		ft_print_stack(all);
// 	}
// 	if (ft_p_or_imp(all->nbr_entry) == 0)
// 	{
// 		ft_pb(all);
// 		ft_print_stack(all);
// 	}
// 	// ft_print_stack(all);
// }

void ft_tob1(t_pslist *all)
{
    int i;

    i = -1;
    while (++i < all->nbr_entry)
    {
        if (all->stack_a[0] < all->s_moy)
        {
            ft_pb(all);
        }
        else
        {
            if (all->stack_a[0] < all->stack_b[all->nbr_in_b])
                ft_rr(all);
            else
                ft_ra(all, 1);
        }
        ft_print_stack(all);
    }
}

void ft_first_class(t_pslist *all)
{
    all->ii = all->nbr_in_b + 1;
    all->kk = all->nbr_entry / 2 - 1;
    while (--all->ii > 0)
    {
        while (all->stack_b[0] != all->save_moy[all->kk])
        {
            if (ft_wside(all) == true)
            {
                ft_rrb(all, 1);
            }
            else
                ft_rb(all, 1);
            ft_print_stack(all);
        }
        if (all->stack_b[0] == all->save_moy[all->kk])
        {
            ft_pa(all);
            ft_print_stack(all);
        }
        all->kk--;
    }
    // ft_printf("HELP\n");
}

void ft_tob2(t_pslist *all)
{
    int i;

    all->x = all->nbr_entry / 2 - 1;
    i = -1;
    while (++i <= all->x)
    {
        if (all->stack_a[0] < all->stack_b[all->nbr_in_b])
            ft_rr(all);
        else
            ft_ra(all, 1);
        ft_print_stack(all);
    }
    i = -1;
    while (++i <= all->x)
    {
        ft_pb(all);
        ft_print_stack(all);
    }
    if (ft_p_or_imp(all->nbr_entry) == 0)
    {
        ft_pb(all);
        ft_print_stack(all);
    }
    // ft_print_stack(all);
}

void ft_second_class(t_pslist *all)
{
    all->ii = all->nbr_in_b + 1;
    all->kk = all->nbr_entry - 1;
    if (!ft_p_or_imp(all->nbr_entry))
    {
        ft_imp(all);
        all->kk = all->nbr_entry - 2;
    }
    while (--all->ii > 0)
    {
        while (all->stack_b[0] != all->save_moy[all->kk])
        {
            if (ft_wside(all) == true)
                ft_rrb(all, 1);
            else
                ft_rb(all, 1);
            ft_print_stack(all);
        }
        if (all->stack_b[0] == all->save_moy[all->kk])
        {
            ft_pa(all);
            ft_print_stack(all);
        }
        all->kk--;
    }
    while (all->x-- > -1)
    {
        ft_ra(all, 1);
        ft_print_stack(all);
    }
    if (!ft_p_or_imp(all->nbr_entry))
    {
        ft_ra(all, 1);
        ft_print_stack(all);
    }
}
