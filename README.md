![](http://i.imgur.com/raSVxN0.png)

*"better, simpler coreutils"*

These intend to follow a derivative of the original UNIX philosophy, which will
eventually be documented in this README.

**Buildfile**

Shell scripting follows a simpler philosophy than using `make`, so I have
written the `Buildfile` script to compile files. The usage is simple:

`$ ./Buildfile FILE.c`

The above command will attempt to compile `FILE.c`, show any warnings that may
arise, and output the executable to `FILE`.
  The reason I will not need to link executables together is because each
utility in this collection will be in its own contained C files.

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

