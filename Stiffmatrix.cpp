/*
 * ************************************************************************* 
 * File:    Stiffmatrix.cpp
 * Purpose: Add the stiffness matrix of each element to A
 * Author:  Houdong Hu
 * *************************************************************************
 */


#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

int Stiffmatrix(struct CRS *MX, double *Ve, double **No, int **El, int n1, int k, double h)
{
    /*
     *  we use the 3D standard piecewise basis sets, which are x, y, z, 1-x-y-z, Gradient_basis are the gradients of the basis sets
     *  J is the Jacobi matrix from actual elements to standard elements
     *  DET is the determinant of the Jacobi matrix
     *  Inverse33MX is the inverse matrix of a 3*3 matrix
     *  GetStiff is the stiffness matrix of one element
     *  FindStiff is to find the corresponding position of stiffness matrix in the whole coefficient matrix
     */
    double det, deta;
    double A[4][3], Stiff[4][4], J[3][3], IJ[3][3], IJT[3][3], IJPR[3][3], Sve[4];
    int i, j, t;
    for (i=0; i<4; i++)
        for (j=0; j<3; j++){
           A[i][j] = No[El[k][i]][j];
    }
    for (i=0; i<3; i++)
        for (j=0; j<3; j++){
            J[i][j] = A[j+1][i] - A[0][i];
    }
    det = J[0][0]*J[1][1]*J[2][2] + J[0][1]*J[1][2]*J[2][0] + J[0][2]*J[1][0]*J[2][1] - J[0][2]*J[1][1]*J[2][0] - J[0][1]*J[1][0]*J[2][2] - J[0][0]*J[1][2]*J[2][1];
    IJ[0][0] = (J[2][2]*J[1][1] - J[2][1]*J[1][2])/det;
    IJ[0][1] = -(J[2][2]*J[0][1] - J[2][1]*J[0][2])/det;
    IJ[0][2] = (J[1][2]*J[0][1] - J[1][1]*J[0][2])/det;
    IJ[1][0] = -(J[2][2]*J[1][0] - J[2][0]*J[1][2])/det;
    IJ[1][1] = (J[2][2]*J[0][0] - J[2][0]*J[0][2])/det;
    IJ[1][2] = -(J[1][2]*J[0][0] - J[1][0]*J[0][2])/det;
    IJ[2][0] = (J[2][1]*J[1][0] - J[2][0]*J[1][1])/det;
    IJ[2][1] = -(J[2][1]*J[0][0] - J[2][0]*J[0][1])/det;
    IJ[2][2] = (J[1][1]*J[0][0] - J[1][0]*J[0][1])/det;
    if (det < 0) deta = -det;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            IJT[i][j] = IJ[j][i];
    for (i=0; i<3; i++)
        for (j=0; j<3; j++){
            IJPR[i][j] = 0;
            for (t=0; t<3; t++)
                IJPR[i][j] += IJ[i][t]*IJT[t][j];
    }
    Stiff[0][0] = (IJPR[0][0] + IJPR[0][1] + IJPR[0][2] + IJPR[1][0] + IJPR[1][1] + IJPR[1][2] + IJPR[2][0] + IJPR[2][1] + IJPR[2][2]) * deta / 6;
    Stiff[0][1] = -(IJPR[0][0] + IJPR[1][0] + IJPR[2][0]) * deta / 6;
    Stiff[0][2] = -(IJPR[0][1] + IJPR[1][1] + IJPR[2][1])* deta / 6;
    Stiff[0][3] = -(IJPR[0][2] + IJPR[1][2] + IJPR[2][2]) * deta / 6;
    Stiff[1][0] = -(IJPR[0][0] + IJPR[0][1] + IJPR[0][2]) * deta / 6;
    Stiff[1][1] = IJPR[0][0] * deta / 6;
    Stiff[1][2] = IJPR[0][1] * deta / 6;
    Stiff[1][3] = IJPR[0][2] * deta / 6;
    Stiff[2][0] = -(IJPR[1][0] + IJPR[1][1] + IJPR[1][2]) * deta / 6;
    Stiff[2][1] = IJPR[1][0] * deta / 6;
    Stiff[2][2] = IJPR[1][1] * deta / 6;
    Stiff[2][3] = IJPR[1][2] * deta / 6;
    Stiff[3][0] = -(IJPR[2][0] + IJPR[2][1] + IJPR[2][2]) * deta / 6;
    Stiff[3][1] = IJPR[2][0] * deta / 6;
    Stiff[3][2] = IJPR[2][1] * deta / 6;
    Stiff[3][3] = IJPR[2][2] * deta / 6;
    for (i=0; i<4; i++)
        Sve[i] = Integral(A[i][0], A[i][1], A[i][2], deta);
   for (i=0; i<4; i++)
        for (j=MX->row[El[k][i]]; j<MX->row[El[k][i]+1]; j++){
            if (El[k][0] == MX->column[j]) MX->value[j] += Stiff[i][0];
            else if (El[k][1] == MX->column[j]) MX->value[j] += Stiff[i][1];
            else if (El[k][2] == MX->column[j]) MX->value[j] += Stiff[i][2];
            else if (El[k][3] == MX->column[j]) MX->value[j] += Stiff[i][3];
   }
   for (i=0; i<4; i++)
        Ve[El[k][i]] += Sve[i];
   return 0;
}
    

    
