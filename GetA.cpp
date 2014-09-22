/*
 * ************************************************************************* *
 * File:    GetA.cpp
 * Purpose: Get the stiffness matrix of Laplacian operator on different mesh level
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

struct CRS *GetA(int *level, struct CRS *MX, int n0, double h)
{
    int i, **El, **E_N, **N_E, n1 = 4;
    double **No;
    if (*level == (int)(log(n0-1)/log(2))){
        return MX;
    }
    else {
        double h0 = h*pow(2, (int)(log(n0-1)/log(2))-(*level));
        int nn0 = pow(2, (*level))+1, nn = (nn0-2)*(nn0-2)*(nn0-2);
        double *V = new double [nn];
        for (i=0; i<nn; i++)
            V[i] = 0;
        struct CRS *MMX = new struct CRS;
        No = Node(nn0, h0);
        El = Element(nn0);
        E_N = ElementNode(El, nn0);
        N_E = Transpose(E_N, nn0);
        MMX = Matrixsetup(V, No, El, E_N, N_E, nn0, n1, h0);
        return MMX;
    }
}

