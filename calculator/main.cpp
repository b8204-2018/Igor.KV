#include <iostream>
#include "src/solver.h"
#include <exception>

const char file[] = "/home/igor/CLionProjects/calculator/src/example";

int main() {
    char *equation = new char[80];
    short type;
    Solver solver1;
    solver1.add(new Add);
    solver1.add(new Sub);
    solver1.add(new Div);
    solver1.add(new Mul);
    solver1.add(new Quadratic);
    try {

        reader(file, type, equation);
        std::cout << type << ' ' << equation << std::endl;
        printer(solver1.solve(type, equation));


    } catch (std::exception &err) {
        std::cout<<err.what()<<std::endl;
    }

    return 0;
}