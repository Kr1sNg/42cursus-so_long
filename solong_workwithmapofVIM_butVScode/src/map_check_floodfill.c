/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_floodfill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:13:19 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/29 18:01:54 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_free_matrix_path(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

static void	ft_floodfill(t_game *game, char **matrix, t_pos curr)
{
	if (matrix[curr.p_row][curr.p_col] == WALL)
		return ;
	else if (matrix[curr.p_row][curr.p_col] == EXIT)
	{
		matrix[curr.p_row][curr.p_col] = WALL;
		return;
	}
	else if (matrix[curr.p_row][curr.p_col] == COIN)
		game->path_coin++;
	matrix[curr.p_row][curr.p_col] = WALL;
	ft_floodfill(game, matrix, (t_pos){curr.p_row + 1, curr.p_col});
	ft_floodfill(game, matrix, (t_pos){curr.p_row - 1, curr.p_col});
	ft_floodfill(game, matrix, (t_pos){curr.p_row, curr.p_col + 1});
	ft_floodfill(game, matrix, (t_pos){curr.p_row, curr.p_col - 1});
}

static bool	ft_count_rest(char **matrix)
{
	int	col;
	int	row;
	int	count_e;
	int count_c;

	count_e = 0;
	count_c = 0;
	row = -1;
	while (matrix[++row])
	{
		col = -1;
		while (matrix[row][++col])
		{
			if (matrix[row][col] == EXIT)
				count_e++;
			else if (matrix[row][col] == COIN)
				count_c++;
		}
	}
	return (count_c == 0 && count_e == 0);
}

bool	ft_map_path(t_game *game)
{
	char	**matrix_path;
	int		i;
	bool		a;

	i = -1;
	matrix_path = ft_calloc(game->map.numoflines + 1, sizeof(char *));
	if (!matrix_path)
	{
		ft_free_map(game);
		return (ft_error_map(24), false);
	}
	while (game->map.matrix[++i])
		matrix_path[i] = ft_strdup(game->map.matrix[i]);
	ft_locate_player(game);
	ft_floodfill(game, matrix_path, game->position);
	a = ft_count_rest(matrix_path);
	ft_free_matrix_path(matrix_path);
	return (a == true && (int)game->path_coin == game->count.coin);
}

