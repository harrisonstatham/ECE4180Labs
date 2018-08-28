@echo off
rem you could also remove the line above, because it might help you to see what happens

rem /i option is needed to avoid the batch file asking you whether destination folder is a file or a folder
rem /e option is needed to copy also all folders and subfolders
xcopy "C:\Users\krist\Documents\GitHub\ECE4180Labs\BUILD\LPC1768\GCC_ARM\ECE4180Labs.bin" "D:\" /i 