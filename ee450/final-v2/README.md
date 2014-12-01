# EE 450 - Final Project

This is the final project for EE 450. Main purpose of this assignment
is to learning basics of socket programing. Detailed description of the
assignment can be found in the docs folder.

## 1 Targets

Project uses make tool for automation.

### 1.1 Compile the program

To compile the program run this command:

    make

This will create an executable file called `army`.

### 1.2 Clean the directory

To remove all the files created by make tool run this command:

    make clean
    
### 1.3 Create a zip archive

To create a zip archive of the project run this commands:

    make zip

## 2 Usage

The program consists of several different processes. These processes
have to be run separately and manually. Please follow the order bellow.

### 2.1 General

To run General's process type this command:

    ./army g

This will start the general.

### 2.2 Major

To run Major's process type this command:

    ./army m

This will start the major.

### 2.3 Captain

There are 2 instances of Captain. To run the first Captain, use the
command bellow:

    ./army c 1

To run the second Captain use the command bellow:

    ./army c 2

## 3 Testing

bin/ directory has some bash scripts to test parts of the program.

### 3.1 captain_to_major.sh

captain_to_major.sh bash script sends two captain's messages to major
for phase 1 using UDP.

## 4 Known limitations

* Captain's id, resources and confidence can only be a digit.
* Major overwrites the captain's data every time it gets message from him.
