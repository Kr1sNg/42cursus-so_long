/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:13:19 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/21 17:39:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/so_long.h"

// void	ft_error_fd(int fd, t_data **game)
// {
// 	if (fd == -1)
// 	{
// 		free(*game);
// 		ft_printf("FD Error\n");
// 		exit(EXIT_FAILURE);
// 	}
// }

// void	ft_no_lines(int i, t_data **game)
// {
// 	if (i == 0)
// 	{
// 		free((*game)->map);
// 		free(*game);
// 		exit(EXIT_FAILURE);
// 	}
// }

// int	ft_check_map_malloc(int fd, t_data **game)
// {
// 	(*game)->map = (char **)malloc(sizeof(char *) * (HEIGHT + 1));
// 	if (!(*game)->map)
// 	{
// 		close(fd);
// 		ft_printf("Error malloc map\n");
// 		return (0);
// 	}
// 	return (1);
// }

// bool	check_rectangular(t_data **game)
// {
// 	int linewidth;
// 	int row_index; // y: row index
// 	int column_index; // x: column index

// 	linewidth = 0;
// 	row_index = 0;
// 	while (((*game)->map[0][linewidth]) && ((*game)->map[0][linewidth] != '\n'))
// 		linewidth++;
// 	while ((*game)->map[row_index])
// 	{
// 		column_index = 0;
// 		while (((*game)->map[row_index][column_index]) && ((*game)->map[row_index][column_index] != '\n'))
// 			column_index++;
// 		if (column_index != linewidth)
// 			return (false);
// 		row_index++;
// 	}
// 	return (true);
// }

// bool	check_border_walls(t_data **game)
// {
// 	int	linewidth;
// 	int	row_index; //y: row index
// 	int column_index; //x: column index

// 	linewidth = 0;
// 	while (((*game)->map[0][linewidth]) && ((*game)->map[0][linewidth] != '\n'))
// 		linewidth++;
// 	// check left and right walls
// 	row_index = 0;
// 	while ((*game)->map[row_index])
// 	{
// 		if (((*game)->map[row_index][0] != WALL) || ((*game)->map[row_index][linewidth - 1] != WALL))
// 			return (false);
// 		row_index++;
// 	}
// 	// check first and last row is walls
// 	column_index = 0;
// 	while (column_index < linewidth)
// 	{
// 		if ((*game)->map[0][column_index] != WALL || (*game)->map[row_index - 1][column_index] != WALL)
// 			return (false);
// 		column_index++;
// 	}
// 	return (true);
// }

#include <stdbool.h>
#include "../libft/includes/libft.h"

bool	ft_map_extension(char *map)
{
	char	*ext;
	int		len;

	ext = ".ber";
	len = ft_strlen(map);
	if (len < 4)
		return (false);
	return (!ft_strcmp(&map[len - 4], ext));
}
