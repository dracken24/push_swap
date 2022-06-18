/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:57:04 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/18 14:55:56 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_big_01(t_pslist *all)
{
	// all->ct.i = -1;
	while (all->nbrs.nbr_in_a > 0)
	{
		while (!(all->stack_a[0] >= all->less_15_nbr)
				|| !(all->stack_a[0] <= all->plus_15_nbr))
		{
			ft_ra(all, 1);
			ft_print_stack(all);
			ft_printf("HELP_R\n");
		}
		
		if ((all->stack_a[0] >= all->less_15_nbr)
				|| (all->stack_a[0] <= all->plus_15_nbr))
		{
			ft_pb(all);
			ft_print_stack(all);
			if (all->stack_b[0] < all->center_nbr && all->nbrs.nbr_in_b < 1)
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
	ft_print_stack(all);
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
	all->to_find1 = all->save_moy[all->nbrs.nbr_in_b - 1];
	all->to_find2 = all->save_moy[all->nbrs.nbr_in_b - 2];
	ft_printf("TO_FIND: %d\n", all->nbrs.nbr_in_b);
	if (all->stack_b)
	{
		// ft_printf("HELP_1\n");
		if (all->stack_b)
		{
			// ft_printf("HELP_2\n");
			while (all->stack_b)
			{
				if (all->stack_b[0] == all->to_find2)
				{
					ft_pa(all);
					break ;
					// ft_printf("HELP_2.1\n");
				}
				if (all->stack_b[0] == all->to_find1)
				{
					ft_pa(all);
					break ;
				}
				if (ft_wside2(all, all->to_find1) == 1)
				{
					ft_rb(all, 1);
					// ft_print_stack(all);
					// ft_printf("HELP_2.a2\n");
				}
				else
				{
					ft_rrb(all, 1);
					// ft_print_stack(all);
					ft_printf("HELP_2.aa2\n");
				}

				// ft_printf("HELP_2.A\n");
			}
			// ft_printf("HELP_3\n");
			
			while (all->stack_b)
			{
				if (all->stack_b[0] == all->to_find1)
				{
					ft_pa(all);
					break ;
					// ft_printf("HELP_3.1\n");
				}
				if (all->stack_b[0] == all->to_find2)
				{
					ft_pa(all);
					break ;
				}
				if (ft_wside2(all, all->to_find2) == 1)
				{
					ft_rb(all, 1);
					// ft_print_stack(all);
					// ft_printf("HELP_2.b2\n");
				}
				else
				{
					ft_rrb(all, 1);
					// ft_print_stack(all);
					// ft_printf("HELP_2.bb2\n");
				}
				// ft_printf("HELP_2.B\n");
			}
			// ft_pa(all);
			// while (!(all->stack_b[0] == all->to_find2))
			// {
			// 	if (ft_wside2(all, all->to_find2) == 1)
			// 		break;
			// 	else
			// 	{
			// 		ft_rrb(all, 1);
			// 		ft_print_stack(all);
			// 	}
			// 	// ft_printf("HELP_2.C\n");
			// }
			// while (!(all->stack_b[0] == all->to_find2))
			// {
			// 	if (ft_wside2(all, all->to_find2) == 0)
			// 		break;
			// 	else
			// 	{
			// 		ft_rb(all, 1);
			// 		ft_print_stack(all);
			// 	}
			// 	ft_printf("HELP_2.D\n");
			// }
			// ft_pa(all);
			ft_printf("HELP_4\n");
		}
		if (all->stack_a[0] > all->stack_a[1] && all->nbrs.nbr_in_a > 1)
			ft_sa(all, 1);
	}
		if (all->nbrs.nbr_in_b > 0)
			ft_big_02(all);
}

bool    ft_wside2(t_pslist *all, int to_find)
{
	int	i;
	int	k;

	all->ct.i = all->nbrs.nbr_in_b - 1;
	i = -1;
	k = -1;
	// if (all->stack_b[0] == to_find)
	// 	return (2);
	while (to_find != all->stack_b[--all->ct.i])
	{
		if (all->ct.i < 0)
			break ;
		++i;
		// ft_printf("HELP_W1: %d\n", all->ct.i);
	}
	all->ct.k = -1;
	while (to_find != all->stack_b[++all->ct.k])
	{
		if (all->ct.k > all->nbrs.nbr_in_b)
			break ;
		++k;
		// ft_printf("HELP_W2: %d\n", all->ct.k);
	}
	if (i > k)
		return (true);
	else
		return (false);	
}
