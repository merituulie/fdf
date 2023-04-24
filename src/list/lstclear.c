/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:53:34 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/24 18:07:09 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_clr_rec(t_vector *vector)
{
	if (!vector)
		return ;
	ft_clr_rec(vector->next);
	vector->next = NULL;
	vector->x = 0;
	vector->y = 0;
	vector->z = 0;
	free(vector);
}

void	lstclear(t_vector **vectors)
{
	if (!vectors)
		return ;
	ft_clr_rec(*vectors);
	*vectors = NULL;
}
