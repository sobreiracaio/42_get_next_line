# get_next_line
This project is an implementation of a function named get_next_line, which reads and returns a line from a file descriptor each time it is called, until it reaches the end of the file.

## How it Work

The get_next_line function reads one line from the file descriptor fd each time it is called.
The function returns a pointer to a string containing the line that was read, without the newline character `\n`.
The function returns `NULL` when the end of file is reached or an error occurs.
The function uses a `static variable` to store the remaining characters from the previous call, if any.
