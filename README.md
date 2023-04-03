# BSCAN


**BSCAN** is a library for Node.js that provides information about the hardware and software of a computing device. Allowing Developers to utilize scanning capabilities in their web applications

<br>

1. [Hardwares](/docs/hwares/intro.md) get information about RAM, CPU, GPU,  Disk, Motheboard...
2. [Softwares](/docs/swares/intro.md) get information about Operating System, Apps, User, Services...

<br>

## Requirements

It is necessary that you have installed the programs below to use **BSCAN** in developer mode.

<br>

### To Linux

<br>

- [Python](https://www.python.org/) **v3.1** or greater
- [Compilers C/C++](https://school.barca.com/edu/ti/overview/c++/compiler/intro.html) 
  - [MinGW/GCC](https://www.mingw-w64.org)
  - [Digital Mars](https://www.digitalmars.com/d/2.0/dmd-linux.html)
  - [Clang](https://clang.llvm.org)
  - [Intel](https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-compiler.html)
  - [GNU GCC](http://gcc.gnu.org)
  - [Code Block](https://wiki.codeblocks.org/index.php/Installing_a_supported_compiler)
  - [Cygwin](http://www.cygwin.org)
  - [Small Device](https://sdcc.sourceforge.net)
- [Node.js](https://nodejs.org/) **v8** or greater

<br>

### To Windows

<br>

- [Python](https://www.python.org/) **v3.1** or greater
- [Compilers C/C++](https://school.barca.com/edu/ti/overview/c++/compiler/intro.html) 
  - [MinGW/GCC](https://www.mingw-w64.org)
  - [Clang](https://clang.llvm.org)
  - [Intel](https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-compiler.html)
  - [Visual (suggested)](https://visualstudio.microsoft.com/vs/features/cplusplus)
  - [Code Block](https://wiki.codeblocks.org/index.php/Installing_a_supported_compiler)
  - [Cygwin](http://www.cygwin.org)
  - [Small Device](https://sdcc.sourceforge.net)
- [Node.js](https://nodejs.org/) **v8** or greater

<br>
<br>

## Obtaining BScan

<br>

View the [changelog](/CHANGELOG.md) for the latest updates and changes by version.

<br>

### Binary Downloads

Binary downloads are available from the [BWC downloads](https://cloud.barca.com/downloads)
page or from each [GitHub Releases](https://github.com/BarcaWebCloud/bscan/releases) page.


<br>
<br>

## Build From Source

<br>

**BSCAN** requires C++ version 17 or newer, the CMakelists requires GNU cmake.

  1. [Install Node.js](https://nodejs.org/) >=8.0.0 (16.11 recommended)
  2. [Install Python](https://www.python.org/downloads/) >=2.6.0 (3.9.0 recommended)
  3. Clone the BScan repository:
    
      ```sh
      git clone https://github.com/BarcaWebCloud/bscan.git
      ```

<br>

## Build Executable BSCAN in Your Environment

### To Linux

<br>

  1. Run `cmake CMakeLists.txt` from the source directory

      ```shell
      cd bscan
      cmake CMakeLists.txt
      ```
  2. Now run `make all` or `make bscan` to compile the main program

<br>

### To Windows

<br>

Check the **gcc** version of your System. BSCAN requires version greater than **17**.
We can view a list of *Makefile* generators with the command: `cmake -G`.
Here shows an example to use the **MinGW** *Makefile* generator:

<br>

  1. Run `cmake -G "MinGW Makefiles" <file-cmake>` from the source directory

      ```shell
      cd bscan
      cmake -G "MinGW Makefiles" CMakeLists.txt
      ```
  2. Now run `make all` or `make bscan` to compile the main program

<br>

## Build Module BSCAN Node.js in Your Environment

<br>
  
  1. Install required `npm` packages 
   

      ```shell
      npm install
      ```
<br>

  1. Generate boilerplate in the root directory of bscan module


      ```shell
      node-gyp configure

      ```
  <br>
  
  1. Now to build bscan native we will need to run the command to generates a **DLL** file with `.node` extension. This file will be placed inside **build/Release** directory


      ```shell
      node-gyp build
      ```

<br>

## Getting Started

<br>

Create a **javascript** file to call the module


```js
// main.js
const bscan = require("./build/Release/bscan.node");

console.log(bscan.info())
```

<br>

Now run the program

```shell
   node main.js
```

<br>
<br>

## Documentation

[Latest Release Documentation](https://cloud.barca.com/docs/bscan/latest/)

For documentation on the latest development code see the [documentation index](/docs).

<br>

## Contributing

There are many ways to contribute:

- Fix and [report bugs](https://github.com//BarcaWebCloud/bscan/issues/new)
- [Review code and feature proposals](https://github.com/BarcaWebCloud/bscan/pulls)
- Answer questions and discuss here on github and on the [Community Site](https://opensource.barca.com/)
- [Contribute plugins](CONTRIBUTING.md)

