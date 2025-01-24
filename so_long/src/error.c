/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:00:14 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/15 20:11:09 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// return feedback for errors of game initiation, read files...
void	ft_error_init(int n)
{
	if (n == 38)
		perror("Error!\nPlease check library compatibility!\n");
	if (n == 1)
		perror("Error!\nOperation not permitted!\n");
	if (n == 2)
		perror("Error!\nNo such file or folder!\n");
	exit(EXIT_FAILURE);
}

// return feedback for errors of map initiation
void	ft_error_map(int n)
{
	if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
		perror("Error!\nUsage: ./so_long <map>.ber\n");
	else if (n == 61)
		perror("Error!\nInvalid map!\n");
	exit(EXIT_FAILURE);
}