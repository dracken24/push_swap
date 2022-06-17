/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:56:20 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/17 12:30:25 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

bool	save_nbr(int nb_arg, char **entry, t_pslist *all)
{
	int	i;
	int	k;
	
	if (!entry)
		return (false);
	all->stack_a = ft_calloc(sizeof(int), nb_arg + 1);
	all->stack_b = ft_calloc(sizeof(int), 1);
	if (!(all->stack_a && all->stack_b))
		return (false);
	all->stack_b[0] = '\0';
	i = 0;
	k = 0;
	while (++i < nb_arg)
	{
		if (ft_atoi(entry[i]) > INT_MAX || ft_atoi(entry[i]) < INT_MIN)
			exit(ft_printf("Over int limit"));
		all->stack_a[k] = ft_atoi(entry[i]);
		k++;
	}
	all->nbr_entry = (i - 1);
	ft_printf("nbr_entry: %d\n", all->nbr_entry);
	all->stack_a[i] = '\0';
	all->i = -1;
	all->nbr_in_a = all->nbr_entry;
	return (true);
}

bool	ft_pa(t_pslist *all)
// pa prend le premier élément au sommet de b et le met sur a
{
	all->i = -1;
	all->k = 0;
	all->nbr = ft_calloc(sizeof(int), all->nbr_in_a + 2);
	if (!all->nbr)
		return (false);
	if (all->nbr_in_b < 1)
		return (true);
	all->nbr[0] = all->stack_b[0];
	while (++all->i < all->nbr_in_a)
		all->nbr[++all->k] = all->stack_a[all->i];
	all->nbr[++all->k] = all->stack_a[all->i];
	all->nbr[all->k] = '\0';
	free(all->stack_a);
	all->stack_a = ft_calloc(sizeof(int), all->nbr_in_a + 2);
	if (!all->stack_a)
		return (false);
	all->i = -1;
	while (++all->i <= all->nbr_in_a)
		all->stack_a[all->i] = all->nbr[all->i];
	all->stack_a[all->i] = '\0';
	free(all->nbr);
	ft_pa2(all);
	return (true);
}

bool	ft_pa2(t_pslist *all)
{
	all->i = 0;
	all->k = -1;
	all->nbr = ft_calloc(sizeof(int), all->nbr_in_b);
	if (!all->nbr)
		return (false);
	while (++all->i < all->nbr_in_b)
		all->nbr[++all->k] = all->stack_b[all->i];
	all->nbr[++all->k] = all->stack_b[all->i];
	all->nbr[all->k] = '\0';
	free(all->stack_b);
	all->i = -1;
	all->stack_b = ft_calloc(sizeof(int), all->nbr_in_b + 1);
	if (!all->stack_b)
		return (false);
	while (++all->i < all->nbr_in_b)
		all->stack_b[all->i] = all->nbr[all->i];
	all->stack_b[all->i] = '\0';
	all->total_count += 1;
	all->nbr_in_a += 1;
	all->nbr_in_b -= 1;
	free(all->nbr);
	return (true);
}

bool	ft_pb(t_pslist *all)
// pb prend le premier élément au sommet de a et le met sur b
{
	all->i = -1;
	all->k = 0;
	all->nbr = ft_calloc(sizeof(int), all->nbr_in_b + 2);
	if (!all->nbr)
		return (false);
	if (all->nbr_in_a < 1)
		return (true);
	all->nbr[0] = all->stack_a[0];
	while (++all->i < all->nbr_in_b)
		all->nbr[++all->k] = all->stack_b[all->i];
	all->nbr[++all->k] = all->stack_b[all->i];
	all->nbr[all->k] = '\0';
	free(all->stack_b);
	all->stack_b = ft_calloc(sizeof(int), all->nbr_in_b + 2);
	if (!all->stack_b)
		return (false);
	all->i = -1;
	while (++all->i <= all->nbr_in_b)
		all->stack_b[all->i] = all->nbr[all->i];
	all->stack_b[all->i] = '\0';
	free(all->nbr);
	ft_pb2(all);
	return (true);
}

bool	ft_pb2(t_pslist *all)
{
	all->i = 0;
	all->k = -1;
	all->nbr = ft_calloc(sizeof(int), all->nbr_in_a);
	while (++all->i < all->nbr_in_a)
		all->nbr[++all->k] = all->stack_a[all->i];
	all->nbr[++all->k] = all->stack_a[all->i];
	all->nbr[all->k] = '\0';
	free(all->stack_a);
	all->i = -1;
	all->stack_a = ft_calloc(sizeof(int), all->nbr_in_a + 1);
	if (!all->stack_a)
		return (false);
	while (++all->i < all->nbr_in_a)
		all->stack_a[all->i] = all->nbr[all->i];
	all->stack_a[all->i] = '\0';
	all->total_count += 1;
	all->nbr_in_b += 1;
	all->nbr_in_a -= 1;
	free(all->nbr);
	return (true);
}
