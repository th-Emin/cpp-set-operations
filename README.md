# C++ Set Operation

This is a simple C++ program that performs basic set operations based on set membership logic.
It was originally written for the MAHT2162 Discrete Mathematics Assignment at Istanbul University.

The program defines a `Set` struct and uses a boolean array to represent which elements from a predefined Universal Set (U) are members of the set.

## Operation Supported

- Union (|)
- Intersection (&)
- Complement (!)
- Difference (-)

## Compiling

This code is written using C++23 standards, specifically for the C++ standard library module (`import std;`).
You will need a C++23 compatible compiler (like GCC 13+ or Clang 17+) and to compile it with module support.

For older compilers, you would need to replace import std; with the traditional headers (`#include <iostream>`, `#include <stdexcept>`, etc.) as seen commented out in the code.

## Current Limitations

This is a basic implementation for a specific assignment and has several limitations:

- Sets can only contain integer elements.
- Once a set is created, elements cannot be added or removed.
- All sets must share the exact same Universal Set instance.
