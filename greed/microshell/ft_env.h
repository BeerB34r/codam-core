/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_env.h                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/09 15:52:37 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/11 15:05:48 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_ENV_H
# define FT_ENV_H
//	equivalent to stdlib getenv()
const char
	*mm_getenv(
		const char *name
		);	// FILE: environment.c
//	equivalent to stdlib setenv()
int		
	mm_setenv(
		const char *name,
		const char *value
		);	// FILE: environment.c
//	equivalent to stdlib clearenv()
void	
	mm_clearenv(void);	// FILE: environment.c
//	used for functions that have to touch the *entire* environment (env, execve)
const char *const *const
	borrow_env(void);	// FILE: environment.c
#endif
