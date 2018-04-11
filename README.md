# {{PROJECT_NAME}}

Template project for embedded C/C++.

## Getting Started

1. Fork or clone the repository.
2. Change the name of the project in the [README.md](README.md).
3. Change the Getting Started, Prerequisites, Installation guide, Style guide in the [README.md](README.md).
5. Change the [LICENSE.md](LICENSE.md) to your license.
6. Change the {{license}} in the [README.md](README.md).
7. ???
8. Profit.

## Prerequisites

* GNUMake.
* An editor.
* GCC compiler tool chain (arm-none-eabi)
* Git
* Doxygen

## Building the project

The project can be build just by calling make like this:

```bash
$ make 
```

### Overriding build type

The project has two destinctive build types "DEBUG" and "RELEASE".
Which to use is determined by the BUILD_TYPE variable in the makefile.
This variable can be overriden by calling make like this:

```bash
$ make BUILD_TYPE=DEBUG
```

for debug, or

```bash
$ make BUILD_TYPE=RELEASE
```

for a release build.

## Installing

## Style

### C/C++

## Directory structure
``.``  
``├── build/``  
``├── make/``  
``├─┬ doc/``  
``│ └─── Doxyfile``  
``├─┬ link/``  
``│ └─── stm32f030x4.ld``  
``├── include/``  
``├── src/``  
``├── LICENCE.md``  
``└── README.md``  

### ``.`` Directory

The root of the project.

### ``build/`` Directory

The directory in which all build products will be places.

### ``make/`` Directory

The directory in which all excess makefiles are supposed to be places.

### ``doc/`` Directory

The directory in which all documentation is supposed to be places.

### ``doc/Doxyfile`` File

### ``link/`` Directory

The directory in which all linkerscripts supposed to be places.

### ``link/stm32f030x4.ld`` File

The linkerscript for the stm32f030x4 microcontroller.

### ``include/`` Directory

The directory in which C/C++ header files are supposed to be placed.

### ``src/`` Directory

The directory in which source code files are supposed to be placed.

### ``LICENCE.md`` File

A Markdown file in which the software licence is to be placed.

### ``README.md`` File

A Markdown file in which README information is to be placed.

## Versioning

This repository uses [SemVer](http://semver.org) for versioning. For the versions available, see the [releases](releases)

## Authors

* **Tom Verloop** - *Initial work* - [TVerloop](https://github.com/TVerloop)

## License

This project is licensed under {{License}} - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgements

* **Billie Thompson** - *Readme template* - [PurpleBooth](https://github.com/PurpleBooth)
