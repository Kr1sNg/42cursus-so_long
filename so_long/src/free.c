/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:14:53 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/17 16:22:32 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.matrix)
		return ;
	i = 0;
	while (game->map.matrix[i])
	{
		free(game->map.matrix[i]);
		game->map.matrix[i] = NULL;
		i++;
	}
	free(game->map.matrix);
	game->map.matrix = NULL;
}

