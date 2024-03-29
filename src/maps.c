/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:17:09 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/01 14:34:51 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

lamap mapy;
void aff_map(int fd, mlx_t *mlx)
{
    mapy.vit = 50;
    mapy.nb_c = 0;
    int x;
    int y = 0;
    mapy.mapp = malloc(100 * sizeof(char *));
    while ((mapy.mapp[y] = get_next_line(fd)) != NULL)
    {
        x = 0;
        while (mapy.mapp[y][x] != '\0')
        {
            if (mapy.mapp[y][x] == '1' ) // texture1 = mur
                mlx_image_to_window(mlx, textureInfoArray[0].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == '0' || mapy.mapp[y][x] == 'C' || mapy.mapp[y][x] == 'P' || mapy.mapp[y][x] == 'Y' || mapy.mapp[y][x] == 'W' || mapy.mapp[y][x] == 'F' 
			|| mapy.mapp[y][x] == '2')
                mlx_image_to_window(mlx, textureInfoArray[1].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'E' ) // texture3 = sortie
            {
                mlx_image_to_window(mlx, textureInfoArray[3].img, x * TILE_SIZE, y * TILE_SIZE);
                mlx_image_to_window(mlx, textureInfoArray[13].img, x * TILE_SIZE, y * TILE_SIZE);
				textureInfoArray[13].img->enabled = false;
            }
            if (mapy.mapp[y][x] == 'Y' ) // texture3 = echelle
                mlx_image_to_window(mlx, textureInfoArray[5].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'W' ) // texture6 = support
                mlx_image_to_window(mlx, textureInfoArray[6].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'F' ) // texture = feux
                mlx_image_to_window(mlx, textureInfoArray[7].img, x * TILE_SIZE, y * TILE_SIZE);
            x += 1;
        }
        y += 1;
    }
    close(fd);
    int z = y;
    mapy.maxY = y;
    mapy.maxX = x;
    y = 0;
    while (z > y)
    {
        x = 0;
        while (mapy.mapp[y][x] != '\0')
        {
            if (mapy.mapp[y][x] == 'C' ) // texture2 = collectable
                mlx_image_to_window(mlx, textureInfoArray[2].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'P' ) // texture4 = perso
            {
                mlx_image_to_window(mlx, textureInfoArray[4].img, x * TILE_SIZE, y * TILE_SIZE);
                mlx_image_to_window(mlx, textureInfoArray[12].img, x * TILE_SIZE, y * TILE_SIZE);
                textureInfoArray[12].img->enabled = false;
            }
            if (mapy.mapp[y][x] == '2' ) // texture = barrel1
            {
				mlx_image_to_window(mlx, textureInfoArray[8].img, x * TILE_SIZE, y * TILE_SIZE);
                mlx_image_to_window(mlx, textureInfoArray[9].img, x * TILE_SIZE, y * TILE_SIZE);
                mlx_image_to_window(mlx, textureInfoArray[10].img, x * TILE_SIZE, y * TILE_SIZE);
                mlx_image_to_window(mlx, textureInfoArray[11].img, x * TILE_SIZE, y * TILE_SIZE);
                textureInfoArray[9].img->enabled = false;
                textureInfoArray[10].img->enabled = false;
                textureInfoArray[11].img->enabled = false;
            }
            x++;
        }
        y++;
    }
}
