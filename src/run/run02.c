/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:28:36 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/11 17:38:52 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

int	ft_check_order_2(t_pslist *all)
{
	int	i;

	i = -1;
	while (++i < all->nbrs.nbr_in_a)
	{
		if (all->s_a[i] != all->save_moy[i])
			return (false);
	}
	return (true);
}

void	ft_less_five(t_pslist *all)
{
	if (ft_check_order_2(all))
	{
		quit(all);
		exit(0);
	}
	if (all->nbrs.nbr_entry <= 3)
		less_tree(all);
	else
		ft_lfive(all);
}

void	ft_lfive(t_pslist *all)
{
	if (all->nbrs.nbr_entry == 4)
		all->center_nbr = all->save_moy[1];
	else
		all->center_nbr = all->save_moy[2];
	while (all->nbrs.nbr_in_a > 3)
	{
		if (all->s_a[0] < all->center_nbr)
			ft_pb(all);
		else
			ft_ra(all, 1);
	}
	less_tree(all);
	if (all->nbrs.nbr_entry == 5)
		end_lfive(all);
	else if (all->nbrs.nbr_entry == 4)
		ft_pa(all);
}

void	end_lfive(t_pslist *all)
{
	if (all->s_b[0] > all->s_b[1])
	{
		ft_pa(all);
		ft_pa(all);
	}
	else
	{
		ft_sb(all, 1);
		ft_pa(all);
		ft_pa(all);
	}
}

void	less_tree(t_pslist *all)
{
	while (!ft_check_order(all))
	{
		if (all->s_a[0] > all->s_a[1]
			&& all->s_a[0] > all->s_a[2])
		{
			ft_ra(all, 1);
			if (all->s_a[0] > all->s_a[1])
				ft_sa(all, 1);
		}
		else if (all->s_a[0] < all->s_a[1]
			&& all->s_a[0] > all->s_a[2])
		{
			ft_rra(all, 1);
			if (all->s_a[0] > all->s_a[1])
				ft_sa(all, 1);
		}
		else if (all->s_a[0] < all->s_a[1] && all->s_a[0] < all->s_a[2])
		{
			ft_rra(all, 1);
			if (all->s_a[0] > all->s_a[1])
				ft_sa(all, 1);
		}
		else if (all->s_a[0] > all->s_a[1] && all->s_a[0] < all->s_a[2])
			ft_sa(all, 1);
	}
}
