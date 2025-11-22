# libft

This is my implementation of C standard library with some useful functions.
Inspired by 42 libft project.

## Building

To build and use the library on your projects, do the following:

```console
git clone <repo>
cd libft
make re && make lib
```

For more detail, check the [Makefile](./Makefile), and feel free to edit it in your own needs.
It requires privileges to install it to `/usr/include` for header file, and to `/usr/lib` for the library itself.

## Disclaimer

This is a personal project, this means I don't guarantee any full functionality of the library.
I try to maximize memory safety by often checking with `valgrind` with memcheck at full,
any memory leak or buffer overflow, but some errors can still occur. I cannot be responsible for
any problem occurring with the usage of the library.

## License

See [LICENSE](./LICENSE).
