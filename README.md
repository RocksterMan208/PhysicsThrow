# What is this project?

PhysicsThrow is a test project in which I will be experimenting with physics calculations and will allow me to learn C++ (this is my second project I've made so far in C++) and Object Oriented Programming..
By the end of this project, I aim to have an application where you can draw polygons and have it so when you hold down left click, you interact with the object and can apply physics to it.

# Where are we now?

I have just created a realistic(-ish) momentum system but it has a few issues i will have to iron out (bare with me)

I am also working on a colour creation system, meaning that you can create a shape with a specified colour.
(For now this is just random colours)

I am planning on adding some sliders for different things, an example being gravity and shape colour when created.


# Here's a current snippet of the project

https://github.com/user-attachments/assets/87e466e8-6552-4e76-924f-dc5fe83cd661

There are some keybinds for basic functions:

- F11 for fullscreen toggle.
- S to spawn a square.
- R to reset.

# If you want to build it for yourself:
(You do need some dependencies)

### You need to install raylib and g++ and be on a Linux operating system.
If you are on Arch Linux, like me, the commands are:
```
sudo pacman -S g++
sudo pacman -S raylib
```

If you are on a Debian based Linux:

For Ubuntu do:

```
sudo apt install g++
sudo apt install libraylib-dev
```

For Fedora do:

```
sudo dnf install g++
sudo dnf install libraylib-dev
```
## Now, whilst in the folder:
There is a makefile already inside of the folder, so it should be easy to run.

Simply do:
```
make run
```
And the code will compile and run automatically.
 
 
 
 
 
<sup> I use Arch btw <sup>
