![](http://i.imgur.com/WoA2pWw.png)

![](https://img.shields.io/github/issues/joshhartigan/iu-coreutils.svg) ![](https://img.shields.io/badge/license-BSD-yellow.svg) ![](https://img.shields.io/badge/language-C-blue.svg)

*"better as in simpler"*

These intend to follow a derivative of the original UNIX philosophy, which will
eventually be documented in this repository.

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

**Programs**

`cat` - sequentially read specified files and output the contents (to stdout by
default).

`lnum` - prepend line numbers to the input. can be used as a filter (e.g.
`cat file.txt | lnum`), can be applied directly to files (`lnum file.txt`).
Chooses `stdin` by default, when run with no arguments.

`ls` - lists files in the directories specified. `-a` option includes hidden
files.

**Code Base**

The code base is simple and easy to understand.

  * `./\*.c` - the actual programs for iu-coreutils
  * `common/` and include/ - code and headers for functionality that is shared
    throught the programs
  * `Makefile` - the compilation automation system. Run `make` to compile all
    the programs
  * `bin/` - the folder in which compiled binaries are placed.
  * `.gitignore` - a list of files for git to ignore (i.e the ones that don't
    need version control)

