# FDF
This project is about creating a simple wireframe model representation of a 3D land- scape by linking various points (x, y, z) thanks to line segments (edges).
The project was executed using the MiniLibX.
## Rules
The program represents the model in isometric projection. The coordinates of the landscape are stored in a ```*.fdf``` file passed as a parameter to the program. Here is an example:
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```
The program displays the image in a window.
## Usage
To compile the progam you should do
```make```
then to start it do
```./fdf <path to .fdf file>```

```.fdf``` the files are in the ```maps``` folder

In opened window you will see an isometric projection of the model.

You can rotate the image by using arrow keys.

To rotate around the X axis, use the keys ```W``` and ```S```, Y axis - ```A``` and ```D```, Z axis - ```Q``` and ```E```.

Zoom in and out by ```+``` and ```-``` keys.

To recover the isometric projection use ```O``` key.

To go to the X Y basis, use ```P``` key. To close the window use ```ESC``` or X mark.

To remove binary and object files use ```make fclean```
