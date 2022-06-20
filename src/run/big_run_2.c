/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_run_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:22:23 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/20 12:56:51 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

void	ft_big_02(t_pslist *all)
{
	all->to_find1 = all->save_moy[all->nbrs.nbr_in_b - 1];
	all->to_find2 = all->save_moy[all->nbrs.nbr_in_b - 2];
	if (all->s_b)
	{
		if (all->s_b)
		{
			b02_part1(all);
			b02_part2(all);
		}
		if (all->s_a[0] > all->s_a[1] && all->nbrs.nbr_in_a > 1)
			ft_sa(all, 1);
	}
	if (all->nbrs.nbr_in_b)
		ft_big_02(all);
}

void	b02_part1(t_pslist *all)
{
	while (all->s_b)
	{
		if (all->s_b[0] == all->to_find2)
		{
			ft_pa(all);
			all->ct.x += 1;
		}
		if (all->s_b[0] == all->to_find1)
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
}

void	b02_part2(t_pslist *all)
{
	while (all->s_b && all->ct.x < 2)
	{
		if (all->s_b[0] == all->to_find1)
		{
			ft_pa(all);
			all->ct.x += 1;
		}
		if (all->s_b[0] == all->to_find2)
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
