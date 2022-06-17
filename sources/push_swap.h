/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:57:18 by nadesjar          #+#    #+#             */
/*   Updated: 2022/04/29 22:57:18 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct p_list
{
	int	i;
	int	k;
	int	x;
	int	ii;
	int	kk;
	int	ct;
	int	len;
	int	total_count;
	int	nbr_entry;
	int	nbr_in_a;
	int nbr_in_b;
	int	*stack_a;
	int	*stack_b;
	int	*save_moy;
	int	*nbr;
	int	temp;
	int	s_qrt;
	int s_moy;
	int s_3_qrt;
	int test;
}		t_pslist;

bool	save_nbr(int nb_arg, char **entry, t_pslist *all);
bool	ft_check_end(t_pslist *all);
bool    ft_wside(t_pslist *all);

int		ft_check_all(int nb_arg, char **entry, t_pslist *all);
int		check_entry(int nb_arg, char **entry, t_pslist *all);
int		check_doub(int nb_arg, char **entry, t_pslist *all);
int		ft_check_order(t_pslist *all);
int		ft_run_prog(t_pslist *all);
int		ft_find_moy(t_pslist *all);

void	alloc_tab(int nb_arg, char **entry, t_pslist *all);
void	ft_init_variables(t_pslist *all);
void	ft_second_class(t_pslist *all);
void    ft_first_class(t_pslist *all);
void	ft_print_stack(t_pslist *all);
void	ft_less_five(t_pslist *all);
void	ft_lfive(t_pslist *all);
void    ft_tob1(t_pslist *all);
void	ft_tob2(t_pslist *all);
void	ft_imp(t_pslist *all);

void	ft_rra(t_pslist *all, int ct);
void	ft_rrb(t_pslist *all, int ct);
void	ft_sa(t_pslist *all, int ct);
void	ft_sb(t_pslist *all, int ct);
void	ft_ss(t_pslist *all, int ct);
void	ft_ra(t_pslist *all, int ct);
void	ft_rb(t_pslist *all, int ct);
void	ft_rrr(t_pslist *all);
bool	ft_pa2(t_pslist *all);
bool	ft_pb2(t_pslist *all);
void	ft_rr(t_pslist *all);
bool	ft_pa(t_pslist *all);
bool	ft_pb(t_pslist *all);

#endif