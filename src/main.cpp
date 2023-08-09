#include "converter.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// #include "/home/kylelo/research/web/semi_structured_spline/Source/src/mesh_to_igs.hpp"

using namespace std;

string readFile(string filename);

int main() {
    string contents = readFile("cube.obj");

    // cout << mesh_to_igs("cube.obj") << endl;

    Converter converter;
    string output = converter.stringConvert(contents);
    cout << output << endl;
    cout << converter.flagReport();
    return 0;
}

string readFile(string filename) {
    ifstream input;
    ostringstream output;
    string temp;
    input.open(filename);

    try {
        if (input.is_open()) {
            while (input.good()) {
                getline(input, temp);
                output << temp << endl;
            }
        }
    }
    catch (...) {
        cout << "Error occurred opening " << filename << endl;
    }

    input.close();

    return output.str();
}
