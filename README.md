![](http://i.imgur.com/WoA2pWw.png)

![](https://img.shields.io/github/issues/joshhartigan/iu-coreutils.svg) ![](https://img.shields.io/badge/license-BSD-yellow.svg) ![](https://img.shields.io/badge/language-C-blue.svg)

*"better as in simpler"*

These intend to follow a derivative of the original UNIX philosophy, which will
eventually be documented in this repository.

**[PROGRAMS](#programs)** / A list of the utilities with brief descriptions

**Installation**

You'll need **a C compiler** with support for the C99 or C11 standard; and the
**make** program. If you're on OS X, BSD, or Linux (or most POSIX systems) you
probably already have these, so don't worry yourself.

* To compile one of the single utilities by itself: `make utility` (obviously
  replace 'utility' with `ls` or `cat` or whatever)
* To compile all of the utilities: `make`.

If you want to be able to run the commands from anywhere, they'll need to be in
your `PATH` environment variable. Thing is, you probably already have a program
called `cat` and `ls`, etc. in your `PATH`. So, in order to override those
conflicting programs, and use the `iu` coreutils, place the folder that you
compiled the programs in to the *beginning* of your `PATH`, not the end.

**Header Files**

Until it gets larger, I will not be using header files for this project.
As said above, each utility gets its own C file, in which the `main` function
comes first. Above the `main` function will be written the signatures of the
functions that follow.
  Placing the `main` function first is important because an entry point to the
program should also be an entry point to the file.

**Compilers**

I am using Clang, not GCC. Clang seems to me like it is a leaner and more
lightweight compiler - speaking of which, I may switch to TCC in the future for
this project.
  When building the `iu` coreutils, it's up to you which compiler you use; I'm
not going to take charge of your life. Just make sure you've set it as your
`CC` variable.

#### Programs

`cat` - sequentially read specified files and output the contents (to stdout by
default).

`lnum` - prepend line numbers to the input. can be used as a filter (e.g.
`cat file.txt | lnum`), can be applied directly to files (`lnum file.txt`).
Chooses `stdin` by default, when run with no arguments.

`ls` - lists files in the directories specified. `-a` option includes hidden
files.

