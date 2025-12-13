# What is this project?

PhysicsThrow is a test project in which I will be experimenting with physics calculations and will allow me to learn C++ (this is my second project I've made so far in C++) and Object Oriented Programming..
By the end of this project, I aim to have an application where you can draw polygons and have it so when you hold down left click, you interact with the object and can apply physics to it.

# Where are we now?

I am currently developing a way to have interactions with shapes which are on the foreground (should be basic stuff I know).

I will then use this to make the basics of a rotating square which would then later be used to create a mouse based,
center of mass based rotation system.

I am also working on a colour creation system, meaning that you can create a shape with a specified colour.

# Here's a current snippet of the project

https://github.com/user-attachments/assets/2b9ec511-ad66-4f72-8087-c00c1d6982c2

# If you want to build it for yourself:
(You do need some dependencies)

### You need to install raylib and g++ and be on a Linux operating system.
If you are on Arch Linux, like me, the commands are:
```
sudo pacman -S g++
sudo pacman -S raylib
```

If you are on a Debian based Linux (e.g Ubuntu):
```
sudo apt install g++
sudo apt install libraylib-dev
```
## Now, whilst in the folder:
There is a makefile already inside of the folder, so it should be easy to run.

Simply do:
```
make run
```
And the code will compile and run automatically.
 
 
 
 
 
<sup> I use Arch btw <sup>
