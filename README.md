<<<<<<< HEAD
# my-first-very-own-C-library-
=======
*This project has been created as part of the 42 curriculum by yait-elm.*

# Libft — My very first own library

## Description

**Libft** is the first project of the 42 common core. The goal is to build, from scratch and in C, a static library (libft.a) containing general-purpose functions that will be reused in every later project of the curriculum.

The project is split into three parts:

1. **Libc functions** — re-implementation of standard functions, with the same prototypes and behavior as the originals (as described in their man pages), but prefixed with ft_.
2. **Additional functions** — utility functions that are not in the libc, or that exist in a different form (string manipulation, number conversion, file-descriptor output).
3. **Linked list** — a 't_list' structure and the functions to manipulate it.

Constraints followed: written in C, compliant with the 42 Norm, compiled with `-Wall -Wextra -Werror`, no global variables, helper functions declared `static`, library built with `ar` (no `libtool`), no memory leaks.

## Instructions

### Compilation

make        # builds libft.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and libft.a
make re     # fclean + all


The Makefile provides the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`, and does not relink if nothing changed.

### Usage in your own project

1. Include the header:

   #include "libft.h"

2. Compile and link against the library:

   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program

### Example

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

## Library content

### Part 1 — Libc functions
- **Character checks:** 'ft_isalpha', 'ft_isdigit', 'ft_isalnum', 'ft_isascii', 'ft_isprint'.
- **Character conversion:** 'ft_toupper', 'ft_tolower'.
- **Strings:** 'ft_strlen', 'ft_strlcpy', 'ft_strlcat', 'ft_strchr', 'ft_strrchr', 'ft_strncmp', 'ft_strnstr', 'ft_atoi'.
- **Memory:** 'ft_memset','ft_bzero', 'ft_memcpy', 'ft_memmove', 'ft_memchr', 'ft_memcmp'.
- **Allocation (malloc):** 'ft_calloc', 'ft_strdup'.

### Part 2 — Additional functions

- 'ft_substr': returns a substring of `s` starting at `start`, of at most `len` characters.
- 'ft_strjoin': returns a new string made of `s1` followed by `s2`.
- 'ft_strtrim': returns a copy of `s1` with the characters of `set` removed from both ends.
- 'ft_split': splits `s` using the delimiter `c`; returns a NULL-terminated array of strings.
- 'ft_itoa': converts an integer to a string (negative numbers handled).
- 'ft_strmapi': applies 'f(index, char)' to each character and returns the new string.
- 'ft_striteri': applies 'f(index, &char)' to each character of `s` in place.
- 'ft_putchar_fd': writes a character on a file descriptor.
- 'ft_putstr_fd': writes a string on a file descriptor.
- 'ft_putendl_fd': writes a string followed by a newline on a file descriptor.
- 'ft_putnbr_fd': writes an integer on a file descriptor.

### Part 3 — Linked list

Structure used : 

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


Functions:

- 'ft_lstnew': creates a new node with the given content; `next` is `NULL`.
- 'ft_lstadd_front': adds a node at the beginning of the list.
- 'ft_lstsize': counts the nodes of the list.
- 'ft_lstlast': returns the last node.
- 'ft_lstadd_back': adds a node at the end of the list.
- 'ft_lstdelone': frees one node's content (with `del`) and the node itself.
- 'ft_lstclear': deletes and frees a node and all its successors, then sets the list pointer to `NULL`.
- 'ft_lstiter': applies a function to the content of each node.
- 'ft_lstmap': builds a new list by applying a function to each node's content (uses `del` on failure).

## Technical choices

- Helper functions are `static` and limited to the file that uses them.
- Allocation failures are handled: functions return `NULL` and free anything already allocated (e.g. `ft_split`, `ft_lstmap`).
- `ft_calloc` returns a unique pointer that can be passed to `free()` when `nmemb` or `size` is 0, as required by the subject.
- The library is built with `ar rcs` into `libft.a` at the root of the repository.

## Resources

### References

- `man 3` pages of each re-implemented function (`man strlen`, `man memmove`, `man strlcpy`, ...)
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) — Kernighan & Ritchie
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [42 Norm](https://github.com/42School/norminette)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [Makefile] : (https://makefiletutorial.com/)
- Peer-learning with other students (1337 Khouribga).


### Use of AI

AI was used in this project as a learning and review aid, not as a code generator. All the functions of the library were written and understood by me.

- **Understanding concepts:** to clarify notions needed for the project, such as how `malloc`/`free` and memory ownership work, pointers and pointer casting, `unsigned char` vs `char`, overlapping memory in `memmove`, how static libraries and `ar` work, and how Makefile rules and relinking behave. This was used across the whole project (Parts 1, 2 and 3).
- **Debugging:** to help understand error messages, warnings and unexpected behavior (e.g. compilation errors with `-Wall -Wextra -Werror`, edge cases in `ft_atoi`, `ft_itoa`, `ft_split`, `ft_strlcat`), and to find the cause before fixing the code myself.
- **Testing and review:** to suggest edge cases to test (empty strings, `INT_MIN`/`INT_MAX`, `NULL` pointers, overlapping buffers, allocation failures), to check for memory leaks, and to review the code against the subject and the Norm (e.g. non-static helpers, prototypes, formatting).
- **Documentation:** AI helped me in this one by suggesting some C Documentation & tutorials .
>>>>>>> 3e68553 (initial commit)
