#include "A123.h"

using namespace std;
Matrix::Matrix(int rows,int cols):rows_(rows),cols_(cols),data_(nullptr){
data_=new double[rows_*cols_];

}

Matrix::~Matrix(){
delete[] data_;
}

void Matrix::set(int i,int j,double v){
    if(i<=0<rows_||j<=0<cols_){
        k=i*cols_+j;
        data_[k]=v;
    }
    else{
        throw std::out_of_range("Index out of range.");
    }
}

void Matrix::setD(int in,double n){
data_[in]=n;

}


double Matrix::getter(int i, int j){

    if(i >= 0 && i < rows_ && j >= 0 && j < cols_){
        k=i*cols_+j;
        return data_[k];
    }
    else{
        throw std::out_of_range("Index out of range.");
    }
}

int Matrix::getRows() const{
return rows_;
}

int Matrix::getCols() const{
return cols_;
}
double* Matrix::getData() const{
return data_;
}


void Matrix::add(const Matrix *other,Matrix *result){
    if(other->getRows()==rows_ && other->getCols()==cols_){
        int K=rows_*cols_;
        double *D=other->getData();
        for(i=0;i<K;i++){

            double s=D[i]+data_[i];
            result->setD(i,s);
        }
    }

    else{

        cout<<"No tienes las mismas dimenciones"<<endl;
    }

}


void Matrix::apply(const Matrix *A,
                   const Matrix *B,
                   Matrix *out,
                   OpFunc op) const {

    if(A->getRows() == B->getRows() &&
       A->getCols() == B->getCols()) {

        int K = rows_ * cols_;

        for(int k = 0; k < K; k++) {

            out->setD(
                k,
                op(A->getData()[k],
                   B->getData()[k])
            );
        }
    }
}
