/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:11:52 by mayoub            #+#    #+#             */
/*   Updated: 2022/06/25 16:51:44 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../push_swap.h"

int	is_trier(t_lst **start_a)
{
	int		i;
	t_lst	*son;

	son = (*start_a);
	i = ft_lstsize(son);
	while (i > 0 && son->next != NULL)
	{
		if (son->nbr > son->next->nbr)
			return (1);
		son = son->next;
		i--;
	}
	return (0);
}

int	trigger_get_min(t_lst **start_a)
{
	int		trigger;
	int		min_trigger;
	t_lst	*son;

	son = (*start_a);
	min_trigger = son->nbr;
	while (son != NULL)
	{
		trigger = son->nbr;
		if (trigger < min_trigger)
			min_trigger = trigger;
		son = son->next;
	}
	return (min_trigger);
}

void	short_sorting_5(t_lst **start_a, t_lst **start_b)
{
	int		trigger;
	int		stop;
	int		min_trigger;
	t_lst	*son;

	son = (*start_a);
	stop = 0;
	while (stop != 2)
	{
		min_trigger = trigger_get_min(start_a);
		while (son != NULL)
		{
			trigger = son->nbr;
			if (min_trigger == trigger)
			{
				while ((*start_a)->nbr != trigger)
					rra(start_a);
				pb(start_a, start_b);
			}
			son = son->next;
		}
		stop++;
	}
	short_sorting_3(start_a);
}

void	short_sorting_3(t_lst **start_a)
{
	while (is_trier(start_a) != 0)
	{
		if ((*start_a)->nbr > (*start_a)->next->nbr
			&& (*start_a)->next->nbr > (*start_a)->next->next->nbr)
		{
			reversed(start_a);
			break ;
		}
		if ((*start_a)->nbr > (*start_a)->next->nbr
			&& (*start_a)->next->nbr < (*start_a)->next->next->nbr)
		{
			if ((*start_a)->nbr < (*start_a)->next->next->nbr)
			{
				sa(start_a);
				break ;
			}
			else
			{
				ra(start_a);
				break ;
			}
		}
		else
			sa(start_a);
	}
}

void	sorting(t_lst **start_a, t_lst **start_b)
{
	if (ft_lstsize(*start_a) == 2)
		sa(start_a);
	else if (ft_lstsize(*start_a) == 3)
	{
		if (((*start_a)->nbr < (*start_a)->next->nbr
				&& (*start_a)->next->nbr > (*start_a)->next->next->nbr)
			&& ((*start_a)->nbr > (*start_a)->next->next->nbr))
			rra(start_a);
		else
			short_sorting_3(start_a);
	}
	else if (ft_lstsize(*start_a) == 5)
	{
		short_sorting_5(start_a, start_b);
		pa(start_a, start_b);
		pa(start_a, start_b);
	}
	else
		big_sorting(start_a, start_b);
}
