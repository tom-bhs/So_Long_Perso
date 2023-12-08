/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/08 20:44:27 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MLX42/include/MLX42/MLX42.h"
#include <stdbool.h>

#define WIN_WIDTH 500
#define WIN_HEIGHT 300
#define TILE_SIZE 16

int main(void)
{
    mlx_t* mlx;
    char *map[5] = 
	{
        "11111111111",
        "1000000C0E1",
        "1000000C0E1",
        "1000000P0E1",
        "11111111111"
    };

    mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So Long", false);
    if (!mlx)
    {
        return 1;
    }

    // Charger une image (remplacer avec votre propre image)
	mlx_texture_t* texture = mlx_load_png("png/Tree.png");
	mlx_texture_t* texture1 = mlx_load_png("png/Grass2.png");
	if (!texture || !texture1)
    {
        mlx_terminate(mlx);
        return 1;
    }
    // Charger une texture et l'appliquer sur l'image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
    mlx_delete_texture(texture); // Nettoyer la texture après usage
	mlx_image_t* img1 = mlx_texture_to_image(mlx, texture1);
    mlx_delete_texture(texture1);

    if (!img)
    {
        mlx_terminate(mlx);
        return 1;
    }

    // Affichage de la carte
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 11; x++)
        {
            if (map[y][x] == '1') // Mur
            {
                mlx_image_to_window(mlx, img, x * TILE_SIZE, y * TILE_SIZE);
            }
			else if (map[y][x] == '0')
			{
				mlx_image_to_window(mlx, img1, x * TILE_SIZE, y * TILE_SIZE);
			}
            // Ajouter ici les autres cas (0, C, E, P) avec leurs images respectives
        }
    }

    mlx_loop(mlx);
    mlx_terminate(mlx);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "MLX42/include/MLX42/MLX42.h"

// #define WIDTH 512
// #define HEIGHT 512

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize()
// {
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				0xFF, // R
// 				0x00, // G
// 				0x00, // B
// 				0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// // void test()
// // {
// //     printf("une touche a ete pressee\n");
// //     return;
// // }

// int32_t main()
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);
//     //mlx_key_hook(mlx, test, NULL);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
