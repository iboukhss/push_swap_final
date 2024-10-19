/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:44:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/19 23:45:59 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_main.h"

#include <stdio.h>

int	main(void)
{
	// Check if stack is correctly initialized
	int nums[10] = {2, 5, 1, 0, 4, 8, 6, 3, 9, 7};
	size_t nums_size = sizeof(nums) / sizeof(nums[0]);
	t_stack *stk = stack_new(nums_size);
	stack_init_from_array(stk, nums, nums_size);
	stack_print(stk);
	stack_push_max(stk);
	stack_push_max(stk);
	stack_push_max(stk);
	stack_print(stk);
	stack_push_mid(stk);
	stack_push_mid(stk);
	stack_push_mid(stk);
	stack_print(stk);
	stack_push_min(stk);
	stack_push_min(stk);
	stack_push_min(stk);
	stack_print(stk);
	stack_delete(stk);
	return (0);
}
