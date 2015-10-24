![](http://i.imgur.com/WoA2pWw.png)

![](https://img.shields.io/github/issues/joshhartigan/iu-coreutils.svg) ![](https://img.shields.io/badge/license-BSD-yellow.svg) ![](https://img.shields.io/badge/language-C-blue.svg)

These intend to follow a derivative of the original UNIX philosophy, with a
heavy emphasis on simplicity and straightforwardness.

[**The `iu` philosophy can be found here**](#philosophy)

**Installation**

You'll need **a C compiler** with support for the C99 or C11 standard; and the
**make** program. If you're on OS X, BSD, or Linux (or most POSIX systems) you
probably already have these, so don't worry yourself.

* To compile one of the single utilities by itself: run `make utility`
  (obviously replace 'utility' with `ls` or `cat` or whatever)

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

  * `*.c` - the actual programs for iu-coreutils
  * `include/` - headers for functionality that is shared throught the programs. This is
    told to the compiler, so you only need to use `#include "[file_name].h"` when `file_name.h`
    is in the include folder, rather than `#include "include/[file_name].h"`
  * `Makefile` - the compilation automation system. Run `make name` to compile
    the program `name.c`
  * `.gitignore` - a list of files for git to ignore (i.e the ones that don't
    need version control)

#### Philosophy

This is the [ 'philosophy' / 'guidelines' / 'rules' / 'regulations' /
'suggestions' ] that `iu` programs should follow. **It is a work in progress.**

* **Do one thing and do it well**.
* One program gets one C file.
  * Shared functionality between programs can be split between multiple file.
* Don't write the same function twice.
* Avoid #ifdef, #ifndef, and general preprocessor-ugliness
* Avoid using a variable name like `sz` when you could use `size`.
* Use comments often, whenever you think something might not be clear. Don't be
  pretentious about comment usage (i.e. *"My code is self-documenting"*)
