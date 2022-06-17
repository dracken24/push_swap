/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::     ::::::::   */
/*   push_swap.c                                        :+:+:    :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:59:35 by nadesjar          #+#    #+#             */
/*   Updated: 2022/04/29 22:59:35 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int	main(int nb_arg, char **entry)
{
	t_pslist	all;

	ft_init_variables(&all);
	ft_check_all(nb_arg, entry, &all);
	if (all.ct == 0)
		return (0);
	all.ct = ft_run_prog(&all);
	if (all.ct == true)
	{
		free(all.stack_a);
		free(all.stack_b);
		free(all.save_moy);
		return (true);
	}
	ft_printf("\nFINALE---------------------------------------------------->>\n");
	ft_print_stack(&all);

	free(all.stack_a);
	free(all.stack_b);
	free(all.save_moy);
	return (0);
}

int	ft_run_prog(t_pslist *all)
{
	ft_find_moy(all);
	all->ct = ft_check_order(all);
	if (all->ct == 1)
		return (false);
	if (all->nbr_entry <= 5)
		ft_less_five(all);
	else
	{
		ft_tob1(all);
		ft_first_class(all);
		ft_tob2(all);
		ft_second_class(all);
	}
	return (false);
}

void	ft_init_variables(t_pslist *all)
{
	all->i =			0;
	all->k =			0;
	all->x =			0;
	all->len =			0;
	all->ct =			-1;
	all->nbr_entry =	0;
	all->temp =			0;
	all->total_count =	0;
	all->nbr =			0;
	all->temp =			0;
	all->s_qrt =		0;
	all->s_moy =		0;
	all->s_3_qrt =		0;
	all->ii =			0;
	all->kk =			0;
	all->test =			0;
	all->nbr_in_b =		0;
}

