#pragma once

#include <fstream>
#include <iostream>

#include "SvgPath.h"

constexpr const char svgPrefix1 [] = "<svg width=\"";
constexpr const char svgPrefix2 [] = "\" height=\"";
constexpr const char svgPrefix3 [] = "\" xmlns=\"http://www.w3.org/2000/svg\">";
constexpr const char svgSuffix [] = "</svg>";


class SvgWriter {
    ostream & out;
    long width, height;
    vector<Path *> paths; // TODO: add support for multiple svg item types

  public:
    SvgWriter() : out( cout ), width( 100 ), height( 100 ) {}
    SvgWriter( ostream & out ) : out( out ), width( 100 ), height( 100 ) {}
    SvgWriter( ostream & out, long width, long height ) : out( out ), width( width ), height( height ) {}

    void addPath( Path & path ) {
        paths.emplace_back( &path );
    }

    void writeHeader() {
        out << svgPrefix1 << width << svgPrefix2 << height << svgPrefix3 << endl;
    }

    void writeFooter() {
        out << svgSuffix << endl;
    }

    void writePaths( bool clear = false ) {
        for ( const auto & path : paths )
            out << path->print() << endl;
        if ( clear ) paths.clear();
    }

    void write() {
        writeHeader();
        writePaths();
        writeFooter();
    }
};
