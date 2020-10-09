# The TI-BASIC Compiler (tibasicc)
The TI-BASIC Compiler is all about compiling TI-BASIC code on your computer into an .8xp file ready for transferring to your TI-83/TI-83+/TI-84 calculator (and vice versa).

Being able to type your programs on a real keyboard instead of the calculator's keypad is much easier and avoids some otherwise big pain.

*Note:* This project is a fork from [pcmattman/tibasic](https://sourceforge.net/projects/tibasic/).

## Installation
#### Unix (GNU/Linux, MacOS, FreeBSD, etc.)
If you are using Arch, you can just install my [AUR Package](https://aur.archlinux.org/packages/tibasicc-git/) with your prefered aur helper (yay, pacaur, yaourt, etc.):

    yay -S tibasicc-git

For other systems, here is my also fairly easy general approach. I have only tested this on GNU/Linux, but it should work on any other unix-like OS like MacOS:

    git clone https://github.com/noahvogt/tibasicc.git
    cd tibasicc
    sudo make clean install

#### Windows
If you are a Windows User,  you have to install [git](https://git-scm.com/) (don't forget to add it to your *Path variable* during the setup process) and [MinGW](http://mingw.org/) first. Now open `cmd.exe` with administrator privileges and enter these commands:
	
	git clone https://github.com/noahvogt/tibasicc.git
	cd tibasicc
	win-installer.bat

Now you have to add the directories specified in the output of the install-script to your *Path variable*. To do this, press the *'Windows Key'* and search for "path". In the window that popped up, click "Environment Variables...". In this window you have to select a *path variable* (you can choose on your own between the system-wide variable and the user-wide variable), click "Edit..." and add them. Now you can open a new terminal window and it should work.

## Usage
After installing, this program should be in your `path`. This means, you can call it from the terminal like this:

    tibasicc [options] filename

I haven't made a man page for this simple program yet, but you can get some usage information when you run this program without any arguments or with some help flags (`-h` or `--help`).

## Features
Base Features
- compiling from source to .8xp
- decompiling from .8xp to source (`-d` flag)
      
Preprocessor 
- support for comments (using `#`)
- remove empty lines
- remove lines that only contain whitespaces
- strip off unneeded whitespaces to make the binary smaller

Additional Options
- verbose / debug mode that gives a lot of information (`-v` flag)
- specify output file (`-o` flag)
