#ifndef A123_H_INCLUDED
#define A123_H_INCLUDED

#include <iostream>
using namespace std;


class Matrix{
private:
    int rows_, cols_,k,i,K;
    double *data_;


public:
    Matrix(int rows, int cols);


    void set(int i,int j,double v);
    void setD(int in, double su);

    double getter(int i, int j);

    int getRows() const;
    int getCols() const;
    double *getData() const;

    void add(const Matrix *other, Matrix *result);

    using OpFunc = double(*)(double, double);
    void apply(const Matrix *A,
           const Matrix *B,
           Matrix *out,
           OpFunc op) const;


    ~Matrix();


};


#endif
