# Tiny Cortex-M semihosting example
Very simple C program to run on Fast Models to demonstrate semi-hosting on Cortex-M7

The example hardware system is a Cortex-M7

FlexLM licenses are not included. If a trial license is needed follow the [instructions on Arm Developer](https://developer.arm.com/documentation/102441/latest/Generate-Fast-Models-product-license)

### Build the Fast Model system
```bash
$ cd system/Cortex-M7
$ ./build.sh
```

### Build the software example with [Arm Compiler 6](https://developer.arm.com/tools-and-software/embedded/arm-compiler)
```bash
$ cd software/Cortex-M7/AC6
$ make
```

### Build the software example with gcc
```bash
$ cd software/Cortex-M7/gcc
$ make
```

### Run the software on the Fast Model
```bash
$ ./run-m7.sh
```

### Run and wait for a debugger to connect via CADI
```bash
$ ./run.sh debug
```

### Run and generate a tarmac file
```bash
$ ./run.sh tarmac
```

### Run and wait for a gdb connection and connect gdb
```bash
$ ./run-gdb.sh

In another window

$ cd software-gcc
$ arm-none-eabi-gdb hello.axf
```
Enter 'c' to continue ot the gdb prompt. Check .gdbinit file for the automatically executed commands.

# Tiny Cortex-M55 example
Very simple C program to run on Fast Models to demonstrate Cortex-M55 vector instructions

The example hardware system is a Cortex-M55

### Build the Fast Model system
```bash
$ cd system/Cortex-M55
$ ./build.sh
```

### Build the software example with [Arm Compiler 6](https://developer.arm.com/tools-and-software/embedded/arm-compiler)
```bash
$ cd software/Cortex-M55/AC6
$ make
```

### Run the software on the Fast Model
```bash
$ ./run-m55.sh
```


