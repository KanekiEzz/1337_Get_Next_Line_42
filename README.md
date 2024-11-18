<h1 align="center">Get Next Line - 42 kaneki</h1>
<p align="center">
  <a href="https://github.com/KanekiEzz/1337_Get_Next_Line_42">
    <img src="https://raw.githubusercontent.com/KanekiEzz/kaneki_badges/refs/heads/main/get_next_linem.png" alt="42 Badge">
  </a>
</p>
<h2 >Introduction</h2>
## 📝 Description
A C function that reads a line from a file descriptor. This project introduces the concept of static variables in C programming while creating a useful function for reading content line by line.

## 🎯 Function Prototype
```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- Returns the line that was read (including the terminating `\n` character, except at EOF)
- Returns `NULL` if there is nothing else to read or if an error occurred

## ⚙️ Technical Considerations
- The function works with both file reading and standard input
- Can handle multiple file descriptors (bonus part)
- Buffer size can be modified during compilation using `-D BUFFER_SIZE=n`
- No forbidden functions used (no lseek)
- No global variables
- Memory is properly freed to avoid leaks

## 📁 Files
### Mandatory
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

### Bonus
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

## 🛠️ Compilation
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

## ✨ Features
### Mandatory
- Read text from a file descriptor, one line at a time
- Handle varying buffer sizes
- Proper memory management
- Works with standard input and files

### Bonus
- Uses only one static variable
- Can manage multiple file descriptors simultaneously

## 🚨 Implementation Notes
- The returned line includes the terminating `\n` character (except at EOF)
- The function has undefined behavior if:
  - The file pointed to by the file descriptor changes between calls and read() hasn't reached EOF
  - Reading a binary file
- Efficient reading: reads as little as possible each time the function is called

## 📚 Resources
- Static variables in C
- File descriptors
- Memory management
- Buffer manipulation

## 🎓 Learning Outcomes
- Understanding static variables
- File manipulation in C
- Memory management
- Buffer handling
- Working with file descriptors

## ⚠️ Requirements
- C compiler
- Unix-based system (for file descriptors)
- Make (for compilation)



# while true; do leaks a.out; sleep 2; clear; done