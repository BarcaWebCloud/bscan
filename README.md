# BSCAN


**Bscan** is a library for Node.js that provides information about the hardware and software of a computing device. Allowing Developers to utilize scanning capabilities in their web applications

1. [Hardwares](/docs/hwares/intro.md) get information about RAM, CPU, Disk...
2. [Softwares](/docs/swares/intro.md) get information about operating system and installed applications


## Minimum Requirements

- [Python](https://www.python.org/) **v3.1** or greater
- [C++](https://cplusplus.com/) **v17** or greater
- [Node.js](https://nodejs.org/) **v8** or greater


## Obtaining BScan

View the [changelog](/CHANGELOG.md) for the latest updates and changes by version.

### Binary Downloads

Binary downloads are available from the [BWC downloads](https://cloud.barca.com/downloads)
page or from each [GitHub Releases](https://github.com/BarcaWebCloud/bscan/releases) page.


### Build From Source

**BScan** requires C++ version 17 or newer, the CMakelists requires GNU cmake.

  1. [Install Node.js](https://nodejs.org/) >=8.0.0 (16.11 recommended)
  2. [Install Python](https://www.python.org/downloads/) >=2.6.0 (3.9.0 recommended)
  3. Clone the BScan repository:
    
      ```sh
      git clone https://github.com/BarcaWebCloud/bscan.git
      ```

#### Build executable bscan in your environment

  1. Run `cmake CMakeLists.txt` from the source directory

      ```shell
      cd bscan
      cmake CMakeLists.txt
      ```
  2. Now run `make all` or `make bscan` to compile the main program


#### Build module bscan in your environment
  
  1. Install required `npm` packages 
      ```shell
      npm install
      ```
  2. Generate boilerplate in the root directory of bscan module

      ```shell
      node-gyp configure
      ```
  3. Now to build bscan native we will need to run the command to generates a **DLL** file with `.node` extension. This file will be placed inside **build/Release** directory

      ```shell
      node-gyp build
      ```

## Getting Started

Create a **javascript** file to call the module


```js
// main.js
const bscan = require("./build/Release/bscan.node");

console.log(bscan.info())
```

Now run the program

```shell
   node main.js
```


## Documentation

[Latest Release Documentation](https://cloud.barca.com/docs/bscan/latest/)

For documentation on the latest development code see the [documentation index](/docs).


## Contributing

There are many ways to contribute:

- Fix and [report bugs](https://github.com//BarcaWebCloud/bscan/issues/new)
- [Review code and feature proposals](https://github.com/BarcaWebCloud/bscan/pulls)
- Answer questions and discuss here on github and on the [Community Site](https://opensource.barca.com/)
- [Contribute plugins](CONTRIBUTING.md)