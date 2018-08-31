### ECE 4180 Labs


#### References

1. https://os.mbed.com/docs/v5.9/tools/arm-mbed-cli.html
2. https://os.mbed.com/docs/latest/tutorials/visual-studio-code.html
3. 


### Building a new lab

Run `python LabFileCreator.py -l Lab1 -n BasicAnalogIn BasicAnalogOut -v` to create folders and files:

```
/Labs/
|.. /Lab1/
    |.. /Headers/
        |.. BasicAnalogIn.hpp
        |.. BasicAnalogOut.hpp
    |.. BasicAnalogIn.cpp
    |.. BasicAnalogOut.cpp
```

If the folder structure already exists, and you just want to add new files you can call:

`python3 LabFileCreator.py -l Lab1 -n BasicDigitalIO -v -f` (Note the added `-f` flag)

The folder structure will now look like:

```
/Labs/
|.. /Lab1/
    |.. /Headers/
        |.. BasicAnalogIn.hpp
        |.. BasicAnalogOut.hpp
        |.. BasicDigitalIO.hpp
    |.. BasicAnalogIn.cpp
    |.. BasicAnalogOut.cpp
    |.. BasicDigitalIO.hpp
```
