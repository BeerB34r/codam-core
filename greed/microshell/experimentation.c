#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <ft_env.h>

void
	goobye(
int signo,
siginfo_t *siginfo,
void *context
)
{
	const char	*replacement = "get replaced on lmao";

	(void)context;
	(void)siginfo;
	(void)signo;
	rl_on_new_line();
	rl_replace_line(replacement, 0);
	rl_redisplay();
	printf("\e[%zuG", 1 + strlen(replacement) + strlen(mm_getenv("PS1")));
	//printf("sigquit recieved, exiting minishell\n");
	//exit(0);
	//in actual implementation this should be ignored
}

void
	new_prompt(
int signo,
siginfo_t *siginfo,
void *context
)
{
	(void)context;
	(void)siginfo;
	(void)signo;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void
	attach_handler(
struct sigaction *handler,
void (*function)(int, siginfo_t *, void *),
int signal
)
{
	sigemptyset(&(handler->sa_mask));
	sigaddset(&(handler->sa_mask), signal);
	handler->sa_flags = (SA_SIGINFO | SA_RESTART);
	handler->sa_sigaction = function;
	sigaction(signal, handler, NULL);
}

void
	set_defaults(void)
{
	if (!mm_getenv("PS1"))
		mm_setenv("PS1", "microshell% ");
}

int
	main(
void
)
{
	char				*line;
	struct sigaction	sigint;
	struct sigaction	sigquit;

	attach_handler(&sigint, &new_prompt, SIGINT);
	attach_handler(&sigquit, &goobye, SIGQUIT);
	printf("PID %d\n", getpid());
	set_defaults();
	while (1)
	{
		line = readline(mm_getenv("PS1"));
		if (!line)
			exit(0);
		else if (!strcmp("clear", line))
		{
			rl_clear_history();
			free(line);
		}
		else
		{
			printf("line is: \"%s\"\n", line);
			add_history(line);
			free(line);
		}
	}
}
