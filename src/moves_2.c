/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:28:13 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/01 19:30:49 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_rr(t_pslist *all)
// ra et rb en même temps.
{
	ft_ra(all, 0);
	ft_rb(all, 0);
	all->total_count += 1;
}

void	ft_rra(t_pslist *all, int ct)
// décale d’une position vers le bas tous les élements de la pile a
{
	if (all->nbr_in_a < 1)
		return ;
	all->i = -1;
	all->len = all->nbr_in_a - 1;
	all->nbr = ft_calloc(sizeof(int), 2);
	if (!all->nbr)
	{
		free(all->nbr);
		return ;
	}
	if (all->stack_a)
	{
		all->nbr[0] = all->stack_a[all->len];
		all->nbr[1] = '\0';
		while (all->len >= 0)
		{
			all->stack_a[all->len] = all->stack_a[all->len -1];
			all->len--;
		}
		all->stack_a[0] = all->nbr[0];
		
	}free(all->nbr);
	if (ct == 1)
		all->total_count += 1;
}

void	ft_rrb(t_pslist *all, int ct)
// décale d’une position vers le bas tous les élements de la pile b
{
	if (all->nbr_in_b < 1)
		return ;
	all->i = -1;
	all->len = all->nbr_in_b - 1;
	all->nbr = ft_calloc(sizeof(int), 2);
	if (!all->nbr)
	{
		free(all->nbr);
		return ;
	}
	if (all->stack_b)
	{
		all->nbr[0] = all->stack_b[all->len];
		all->nbr[1] = '\0';
		while (all->len >= 0)
		{
			all->stack_b[all->len] = all->stack_b[all->len - 1];
			all->len--;
		}
		all->stack_b[0] = all->nbr[0];
		free(all->nbr);
	}
	if (ct == 1)
		all->total_count += 1;
}

void	ft_rrr(t_pslist *all)
{
	ft_rra(all, 0);
	ft_rrb(all, 0);
	all->total_count += 1;
}
