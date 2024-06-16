#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// A single step in an svg path
struct PathStep {
    enum {
        MoveTo = 'M',
        PathTo = 'P'
    } command;
    double arg;
};


constexpr char pathPrefix [] = "<path d=\"";
constexpr char pathSuffix [] = "\">";
// Representation of an svg path
class Path {
    vector<PathStep> steps;

    // 
    // TODO: handle precision of output stream using something like std::cout.precision(3);
    string print() const {
        for ( const auto & step : steps ) {

        }
    }
};












int main() {

}