/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_run_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:11:58 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/21 16:28:22 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

void	ft_med_01(t_pslist *all)
{
	if (all->nbrs.nbr_in_a < 31)
	{
		while (all->nbrs.nbr_in_a)
		{
			ft_pb(all);
			if (all->s_b[0] <= all->center_nbr && all->nbrs.nbr_in_b > 1)
				ft_rb(all, 1);
		}
	}
	else
		more_31_med(all);
	all->ct.ct2 = (all->nbrs.nbr_in_b - 1);
	all->ct.kk = all->ct.ct2;
	rec_m01(all);
}

void	more_31_med(t_pslist *all)
{
	while (all->nbrs.nbr_in_a >= 31)
	{
		while (!(all->s_a[0] >= all->less_15_nbr)
			|| !(all->s_a[0] <= all->plus_15_nbr))
			ft_ra(all, 1);
		if ((all->s_a[0] >= all->less_15_nbr)
			|| (all->s_a[0] <= all->plus_15_nbr))
		{
			ft_pb(all);
			if (all->s_b[0] < all->center_nbr && all->nbrs.nbr_in_b > 1)
				ft_rb(all, 1);
		}
		if (all->nbrs.nbr_in_a > 31)
			if (all->nbrs.nbr_entry - all->nbrs.nbr_in_a > all->diff)
				break ;
	}
}

void	rec_m01(t_pslist *all)
{
	all->plus_15_i += 15;
	all->less_15_i -= 15;
	all->plus_15_nbr = all->save_moy[all->plus_15_i];
	all->less_15_nbr = all->save_moy[all->less_15_i];
	all->diff = all->plus_15_i - all->less_15_i;
	if (all->nbrs.nbr_in_a)
		ft_med_01(all);
}
