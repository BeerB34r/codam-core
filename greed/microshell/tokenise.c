/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   tokenise.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/11 14:24:50 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/11 18:43:23 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

//	Bash tokens are either WORDs or OPERATORs, and the sole determining factor
//	is wether or not the sequence of characters contains an unquoted
//	metacharacter. for convenience, that set of characters is now a macro.

#define METACHARACTERS " \t\n|&;()<>"

const char *ctl_op[] = {
						"||",
						"&&",
						"&",
						";",
						";;",
						";&",
						";;&",
						"|",
						"|&",
						"(",
						")"
						};

const char *rdr_op[] = {
						">",	// '[n] > word'
						"&>",	// redir stdout && stderr to
						">&",	// alternative to previous
						};

static int
	count_tokens(
const char *input
)
{
	int	count;
	int	previous;

	i = 0;
	previous = 1;
	while (input && *input)
	{
		if (ft_isinset(METACHARACTERS) != -1)
		{
		}
		else
		{
		}
	}
}

const char
	**tokenise(
const char *input
)
{
}
