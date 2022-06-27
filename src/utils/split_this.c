/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_this.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:54:33 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/27 17:38:16 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

int	split_this(int nb_arg, char **entry, t_pslist *all)
{
	char	**tmp;
	int i = -1;

	// ft_printf("TEST\n");
	tmp = ft_calloc(sizeof(char), ft_strlen(entry[1]) + 1);
	if (!tmp)
	{
		free(tmp);
		return (false);
	}
	if (nb_arg == 2)
	{
		tmp = ft_split(entry[1], ' ');
		
		while (tmp[++i])
		{
			ft_printf("%s\n", tmp[i]);
		}
		all->ct.ct = check_entry(nb_arg, tmp, all);
		// if (all->ct.ct == 0)
		// 	return (false);
		// else if (all->ct.ct == -1)
		// 	return (false);
	}
	else
	{
		free(tmp);
		return (false);
	}
	free(tmp);
	return (true);
}
