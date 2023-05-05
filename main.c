/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:06:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/28 13:05:47 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
		exit_failure();
	if (argv[1][0] == '\0')
		exit_success(NULL);
	run(argv[1]);
	return (0);
}
