/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   environment.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/06 18:37:59 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/16 16:24:07 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <libft.h>

extern char	**environ;	// There is a specific edge case in norminette for this
char	**dup_str_ar(char **str_ar);	// TODO: move into header
int		str_ar_len(char **str_ar);		// TODO: move into header

//	Holds the entirety of our environment, as youre not allowed to touch it
//	otherwise. thus, it is duped and kept in a nice enclosure where only *some*
//	functions are allowed to touch it. and even then under strict supervision
static char
	***env_holder(void)
{
	static char	**envp = NULL;
	static int	initialised = 0;

	if (!initialised)
	{
		envp = dup_str_ar(environ);
		initialised = 1;
	}
	return (&envp);
}

//	used exclusively by functions that require the entire env at once e.g.:
//	(printenv, execve)
const char *const *const
	borrow_env(void)
{
	return ((const char *const *const)*env_holder());
}

//	helper for mm_setenv(), deletes a variable from the environment.
static int	
	mm_delenv(
const char *name
)
{
	char ***const	env = env_holder();
	char **const	new_env = ft_calloc(str_ar_len(*env), sizeof(char *));
	int				i;
	int				j;

	if (!new_env)
		return (perror("Malloc error environ\n"), -1);
	i = -1;
	j = 0;
	while (*env && (*env)[++i])
	{
		if (ft_strncmp((*env)[i], name, ft_strlen(name)))
			new_env[j++] = (*env)[i];
		else
			free((*env)[i]);
	}
	free(*env);
	*env = new_env;
	return (0);
}

//	equivalent to the stdlib function setenv()
//	to delete an env variable, call with value = NULL
//	NOTE: to declare a variable without giving it a value, call as follows:
//		`mm_setenv(VARNAME, "")`
int	
	mm_setenv(
const char *name,
const char *value
)
{
	char ***const	env = env_holder();
	char			*var;
	char			**new_env;
	int				i;

	if (!name)
		return (perror("Nameless variable cannot be set\n"), 1);
	if (!value)
		return (mm_delenv(name));
	var = ft_calloc(ft_strlen(name) + ft_strlen(value) + 2, sizeof(char));
	if (!var)
		return (perror("Malloc error environ\n"), 2);
	sprintf(var, "%s%c%s", name, '=', value);
	i = -1;
	while (*env && (*env)[++i])
		if (!ft_strncmp((*env)[i], name, ft_strlen(name)))
			return (free((*env)[i]), ((*env)[i] = var), 0);
	new_env = (char **)ft_calloc(str_ar_len(*env) + 2, sizeof(char *));
	if (!new_env)
		return (perror("Malloc error environ\n"), free(var), 2);
	new_env[i] = var;
	while (i-- > 0)
		new_env[i] = (*env)[i];
	return (free(*env), (*env = new_env), 0);
}

//	equivalent to the stdib function clearenv()
void
	mm_clearenv(void)
{
	char ***const	env = env_holder();
	const char		**arr = (const char **)*env;

	while (arr && *arr)
		free((void *)*arr++);
	free(*env);
	*env = NULL;
}
