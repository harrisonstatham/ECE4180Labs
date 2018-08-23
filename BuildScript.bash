#!/bin/bash

# Upload the new binary to the MBED.

cp -f BUILD/LPC1768/GCC_ARM/ECE4180Labs.bin /Volumes/MBED/ECE4180Labs.bin

# Clear the screen of all the junk.
clear

# List all of the files in the directory of the MBED to make sure it worked.

ls -a /Volumes/MBED/