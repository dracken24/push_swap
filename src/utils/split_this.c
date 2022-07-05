/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_this.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:54:33 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/05 16:15:33 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

char	*ft_strjoin_2(char const *s1, char const *s2, char const *s3)
{
	int		l;
	int		l2;
	int		l3;
	int		ct;
	char	*str;

	l2 = ft_strlen(s1);
	l3 = ft_strlen(s1) + ft_strlen(s2);
	l = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (!s1 || !s2 || !s3 || l <= 0)
		return (NULL);
	str = ft_calloc(l + 1, sizeof(char));
	if (!str)
		return (NULL);
	ct = -1;
	while (++ct < l)
	{
		if (ct < l2)
			str[ct] = s1[ct];
		else if (ct < l3)
			str[ct] = s2[ct - l2];
		else
			str[ct] = s3[ct - l3];
	}
	str[l] = '\0';
	return (str);
}

int	split_this(int nb_arg, char **entry, t_pslist *all)
{
	int		k;
	char	*str;

	if (nb_arg == 2)
	{
		str = ft_strjoin_2(entry[0], " ", entry[1]);
		all->tmp = ft_split(str, ' ');
		free(str);
		k = 0;
		while (all->tmp[k])
			k++;
		all->ct.ct = check_entry(k, all->tmp, all);
		if (all->ct.ct == 0)
			return (false);
		else if (all->ct.ct == -1)
			return (false);
		save_nbr(k, all->tmp, all);
		free(all->tmp);
	}
	else
		return (false);
	return (true);
}
