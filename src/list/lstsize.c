/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:23:05 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/21 15:10:55 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	lstsize(t_vector *vector)
{
	int	count;

	count = 0;
	if (!vector)
		return (count);
	while (vector)
	{
		count++;
		vector = vector->next;
	}
	return (count);
}
