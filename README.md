# rexglue-sdk-xeo3

A proof-of-concept fork of ReXGlue aimed at allowing arbitrary games to run on Microsoft's official XEO3 emulator.

Original README can be found [here](./README.orig.md).

## Usage
Follow normal ReXGlue instructions for setup, just use this repository instead.
The executable is "rexglue_xeo3" instead of "rexglue", but otherwise the steps will be more or less the same.
Once you have initialized a project and gotten codegen working with it, you can build the project with cmake and it will output a xeo3 DLL that you can throw in the emulator folder.

## TODOs
MMIO R/W is currently not handled, as it seemed to just crash the emulator when used and games seemed to work fine without it.

## Current status
Chaos;Head Love Chu Chu runs playably with XEO3 using the recompiled binary.

Any recomps that work with normal ReXGlue will also probably run on XEO3, at least recompiled code wise. Be aware that XEO3 PC XBOX 360 support is very unstable, most games have issues with rendering or audio. 

## Credits
[XenonRecomp-XEO3](github.com/WitherOrNot/XenonRecomp-XEO3) - heavily based on it, thank you a lot for your research!

[ReXGlue](https://github.com/rexglue/rexglue-sdk) - wouldn't be here without it
