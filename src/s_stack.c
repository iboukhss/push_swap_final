/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:21:18 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/21 20:00:35 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include <stdlib.h>

t_node	*freelist_init(t_node *pool, ptrdiff_t pool_size)
{
	ptrdiff_t	i;

	i = 0;
	while (i < pool_size - 1)
	{
		pool[i].next_free = &pool[i + 1];
		++i;
	}
	pool[i].next_free = NULL;
	return (pool);
}

t_stack	*stack_new(ptrdiff_t stack_size)
{
	t_stack	*stack;
	t_node	*pool;

	stack = calloc(1, sizeof(*stack));
	pool = calloc(stack_size, sizeof(*pool));
	stack->pool = pool;
	stack->free_list = freelist_init(pool, stack_size);
	stack->cap = stack_size;
	stack->curr.pos = TOP_A;
	stack->min.pos = BOT_B;
	stack->mid.pos = TOP_B;
	stack->max.pos = BOT_A;
	return (stack);
}

void	stack_delete(t_stack *stack)
{
	free(stack->pool);
	free(stack);
}

t_node	*freelist_pop(t_stack *stack)
{
	t_node	*node;

	if (stack->free_list == NULL)
	{
		return (NULL);
	}
	node = stack->free_list;
	stack->free_list = stack->free_list->next_free;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack	*stack_init_from_array(t_stack *stack, int *array, ptrdiff_t array_size)
{
	t_node	*node;
	int		*end;

	end = array + array_size;
	while (end > array)
	{
		node = freelist_pop(stack);
		if (node == NULL)
		{
			return (NULL);
		}
		node->data = *--end;
		chunk_push(&stack->curr, node);
	}
	return (stack);
}
