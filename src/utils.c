/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:16:49 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/17 15:44:58 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int ft_find_moy(t_pslist *all)
{
    all->save_moy = ft_calloc(sizeof(int), all->nbrs.nbr_entry + 1);
    if (!all->save_moy)
    {
        free(all->save_moy);
        return (0);
    }
    all->ct.i = -1;
    while (++all->ct.i < all->nbrs.nbr_in_a)
        all->save_moy[all->ct.i] = all->stack_a[all->ct.i];
    all->ct.i = -1;
    while (++all->ct.i < all->nbrs.nbr_in_a)
    {
        all->ct.k = all->ct.i;
        while (++all->ct.k < all->nbrs.nbr_entry)
            if (all->save_moy[all->ct.i] > all->save_moy[all->ct.k])
                ft_swap(&all->save_moy[all->ct.i], &all->save_moy[all->ct.k]);
    }
    all->save_moy[all->ct.i] = '\0';
    all->nbrs.s_moy = all->save_moy[all->nbrs.nbr_entry / 2];
    ft_printf("QRT; %d\nMED: %d\n3QRT:%d\n", all->nbrs.s_qrt, all->nbrs.s_moy, all->nbrs.s_3_qrt);
    all->ct.i = -1;
    while (++all->ct.i < all->nbrs.nbr_entry)
        ft_printf("%d ", all->save_moy[all->ct.i]);
    ft_printf("\n");
    return (0);
}

bool    ft_wside(t_pslist *all)
{
    all->test += 1;
    all->ct.ii = all->nbrs.nbr_in_b;
    all->ct.i = - 1;
    while (++all->ct.i < all->nbrs.nbr_in_b)
    {
        if (all->stack_b[all->ct.i] == all->save_moy[all->ct.kk])
        {
            if (all->ct.i < all->ct.ii / 2)
                return (false);
            else
                return (true);
        }
    }
    return (true);
}

bool    ft_wside_a(t_pslist *all)
{
    all->test += 1;
    all->ct.ii = all->nbrs.nbr_in_a;
    all->ct.i = - 1;
    while (++all->ct.i < all->nbrs.nbr_in_a)
    {
        if (all->stack_a[all->ct.i] == all->save_moy[all->ct.kk])
        {
            if (all->ct.i < all->ct.ii / 2)
                return (false);
            else
                return (true);
        }
    }
    return (true);
}

void ft_print_stack(t_pslist *all)
{
    int i;

    i = -1;
    printf("\033[0;32mSTACK A  \033[0;37m");
    while (++i < all->nbrs.nbr_in_a)
        printf("[\033[0;36m%03d\033[0;37m]", all->stack_a[i]);
    printf("\n");
    i = -1;
    printf("\033[0;33mSTACK B  \033[0;37m");
    while (++i < all->nbrs.nbr_in_b)
        printf("[\033[0;36m%03d\033[0;37m]", all->stack_b[i]);
    printf("\n");
    ft_printf("COUNT: %d\n", all->total_count);
}
