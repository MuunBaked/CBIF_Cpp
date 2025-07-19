# CBIF_Cpp -- Made by Muun / Gabriel Henry.
## ConsoleBasedInterfaceFramework

ConsoleBasedInterfaceFramework / CBIF is a simple namespace that you can put in your C++ projects that's specifically made to provide a few functions for an easy display for text, alongside a textbox function, there are choice functions and other functions that may not be put in C++ by default, such as an average and a random between numbers function, you may add onto this however you'd like, apologies if its too basic and or not made well, this is my first attempt at making something with code.

## How to Use:
Download **CBIF_Frame.h**

then put it in the folder with your main.cpp file.

then write #include "CBIF_Frame.h" in the main cpp file

then write using namespace cbif; (you can also use another namespace alongside tihis!)

## Functions

### CBIF_textbox();

input 1: `string& name` input 2: `string& dialogue`

The following function is to provide a textbox with a wrapping function
and a style. It has a name and a dialogue but nothing else, a simple textbox.

it wraps every 20 spaces.
```cpp
CBIF_textbox(name, dialogue);

//output:
[name]
============================================================
[:] text
```

### CBIF_choice();

input 1: `int numberspecified` input 2: `int& point` input 3: `string choicednm` input 4: `string choicedtb`

Used after CBIF_getinput, if the number from getinput is equal to the numberspecified for this choice, it'll pop out a textbox with the name and dialogue being replaced by `choicednm` and `choicedtb` (name and dialogue rspctvly).
DOES NOT SHOW WHAT THE CHOICE IS, use CBIF_showchoice if you want to show it, use it right after or before CBIF_choice.
uses CBIF_CLRSCRN right after the choice is chosen.
```cpp
  CBIF_choice(1,point,"name","dialogue");

//output:
//if point == 1
//all previous text cleared by CLRSCRN
[name]
============================================================
[:] dialogue

//if point not == 1
N/A
  
```

### CBIF_CLRSCRN();

no input

Enters 60 \n outputs.
```cpp
CBIF_CLRSCRN();

//output:
//idk what you expected :/.
```

### CBIF_getinput();

input 1: `int& point` input 2: `int min` input 3: `int max`

gets the input of user between 2 values and returns it to the point variable, usually used before CBIF_choice.
has an error handling for when user doesn't put the correct number, there'll be an error if you attempt to put in letters, I think.
```cpp
CBIF_getinput(point, min, max);

//output:
INPUT: //input requested
```

### CBIF_showchoice();

input 1: `int numberspecified` input 2: `string text`

meant to show the choice, used inbetween CBIF_choice and CBIF_getinput.
automatically uses endl.

```cpp
CBIF_showchoice(numberspecfied, text);

//output:
[numberspecified] text
```

### CBIF_Ext_randomchoice();

input 1: `int& point` input 2: `int max` input 3: `int shiftmax`

changes the point to a random value inbetween the maximum and shifted maximum, defaults min = 0

```cpp
CBIF_Ext_randomchoice(point, max, shiftmax);

//changed point == (random(between 0+shiftmax -> max))
```

### CBIF_Ext_average();

input 1: `int array[]` input 2: `int size` input 3: `int& totald`

averages an entire array with the number from size (manual size checking, apologies...)  totald is what value to change to the average.
```cpp
CBIF_Ext_average(array[5,5,3,3] 4, totald);

//changed: totald = 4
```

### CBIF_EndText();

input 1: `string endtext` input 2: `string sdmsg`

provides a text that after pressing ENTER it'll end the program.

```cpp
CBIF_EndText("woah", "woah");

//output:
//clearscreens
[XXX] woah
woah //input enter
```

### CBIF_NAMovement();

input 1: `string text`

simply displays text then requests you to press enter to continue.

```cpp
CBIF_NAMovement(' ');

//output:
 
(Press Enter to continue...) //input enter
```


## Memory Functions

all memory functions are strings, the value, and the index are strings, unless you're using the int version, which in that case the value is an integer and the index is a string.
