/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_this.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:54:33 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/28 15:58:24 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

int	split_suite(t_pslist *all, char **entry, char **tmp2, int nb_arg)
{
	int	k;

	k = 0;
	if (!all->tmp && !tmp2)
	{
		free(all->tmp);
		free(tmp2);
		return (false);
	}
	if (nb_arg == 2)
	{
		all->tmp = ft_split(entry[1], ' ');
		tmp2[0] = entry[0];
		k = -1;
		while (all->tmp[++k])
			tmp2[k + 1] = all->tmp[k];
		all->ct.ct = check_entry(++k, tmp2, all);
		if (all->ct.ct == 0)
			return (false);
		else if (all->ct.ct == -1)
			return (false);
		save_nbr(k, tmp2, all);
	}
	return (true);
}

int	split_this(int nb_arg, char **entry, t_pslist *all)
{
	char	**tmp2;

	all->tmp = ft_calloc(sizeof(all->tmp), ft_strlen(entry[1]) + 1);
	tmp2 = ft_calloc(sizeof(tmp2), ft_strlen(entry[1]) + 1);
	if (split_suite(all, entry, tmp2, nb_arg) == 1)
		split_suite(all, entry, tmp2, nb_arg);
	else
	{
		free(all->tmp);
		free(tmp2);
		return (false);
	}
	free(tmp2);
	free(all->tmp);
	return (true);
}
