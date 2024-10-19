/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:21:18 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/19 20:12:38 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include <stdlib.h>

static t_node	*free_list_init(t_node *pool, ptrdiff_t pool_size)
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
	stack->free_list = free_list_init(pool, stack_size);
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

// TODO
t_stack	*stack_init_from_array(t_stack *stack, int *array, ptrdiff_t array_size);
