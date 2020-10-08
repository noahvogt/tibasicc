# The TI-BASIC Compiler (tibasicc)
The TI-BASIC Compiler is all about compiling TI-BASIC code on your computer into an .8xp file ready for transferring to your TI-83/TI-83+/TI-84 calculator (and vice versa).

Being able to type your programs on a real keyboard instead of the calculator's keypad is much easier and avoids some otherwise big pain.

*Note:* This project is a fork from [pcmattman/tibasic](https://sourceforge.net/projects/tibasic/).

## Installation
I have only tested this on GNU/Linux, but it should work on any other unix-like OS like MacOS:

    git clone https://github.com/noahvogt/tibasicc.git
    cd tibasicc
    sudo make clean install

*Note:* If you are a Windows User, I would recommend using WSL or you can make your own fork of this project, because I haven't made/released a Windows-compatible version yet.

## Usage
After installing, this program should be in your `path`. This means, you can call it from the terminal like this:

    tibasicc [options]

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
- verbose / debug mode that give a lot of information (`-v` flag)
- specify output file (`-o` flag)
