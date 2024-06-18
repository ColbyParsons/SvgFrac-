#pragma once

#include <string>
#include <vector>

#include "Pos.h"

// TODO: refactor into header + cc
using namespace std;

// A single step in an svg path
class PathStep {
  public:
    enum Command {
        MoveTo = 'M',
        LineTo = 'L'
    } cmd;
    Pos2D pos;

    PathStep( Command cmd, Pos2D pos ) : cmd( cmd ), pos( pos ) {}
    PathStep( Command cmd, long double x, long double y ) : cmd( cmd ), pos( x, y ) {}

    string print() const { // TODO: make more efficient than normal concat
        string ret;
        ret += cmd;
        ret += ' ';
        ret += to_string( pos.x ) + ' ';
        ret += to_string( pos.y ) + ' ';
        return ret;
    }
    
};

// TODO: maybe also support raster drawing since svg has its quirks
constexpr char pathPrefix [] = "<path style=\"fill: none; stroke: black; stroke-width: 1px\" d=\""; // TODO: fix stroke issue
constexpr char pathSuffix [] = "\"/>";
// Representation of an svg path
class Path {
    vector<PathStep> steps;
  public:
    void moveTo( long double x, long double y ) {
        steps.emplace_back( PathStep::Command::MoveTo, x, y );
    }
    void moveTo( Pos2D pos ) { steps.emplace_back( PathStep::Command::MoveTo, pos ); }

    void lineTo( long double x, long double y ) {
        steps.emplace_back( PathStep::Command::LineTo, x, y );
    }
    void lineTo( Pos2D pos ) { steps.emplace_back( PathStep::Command::LineTo, pos ); }

    // TODO: make more performant than string concat (doubling char array?)
    // TODO: handle precision of output stream using something like std::cout.precision(3);
    // TODO: overloaded routine that supports direct print to outstream
    string print() const {
        string ret = pathPrefix;
        for ( const auto & step : steps ) {
            ret += step.print();
        }
        ret += pathSuffix;
        return ret;
    }
};
