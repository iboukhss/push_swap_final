/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:45:12 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/20 00:17:14 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_main.h"

#include <stdio.h>

static t_chunk	*chunk_at_pos(t_stack *stack, t_position pos)
{
	if (stack->curr.pos == pos)
		return (&stack->curr);
	if (stack->min.pos == pos)
		return (&stack->min);
	if (stack->mid.pos == pos)
		return (&stack->mid);
	else
		return (&stack->max);
}

void	stack_print(t_stack *stack)
{
	t_chunk		*top_a;
	t_chunk		*top_b;
	t_chunk		*bot_a;
	t_chunk		*bot_b;
	t_node		*left;
	t_node		*right;

	top_a = chunk_at_pos(stack, TOP_A);
	top_b = chunk_at_pos(stack, TOP_B);
	bot_a = chunk_at_pos(stack, BOT_A);
	bot_b = chunk_at_pos(stack, BOT_B);
	left = top_a->head;
	right = top_b->head;
	printf("--------------------------------------------------------\n");
	printf("   A ** B\n");
	while (left || right)
	{
		if (left == NULL) {
			printf("   .  ");
		}
		else {
			printf(" %3d  ", left->data);
			left = left->next;
		}
		if (right == NULL) {
			printf("  .\n");
		}
		else {
			printf("%3d\n", right->data);
			right = right->next;
		}
	}
	left = bot_a->head;
	right = bot_b->head;
	printf("   A ** B\n");
	while (left || right)
	{
		if (left == NULL) {
			printf("   .  ");
		}
		else {
			printf(" %3d  ", left->data);
			left = left->next;
		}
		if (right == NULL) {
			printf("  .\n");
		}
		else {
			printf("%3d\n", right->data);
			right = right->next;
		}
	}
}
