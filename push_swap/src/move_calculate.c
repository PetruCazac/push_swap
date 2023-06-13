/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:43:00 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 19:34:31 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	moves(t_dlist **stack)
{
	int		i;
	t_dlist	*temp;
	int		m;

	i = 0;
	temp = *stack;
	m = count_list(stack);
	while (i <= m && temp)
	{
		temp->moves_up = i;
		i++;
		temp = temp->end;
	}
	i = m;
	while (i > 0 && temp)
	{
		temp->moves_down = i;
		i--;
		temp = temp->end;
	}
}
void	find_place(t_dlist **a, t_dlist **b)
{
	t_dlist	*ta;
	t_dlist	*tb;
	t_dlist	*pos;

	tb = *b;
	pos = NULL;
	while (tb)
	{
		ta = *a;
		tb->pos = ta;
		while (ta)
		{
			if (tb->index < ta->index)
			{
				pos = tb->pos;
				tb->pos = ta;
				if (pos->index < ta->index && pos->index > tb->index)
					tb->pos = pos;
			}
			ta = ta->end;
		}
		tb = tb->end;
	}
}
// Takes into account the common moves. 
t_dlist	*choose_smaller(t_dlist **b)
{
	t_dlist	*element;
	t_dlist	*tb;
	int		moves_up;
	int		moves_down;

	tb = *b;
	while (tb)
	{
		moves_up = tb->moves_down + tb->pos->moves_up;
		moves_down= tb
		// Commputate single moves
		if ()
		tb->common_moves = 
		// Computate common moves

		tb = tb->end;
	}




	
	tb->common_moves = tb->moves_b + tb->pos->moves_a;
	element = tb;
	while (tb)
	{
		if (tb->moves < element->moves)
			element = tb;
		tb = tb->end;
		if (tb)
			tb->moves = tb->moves_b + tb->pos->moves_a;
	}
	return (element);
}
// The function will find calculate the optimum movement for each element in each stack
// it will then return the element to be brought on top of the stack from a and b.
t_dlist	*move_calculate(t_dlist **a, t_dlist **b)
{
	moves(b);
	moves(a);
	find_place(a, b);
	return (choose_smaller(b));
}
