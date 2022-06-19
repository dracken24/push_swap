/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_run_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:11:58 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/19 13:24:36 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void ft_med_01(t_pslist *all)
{
	if (all->nbrs.nbr_in_a < 31)
	{
		while (all->nbrs.nbr_in_a)
		{
			ft_pb(all);
			if (all->stack_b[0] <= all->center_nbr && all->nbrs.nbr_in_b > 1)
				ft_rb(all, 1);
		}
	}
	else
		more_31_med(all);
	all->ct.ct2 = (all->nbrs.nbr_in_b - 1);
	all->ct.kk = all->ct.ct2;
	rec_m01(all);
}

void more_31_med(t_pslist *all)
{
	while (all->nbrs.nbr_in_a >= 31)
	{
		while (!(all->stack_a[0] >= all->less_15_nbr) || !(all->stack_a[0] <= all->plus_15_nbr))
			ft_ra(all, 1);

		if ((all->stack_a[0] >= all->less_15_nbr) || (all->stack_a[0] <= all->plus_15_nbr))
		{
			ft_pb(all);
			if (all->stack_b[0] < all->center_nbr && all->nbrs.nbr_in_b > 1)
				ft_rb(all, 1);
		}
		if (all->nbrs.nbr_in_a > 31)
			if (all->nbrs.nbr_entry - all->nbrs.nbr_in_a > all->diff)
				break;
	}
}

void rec_m01(t_pslist *all)
{
	all->plus_15_i += 15;
	all->less_15_i -= 15;
	all->plus_15_nbr = all->save_moy[all->plus_15_i];
	all->less_15_nbr = all->save_moy[all->less_15_i];
	all->diff = all->plus_15_i - all->less_15_i;

	if (all->nbrs.nbr_in_a)
		ft_med_01(all);
}




void ft_med_02(t_pslist *all)
{
	all->to_find1 = all->save_moy[all->nbrs.nbr_in_b - 1];
	all->to_find2 = all->save_moy[all->nbrs.nbr_in_b - 2];
	if (all->stack_b)
	{
		if (all->stack_b)
		{
			m02_part1(all);
			m02_part2(all);
		}
		if (all->stack_a[0] > all->stack_a[1] && all->nbrs.nbr_in_a > 1)
			ft_sa(all, 1);
	}
	if (all->nbrs.nbr_in_b)
		ft_med_02(all);
}

void m02_part1(t_pslist *all)
{
	while (all->stack_b)
	{
		if (all->stack_b[0] == all->to_find2)
		{
			ft_pa(all);
			all->ct.x += 1;
		}
		if (all->stack_b[0] == all->to_find1)
		{
			ft_pa(all);
			all->ct.x += 1;
			break;
		}
		if (ft_wside2(all, all->to_find1) == 1)
			ft_rb(all, 1);
		else
			ft_rrb(all, 1);
	}
}

void m02_part2(t_pslist *all)
{
	while (all->stack_b && all->ct.x < 2)
	{
		if (all->stack_b[0] == all->to_find1)
		{
			ft_pa(all);
			all->ct.x += 1;
		}
		if (all->stack_b[0] == all->to_find2)
		{
			ft_pa(all);
			break;
		}
		if (ft_wside2(all, all->to_find2) == 1)
			ft_rb(all, 1);
		else
			ft_rrb(all, 1);
	}
}
