/*
 * *************************************************************************
 * File:    Element.cpp
 * Purpose: Input the relationship between elements and nodes
 * Author:  Houdong Hu
 * ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "types.h"
#include "vincehouhou.h"
using namespace std;

int **Element(int n0)
{
    /*
     *  n is the number of elements
     *  E is a pointer^2, and E[i][0],E[i][1],E[i][2],E[i][3] express the four nodes for each element
     *  we specify one kind of decompostion for each cubic, and decompose each cubic to 6 tetrahedrons
     */
    int n = (n0-1)*(n0-1)*(n0-1)*6, nn = (n0-1)*(n0-1), nnn = n0*n0, i, j, k, m, mm;
    int **E = new int*[n];
    for (i=0; i<n; i++)
        E[i] = new int[4];
    for (k=0; k<n0-1; k++)
        for (j=0; j<n0-1; j++)
            for (i=0; i<n0-1; i++){
                m = i + j*(n0-1) + k*nn;
                mm = i + j*n0 + k*nnn;
                E[6*m][0] = mm;
                E[6*m][1] = mm+n0;
                E[6*m][2] = mm+n0+1;
                E[6*m][3] = mm+nnn+n0+1;
                E[6*m+1][0] = mm;
                E[6*m+1][1] = mm+n0;
                E[6*m+1][2] = mm+nnn+n0;
                E[6*m+1][3] = mm+nnn+n0+1;
                E[6*m+2][0] = mm;
                E[6*m+2][1] = mm+1;
                E[6*m+2][2] = mm+n0+1;
                E[6*m+2][3] = mm+nnn+n0+1;
                E[6*m+3][0] = mm;
                E[6*m+3][1] = mm+1;
                E[6*m+3][2] = mm+nnn+1;
                E[6*m+3][3] = mm+nnn+n0+1;
                E[6*m+4][0] = mm;
                E[6*m+4][1] = mm+nnn;
                E[6*m+4][2] = mm+nnn+n0;
                E[6*m+4][3] = mm+nnn+n0+1;
                E[6*m+5][0] = mm;
                E[6*m+5][1] = mm+nnn;
                E[6*m+5][2] = mm+nnn+1;
                E[6*m+5][3] = mm+nnn+n0+1;
    }
    return(E);
}   
