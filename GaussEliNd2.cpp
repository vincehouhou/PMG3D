/*
 * ************************************************************************* *
 * File:    GaussEli.cpp
 * Purpose: Part 2 of Gauss elimination OpenMP code
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

int GaussEliNd2(struct CRS *MT, double *r, int i)
{
    r[i] = r[i]/MT->value[MT->row[i]];
    return 0;
}
