/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:57:04 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/19 15:58:11 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_big_01(t_pslist *all)
{
	if (all->nbrs.nbr_in_a < 65)
	{
		while (all->nbrs.nbr_in_a)
		{
			ft_pb(all);
			if (all->stack_b[0] <= all->center_nbr && all->nbrs.nbr_in_b > 1)
				ft_rb(all, 1);
		}
	}
	else
		more_31(all);
	all->ct.ct2 = (all->nbrs.nbr_in_b - 1);
	all->ct.kk = all->ct.ct2;
	rec_b01(all);
}

void	more_31(t_pslist *all)
{
	while (all->nbrs.nbr_in_a >= 65)
	{
		while (!(all->stack_a[0] >= all->less_15_nbr) || !(all->stack_a[0] <= all->plus_15_nbr))
			ft_ra(all, 1);

		if ((all->stack_a[0] >= all->less_15_nbr) || (all->stack_a[0] <= all->plus_15_nbr))
		{
			ft_pb(all);
			if (all->stack_b[0] < all->center_nbr && all->nbrs.nbr_in_b > 1)
				ft_rb(all, 1);
		}
		if (all->nbrs.nbr_in_a > 65)
			if (all->nbrs.nbr_entry - all->nbrs.nbr_in_a > all->diff)
				break;
	}
}

void	rec_b01(t_pslist *all)
{
	all->plus_15_i += 32;
	all->less_15_i -= 32;
	all->plus_15_nbr = all->save_moy[all->plus_15_i];
	all->less_15_nbr = all->save_moy[all->less_15_i];
	all->diff = all->plus_15_i - all->less_15_i;

	if (all->nbrs.nbr_in_a)
		ft_big_01(all);
}





void	ft_big_02(t_pslist *all)
{
	all->to_find1 = all->save_moy[all->nbrs.nbr_in_b - 1];
	all->to_find2 = all->save_moy[all->nbrs.nbr_in_b - 2];
	if (all->stack_b)
	{
		if (all->stack_b)
		{
			b02_part1(all);
			b02_part2(all);
		}
		if (all->stack_a[0] > all->stack_a[1] && all->nbrs.nbr_in_a > 1)
			ft_sa(all, 1);
	}
	if (all->nbrs.nbr_in_b)
		ft_big_02(all);
}

void	b02_part1(t_pslist *all)
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

void	b02_part2(t_pslist *all)
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
