# get_next_line
GNL is a function that reads file line by line, one line per function call, without loosing progress.

# Project description
As a part of 21 school (aka 42 school) projects, this project has some special requirements, and must be prototyped as:
```sh
int get_next_line(int const fd, char **line);
```
- The first parameter is the file descriptor that will be used to read
- The second parameter is the address of a pointer to a character that will be used to save the line read from the file descriptor
- Function get_next_line must return its result without ’\n’
- You can only use those three standard library functions: `read`, `malloc`, `free`. Other functions should be in your own С library (libft).
- Function returns `-1` when error occurs (like cannot open file etc.), `1` when the line reading is successful, `0` when function reaches end of file (EOF).

# Test!
Run `./get_next_line tom_sawyer.txt` or `./get_next_line war_and_peace.txt` or use other files.

![Image alt](https://github.com/randomaru/get_next_line/raw/master/gnl_gif.gif)
