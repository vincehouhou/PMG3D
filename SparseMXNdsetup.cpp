/*
 * *************************************************************************
 * File:    SparseMXNdsetup.cpp
 * Purpose: Find the dimension of sparse matrix format of A in Ax = b in OpenMP code
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

int SparseMXNdsetup(int **El, int **E_N, int **N_E, int *count, int **tja, int n0, int k)
{
	int l, m, p, q, o;
	//#pragma omp parallel for private(l)
	for (l=N_E[0][k]; l<N_E[0][k+1]; l++)
            for (m=E_N[0][N_E[1][l]]; m<E_N[0][N_E[1][l]+1]; m++){  
              	q=count[k];
                //  count[nn] is an array to store the number of nonrepeating overlapping nodes with each node 
                if (q==0){
                    tja[k][1] = E_N[1][m];
                    count[k]++;
                }
                //  case: first element
                else if (q==1 && tja[k][1]>E_N[1][m]){
                    tja[k][2] = tja[k][1];
                    tja[k][1] = E_N[1][m];
                    count[k]++;
                }
                //  case: two elements; second element is smaller than first element
                else if (tja[k][q] < E_N[1][m]){
                    tja[k][q+1] = E_N[1][m];
	            count[k]++;
                }
                //  case: N elements; the newest element is the largest
                else{
                    for (o=1; o<=q; o++){
                        if (tja[k][o] == E_N[1][m]) o = q;
                        else if (E_N[1][m] > tja[k][o] && E_N[1][m] < tja[k][o+1]){
                            for (p=q; p>o; p--){
                                tja[k][p+1] = tja[k][p];
                            }
                            tja[k][o+1] = E_N[1][m];
                            o = q;
                            count[k]++;
                        }
                    }
                //  case: N elements; the newest element is neither the largest nor the smallest
                }
        }
	tja[k][0] = count[k];
        return 0;
}



