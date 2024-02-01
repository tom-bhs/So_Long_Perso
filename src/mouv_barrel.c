/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/01 14:34:55 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	mouv_right(void)
{
	int	i;

	textureInfoArray[8].img->instances[0].x += 8;
	textureInfoArray[9].img->instances[0].x += 8;
	textureInfoArray[10].img->instances[0].x += 8;
	textureInfoArray[11].img->instances[0].x += 8;
	i = 0;
	if (textureInfoArray[8].img->enabled == true)
		i = 9;
	else if (textureInfoArray[9].img->enabled == true)
		i = 10;
	else if (textureInfoArray[10].img->enabled == true)
		i = 11;
	else if (textureInfoArray[11].img->enabled == true)
		i = 8;
	textureInfoArray[8].img->enabled = false;
	textureInfoArray[9].img->enabled = false;
	textureInfoArray[10].img->enabled = false;
	textureInfoArray[11].img->enabled = false;
	textureInfoArray[i].img->enabled = true;
	mapy.vit /= 0.999;
}
void	mouv_left(void)
{
	int	i;

	textureInfoArray[8].img->instances[0].x -= 8;
	textureInfoArray[9].img->instances[0].x -= 8;
	textureInfoArray[10].img->instances[0].x -= 8;
	textureInfoArray[11].img->instances[0].x -= 8;
	i = 0;
	if (textureInfoArray[8].img->enabled == true)
		i = 11;
	else if (textureInfoArray[11].img->enabled == true)
		i = 10;
	else if (textureInfoArray[10].img->enabled == true)
		i = 9;
	else if (textureInfoArray[9].img->enabled == true)
		i = 8;
	textureInfoArray[8].img->enabled = false;
	textureInfoArray[9].img->enabled = false;
	textureInfoArray[10].img->enabled = false;
	textureInfoArray[11].img->enabled = false;
	textureInfoArray[i].img->enabled = true;
	mapy.vit /= 0.999;
}
void	mouv_down(void)
{
	int	i;

	textureInfoArray[8].img->instances[0].y += 8;
	textureInfoArray[9].img->instances[0].y += 8;
	textureInfoArray[10].img->instances[0].y += 8;
	textureInfoArray[11].img->instances[0].y += 8;
	i = 0;
	if (textureInfoArray[8].img->enabled == true)
		i = 9;
	else if (textureInfoArray[9].img->enabled == true)
		i = 10;
	else if (textureInfoArray[10].img->enabled == true)
		i = 11;
	else if (textureInfoArray[11].img->enabled == true)
		i = 8;
	textureInfoArray[8].img->enabled = false;
	textureInfoArray[9].img->enabled = false;
	textureInfoArray[10].img->enabled = false;
	textureInfoArray[11].img->enabled = false;
	textureInfoArray[i].img->enabled = true;
	mapy.vit /= 0.999;
}

void	mouvBarrel(void)
{
	static unsigned long long	lastMoveTime = 0;
	unsigned long long			currentTime;
	static int					sens = 1;

	currentTime = getCurrentTimeInMilliseconds();
	if (currentTime - lastMoveTime >= mapy.vit)
	{
		if (isPositionValid(textureInfoArray[8].img->instances[0].x + 32,
				textureInfoArray[8].img->instances[0].y) && sens == 1)
			mouv_right();
		else if (isPositionValid(textureInfoArray[8].img->instances[0].x,
				textureInfoArray[8].img->instances[0].y + 32)
			&& ((textureInfoArray[8].img->instances[0].x + 32) % 32 == 0))
        {
			mouv_down();
            mapy.vit = 30;
        }
		else if (isPositionValid(textureInfoArray[8].img->instances[0].x - 8,
				textureInfoArray[8].img->instances[0].y))
		{
			mouv_left();
			sens = 0;
		}
		lastMoveTime = currentTime;
	}
}
