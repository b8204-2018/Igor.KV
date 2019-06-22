//
// Created by igor on 24.05.19.
//

#ifndef CALCULATOR_SOLVER_H
#define CALCULATOR_SOLVER_H
#include<string>
#include<fstream>
#include<vector>


void reader(const char *file,short &code, char *expression);
void printer(std::vector<double>);

class Parser{
        public:
        std::vector<double> parse(std::string &equation);
};

class OrdinaryParser: public Parser{
public:
    std::vector<double> parse(std::string &equation);
};

class QuadraticParser: public Parser{
public:
    std::vector<double> parse(std::string &equation);
};


class Operation{
public:
    virtual short get_Type() = 0;
    virtual std::vector<double> result(std::string &equation) = 0;
};

class Ordinary : public Operation {
public:
    std::vector<double> result(std::string &s);
    virtual double calculate(std::vector<double> elements) = 0;
};

class Add :public Ordinary{
public:
    short get_Type();
    double calculate(std::vector<double > elements);
};

class Sub :public Ordinary{
public:
    short get_Type();
    double calculate(std::vector<double> elements);
};

class Mul :public Ordinary{
public:
    short get_Type();
    double calculate(std::vector<double> elements);
};

class Div :public Ordinary{
public:
    short get_Type();
    double calculate(std::vector<double> elements);
};

class Quadratic :public Operation{

    short get_Type();
    std::vector<double> result(std::string &equation);



};



class Solver{
    std::vector<Operation*>op ;
public:
    void add(Operation* operation1);
    std::vector<double> solve(short type,std::string error);
};








#endif //CALCULATOR_SOLVER_H
