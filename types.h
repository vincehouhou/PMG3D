/*
 * ************************************************************************
 * File:    types.h
 * Purpose: Define data structrue of a CRS sparse matrix
 * Author:  Houdong Hu
 * ************************************************************************
 */

#ifndef _TYPES_H_
#define _TYPES_H_

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
using namespace std;

/*
 * the only difference between CRS in MG3D with tranditional CRS is we have
 * one more unit for column and value, the first unit of column and value 
 * store the length of column and value
 */

struct CRS
{
     int *row;
     int *column;
     double *value;
};


#endif
