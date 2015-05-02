Linear-Algebra
==============
This Collection of code, is intended to represent most common and major Linear Algebra problems and solutions.
While giving me the opportunity to continue to learn C++ with Const correct style, and once complete will provide me 
a project to practice make commands and language.

Building
==============
To build run the following commands in the directory you wish to store the project.
The cmake command can take various options based on your desired configuration.
The following are the commands that can be set.

|Description            | Command                     |
|:---------------------:|:---------------------------:|
|Include unit tests     | -DBUILD\_TESTS=(TRUE|FALSE) |
|Include documentation  | -DBUILD\_DOCS=(TRUE|FALSE)  |

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
To make the tests you need to ensure you ran cmake with build tests on.
If you did not then run the following command in the build directory

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

Documentation
==============
I plan on uploading the documentation to the github wiki,
however if I haven't done it or it isn't up to date you can build it yourself.

To make the documentation you need to ensure you ran cmake with build docs on.
If you did not then run the following command in the build directory

```
cmake ../ -DBUILD_DOCS=TRUE
```

Once cmake is configured to build documentation, you can run

```
make docs
```

The documents will be stored in the build directory at docs/

They can be viewed in a web browser at

```
docs/html/index.html
```

or if prefer using latex by going

```
cd docs/latex
make
```

Latex must be installed on your system.

To-Do
==============
I plan on creating an demo project that will show how to link and use this library. Once this is done I will link to it from here.
