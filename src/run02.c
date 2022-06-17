/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:28:36 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/16 15:58:25 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void    ft_less_five(t_pslist *all)
{
	if (all->nbr_entry <= 3)
	{
		while (!ft_check_order(all))
		{
			if (all->stack_a[0] > all->stack_a[1] && all->stack_a[0] > all->stack_a[2])
			{
				ft_ra(all, 1);
				if (all->stack_a[0] > all->stack_a[1])
					ft_sa(all, 1);
			}
			else if (all->stack_a[0] < all->stack_a[1] && all->stack_a[0] > all->stack_a[2])
			{
				ft_rra(all, 1);
				if (all->stack_a[0] > all->stack_a[1])
					ft_sa(all, 1);
			}
			else if(all->stack_a[0] < all->stack_a[1] && all->stack_a[0] < all->stack_a[2])
			{
				ft_ra(all, 1);
				if (all->stack_a[0] > all->stack_a[1])
					ft_sa(all, 1);
			}
			else
				ft_rra(all, 1);
		}
	}
	else
		ft_lfive(all);	
}

void	ft_imp(t_pslist *all)
{
	while (all->stack_b[0] != all->save_moy[all->nbr_entry - 1])
		ft_rb(all, 1);
	ft_pa(all);
}

void ft_lfive(t_pslist *all)
{
	all->i = -1;
	all->k = all->nbr_in_a;
	while (all->nbr_in_a > 0)
		ft_pb(all);
	all->i = -1;
	all->k = all->nbr_entry - 1;
	while (all->k > 0)
	{
		while (all->stack_b[0] < all->save_moy[all->k])
			ft_rb(all, 1);
		if (all->stack_b[0] == all->save_moy[all->k])
			ft_pa(all);
		all->k--;
	}
	ft_pa(all);
}