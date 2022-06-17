/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:46:06 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/01 18:46:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int	ft_check_all(int nb_arg, char **entry, t_pslist *all)
{
	if (nb_arg > 1)
	{
		all->ct = check_entry(nb_arg, entry, all);
		if (all->ct == 0)
			return (false);
		else if (all->ct == -1)
			return (false);
	}
	all->ct = save_nbr(nb_arg, entry, all);
	if (all->ct == 0)
	{
		free(all->stack_a);
		return (false);
	}
	return (true);
}

int	check_entry(int nb_arg, char **entry, t_pslist *all)
{
    all->i = 0;
    while (++all->i < nb_arg)
    {
        all->k = -1;
        while (entry[all->i][++all->k])
		{
            if ((entry[all->i][all->k] < '0' || entry[all->i][all->k] > '9')
					&& (entry[all->i][all->k] != '-'))
                return (false);
			if (entry[all->i][0] == '-' && entry[all->i][1] == '\0')
				return (false);
		}
	}
    all->i = check_doub(nb_arg, entry, all);
    return (all->i);
}

int	check_doub(int nb_arg, char **entry, t_pslist *all)
{
	all->i = 0;
	while (++all->i < nb_arg - 1)
	{
		all->k = all->i;
		while (++all->k < nb_arg)
			if ((!ft_strncmp(entry[all->i], entry[all->k], ft_strlen(entry[all->i]))
					&& !ft_strncmp(entry[all->k], entry[all->i],
						ft_strlen(entry[all->k]))) != 0)
				return (false);
	}
	return (true);
}

int	ft_check_order(t_pslist *all)
{
	all->i = 0;
	if (all->nbr_entry == 1)
		return(true);
	else if (all->nbr_entry == 2)
	{
		if (all->stack_a[0] > all->stack_a[1])
			ft_ra(all, 1);
		return (true);
	}
	while (all->i < all->nbr_entry)
	{
		if (all->stack_a[all->i] != all->save_moy[all->i])
			return(false);
		all->i++;
	}
	return (true);
}

