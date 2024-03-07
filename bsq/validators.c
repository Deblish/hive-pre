/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   validators.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: djelacik <djelacik@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/06 16:10:09 by djelacik		  #+#	#+#			 */
/*   Updated: 2024/03/06 21:45:30 by djelacik         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

int	ft_validate_all(char *box, struct map_info info)
{
	if (ft_if_info_differs(info) == 0)
		return (0);
	if (ft_box_has_valid_characters(box, info) == 0)
		return (0);
	if (ft_box_has_valid_lines(box, info) == 0)
		return (0);
	if (check_new_line(box, info) == 0)
		return (0);
	return (1);
}

int	ft_if_info_differs(struct map_info info)
{
	if (info.empty_char == info.obstacle_char
		|| info.empty_char == info.full_char
		|| info.obstacle_char == info.full_char)
		return (0);
	return (1);
}

int	ft_box_has_valid_characters(char *box, struct map_info info)
{
	int	i;

	i = 0;
	while (box[i] != '\0')
	{
		if (box[i] != info.empty_char && box[i] != info.obstacle_char)
			return (0);
		i++;
	}
	return (1);
}

int	ft_box_has_valid_lines(char *box, struct map_info info)
{
	int	i;
	int	line_count;
	int	line_size;

	i = 0;
	line_count = 0;
	while (box[i] != '\0')
	{
		line_size = 0;
		while (box[i] != '\n')
		{
			line_size++;
			i++;
		}
		if (line_size != info.line_size)
			return (0);
		line_count++;
		i++;
	}
	if (line_count != info.num_lines)
		return (0);
	return (1);
}

int	check_new_line(char *box, struct map_info info)
{
	int	i;
	int	line_count;

	i = 0;
	line_count = 0;
	while (box[i] != '\0')
	{
		if (box[i] == '\n')
			line_count++;
		i++;
	}
	if (line_count != info.num_lines)
		return (0);
	return (1);
}
