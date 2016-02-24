bin_game_mvc
============

[![Build Status][build-status]][travis]
[![License][license]](LICENSE)

It's a C++ version of [2048 game][2048] (with modified
[game rules](ABOUT.md)) with bot and many other features.

Console and GUI modes are possible.

Run dependencies
----------------

 - Qt library (version 4.6+)
 - Standard library of C language
 - Standard library of C++ language
 - lua
 - luabind

Build dependencies
------------------

**Warning**. Make sure you use the same Lua which luabind
was linked against. Otherwise it compiles but results in
memory error.

 - All the run dependencies
 - cmake
 - make
 - C++ compiler

How to build (Linux)
--------------------

```bash
$ mkdir build-dir
$ cd build-dir
$ cmake /path/to/bin_game_mvc
$ make
```

[2048]: https://gabrielecirulli.github.io/2048/
[license]: https://img.shields.io/badge/License-MIT-brightgreen.png
[travis]: https://travis-ci.org/zer0main/bin_game_mvc
[build-status]: https://travis-ci.org/zer0main/bin_game_mvc.png?branch=master
