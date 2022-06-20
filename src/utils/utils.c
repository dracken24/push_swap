/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:16:49 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/20 12:55:45 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

int	ft_find_moy(t_pslist *all)
{
	all->save_moy = ft_calloc(sizeof(int), all->nbrs.nbr_entry + 1);
	if (!all->save_moy)
	{
		free(all->save_moy);
		return (0);
	}
	all->ct.i = -1;
	while (++all->ct.i < all->nbrs.nbr_in_a)
		all->save_moy[all->ct.i] = all->s_a[all->ct.i];
	all->ct.i = -1;
	while (++all->ct.i < all->nbrs.nbr_in_a)
	{
		all->ct.k = all->ct.i;
		while (++all->ct.k < all->nbrs.nbr_entry)
			if (all->save_moy[all->ct.i] > all->save_moy[all->ct.k])
				ft_swap(&all->save_moy[all->ct.i], &all->save_moy[all->ct.k]);
	}
	all->save_moy[all->ct.i] = '\0';
	all->nbrs.s_moy = all->save_moy[all->nbrs.nbr_entry / 2];
	return (0);
}

void	ft_print_stack(t_pslist *all)
{
	int	i;

	i = -1;
	printf("\033[0;32mSTACK A  \033[0;37m");
	while (++i < all->nbrs.nbr_in_a)
		printf("[\033[0;36m%03d\033[0;37m]", all->s_a[i]);
	printf("\n");
	i = -1;
	printf("\033[0;33mSTACK B  \033[0;37m");
	while (++i < all->nbrs.nbr_in_b)
		printf("[\033[0;36m%03d\033[0;37m]", all->s_b[i]);
	printf("\n");
	ft_printf("COUNT: %d\n", all->total_count);
}

bool	ft_wside2(t_pslist *all, int to_find)
{
	int	i;
	int	k;

	all->ct.i = all->nbrs.nbr_in_b - 1;
	i = -1;
	k = -1;
	while (to_find != all->s_b[--all->ct.i])
	{
		if (all->ct.i < 0)
			break ;
		++i;
	}
	all->ct.k = -1;
	while (to_find != all->s_b[++all->ct.k])
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

void	ft_rrr(t_pslist *all)
{
	ft_rra(all, 0);
	ft_rrb(all, 0);
	all->total_count += 1;
	ft_printf("rrr\n");
}
