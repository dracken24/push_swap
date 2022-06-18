/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:57:04 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/17 23:46:14 by nadesjar         ###   ########.fr       */
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
	all->ct.ct2 = (all->nbrs.nbr_in_b - 1);
	all->ct.kk = all->ct.ct2;
	rec_b01(all);
	ft_printf("EXIT------------------------------\n");
	ft_printf("center_i: %d\nplus15_i: %d\nless15_i: %d\n",all->center_i, all->plus_15_i, all->less_15_i);
	ft_printf("center_nbr: %d\nplus15_nbr: %d\nless15_nbr: %d\n", all->center_nbr, all->plus_15_nbr, all->less_15_nbr);
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
	ft_printf("HELP_0\n");
	all->to_find1 = all->save_moy[all->ct.ct2];
	all->to_find2 = all->save_moy[all->ct.ct2 - 1];
	ft_printf("TO_FIND: %d\n", all->nbrs.nbr_in_b);
	while (all->stack_b && all->ct.x < 2)
	{
		ft_printf("HELP_1\n");
		while (all->stack_b[0] != all->to_find1 || all->stack_b[0] != all->to_find2)
		{
			ft_printf("HELP_2\n");
			if (ft_wside2(all, all->to_find1, 1) == 1)
				all->side = 1;
			if (ft_wside2(all, all->to_find1, 1) == 0)
				all->side = 0;
			while (ft_wside2(all, all->to_find1, 2) == 1)
			{
				if (all->stack_b[0] == all->to_find1 || all->side == 1)
					break ;
				ft_rrb(all, 1);
				ft_printf("HELP_2.A\n");
			}
			ft_printf("HELP_2.2\n");
			while (ft_wside2(all, all->to_find1, 1) == 0)
			{
				if (all->stack_b[0] == all->to_find1 || all->side == 1)
					break;
				ft_rb(all, 1);
				ft_printf("HELP_2.B\n");
			}
			ft_pa(all);
			while (ft_wside2(all, all->to_find2, 2) == 1)
			{
				if (all->stack_b[0] == all->to_find2 || all->side == 0)
					break;
				ft_rrb(all, 1);
				ft_printf("HELP_2.C\n");
			}
			while (ft_wside2(all, all->to_find2, 2) == 0)
			{
				if (all->stack_b[0] == all->to_find2 || all->side == 0)
					break;
				ft_rb(all, 1);
				ft_printf("HELP_2.D\n");
			}
			ft_pa(all);
			ft_printf("HELP_3\n");
		}
	}
	all->ct.ct2 -= 2;
	if (all->stack_b)
		ft_big_02(all);
}

bool    ft_wside2(t_pslist *all, int to_find, int nb)
{
	int	i;
	int	k;

	if (nb == 1)
		all->ct.i = all->nbrs.nbr_in_b - 1;
	if (nb == 2)
		all->ct.i = all->nbrs.nbr_in_b - 1;
	all->ct.k = -1;
	i = -1;
	k = -1;
	if (all->stack_a[0] == to_find)
		return (2);
	while (to_find != all->stack_b[--all->ct.i])
	{
		++i;
		ft_printf("HELP_W1: %d\n", all->ct.i);
	}
	while (to_find != all->stack_b[++all->ct.k])
	{
		++k;
		ft_printf("HELP_W2: %d\n", all->ct.k);
	}
	if (i > k)
		return (true);
	else
		return (false);	
}
