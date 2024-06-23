# SvgFractal
Some C++ code for generating svg fractals

Turns out svgs start to lag pretty badly when the paths get too complex, so I have abandoned this in favour of using bitmap images.

TODOS:
- Change output format from svg to some image format. (probably ppm)
    - Make data class for output format.
    - Make file writer for said output format.
- Make some form of standardized datafile for specifying lsystems, context-sensitive lsystems, randomized lsystems, etc.
- Add all examples from the algorithmic beauty of plants as datafiles
- Write generator that takes a datafile and creates the corresponding image.
- Look into how I could cupport generating a series of images as an animation.
    - Perhaps I could take a model parameter start value, end value, and interpolation function?
