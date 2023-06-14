/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 15:33:55 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	move_both(t_dlist *element, t_dlist **a, t_dlist **b)
{
	while ((*b) != element || (*a) != element->pos)
	{
		if (element->dir == 11)
			rotate_both(a, b);
		else if (element->dir == 22)
			rrotate_both(a, b);
	}
	while ((*b) != element && element->dir == 11)
		rotate(b, 'b');
	while ((*a) != element->pos && element->dir == 11)
		rotate(a, 'a');
	while ((*b) != element && element->dir == 22)
		rrotate(b, 'b');
	while ((*a) != element->pos && element->dir == 22)
		rrotate(a, 'a');
	push(b, a, 'a');
}

void	move_element(t_dlist *element, t_dlist **a, t_dlist **b)
{
	while ((*b) != element)
	{
		if (element->dir == 21 && (*b) != element)
			rotate(b, 'b');
		else if (element->dir == 12 && (*b) != element)
			rrotate(b, 'b');
	}
	while ((*a) != element->pos)
	{
		if (element->dir == 12 && (*a) != element->pos)
			rotate(a, 'a');
		else if (element->dir == 21 && (*a) != element->pos)
			rrotate(a, 'a');
	}
	push(b, a, 'a');
}

void	choose_move(t_dlist *element, t_dlist **a, t_dlist **b)
{
	if (element->dir == 11 || element->dir == 22)
		move_both(element, a, b);
	if (element->dir == 12 || element->dir == 21)
		move_element(element, a, b);
	return ;
}

void	final_rotate(t_dlist **a)
{
	int		i;
	t_dlist	*temp;
	int		m;

	m = count_list(a);
	i = 0;
	temp = *a;
	while (temp->index != 0)
	{
		temp = temp->end;
		i++;
	}
	if (i <= m / 2)
	{
		while ((*a)->index != 0)
			rotate(a, 'a');
	}
	else if (i > m / 2)
	{
		while ((*a)->index != 0)
			rrotate(a, 'a');
	}
}

void	push_b(t_dlist **a, t_dlist **b)
{
	int		max;
	int		med;
	int		j;
	// t_dlist	*element;
	
	max = (find_max(a))->index;
	med = max / 2;
	j = count_list(a);
	while (j != 3)
	{
		if ((*a)->index == 0 || (*a)->index == max || (*a)->index == med)
			rotate(a, 'a');
		else
			push(a, b, 'b');
		j = count_list(a);
	}
	sort_small(a);
	while (count_list(b) != 0)
		choose_move(move_calculate(a, b), a, b);
	final_rotate(a);
}
