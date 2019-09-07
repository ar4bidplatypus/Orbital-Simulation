This is an orbital simulator written for QSET by Alex White.

As of now the simulation is localized to a single python script which requires an external image for visulization of the earth. Libraries used include matplotlib for 2d visualization, mayavi for 3d visulization, PyQt5 for user interface and some others (see script for details). This simulation uses SI units such as killograms for mass and seconds for time. 

Every second the simulation undates position, velocity and acceleration due to gravity via leapfrog integration. This method is stable for oscillating systems. If you'd like to know more about the leapfrog method try reading https://en.wikipedia.org/wiki/Leapfrog_integration. Leapfrog integration takes place in the function "stepTime(sat, total_time, dt)".
