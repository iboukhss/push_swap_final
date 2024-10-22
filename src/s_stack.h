/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:21:28 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/21 19:59:41 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

# include <stdbool.h>
# include <stddef.h>

// Doubly linked list of integers
typedef struct s_node	t_node;

struct s_node
{
	int		data;
	t_node	*prev;
	t_node	*next;
	t_node	*next_free;
};

// Chunk position in the stack
typedef enum e_position
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B,
}	t_position;

// Chunk of the linked list
typedef struct s_chunk
{
	t_position	pos;
	t_node		*head;
	t_node		*tail;
	ptrdiff_t	len;
}	t_chunk;

// Practical stack representation for push_swap
typedef struct s_stack
{
	void		*pool;
	t_node		*free_list;
	ptrdiff_t	cap;
	t_chunk		curr;
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}	t_stack;

// Stack construct/destruct
t_stack	*stack_new(ptrdiff_t stack_size);
t_stack	*stack_init_from_array(t_stack *stack, int *array, ptrdiff_t array_size);
void	stack_delete(t_stack *stack);

// Stack pop
t_node	*stack_pop_curr(t_stack *stack);
t_node	*stack_pop_min(t_stack *stack);
t_node	*stack_pop_mid(t_stack *stack);
t_node	*stack_pop_max(t_stack *stack);

// Stack push
void	stack_push_min(t_stack *stack);
void	stack_push_mid(t_stack *stack);
void	stack_push_max(t_stack *stack);

// Free list
t_node	*freelist_init(t_node *pool, ptrdiff_t pool_size);
t_node	*freelist_pop(t_stack *stack);

// Chunk
t_node	*chunk_pop(t_chunk *chunk);
void	chunk_push(t_chunk *chunk, t_node *node);
bool	chunk_is_sorted(t_chunk *chunk);

#endif
