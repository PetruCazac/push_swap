/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:55:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 19:30:46 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*tmp;

	tmp = malloc(sizeof(t_dlist));
	if (!tmp)
		return (NULL);
	if (tmp)
	{
		tmp->number = content;
		tmp->index = 0;
		tmp->moves = 0;
		tmp->moves_up = 0;
		tmp->moves_down= 0;
		tmp->common_moves = 0;
		tmp->common_dir = 0;
		tmp->pos = NULL;
		tmp->next = NULL;
		tmp->previous = NULL;
		tmp->end = NULL;
	}
	return (tmp);
}
