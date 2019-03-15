# electrospinner/firmare
embedded software controlling the PCB components

## Board
MSP430G2553

## Compiling
1. Use Make
    * Install `msp430-gcc-support-files`
    * Change `MSP430_SUPPORT_FILES_INCLUDE` in `Makefile` to `/some/directory/msp430-gcc-support-files/include`
    * Run `make`
2. CodeComposer Studio
    * Link the header files in `include`
    * Compile using `msp430-elf-gcc`

## Uploading
* Install `mspdebug`
* Run `make run`
