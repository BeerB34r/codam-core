# minishell

## notes

### tokenisation
control operators are easy shpeecy, just check which string it precisely matches

rdr_ops will work similarly, but might touch various other words nearby. the
operator itself is easy to delimit, but in cleaning up output for the purposes
of execve, the previous and next word _might_ be affected. the main offenders
are words that consist solely of digits.

#### redir op notes
'[n]< _word_'
	- keep in mind that n is optional,
'[n]> _word_'
	- keep in mind that n is optional, and only applies if the previous
	  __non-delimited__ word contains ONLY digits, periods not allowed.
	  word should be consumed, and an error message displayed if not given.
	- if n is unspecified, it is equal to 1


## function quickref

### readline gang <stdio.h> <readline/readline.h> <readline/history.h>
- readline
	- reads line from stdin, outputs const char * parameter to stdout first
- rl_clear_history
- rl_on_new_line
	- clears whatever the user put into the prompt from the buffer, essentially resetting the prompt
- rl_replace_line
	- kinda weird. replaces current buffer with whatever is passed to it, but if you then type, the replacement is instead _appended_ to the buffer
- rl_redisplay
	- redisplays the prompt and anything in the buffer
- add_history
	- lets you access the history. history does not persist between processes
### the standard stuff
- printf
- malloc
- free
- write
- access
- open
- read
- close
### the forkbomb section
- fork
- wait
- waitpid
- wait3
- wait4
### the signal suite
- signal
- sigaction
- sigemptyset
- sigaddset
- kill
### program management
- exit
- getcwd
- chdir
- stat
- lstat
- fstat
- unlink
- execve
	- envp??????? ig we storing the environment as a pointer to strings now
- dup
- dup2
- pipe
- opendir
- readdir
- closedir
- strerror
	- i love error messages
- perror
- isatty
- ttyname
- ttyslot
- ioctl
- getenv
	- this one will exclusively be used to fill the inevitable getters and setters that are needed to have a proper environment
	- WRONG, this is used a total of ZERO times, we have our own GETENV with
	  BLACKJACK AND HOOKERS
- tcsetattr
- tcgetattr
- tgetent
- tgetflag
- tgetnum
- tgetstr
- tgoto
- tputs
- libft
