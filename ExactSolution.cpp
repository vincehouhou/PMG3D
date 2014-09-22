/*
 * ************************************************************************* *
 * File:    ExactSolution.cpp
 * Purpose: Exact solution of an exmaple, and we use it to calculate the error
 * Author:  Houdong Hu
 * ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
using namespace std;

double *ExactSolution(double **No, int n0, double h)
{
    int i, j, k, m, mm, nn=n0*n0, nnn=n0*n0*n0;
    double pi = 3.1415926;
    double *x = new double [(n0-2)*(n0-2)*(n0-2)];
    for (m=0; m<nnn; m++){
        i = m%n0;
        if (i!=0 && i!=n0-1){
            j = (m%nn-i)/n0;
            if (j!=0 && j!=n0-1){
                k = (m-i-j*n0)/nn;
                if (k!=0 && k!=n0-1){
                    mm = i-1 + (j-1)*(n0-2) +(k-1)*(n0-2)*(n0-2);
                    x[mm] = sin(pi*No[m][0])*sin(pi*No[m][1])*sin(pi*No[m][2]);
                }
            }
         }
     }
     return (x);
}
