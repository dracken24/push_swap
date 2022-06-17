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
	if (all.ct.ct == 0)
		return (0);
	all.ct.ct = ft_run_prog(&all);
	if (all.ct.ct == true)
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
	all->ct.ct = ft_check_order(all);
	if (all->ct.ct == 1)
		return (false);
	if (all->nbrs.nbr_entry <= 5)
		ft_less_five(all);
	init_big(all);
	if (all->nbrs.nbr_entry < 100)
	{
		ft_tob1(all);
		ft_first_class(all);
		ft_tob2(all);
		ft_second_class(all);
	}
	else
	{
		ft_big_01(all);
	}
	return (false);
}

void	init_big(t_pslist *all)
{
	all->center_i = all->nbrs.nbr_entry / 2;
	all->plus_15_i = all->center_i + 15;
	all->less_15_i = all->center_i - 15;
	all->center_nbr = all->save_moy[all->nbrs.nbr_entry / 2];
	all->plus_15_nbr = all->save_moy[all->center_i + 15];
	all->less_15_nbr = all->save_moy[all->center_i - 15];
	all->diff = all->plus_15_i - all->less_15_i;
}

void	ft_init_variables(t_pslist *all)
{
	all->ct.ct = -1;
	all->ct.ii =0;
	all->ct.kk =0;
	all->ct.i = 0;
	all->ct.k = 0;
	all->ct.x = 0;
	all->nbrs.nbr_entry = 0;
	all->nbrs.nbr_in_b =0;
	all->nbrs.s_3_qrt =	0;
	all->nbrs.s_qrt =0;
	all->nbrs.s_moy =0;
	all->total_count = 0;
	all->temp =	0;
	all->test =	0;
	all->nbr = 0;
	all->len = 0;
}
