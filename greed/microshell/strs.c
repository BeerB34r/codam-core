/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   strs.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/09 13:53:11 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/09 16:42:03 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void free_ar(char **ar);	// TODO: move into header

int	
	str_ar_len(
const char **str_ar
)
{
	int	i;

	i = -1;
	while (str_ar[++i])
		;
	return (i);
}
void
	free_ar(
char **ar
)
{
	int	i;
	
	i = -1;
	while (ar[++i])
		free(ar[i]);
	free(ar);
}
char
	**dup_str_ar(
const char **str_ar
)
{
	char	**ret;
	int		i;

	if (str_ar)
		ret = ft_calloc(str_ar_len(str_ar), sizeof(char *));
	else
		return (NULL);
	i = -1;
	if (!ret)
		return (NULL);
	while (str_ar[++i])
	{
		ret[i] = ft_strdup(str_ar[i]);
		if (!ret[i])
			return (free_ar(ret), NULL);
	}
	ret[i] = NULL;
	return (ret);
}
