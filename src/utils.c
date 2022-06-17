/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:16:49 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/17 13:47:01 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

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
