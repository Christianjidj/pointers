#include <iostream>
#include "MatrixOp.h"
using namespace std;

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}


int main()
{
Matrix A(4,3),B(4,3),C(4,3),D(4,3);
for(int i=0;i<12;i++){
    A.setD(i,i);
    B.setD(i,i*2);

}
A.add(&B,&C);

for(int k=0;k<A.getRows();k++){
    for (int i=0;i<A.getCols();i++){
       cout<<C.getData()[A.getCols()*k+i]<<" ";
    }
    cout<<endl;
}

cout<<endl<<endl;


A.apply(&A,&B,&C,sub);

A.apply(&A,&B,&D,mul);

for(int i=0;i<12;i++){
    A.setD(i,i);
    B.setD(i,i*2);

}

for(int k=0;k<A.getRows();k++){
    for (int i=0;i<A.getCols();i++){
       cout<<C.getData()[A.getCols()*k+i]<<" ";
    }
    cout<<endl;
}
cout<<endl<<endl;

for(int k=0;k<A.getRows();k++){
    for (int i=0;i<A.getCols();i++){
       cout<<D.getData()[A.getCols()*k+i]<<" ";
    }
    cout<<endl;
}


    return 0;
}
