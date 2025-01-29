/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:00:14 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/26 21:00:55 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// return feedback for errors of game initiation, files reading
void	ft_error_init(int n)
{
	if (n == 11)
		ft_printf("Error!\nPlease check MLX connection!\n");
	else if (n == 12)
		ft_printf("Error!\nPlease check MLX window!\n");
	else if (n == 13)
		ft_printf("Error!\nInvalid images or Invalid path to images!\n");
	exit(EXIT_FAILURE);
}

// return feedback for errors of map initiation
void	ft_error_map(int n)
{
	if (n == 20)
		ft_printf("Error!\nUsage: ./so_long map/<map>.ber\n");
	else if (n == 21)
		ft_printf("Error!\nInvalid map!\n");
	else if (n == 22)
		ft_printf("Error!\nInvalid path to maps!\n");
	else if (n == 23)
		ft_printf("Error!\nPlease use map in the '.ber' files!\n");
	else if (n == 24)
		ft_printf("Error!\nCan't Allocate Memory!\n");
	exit(EXIT_FAILURE);
}
