/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:02:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 14:34:28 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

static int	count_filename(char *filename)
{
	int	count;

	count = 0;
	while (filename[count])
		count++;
	return (count);
}

static int	valid_file(char *filename)
{
	int	length;

	length = count_filename(filename);
	if (length < 5)
		return (0);
	else if (filename[length - 1] != 102
		|| filename[length - 2] != 100
		|| filename[length - 3] != 102
		|| filename[length - 4] != 46)
		return (0);
	else
		return (1);
}

int	get_fd(char *filename)
{
	int	fd;

	if (!valid_file(filename))
		exit_failure();
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_failure();
	return (fd);
}
