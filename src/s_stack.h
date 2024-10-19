/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:21:28 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/19 17:31:48 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

# include <stddef.h>

// Doubly linked list of integers
typedef struct s_node	t_node;

struct s_node
{
	int		data;
	t_node	*prev;
	t_node	*next;
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
	t_node		*pool;
	ptrdiff_t	cap;
	t_chunk		*curr;
	t_chunk		*min;
	t_chunk		*mid;
	t_chunk		*max;
}	t_stack;

#endif
