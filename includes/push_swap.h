/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:08:00 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 00:27:17 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

/*structs*/
typedef struct s_node
{
	long	value;
	int		index;
	void	*prev;
	void	*next;
}			t_node;

/*main*/
int			main(int ac, char **av);

/*error*/
void		display_error(char *str);
void		putstr(char *str);

/*struct init*/
bool		create_head_node(t_node **head, char *str);
bool		new_node(t_node **head, char *str, int i);
bool		lst_maker(t_node **head, char *str, int i);

/*arg_parsing*/
bool		create_stack(t_node **head, int argc, char **argv);

/*brut_force*/
void		brut_force(t_node **a_head, t_node **b_head, int size, char stack);

/*direct_ins*/
void		direct_ins(t_node **a_head, t_node **b_head);

/*radix*/
void		radix_sort(t_node **a_head, t_node **b_head, int size);

/*frees_utils*/
void		free_stack(t_node **head);
void		find_free(char *str1, char *str2);

/*dispatcher*/
void		dispatcher(t_node **a_head);

/*utils*/
bool		num_is_int(long nbr);
bool		onlyspace(char *str);
bool		is_a_number(char *str);
int			log2_rounded(long num);

/*swap_moves*/
void		swap(t_node **head, char stack);
void		swap_all(t_node **a_head, t_node **b_head);

/*push_rotates_moves*/
void		push(t_node **src_head, t_node **dst_head, char stack);
void		rotate(t_node **head, char stack);
void		rotate_all(t_node **a_head, t_node **b_head);

/*reverse_rotate_moves*/
void		reverse_rotate(t_node **head, char stack);
void		reverse_rotate_all(t_node **a_head, t_node **b_head);

/*struct_utils*/
void		lst_remove_node(t_node **head);
void		lst_new_head(t_node **head, t_node *temp);
void		index_update(t_node **head);
t_node		*search_vmin_node(t_node **a_head);
void		put_vmin_at_head(t_node **head, t_node **v_min);

/*struct_utils2*/
long		search_vmin(t_node **a_head);
long		search_vmax(t_node **a_head);
void		normalize_values(t_node **a_head, long vmin);
void		set_original_values(t_node **a_head, long vmin);

/*struct_utils3*/
int			clockwise_search(t_node **a_head, t_node **target);
int			reverse_search(t_node **a_head, t_node **target);
t_node		*get_target_node_index(t_node **head, int index);
t_node		*get_target_node_value(t_node **head, long value);

/*sort stack*/
void		sort_stack(t_node **a_head, t_node **b_head, int size);
void		target_pos_inst(char **tab, t_node **current, t_node **b_head);
void		put_instructions(char **tab, int nbr, char mov);

/*exe_instructions*/
void		execute_inst_set(char *tab, t_node **a_head, t_node **b_head);

/*optimiations*/
char		*find_optimisation_to_b(char *tab);

#endif
