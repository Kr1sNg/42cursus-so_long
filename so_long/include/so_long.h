/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:57:06 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/21 16:45:17 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Linux:
**	make && ./configure
**	flag needed to add to compile
**	-L../minilibx-linux -lmlx -lX11 -lXext
**	
**	MacOS:
**	make && ./configure (have to install mlx first)
** 	-I /usr/X11/include(to find X11/X.h and keysym.h) -L../minilibx-linux -lmlx -L/usr/X11/lib -lX11 -lXext    
**	(-framework OpenGL -framework AppKit)
**
**	https://github.com/rbourgeat/so_long
*/

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** :::::::::::::::::::::::::::::::::* HEADERS *:::::::::::::::::::::::::::::: **
*/

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

/*
** :::::::::::::::::::::::::::* DEFINE DECLARATION *::::::::::::::::::::::::: **
*/


#define EMPTY '0'
#define WALL '1'
#define COLLECTIBLE 'C'
#define EXIT 'E'
#define PLAYER 'P'


/*
** :::::::::::::::::::::::::::* STRUCT DECLARATION *::::::::::::::::::::::::: **
*/

/*
** ...:::*** Main Controller ***:::...
*/
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		argc_tmp;
	char	**argv_tmp;
	
		
	
}

/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/




#endif