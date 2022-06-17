/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:57:04 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/17 16:29:41 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_big_01(t_pslist *all)
{
	all->ct.i = -1;
	while (++all->ct.i < 30 || all->nbrs.nbr_in_a >= 0)
	{
		while (!(all->stack_a[0] >= all->less_15_nbr)
				|| !(all->stack_a[0] <= all->plus_15_nbr))
		{
			ft_ra(all, 1);
			ft_print_stack(all);
		}
		
		if ((all->stack_a[0] >= all->less_15_nbr)
				|| (all->stack_a[0] <= all->plus_15_nbr))
		{
			ft_pb(all);
			ft_print_stack(all);
			if (all->stack_b[0] < all->center_nbr)
			{
				ft_printf("T\n");
				ft_rb(all, 1);
				ft_print_stack(all);
			}
		}
		if (all->nbrs.nbr_entry - all->nbrs.nbr_in_a > all->diff)
			break ;
		// ft_printf("T\n");
	}
	rec_b01(all);
	// ft_printf("EXIT------------------------------\n");
	// ft_printf("center_i: %d\nplus15_i: %d\nless15_i: %d\n",all->center_i, all->plus_15_i, all->less_15_i);
	// ft_printf("center_nbr: %d\nplus15_nbr: %d\nless15_nbr: %d\n", all->center_nbr, all->plus_15_nbr, all->less_15_nbr);
}

void	rec_b01(t_pslist *all)
{
	if (all->nbrs.nbr_in_a >= 15)
	{
		all->plus_15_i += 15;
		all->less_15_i -= 15;
		all->plus_15_nbr = all->save_moy[all->plus_15_i];
		all->less_15_nbr = all->save_moy[all->less_15_i];
		all->diff = all->plus_15_i - all->less_15_i;
	}
	else
	{
		all->plus_15_i = all->nbrs.nbr_entry - 1;
		all->less_15_i = 0;
		all->plus_15_nbr = all->save_moy[all->plus_15_i];
		all->less_15_nbr = all->save_moy[all->less_15_i];
		all->diff = all->plus_15_i - all->less_15_i;
	}
	if (all->nbrs.nbr_in_a)
		ft_big_01(all);
}

// void	ft_big_02(t_pslist *all)
// {
	
// }
