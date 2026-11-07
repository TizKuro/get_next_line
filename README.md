*This project has been created as part of the 42 curriculum by trmorand*
# get_next_line

## Description

`get_next_line` is the third project of the 42 Common Core.

The goal is to write a function that returns the next line of a file descriptor each time it is called, including the terminating `\n` when there is one. It can read from a file or from standard input, and it must work with any `BUFFER_SIZE` defined at compile time.

The project is written in C and follows the 42 Norm.

## Functions

| Function | Description |
|:---|:---|
| `ft_free` | Frees the buffer and the stash. |
| `read_to_stash` | Reads from the file descriptor and appends the data to the stash until a `\n` is found or the end of file is reached. |
| `extract_line` | Extracts the line from the stash, up to and including the `\n` (or up to the end of the text). |
| `clean_stash` | Removes the extracted line from the stash, keeping the remainder for the next call. |
| `get_next_line` | Calls the functions above and returns the next line, or `NULL` when there is nothing left to read or on error. |

## Algorithm and data structures

The function relies on a `static` variable, the **stash**, which keeps the data that has been read but not yet returned. It persists between calls.

On each call to `get_next_line`:

1. **Read**: `BUFFER_SIZE` bytes are read with `read()` and appended to the stash, until the stash contains a `\n` or `read()` returns `0` (end of file). If `read()` returns `-1`, the stash is freed and `NULL` is returned.
2. **Extract**: the stash is scanned for the first `\n`, and everything up to and including it is copied into a new string, which is the line to return. If there is no `\n` (end of file), the remaining text is returned as is.
3. **Clean**: the part of the stash after the `\n` is kept for the next call, and the old stash is freed.
4. **Return** the line, or `NULL` if there is nothing left or if an error occurred.

The stash is a simple dynamically allocated string. Since `read()` consumes the data and `lseek` is forbidden, the stash keeps what was read beyond the `\n` so that it is available at the next call. This works with any `BUFFER_SIZE`.

## Instructions

Compile the sources with the desired buffer size.

To build the object files:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
```

To build an executable with your own `main.c`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Include the header in your own code:

```c
#include "get_next_line.h"
```

## Resources

- `man 2 read`
- [understanding get_next_line](https://www.youtube.com/watch?v=-Mt2FdJjVno) (video by nikito)

### Use of AI

I used an AI assistant `Claude` during this project for the following tasks:

- understanding how `static` variables behave between calls
- proofreading and correcting this README.

All the code was written by me.
