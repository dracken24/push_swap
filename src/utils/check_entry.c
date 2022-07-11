/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:46:06 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/11 17:26:15 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

int	ft_check_all(int nb_arg, char **entry, t_pslist *all)
{
	if (nb_arg > 1)
	{
		if (ft_strchr(entry[1], ' '))
			all->ct.ct = split_this(nb_arg, entry, all);
		else
		{
			all->ct.ct = check_entry(nb_arg, entry, all);
			if (all->ct.ct == 0)
				return (false);
			else if (all->ct.ct == -1)
				return (false);
			all->ct.ct = save_nbr(nb_arg, entry, all);
		}
	}
	if (all->ct.ct == false)
		return (false);
	return (true);
}

int	check_entry(int nb_arg, char **entry, t_pslist *all)
{
	all->ct.i = 0;
	while (++all->ct.i < nb_arg)
	{
		all->ct.k = -1;
		if (entry[all->ct.i][0] == '-')
			all->ct.k += 1;
		if (entry[all->ct.i][1] == '\0' && entry[all->ct.i][0] == '-')
			return (false);
		while (++all->ct.k < (int)ft_strlen(entry[all->ct.i]))
		{
			if (entry[all->ct.i][all->ct.k] < '0'
				|| entry[all->ct.i][all->ct.k] > '9')
				return (false);
			if (all->ct.k > 13)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
		}
	}
	all->ct.i = check_doub(nb_arg, entry, all);
	return (all->ct.i);
}

int	check_doub(int nb_arg, char **entry, t_pslist *all)
{
	all->ct.i = 0;
	while (++all->ct.i < nb_arg - 1)
	{
		all->ct.k = all->ct.i;
		while (++all->ct.k < nb_arg)
			if ((!ft_strncmp(entry[all->ct.i], entry[all->ct.k],
						ft_strlen(entry[all->ct.i]))
					&& !ft_strncmp(entry[all->ct.k], entry[all->ct.i],
						ft_strlen(entry[all->ct.k]))) != 0)
				return (false);
	}
	return (true);
}

int	ft_check_order(t_pslist *all)
{
	all->ct.i = 0;
	all->ct.k = 0;
	if (all->nbrs.nbr_entry == 1)
		return (true);
	if (all->nbrs.nbr_entry == 5)
		all->ct.k = 2;
	if (all->nbrs.nbr_entry == 4)
		all->ct.k = 1;
	else if (all->nbrs.nbr_entry == 2)
	{
		if (all->s_a[0] > all->s_a[1])
			ft_ra(all, 1);
		return (true);
	}
	while (all->ct.i < all->nbrs.nbr_in_a)
	{
		if (all->s_a[all->ct.i] != all->save_moy[all->ct.k])
			return (false);
		all->ct.i++;
		all->ct.k++;
	}
	return (true);
}
