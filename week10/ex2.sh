#!/bin/bash
link /Users/ritasidorska/Desktop/OSLabs/week1/file.txt _ex2.txt 
find /Users/ritasidorska/Desktop/OSLabs/week1/file.txt -inum $( ls -i /Users/ritasidorska/Desktop/OSLabs/week1/file.txt |  awk '{print $1}') >> ex2.txt
find /Users/ritasidorska/Desktop/OSLabs/week1/file.txt -inum $( ls -i /Users/ritasidorska/Desktop/OSLabs/week1/file.txt |  awk '{print $1}') -exec rm {} \; >> ex2.txt 
