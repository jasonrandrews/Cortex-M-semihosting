#!/bin/bash

SYS=Cortex-M7 

BuildDir=$(ls -d system/$SYS/* | grep Lin)

echo $BuildDir

$BuildDir/isim_system -f params.txt --allow-debug-plugin --plugin $HOME/GDBRemoteConnection.so

