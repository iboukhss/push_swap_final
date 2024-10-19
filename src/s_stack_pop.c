/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:09:18 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/20 01:34:09 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

t_node	*chunk_pop(t_chunk *chunk)
{
	t_node	*node;

	if (chunk->len == 0)
	{
		return (NULL);
	}
	if (chunk->len == 1)
	{
		node = chunk->head;
		chunk->head = NULL;
		chunk->tail = NULL;
	}
	else if (chunk->pos == TOP_A || chunk->pos == TOP_B)
	{
		node = chunk->head;
		chunk->head = chunk->head->next;
		chunk->head->prev = NULL;
	}
	else
	{
		node = chunk->tail;
		chunk->tail = chunk->tail->prev;
		chunk->tail->next = NULL;
	}
	node->prev = NULL;
	node->next = NULL;
	chunk->len -= 1;
	return (node);
}

t_node	*stack_pop_curr(t_stack *stack)
{
	t_node	*node;

	node = chunk_pop(&stack->curr);
	return (node);
}

t_node	*stack_pop_min(t_stack *stack)
{
	t_node	*node;

	node = chunk_pop(&stack->min);
	return (node);
}

t_node	*stack_pop_mid(t_stack *stack)
{
	t_node	*node;

	node = chunk_pop(&stack->mid);
	return (node);
}

t_node	*stack_pop_max(t_stack *stack)
{
	t_node	*node;

	node = chunk_pop(&stack->max);
	return (node);
}
