/*
 * ************************************************************************* *
 * File:    Prolongation.cpp
 * Purpose: Prolongation step of OpenMP code in multigrid solver
 * Author:  Houdong Hu
 * ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

int ProlongationNd(double ***vv, double *r, int m, int nn, int n0)
{
        int k = (int)((m-1)/nn)+1;
        int j=(int)((m-1-(k-1)*nn)/(n0-2))+1;
        int i=m-(j-1)*(n0-2)-(k-1)*nn;
        double a = r[m-1];
        vv[2*i][2*j][2*k] += a;
        vv[2*i-1][2*j][2*k] += a/2;
        vv[2*i+1][2*j][2*k] += a/2;
        vv[2*i][2*j-1][2*k] += a/2;
        vv[2*i][2*j+1][2*k] += a/2;
        vv[2*i][2*j][2*k-1] += a/2;
        vv[2*i][2*j][2*k+1] += a/2;
        vv[2*i-1][2*j-1][2*k] += a/4;
        vv[2*i-1][2*j+1][2*k] += a/4;
        vv[2*i+1][2*j-1][2*k] += a/4;
        vv[2*i+1][2*j+1][2*k] += a/4;
        vv[2*i-1][2*j][2*k-1] += a/4;
        vv[2*i-1][2*j][2*k+1] += a/4;
        vv[2*i+1][2*j][2*k-1] += a/4;
        vv[2*i+1][2*j][2*k+1] += a/4;
        vv[2*i][2*j-1][2*k-1] += a/4;
        vv[2*i][2*j-1][2*k+1] += a/4;
        vv[2*i][2*j+1][2*k-1] += a/4;
        vv[2*i][2*j+1][2*k+1] += a/4;
        vv[2*i-1][2*j-1][2*k-1] += a/8;
        vv[2*i-1][2*j-1][2*k+1] += a/8;
        vv[2*i-1][2*j+1][2*k-1] += a/8;
        vv[2*i-1][2*j+1][2*k+1] += a/8;
        vv[2*i+1][2*j-1][2*k-1] += a/8;
        vv[2*i+1][2*j-1][2*k+1] += a/8;
        vv[2*i+1][2*j+1][2*k-1] += a/8;
        vv[2*i+1][2*j+1][2*k+1] += a/8;
        return 0;
}
