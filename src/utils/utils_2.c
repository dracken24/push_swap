/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:40:28 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/11 17:39:08 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

bool	save_nbr(int nb_arg, char **entry, t_pslist *all)
{
	int	i;
	int	k;

	if (!entry)
		return (false);
	all->s_a = ft_calloc(sizeof(int), nb_arg + 1);
	all->s_b = ft_calloc(sizeof(int), 1);
	if (!(all->s_a && all->s_b))
		return (false);
	all->s_b[0] = '\0';
	i = 0;
	k = 0;
	while (++i < nb_arg)
	{
		save_nbr_p2(all, entry, i, k);
		k++;
	}
	all->nbrs.nbr_entry = (i - 1);
	all->s_a[i] = '\0';
	all->nbrs.nbr_in_a = all->nbrs.nbr_entry;
	return (true);
}

void	save_nbr_p2(t_pslist *all, char **entry, int i, int k)
{
	if (ft_atoi(entry[i]) > INT_MAX || ft_atoi(entry[i]) < INT_MIN)
	{
		free(all->s_a);
		free(all->s_b);
		free(all->tmp);
		write(2, "Error\n", 6);
		exit(0);
	}
	all->s_a[k] = ft_atoi(entry[i]);
}

void	ft_imp(t_pslist *all)
{
	while (all->s_b[0] != all->save_moy[all->nbrs.nbr_entry - 1])
		ft_rb(all, 1);
	ft_pa(all);
}

void	quit(t_pslist *all)
{
	free(all->s_a);
	free(all->s_b);
	free(all->save_moy);
}
