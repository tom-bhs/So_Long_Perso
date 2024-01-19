/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/19 14:01:53 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

#define WIN_WIDTH 1248
#define WIN_HEIGHT 512

TextureInfo textureInfoArray[15];

extern mlx_image_t* normal;  // Face normale = droite
extern mlx_image_t* flipped; // Face inversée = gauche

void initializeTextures(mlx_t* mlx) {
    int i = 0;
    textureInfoArray[0].texture = mlx_load_png("png/rock32.png");
    textureInfoArray[1].texture = mlx_load_png("png/back32.png");
    textureInfoArray[2].texture = mlx_load_png("png/banana32.png");
    textureInfoArray[3].texture = mlx_load_png("png/doorclose32.png");
    textureInfoArray[4].texture = mlx_load_png("png/kong32.png");
    textureInfoArray[5].texture = mlx_load_png("png/ladder32.png");
    textureInfoArray[6].texture = mlx_load_png("png/bloc32.png");
    textureInfoArray[7].texture = mlx_load_png("png/fire32.png");
    textureInfoArray[8].texture = mlx_load_png("png/1barrel32.png");
    textureInfoArray[9].texture = mlx_load_png("png/2barrel32.png");
    textureInfoArray[10].texture = mlx_load_png("png/3barrel32.png");
    textureInfoArray[11].texture = mlx_load_png("png/4barrel32.png");
    textureInfoArray[12].texture = mlx_load_png("png/reversekong32.png");
    textureInfoArray[13].texture = mlx_load_png("png/dooropen32.png");
    textureInfoArray[14].texture = mlx_load_png("png/blast32.png");

	while (i < 15)
	{
		textureInfoArray[i].img = mlx_texture_to_image(mlx, textureInfoArray[i].texture);
		mlx_delete_texture(textureInfoArray[i].texture);
		i++;
	}
}


int main(void)  
{
    mlx_t* mlx;

    mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So_Long", true);
    if (!mlx)
        return 1;
    initializeTextures(mlx);
    int fd = open("maps/maps.ber", O_RDONLY);  // Ouvre le fichier en lecture seule

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
    }
    aff_map(fd, mlx);
    isMapValid(mlx);
    close(fd);
    // Affichage de la carte
    mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return 0;
}
