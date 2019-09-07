This is an orbital simulator written for QSET by Alex White.

As of now the simulation is localized to a single python3 script which requires an external image for visualization of the earth. This image is on the git and was taken from https://visibleearth.nasa.gov/view.php?id=73909. Libraries used include matplotlib for 2d visualization, Mayavi for 3d visualization, PyQt5 for user interface and some others (see script for details). This simulation uses SI units such as kilograms for mass and seconds for time. 

Every second the simulation updates position, velocity and acceleration due to gravity, via leapfrog integration. This method is stable for oscillating systems. If you'd like to know more about the leapfrog method try reading https://en.wikipedia.org/wiki/Leapfrog_integration. Leapfrog integration takes place in the function "stepTime(sat, total_time, dt)". If this method were not used and you simply updated position, velocity and acceleration one by one, the orbit would spiral outward or inward depending on the order of the parameters being updated. This naive approach would be an example of the Euler method or backwards Euler method.

Gravity is currently calculated as if the earth were a point mass. This is sufficient for now but should be updated later to allow for things like orbit precession. 
