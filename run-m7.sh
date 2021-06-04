#!/bin/bash

SYS=Cortex-M7 

# Find subdirectory under 'system' folder, which is the compiler used to generate the virtual platform.
BuildDir=$(ls -d system/$SYS/* | grep Lin)

echo $BuildDir

PLUGINS=$PVLIB_HOME/plugins/Linux64_GCC-7.3

# Verify isim_system exists, if it doesn't toss an error

[ ! -f ./$BuildDir/isim_system ] && echo Error, cant find isim_system executable file. Searched directory: ./$BuildDir && exit 0

if [ "$1" = "tarmac" ]; then
    TMAC="--plugin $PLUGINS/TarmacTrace.so"
else
    TMAC=""

fi

if [ "$1" = "trace" ]; then
    CT="--plugin $PLUGINS/GenericTrace.so -C TRACE.GenericTrace.trace-sources=READ_ACCESS,WRITE_ACCESS"
else
    CT=""
fi

if [ "$1" = "debug" ]; then
    DEBUG="-S -p"
else
    DEBUG=""
fi


echo "Running fast model simulation"

./$BuildDir/isim_system -a ./software/$SYS/AC6/hello.axf \
$TMAC \
$CT \
$DEBUG \
-C armcortexm7ct.semihosting-cmd_line="test.txt" --stat
