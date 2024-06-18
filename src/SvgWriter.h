#pragma once

#include <fstream>
#include <iostream>

#include "SvgPath.h"

constexpr const char svgPrefix1 [] = "<svg width=\"";
constexpr const char svgPrefix2 [] = "\" height=\"";
constexpr const char svgPrefix3 [] = "\" xmlns=\"http://www.w3.org/2000/svg\">";
constexpr const char svgSuffix [] = "</svg>";


class SvgWriter {
    Path & path; // TODO: add support for multiple svg items
    ostream & out;
    long width, height;
    

  public:
    SvgWriter( Path & path ) : path( path ), out( cout ), width( 100 ), height( 100 ) {}
    SvgWriter( Path & path, ostream & out ) : path( path ), out( out ), width( 100 ), height( 100 ) {}
    SvgWriter( Path & path, ostream & out, long width, long height )
        : path( path ), out( out ), width( width ), height( height ) {}

    void write() {
        out << svgPrefix1 << width << svgPrefix2 << height << svgPrefix3 << endl;
        out << path.print() << endl;
        out << svgSuffix << endl;
    }
};
