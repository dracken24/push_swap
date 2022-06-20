/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:56:20 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/20 12:55:54 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

bool	ft_pa(t_pslist *all)
// pa prend le premier élément au sommet de b et le met sur a
{
	all->ct.i = -1;
	all->ct.k = 0;
	all->nbr = ft_calloc(sizeof(int), all->nbrs.nbr_in_a + 2);
	if (!all->nbr)
		return (false);
	if (all->nbrs.nbr_in_b < 1)
		return (true);
	all->nbr[0] = all->s_b[0];
	while (++all->ct.i < all->nbrs.nbr_in_a)
		all->nbr[++all->ct.k] = all->s_a[all->ct.i];
	all->nbr[++all->ct.k] = all->s_a[all->ct.i];
	all->nbr[all->ct.k] = '\0';
	free(all->s_a);
	all->s_a = ft_calloc(sizeof(int), all->nbrs.nbr_in_a + 2);
	if (!all->s_a)
		return (false);
	all->ct.i = -1;
	while (++all->ct.i <= all->nbrs.nbr_in_a)
		all->s_a[all->ct.i] = all->nbr[all->ct.i];
	all->s_a[all->ct.i] = '\0';
	free(all->nbr);
	ft_pa2(all);
	return (true);
}

bool	ft_pa2(t_pslist *all)
{
	all->ct.i = 0;
	all->ct.k = -1;
	all->nbr = ft_calloc(sizeof(int), all->nbrs.nbr_in_b);
	if (!all->nbr)
		return (false);
	while (++all->ct.i < all->nbrs.nbr_in_b)
		all->nbr[++all->ct.k] = all->s_b[all->ct.i];
	all->nbr[++all->ct.k] = all->s_b[all->ct.i];
	all->nbr[all->ct.k] = '\0';
	free(all->s_b);
	all->ct.i = -1;
	all->s_b = ft_calloc(sizeof(int), all->nbrs.nbr_in_b + 1);
	if (!all->s_b)
		return (false);
	while (++all->ct.i < all->nbrs.nbr_in_b)
		all->s_b[all->ct.i] = all->nbr[all->ct.i];
	all->s_b[all->ct.i] = '\0';
	all->total_count += 1;
	all->nbrs.nbr_in_a += 1;
	all->nbrs.nbr_in_b -= 1;
	ft_printf("pa\n");
	free(all->nbr);
	return (true);
}

bool	ft_pb(t_pslist *all)
// pb prend le premier élément au sommet de a et le met sur b
{
	all->ct.i = -1;
	all->ct.k = 0;
	all->nbr = ft_calloc(sizeof(int), all->nbrs.nbr_in_b + 2);
	if (!all->nbr)
		return (false);
	if (all->nbrs.nbr_in_a < 1)
		return (true);
	all->nbr[0] = all->s_a[0];
	while (++all->ct.i < all->nbrs.nbr_in_b)
		all->nbr[++all->ct.k] = all->s_b[all->ct.i];
	all->nbr[++all->ct.k] = all->s_b[all->ct.i];
	all->nbr[all->ct.k] = '\0';
	free(all->s_b);
	all->s_b = ft_calloc(sizeof(int), all->nbrs.nbr_in_b + 2);
	if (!all->s_b)
		return (false);
	all->ct.i = -1;
	while (++all->ct.i <= all->nbrs.nbr_in_b)
		all->s_b[all->ct.i] = all->nbr[all->ct.i];
	all->s_b[all->ct.i] = '\0';
	free(all->nbr);
	ft_pb2(all);
	return (true);
}

bool	ft_pb2(t_pslist *all)
{
	all->ct.i = 0;
	all->ct.k = -1;
	all->nbr = ft_calloc(sizeof(int), all->nbrs.nbr_in_a);
	while (++all->ct.i < all->nbrs.nbr_in_a)
		all->nbr[++all->ct.k] = all->s_a[all->ct.i];
	all->nbr[++all->ct.k] = all->s_a[all->ct.i];
	all->nbr[all->ct.k] = '\0';
	free(all->s_a);
	all->ct.i = -1;
	all->s_a = ft_calloc(sizeof(int), all->nbrs.nbr_in_a + 1);
	if (!all->s_a)
		return (false);
	while (++all->ct.i < all->nbrs.nbr_in_a)
		all->s_a[all->ct.i] = all->nbr[all->ct.i];
	all->s_a[all->ct.i] = '\0';
	all->total_count += 1;
	all->nbrs.nbr_in_b += 1;
	all->nbrs.nbr_in_a -= 1;
	ft_printf("pb\n");
	free(all->nbr);
	return (true);
}
