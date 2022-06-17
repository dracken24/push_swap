/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:57:04 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/17 13:56:38 by nadesjar         ###   ########.fr       */
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
	all->nbrs.s_moy = all->save_moy[all->nbrs.nbr_entry / 2 ];
	ft_printf("QRT; %d\nMED: %d\n3QRT:%d\n", all->nbrs.s_qrt, all->nbrs.s_moy, all->nbrs.s_3_qrt);
	all->ct.i = -1;
	while (++all->ct.i < all->nbrs.nbr_entry)
		ft_printf("%d ", all->save_moy[all->ct.i]);
	ft_printf("\n");
	return (0);
}


void ft_tob1(t_pslist *all)
{
	
}

