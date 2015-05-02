Linear-Algebra
==============
This Collection of code, is intended to represent most common and major Linear Algebra problems and solutions.
While giving me the opportunity to continue to learn C++ with Const correct style, and once complete will provide me 
a project to practice make commands and language.

Building
==============
To build run the following commands in the directory you wish to store the project.
The building of unit tests can be turned on by passing
-DBUILD\_TESTS=TRUE to the cmake command, or off by -DBUILD\_TESTS=FALSE
```
git clone https://github.com/StephenNu/Linear-Algebra.git
cd Linear-Algebra
mkdir build
cd build
cmake ../
make
```

Testing
==============
To make the tests you need to ensure you ran cmake with build tests on. If you did not then run the following command in the build directory
```
cmake ../ -DBUILD_TESTS=TRUE
```
Be forewarned this will download and install GTest and GMock for the unit tests usage.

Once cmake has been configured to build the tests and dependencies related to it, run
```
make check
```

or explicitly

```
make
make test
```
You can also run each test indivdually in the bin/ directory, all test executables end in \_test.

To-Do
==============
I plan on creating an demo project that will show how to link and use this library. Once this is done I will link to it from here.
