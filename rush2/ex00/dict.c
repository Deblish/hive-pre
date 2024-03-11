/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:10:48 by alaakson          #+#    #+#             */
/*   Updated: 2024/03/03 11:39:26 by srautvuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct Dict
{
	void *key;
	void *value;
}

struct Dict dict_constructor(void *key, int key_size, void *value, int value_size)
{
	struct Dict dict;
	dict.key = malloc(key_size);
	dict.value - malloc(value_size);
	

	return (dict);
}

void	dict_deconstructor(struct Dict *dict);
{
	free(dict->key);
	free(dict->value);
	free(dict);
}
