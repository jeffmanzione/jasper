# zinnia

A process virtual machine that I've created in my spare time.

The VM is written from scratch by me in C and meets the C90 standard. It compiles on Linux (via gcc) and Windows (via MSVC). I've heavily leveraged [Bazel](https://bazel.build/) to take advantage of incremental and fast builds.

## Dependencies

* [bazel](https://bazel.build/) - Compile and building the entire application.
* [language-tools](https://github.com/jeffmanzione/language-tools) - Creating the lexer, parser, and semanatic analyzer.
* [memory-wrapper](https://github.com/jeffmanzione/memory-wrapper) - Heap, intern, arena, and memory debugging.
* [file-utils](https://github.com/jeffmanzione/file-utils) - Basic C file wrapper for reading files.
* [c-data-structures](https://github.com/jeffmanzione/c-data-structures) - Some useful data structures.

## Downloading this project

Download the latest binaries released on GitHub.

## Building this project from source

| :exclamation: You will need to install Bazel to build the binaries. Follow the [Bazel installation instructions](https://bazel.build/install). I promise it is very easy to install! |
|-|

To build zinnia:

```shell
# Clones this git repository.
git clone https://github.com/jeffmanzione/zinnia.git

# Bazel requires building within the workspace.
cd zinnia

# Builds the compiler and runner.
bazel build -c opt //:all
```

## Compiling your program to assembly and bytecode

Use `zinniac` to compile your program.

* `-a`: Output assembly (default=`false`).
* `-b`: Output binary (default=`false`).
* `-o`: Optimize the program (default=`true`).
* `-binary_out_dir`: Output location of JB files (default=`"./"`).
* `-assembly_out_dir`: Output location for JA files (default=`"./"`).

```shell
zinniac -a -b my_program.zn
```

## Running your program

Use `zinnia` to run your program either from source, assembly, or bytecode.

```shell
zinnia my_program.zn
# or
zinnia my_program.zna
# or
zinnia my_program.znb
```

## Examples

Check out the [examples](https://github.com/jeffmanzione/zinnia/tree/master/examples).
