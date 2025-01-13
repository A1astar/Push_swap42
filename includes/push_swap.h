/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:08:00 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/13 17:32:34 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

# define STACK_A 'y'
# define STACK_B 'z'

typedef struct s_node
{
	long	value;
	int		index;
	void	*prev;
	void	*next;
}			t_node;

/*main*/
int			main(int argc, char **argv);

/*error*/
void		display_error(char *str);

/*arg parsing*/
bool		create_stack(t_node **head, int argc, char **argv);

/*arg parsing utils*/
bool		num_is_int(long nbr);
bool		onlyspace(char *str);
bool		is_a_number(char *str);

/*dispatcher*/
void		dispatcher(t_node **a_head);

/*brut force*/
void		brut_force(t_node **a_head, t_node **b_head, int size, char stack);

/*sort stack*/
void		sort_stack(t_node **a_head, t_node **b_head);

/*sort stack2*/
void		target_pos_inst(char **tab, t_node **target, t_node **dst_head);

/*put instructions*/
char		*put_single_inst(char *str1, char inst);
void		put_multi_inst(char **tab, int nbr, char inst);

/*exe instructions*/
void		execute_inst_set(char *tab, t_node **a_head, t_node **b_head);

/*push rotate moves*/
void		push(t_node **src_head, t_node **dst_head, char stack);
void		rotate(t_node **head, char stack);
void		rotate_all(t_node **a_head, t_node **b_head, char stack);

/*reverse rotate moves*/
void		reverse_rotate(t_node **head, char stack);
void		reverse_rotate_all(t_node **a_head, t_node **b_head, char stack);

/*swap moves*/
void		swap(t_node **head, char stack);
void		swap_all(t_node **a_head, t_node **b_head, char stack);

/*struc min max*/
bool		is_min_value(t_node **target, t_node **head);
bool		is_max_value(t_node **target, t_node **head);

/*struct free*/
void		free_stack(t_node **head);

/*struct init*/
bool		create_head_node(t_node **head, char *str);
bool		new_node(t_node **head, char *str, int i);
bool		lst_maker(t_node **head, char *str, int i);

/*struct modif*/
void		lst_remove_node(t_node **head);
void		lst_new_head(t_node **head, t_node *temp);
void		index_update(t_node **head);
void		put_vmin_at_head(t_node **head, t_node **v_min);

/*struct search node*/
t_node		*search_vmin_node(t_node **head);
t_node		*search_vmax_node(t_node **head);

/*struct browse count*/
int			clockwise_target_search(t_node **head, t_node **target);
int			reverse_target_search(t_node **head, t_node **target);
int			clockwise_target_rev_ins(t_node **target, t_node **head);
int			reverse_target_rev_ins(t_node **target, t_node **head);

/*struct check*/
bool		stack_is_sorted(t_node *a_head);

/*check_combo*/
void		check_simple_combo(char *c1, char *c2);
void		check_multi_combo(char *s);

/*new inst set*/
char		*find_optimisations(char *s);
void		change_multi_inst(char *s, int nbr, char inst);
void		change_instructions(char *c1, char *c2, char inst);

/*checker exe inst*/
void		check_execute_inst(t_node **a_head, t_node **b_head, char *tab);

#endif
