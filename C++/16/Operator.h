#ifndef OPERATOR_H
#define OPERATOR_H

class Operator
{
private:
    char mOp;
    double mP1;
    double mP2;

public:
    bool setOperator(char op);
    void setParameter(double p1, double p2);
    bool result(double& r);
};

#endif