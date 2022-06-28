/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_this.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:54:33 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/27 20:28:01 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

void	split_this(int nb_arg, char **entry, t_pslist *all)
{
	char	**tmp;
	char	**tmp2;
	char	*str;
	int i = -1;
	int	k = 0;

	str = entry[0];
	ft_printf("TEST\n");
	tmp = ft_calloc(sizeof(char), ft_strlen(entry[1]) + 1);
	tmp2 = ft_calloc(sizeof(char), ft_strlen(entry[1]) + 1);
	if (!tmp && !tmp2)
	{
		free(tmp);
		free(tmp2);
		return ;
	}
	ft_printf("TEST1\n");
	if (nb_arg == 2)
	{
		tmp = ft_split(entry[1], ' ');

		i = -1;
		while (tmp[++i])
		{
			ft_printf("0: %s\n", tmp[i]);
		}

		tmp2[0] = str;

		k = -1;
		while (++k < i)
		{
			tmp2[k + 1] = tmp[k];
			ft_printf("2: %s\n", tmp2[k + 1]);
		}
		tmp2[++k] = '\0';
		ft_printf("ARG: %d\n", k);
		all->ct.ct = check_entry(k, tmp2, all);
	}
	else
	{
		ft_printf("TEST5\n");
		free(tmp);
		free(tmp2);
		return ;
	}
	free(tmp2);
}
