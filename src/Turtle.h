#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include "SvgPath.h"

constexpr long double TAU = ( 2 * M_PI );

class Turtle {
    Pos2D pos;
    long double direction; // in radians
    long double stepSize;
    long double turnDelta;
    Path path;

    void step() {
        pos.x += stepSize * cos( direction );
        pos.y += stepSize * sin( direction );
    }
    
  public:

    Turtle() : pos( 0, 0 ), direction( 0 ), stepSize( 1 ), turnDelta( M_PI_2 ) {}
    Turtle( Pos2D pos ) : pos( pos ), direction( 0 ), stepSize( 1 ), turnDelta( M_PI_2 ) {}
    Turtle( Pos2D pos, long double dir ) 
        : pos( pos ), direction( dir ), stepSize( 1 ), turnDelta( M_PI_2 ) {}
    Turtle( Pos2D pos, long double dir, long double step )
        : pos( pos ), direction( dir ), stepSize( step ), turnDelta( M_PI_2 ) {}
    Turtle( Pos2D pos, long double dir, long double step, long double turnDelta )
        : pos( pos ), direction( dir ), stepSize( step ), turnDelta( turnDelta ) {}

    // Move one stepSize forward while drawing
    void drawStep() { 
        // TODO: maybe optimize if multiple steps in same direction so path isn't too complex
        // could buffer steps to achieve this and only flush to path upon 
        // direction change or operation change
        step();
        path.pathTo( pos );
    }

    void moveStep() {
        step();
        path.moveTo( pos );
    }

    void moveTo( Pos2D newPos ) {
        pos = newPos;
        path.moveTo( pos );
    }

    // Rotate direction theta radians
    void rotate( long double theta ) {
        direction = fmod( direction + theta, TAU );
    }

    // Uses default turning amount passed to ctor
    void rotateLeft() {
        direction = fmod( direction + turnDelta, TAU );
    }

    // Uses default turning amount passed to ctor
    void rotateRight() {
        direction = fmod( direction + turnDelta, TAU );
    }
};
