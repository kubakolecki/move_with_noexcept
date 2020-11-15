# move_with_noexcept

In this repo we can test how the noexcept specifer impact the time performance.
To test comment/uncomment line #2 in defnoexcept.h

Using noexcept causes program to use move constructor instead of copy constructor when realocating memory when more and more data are pushed into the vector.
However if we deffine the move constructor using =defalut, it means the noexcept specifer is also included.

Requirements: C++17


