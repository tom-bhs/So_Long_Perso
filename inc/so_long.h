/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:24:31 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/01 14:42:56 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32

#define WIN_WIDTH 1248
#define WIN_HEIGHT 512

# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <time.h>

typedef struct txt_inf{
    mlx_texture_t* texture;
    mlx_image_t* img;
} TextureInfo;

typedef struct lmp {
    char** mapp;
    int maxY;
    int maxX;
    int gravity;
    size_t nb_c;
    unsigned long long vit;
} lamap;

typedef struct s_barrel{
	int x, y;
	int frame;
} t_barrel;

extern lamap mapy;
extern TextureInfo textureInfoArray[28];

void	ft_hook(void* param); 
int		main(void);
int		isPositionValid(int x, int y);
void	aff_map(int fd, mlx_t *mlx);
void	update_barrel_position(t_barrel *tonneau, int window_width, int largeur_tonneau);
void	update_barrel_animation(t_barrel *tonneau);
void	initialiser_tonneaux(t_barrel *tonneaux, int window_width, int start_y);
void	game_update(t_barrel *tonneaux, int window_width, int start_y);
void	collectible(void);
bool	jump(int x, int y);
int		notladder(int x, int y);
void	mouvBarrel(void);
unsigned long long  getCurrentTimeInMilliseconds(void);
void	isMapValid();
void	animate_next_frame(void *param);

#endif