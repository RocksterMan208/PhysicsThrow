# What is this project?

PhysicsThrow is a test project in which I will be experimenting with physics calculations and will allow me to learn C++ (this is my second project I've made so far in C++) and Object Oriented Programming..
By the end of this project, I aim to have an application where you can draw polygons and have it so when you hold down left click, you interact with the object and can apply physics to it.

# Where are we now?

I am currently developing a center of rotation and a center of mass function which would allow the placement of the mouse to actually matter.
And after this I plan on creating a movement system where you can press either A or D to freely rotate the shape.

# Here's a current snippet of the project

(Do not worry I am planning to add UI features and such)

https://github.com/user-attachments/assets/b704e89d-fbf5-4f9a-b77e-04533e37eb53

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
