/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:38 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/19 14:56:24 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_sa(t_pslist *all, int ct)
// sa intervertit les 2 premiers éléments au sommet de la pile a
{
	if ((all->stack_a[0] || all->stack_a[1]) == '\0')
		return ;
	all->temp = all->stack_a[0];
	all->stack_a[0] = all->stack_a[1];
	all->stack_a[1] = all->temp;
	if (ct == 1)
	{
		all->total_count += 1;
		ft_printf("sa\n");
	}
}

void	ft_sb(t_pslist *all, int ct)
// sb intervertit les 2 premiers éléments au sommet de la pile b
{
	if ((all->stack_b[0] || all->stack_b[1]) == '\0')
		return ;
	all->temp = all->stack_b[0];
	all->stack_b[0] = all->stack_b[1];
	all->stack_b[1] = all->temp;
	all->total_count += 1;
	if (ct == 1)
	{
		all->total_count += 1;
		ft_printf("sb\n");
	}
}

void	ft_ss(t_pslist *all, int ct)
// fait sa et ss
{
	ft_sa(all, ct);
	ft_sb(all, ct);
	all->total_count += 1;
	ft_printf("ss\n");
}

void	ft_ra(t_pslist *all, int ct)
// ra décale d’une position vers le haut tous les élements de la pile a
{
	all->ct.i = 1;
	if (!all->stack_a)
		return;
	all->temp = all->stack_a[0];
	while (all->ct.i < all->nbrs.nbr_in_a - 1)
	{
		all->stack_a[all->ct.i - 1] = all->stack_a[all->ct.i];
		all->ct.i++;
	}
	all->stack_a[all->ct.i - 1] = all->stack_a[all->ct.i];
	all->stack_a[all->ct.i] = all->temp;
	if (ct == 1)
	{
		all->total_count += 1;
		ft_printf("ra\n");
	}
}

void	ft_rb(t_pslist *all, int ct)
// rb décale d’une position vers le haut tous les élements de la pile b
{
	all->ct.i = 1;
	if (!all->stack_b)
		return;
	all->temp = all->stack_b[0];
	while (all->ct.i < all->nbrs.nbr_in_b - 1)
	{
		all->stack_b[all->ct.i - 1] = all->stack_b[all->ct.i];
		all->ct.i++;
	}
	all->stack_b[all->ct.i - 1] = all->stack_b[all->ct.i];
	all->stack_b[all->ct.i] = all->temp;
	if (ct == 1)
	{
		all->total_count += 1;
		ft_printf("rb\n");
	}
}
