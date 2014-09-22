/*
 * *************************************************************************
 * File:    SparseMXNdreduction.cpp
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

int SparseMXNdreduction(int *MMX1, int *MMX2, double *MMX3, struct CRS *MX, double *Ve, double *V, int *tcount, int *tvcount, int *count, int n0, int nn, int m)
{
	int nnn = (n0-2)*(n0-2),i, j, k, l, t, x, y, z, p, q;
	 k=(int)((m-1)/nnn)+1;
	//cout << k << endl;
        j=(int)((m-1-(k-1)*nnn)/(n0-2))+1;
        //cout << j << endl;
        i=m-(j-1)*(n0-2)-(k-1)*nnn;
        //cout << i << endl;
                p = i + j*n0 + k*nn;
                q = i-1 + (j-1)*(n0-2) + (k-1)*nnn;
                x = p%n0;
                if (x!=0 && x!=n0-1){
                    y = (p%nn-x)/n0;
                    if (y!=0 && y!=n0-1){
                        z = (p-x-y*n0)/nn;
                        if (z!=0 && z!=n0-1){
                            V[*tvcount]=Ve[p];
                            (*tvcount)++;
                        }
                    }
                }
//                MMX1[q+1] = MMX1[q] + MX->row[p+1] - MX->row[p];
                int ccount =0;
		for (l=MX->row[p]; l<MX->row[p+1]; l++){
                    t = MX->column[l];
                    x = t%n0;
                    if (x!=0 && x!=n0-1){
y = (t%nn-x)/n0;
                        if (y!=0 && y!=n0-1){
                            z = (t-x-y*n0)/nn;
                            if (z!=0 && z!=n0-1){
                                (*tcount)++;
                                ccount++;
				MMX2[*tcount]=x-1 + (y-1)*(n0-2) +(z-1)*nnn;
                                MMX3[*tcount]=MX->value[l];
                                //cout << MMX2[*tcount] << endl;
				}
                        }
                    }
                }
//		MMX1[q+1] = MMX1[q] + ccount;
//cout << *tcount << endl;
count[m-1] = ccount;
return 0;
}
