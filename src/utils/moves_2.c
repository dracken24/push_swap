/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:28:13 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/20 12:56:23 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

void	ft_rr(t_pslist *all)
// ra et rb en même temps.
{
	ft_ra(all, 0);
	ft_rb(all, 0);
	all->total_count += 1;
	ft_printf("rr\n");
}

void	ft_rra(t_pslist *all, int ct)
// décale d’une position vers le bas tous les élements de la pile a
{
	if (all->nbrs.nbr_in_a < 1)
		return ;
	all->ct.i = -1;
	all->len = all->nbrs.nbr_in_a - 1;
	all->nbr = ft_calloc(sizeof(int), 2);
	if (!all->nbr)
	{
		free(all->nbr);
		return ;
	}
	ft_rra_p2(all);
	free(all->nbr);
	if (ct == 1)
	{
		all->total_count += 1;
		ft_printf("rra\n");
	}
}

void	ft_rra_p2(t_pslist *all)
{
	if (all->s_a)
	{
		all->nbr[0] = all->s_a[all->len];
		all->nbr[1] = '\0';
		while (all->len >= 0)
		{
			all->s_a[all->len] = all->s_a[all->len - 1];
			all->len--;
		}
		all->s_a[0] = all->nbr[0];
	}
}

void	ft_rrb(t_pslist *all, int ct)
// décale d’une position vers le bas tous les élements de la pile b
{
	if (all->nbrs.nbr_in_b < 1)
		return ;
	all->ct.i = -1;
	all->len = all->nbrs.nbr_in_b - 1;
	all->nbr = ft_calloc(sizeof(int), 2);
	if (!all->nbr)
	{
		free(all->nbr);
		return ;
	}
	ft_rrb_p2(all);
	free(all->nbr);
	if (ct == 1)
	{
		all->total_count += 1;
		ft_printf("rrb\n");
	}
}

void	ft_rrb_p2(t_pslist *all)
{
	if (all->s_b)
	{
		all->nbr[0] = all->s_b[all->len];
		all->nbr[1] = '\0';
		while (all->len >= 0)
		{
			all->s_b[all->len] = all->s_b[all->len - 1];
			all->len--;
		}
		all->s_b[0] = all->nbr[0];
	}
}
