/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:57:04 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/18 16:32:48 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_big_01(t_pslist *all)
{
	if (all->nbrs.nbr_in_a < 31)
	{
		while (all->nbrs.nbr_in_a)
		{
			ft_pb(all);
			ft_print_stack(all);
			if (all->stack_b[0] <= all->center_nbr && all->nbrs.nbr_in_b > 1)
			{
				ft_rb(all, 1);
				ft_print_stack(all);
			}
		}
	}
	else
	{
		while (all->nbrs.nbr_in_a >= 31)
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
				if (all->stack_b[0] < all->center_nbr && all->nbrs.nbr_in_b > 1)
				{
					ft_rb(all, 1);
					ft_print_stack(all);
				}
			}
			if (all->nbrs.nbr_in_a > 31)
				if (all->nbrs.nbr_entry - all->nbrs.nbr_in_a > all->diff)
					break ;
		}
	}
	all->ct.ct2 = (all->nbrs.nbr_in_b - 1);
	all->ct.kk = all->ct.ct2;
	rec_b01(all);
	ft_print_stack(all);
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




void	ft_big_02(t_pslist *all)
{
	all->to_find1 = all->save_moy[all->nbrs.nbr_in_b - 1];
	all->to_find2 = all->save_moy[all->nbrs.nbr_in_b - 2];
	if (all->stack_b)
	{
		if (all->stack_b)
		{
			all->ct.x = 0;
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
					break ;
				}
				if (ft_wside2(all, all->to_find1) == 1)
					ft_rb(all, 1);
				else
					ft_rrb(all, 1);

			}
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
					break ;
				}
				if (ft_wside2(all, all->to_find2) == 1)
					ft_rb(all, 1);
				else
					ft_rrb(all, 1);
			}
		}
		if (all->stack_a[0] > all->stack_a[1] && all->nbrs.nbr_in_a > 1)
			ft_sa(all, 1);
	}
		if (all->nbrs.nbr_in_b)
			ft_big_02(all);
}

bool    ft_wside2(t_pslist *all, int to_find)
{
	int	i;
	int	k;

	all->ct.i = all->nbrs.nbr_in_b - 1;
	i = -1;
	k = -1;
	while (to_find != all->stack_b[--all->ct.i])
	{
		if (all->ct.i < 0)
			break ;
		++i;
	}
	all->ct.k = -1;
	while (to_find != all->stack_b[++all->ct.k])
	{
		if (all->ct.k > all->nbrs.nbr_in_b)
			break ;
		++k;
	}
	if (i > k)
		return (true);
	else
		return (false);	
}
