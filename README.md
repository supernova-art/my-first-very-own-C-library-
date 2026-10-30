*This project has been created as part of the 42 curriculum by yait-elm.*

# Libft

## Description

**Libft** is the first project of the 42 common core. The goal is to build, from scratch and in C, a static library (libft.a) containing general-purpose functions that will be reused in every later project of the curriculum.

The project is split into three parts:

1. **Libc functions** — re-implementation of standard functions, with the same prototypes and behavior as the originals (as described in their man pages), but prefixed with ft_.
2. **Additional functions** — utility functions that are not in the libc, or that exist in a different form (string manipulation, number conversion, file-descriptor output).
3. **Linked list** — a 't_list' structure and the functions to manipulate it.

Constraints followed: written in C, compliant with the 42 Norm, compiled with `-Wall -Wextra -Werror`, no global variables, helper functions declared `static`, library built with `ar` (no `libtool`), no memory leaks.

## Instructions

-- Compilation

make        # builds libft.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and libft.a
make re     # fclean + all


The Makefile provides the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`, and does not relink if nothing changed.

-- Usage in your own project

1. Include the header:

   #include "libft.h"

2. Compile and link against the library:

   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program

-- Example

#include "libft.h"

int main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello 42 world", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}


## Resources

- `man 3` pages of each re-implemented function (`man strlen`, `man memmove`, `man strlcpy`, ...)
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) — Kernighan & Ritchie
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [42 Norm](https://github.com/42School/norminette)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [Makefile] : (https://makefiletutorial.com/)
- Peer-learning with other students (1337 Khouribga).

- Use of AI : 
	AI was used in this project as a learning and review aid, not as a code generator. All the functions of the library were written and understood by me.

	- **Understanding concepts:** to clarify notions needed for the project, such as how `malloc`/`free` and memory ownership work, pointers and pointer casting, `unsigned char` vs `char`, overlapping memory in `memmove`, how static libraries and `ar` work, and how Makefile rules and relinking behave. This was used across the whole project (Parts 1, 2 and 3).
	- **Debugging:** to help understand error messages, warnings and unexpected behavior (e.g. compilation errors with `-Wall -Wextra -Werror`, edge cases in `ft_atoi`, `ft_itoa`, `ft_split`, `ft_strlcat`), and to find the cause before fixing the code myself.
	- **Testing and review:** to suggest edge cases to test (empty strings, `INT_MIN`/`INT_MAX`, `NULL` pointers, overlapping buffers, allocation failures), to check for memory leaks, and to review the code against the subject and the Norm (e.g. non-static helpers, prototypes, formatting).
	- **Documentation:** AI helped me in this one by suggesting some C Documentation & tutorials .


