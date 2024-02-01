/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/01 14:35:29 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

TextureInfo textureInfoArray[28];

extern mlx_image_t* normal;  // Face normale = droite
extern mlx_image_t* flipped; // Face inversée = gauche

void initializeTextures(mlx_t* mlx)
{
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
	textureInfoArray[15].texture = mlx_load_png("png/end1.png");
	textureInfoArray[16].texture = mlx_load_png("png/end2.png");
	textureInfoArray[17].texture = mlx_load_png("png/end3.png");
	textureInfoArray[18].texture = mlx_load_png("png/end4.png");
	textureInfoArray[19].texture = mlx_load_png("png/end5.png");
	textureInfoArray[20].texture = mlx_load_png("png/end6.png");
	textureInfoArray[21].texture = mlx_load_png("png/end7.png");
	textureInfoArray[22].texture = mlx_load_png("png/end8.png");
	textureInfoArray[23].texture = mlx_load_png("png/end9.png");
	textureInfoArray[24].texture = mlx_load_png("png/end10.png");
	textureInfoArray[25].texture = mlx_load_png("png/end11.png");
	textureInfoArray[26].texture = mlx_load_png("png/end12.png");
    textureInfoArray[27].texture = mlx_load_png("png/over.png");


	while (i < 28)
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
