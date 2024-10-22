/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:04:01 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/20 02:12:39 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

// TODO: refactor code duplication
bool	chunk_is_sorted(t_chunk *chunk)
{
	t_node	*curr;

	curr = chunk->head;
	if (chunk->pos == TOP_A || chunk->pos == BOT_A)
	{
		while (curr && curr->next)
		{
			if (curr->data > curr->next->data)
			{
				return (false);
			}
			curr = curr->next;
		}
	}
	else
	{
		while (curr && curr->next)
		{
			if (curr->data < curr->next->data)
			{
				return (false);
			}
			curr = curr->next;
		}
	}
	return (true);
}
