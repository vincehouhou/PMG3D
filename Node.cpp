/*
 * *************************************************************************
 * File:    Node.cpp
 * Purpose: Input the nodes' coordinates
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

double **Node(int n0, double h)
{
    /*
     *  n0 is the number of nodes in 1D
     *  n is the number of nodes in 2D
     *  nn is the number of nodes in 3D
     *  we suppose the nodes are cubic grid here
     *  h is the length between neighbour grids
     *  N is a pointer^2, and N[i][0],N[i][1],N[i][2] are the x, y, z coordinates of grids
     */
    int n = n0*n0*n0, nn = n0*n0, i, j, k, m;
    double **N = new double*[n];
    for (i=0; i<n; i++)
        N[i] = new double[3];
    for (k=0; k<n0; k++)
        for (j=0; j<n0; j++)
            for (i=0; i<n0; i++){
                m = i + j*n0 + k*nn;
                N[m][0] = i*h;
                N[m][1] = j*h;
                N[m][2] = k*h;
    }
    return(N);
}
   
