/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_this.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:54:33 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/06 13:33:30 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/push_swap.h"

char	*ft_strjoin_2(t_pslist *all, char const *s1,
		char const *s2, char const *s3)
{
	int		ct;
	char	*str;

	all->ct.l2 = ft_strlen(s1);
	all->ct.l3 = ft_strlen(s1) + ft_strlen(s2);
	all->ct.l = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (!s1 || !s2 || !s3 || all->ct.l <= 0)
		return (NULL);
	str = ft_calloc(all->ct.l + 1, sizeof(char));
	if (!str)
		return (NULL);
	ct = -1;
	while (++ct < all->ct.l)
	{
		if (ct < all->ct.l2)
			str[ct] = s1[ct];
		else if (ct < all->ct.l3)
			str[ct] = s2[ct - all->ct.l2];
		else
			str[ct] = s3[ct - all->ct.l3];
	}
	str[all->ct.l] = '\0';
	return (str);
}

int	split_this(int nb_arg, char **entry, t_pslist *all)
{
	int		k;
	char	*str;

	if (nb_arg == 2)
	{
		str = ft_strjoin_2(all, entry[0], " ", entry[1]);
		all->tmp = ft_split(str, ' ');
		free(str);
		k = 0;
		while (all->tmp[k])
			k++;
		all->ct.ct = check_entry(k, all->tmp, all);
		if (all->ct.ct == 0 || all->ct.ct == -1)
		{
			free_ptr(all->tmp);
			return (false);
		}
		save_nbr(k, all->tmp, all);
		free_ptr(all->tmp);
	}
	else
		return (false);
	return (true);
}
