/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:22:02 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/20 01:34:33 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

void	chunk_push(t_chunk *chunk, t_node *node)
{
	if (node == NULL)
	{
		return ;
	}
	if (chunk->len == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		chunk->head = node;
		chunk->tail = node;
	}
	else if (chunk->pos == TOP_A || chunk->pos == TOP_B)
	{
		node->prev = NULL;
		node->next = chunk->head;
		chunk->head->prev = node;
		chunk->head = node;
	}
	else
	{
		node->prev = chunk->tail;
		node->next = NULL;
		chunk->tail->next = node;
		chunk->tail = node;
	}
	chunk->len += 1;
}

void	stack_push_min(t_stack *stack)
{
	t_node	*node;

	node = chunk_pop(&stack->curr);
	chunk_push(&stack->min, node);
}

void	stack_push_mid(t_stack *stack)
{
	t_node	*node;

	node = chunk_pop(&stack->curr);
	chunk_push(&stack->mid, node);
}

void	stack_push_max(t_stack *stack)
{
	t_node	*node;

	node = chunk_pop(&stack->curr);
	chunk_push(&stack->max, node);
}
