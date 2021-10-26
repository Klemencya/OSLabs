#!/bin/bash
mkdir tmp
cd tmp
nano file1
nano file2
ln file1 link1
ln file1 link2
ln file1 link3
cd ..
gcc ex4.c -o ex4
./ex4
