# Building with CMake
 1. Clone this repository
 2. [Download and install the latest version of CMake](https://cmake.org/download/)
 3. From a command line in the source directory run the following:
    - ` sudo "/Applications/CMake.app/Contents/bin/cmake-gui" --install`
    - `mkdir build`
    - `cd build`
    - `cmake ..`
 4. Open the resulting directory/files in the CMake GUI
 5. Select `Advanced`.
 6. Search `rpath` in the search box and turn on `CMAKE_SKIP_INSTALL_RPATH` and `CMAKE_SKIP_RPATH`.
 7. Click `Configure`.
 8. Click `Generate`.
 9. Return to the commandline and run: `make`
10. The binary will be placed in `build/libproxy`. Rename the dylib to `libproxy.1.dylib`