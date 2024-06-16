#pragma once

// Position record types
struct Pos2D {
    long double x, y;

    Pos2D() : x( 0 ), y( 0 ) {}
    Pos2D( double x, double y ) : x( x ), y( y ) {}
};

struct Pos3D {
    long double x, y, z;

    Pos3D() : x( 0 ), y( 0 ), z( 0 ) {}
    Pos3D( double x, double y, double z ) : x( x ), y( y ), z( z ) {}
};
