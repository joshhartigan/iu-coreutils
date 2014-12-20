![](http://i.imgur.com/WoA2pWw.png)

![](https://img.shields.io/github/issues/joshhartigan/iu-coreutils.svg) ![](https://img.shields.io/badge/license-BSD-yellow.svg) ![](https://img.shields.io/badge/language-C-blue.svg)

*"better, simpler coreutils"*

These intend to follow a derivative of the original UNIX philosophy, which will
eventually be documented in this repository.

**[PROGRAMS](#programs)** / A list of the utilities with brief descriptions

**Buildfile**

Shell scripting follows a simpler philosophy than using `make`, so I have
written the `Buildfile` script to compile files. The usage is simple:

`$ ./Buildfile FILE.c`

The above command will attempt to compile `FILE.c`, show any warnings that may
arise, and output the executable to `FILE`.
  The reason I will not need to link executables together is because each
utility in this collection will be in its own contained C files.
  When run with no arguments, the Buildfile will compile all `.c` files in the
directory.

**Header Files**

I will not be using header files for this project. As said above, each utility
gets its own C file, in which the `main` function comes first. Above the `main`
function will be written the signatures of the functions that follow.
  Placing the `main` function first is important because an entry point to the
program should also be an entry point to the file.

**Compilers**

I am using Clang, not GCC. Clang seems to me like it is a leaner and more
lightweight compiler - speaking of which, I may switch to TCC in the future for
this project.

#### Programs

`cat` - sequentially read specified files and output the contents (to stdout by
default).

`lnum` - prepend line numbers to the input. can be used as a filter (e.g.
`cat file.txt | lnum`), can be applied directly to files (`lnum file.txt`).
Chooses `stdin` by default, when run with no arguments.

`ls` - lists files in the directories specified. `-a` option includes hidden
files.

