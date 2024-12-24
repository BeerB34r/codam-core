/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   environment_touchers.c                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/11 15:03:06 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/11 15:04:51 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <ft_env.h>

//	prints all environment variables, equivalent to shell builtin env without
//	any arguments
void
	mm_printenv(void)
{
	const char *const *const	env = borrow_env();
	int							i;

	i = -1;
	while (env && env[++i])
		printf("%s\n", env[i]);
}

int
	ush_execve(
const char *pathname,
const char **argv
)
{
	const char *const *const	env = borrow_env();

	return (execve(pathname, argv, env));
}
