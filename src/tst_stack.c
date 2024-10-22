/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:44:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/21 21:22:52 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_main.h"

void	test_stack_new(void)
{
	// Small stack
	t_stack *stk = stack_new(1);
	if (stk != NULL)
	{
		assert(stk->cap == 1);
		assert(stk->pool != NULL);
		assert(stk->free_list != NULL);
	}
	stack_delete(stk);

	// Medium stack
	stk = stack_new(100);
	if (stk != NULL)
	{
		assert(stk->cap == 100);
		assert(stk->pool != NULL);
		assert(stk->free_list != NULL);
	}
	stack_delete(stk);

	// Big stack
	stk = stack_new(12345);
	if (stk != NULL)
	{
		assert(stk->cap == 12345);
		assert(stk->pool != NULL);
		assert(stk->free_list != NULL);
	}
	stack_delete(stk);
}

void	test_stack_init(void)
{
	int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Stack equal to array
	t_stack *stk = stack_new(10);
	if (stk != NULL)
	{
		assert(stack_init_from_array(stk, nums, 10) != NULL);
		assert(stk->cap == 10);
		assert(stk->pool != NULL);
		assert(stk->free_list == NULL);
		assert(stk->curr.len == 10);
	}
	stack_delete(stk);

	// Stack smaller than array
	stk = stack_new(5);
	if (stk != NULL)
	{
		assert(stack_init_from_array(stk, nums, 10) == NULL);
	}
	stack_delete(stk);

	// Stack bigger than array
	stk = stack_new(10);
	if (stk != NULL)
	{
		assert(stack_init_from_array(stk, nums, 5) != NULL);
		assert(stk->cap == 10);
		assert(stk->pool != NULL);
		assert(stk->free_list != NULL);
		assert(stk->curr.len == 5);
	}
	stack_delete(stk);
}
