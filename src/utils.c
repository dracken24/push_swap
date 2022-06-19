/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:16:49 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/19 13:07:24 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int ft_find_moy(t_pslist *all)
{
	all->save_moy = ft_calloc(sizeof(int), all->nbrs.nbr_entry + 1);
	if (!all->save_moy)
	{
		free(all->save_moy);
		return (0);
	}
	all->ct.i = -1;
	while (++all->ct.i < all->nbrs.nbr_in_a)
		all->save_moy[all->ct.i] = all->stack_a[all->ct.i];
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

void    ft_print_stack(t_pslist *all)
{
	int i;

	i = -1;
	printf("\033[0;32mSTACK A  \033[0;37m");
	while (++i < all->nbrs.nbr_in_a)
		printf("[\033[0;36m%03d\033[0;37m]", all->stack_a[i]);
	printf("\n");
	i = -1;
	printf("\033[0;33mSTACK B  \033[0;37m");
	while (++i < all->nbrs.nbr_in_b)
		printf("[\033[0;36m%03d\033[0;37m]", all->stack_b[i]);
	printf("\n");
	ft_printf("COUNT: %d\n", all->total_count);
}

bool    ft_wside2(t_pslist *all, int to_find)
{
	int	i;
	int	k;

	all->ct.i = all->nbrs.nbr_in_b - 1;
	i = -1;
	k = -1;
	while (to_find != all->stack_b[--all->ct.i])
	{
		if (all->ct.i < 0)
			break ;
		++i;
	}
	all->ct.k = -1;
	while (to_find != all->stack_b[++all->ct.k])
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

void	choose_to_find(t_pslist *all, int find1, int find2)
{
	int	i;
	int	k;
	// ft_printf("HELP\n");
	i = 0;
	while (all->save_moy[i] != find1 || i < all->nbrs.nbr_in_b)
		i++;
	// ft_printf("HELP1\n");
	k = all->nbrs.nbr_in_b - 1;
	while (all->save_moy[k] != find1 && k >= 0)
		k--;
	// ft_printf("HELP2\n");
	if (i < k)
		all->ct.find1 = i;
	// ft_printf("HELP3\n");
	if (i > k)
		all->ct.find1 = k;
	// ft_printf("HELP4\n");
	i = 0;
	while (all->save_moy[i] != find2 || i < all->nbrs.nbr_in_b)
		i++;
	// ft_printf("HELP5\n");
	k = all->nbrs.nbr_in_b - 1;
	while (all->save_moy[k] != find2 && k >= 0)
		k--;
	// ft_printf("HELP6\n");
	if (i < k)
		all->ct.find2 = i;
	// ft_printf("HELP7\n");
	if (i > k)
		all->ct.find2 = k;
	// ft_printf("HELP8\n");
}
