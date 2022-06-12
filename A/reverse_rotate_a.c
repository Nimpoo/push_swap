/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:14:53 by mayoub            #+#    #+#             */
/*   Updated: 2022/06/12 14:15:09 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_lst **start_a)
{
	t_lst	*first;
	t_lst	*swap;

	swap = (*start_a);
	while (swap->next != NULL)
	{
		if (swap->next->next == NULL)
			first = swap;
		swap = swap->next;
	}
	first->next = NULL;
	swap->next = (*start_a);
	(*start_a) = swap;
	printf("rra\n");
}
