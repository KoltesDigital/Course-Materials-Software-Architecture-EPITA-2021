# Software Architecture Applied To Game Engines - EPITA 2020

This repository contains the materials for the course on software architecture. It features a game project, whose architecture is a lighter version of industrial-grade ones.

The project's code contains voluntary errors and design flaws which are addressed during the classes. The repository is updated after every class, in order to reflect the evolution of its code.

## Installation

The following tools are required:

1. [Premake 5](https://premake.github.io/download.html)
2. [Visual Studio 2017 or higher](https://www.visualstudio.com/downloads/)

If you're not on Windows, or cannot use Visual Studio, Premake allows to use other toolchains, please read its documentation.

## Build

Open a terminal in _StealthFactor_ directory and follow the instructions for your platform.

### Windows

    premake5.exe vs2019

Open _build\StealthFactor.sln_, choose your target, and build.

### Linux

    apt-get install -y g++ g++-multilib libode-dev libsfml-dev make
    premake5 gmake2
    cd build
    make config=release_linux64

## External dependencies

In order to simplify installation of the project, the repository contains parts of external projects, in source code form or executable form.

Although the code should support multiple platforms, only precompiled libraries for Windows are provided.

1. [cli.cpp](https://github.com/KoltesDigital/cli.cpp), a CLI argument parser (header-only)
2. [GoogleTest](https://github.com/google/googletest), a test framework
3. [json](https://github.com/nlohmann/json), a JSON parser (header-only)
4. [ODE](http://www.ode.org/), a physics engine
5. [pugixml](http://pugixml.org/), an XML parser (header-only)
6. [SFML](https://www.sfml-dev.org/), a small multimedia framework

## Session #1

- Why do we need architecture and code quality anyway?
- Architecture principle: rely on lower level, cannot access to higher level.
- Overview of a typical game engine architecture.

## Session #2

- Dependency cycles to be avoided.
- Singletons can facilitate architecture breaches.
- Division of responsibilities.
- Interfaces to break dependency cycles.
- Dependency injection.
- Dependency inversion.
- pImpl.
- void\*: C-style pointer to user data.
- Interface with opaque structures through handlers.

## Session #3

- RAII.
- Ownership.
- Smart pointers (std::unique_ptr, std::shared_ptr).
- Move semantics.
- Dissonance in naming and in responsibilities.

## Session #4

- Specialization through inheritance.
- Specialization through components, entity-component-system.
- Camera system.
- Separation between Model and View.
- Visitor pattern.

## Session #5

- Serialization.
- Visitor pattern, again.
- Model-View, again.
- Command pattern, undo-redo.
- Test-driven development, unit tests.
