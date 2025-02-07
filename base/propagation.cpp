#include<math.h>

#include "propagation.h"

#define PI 3.1415926535897932

void wavefunction::init(int size)
{
    wf_dim = size;
    psi = new cplxd[size];
    for (long i=0; i<size; i++){
        psi[i] = cplxd(0.0,0.0);
    }    
}

void wavefunction::print_1d(FILE* file, int size){
    for (long i=0; i<size; i++){
       //cout<<psi[i]<<" ";
       fprintf(file,"%e %e\n",real(psi[i]),imag(psi[i]));
    }
}

void wavefunction::kinetic_energy(int size, double dx)
{
    wf_dim = size;

    hmt = new double*[size];
    for (int i=0; i<size; i++){
        hmt[i] = new double[size];
    } 

    for (int k=0; k<size; k++){
        hmt[k][k] = (PI*PI)/(6.0*dx*dx);

        for(int j=0; j<k; j++){
           hmt[k][j] = (pow(-1.0,(k-j)))/((k-j)*(k-j)*dx*dx);
           hmt[j][k] = hmt[k][j];
        }
    }
}

void wavefunction::print_2d(FILE* file, int size){
   for (int i=0; i<size; i++){
      for (int j=0; j<size; j++){
          fprintf(file,"%e ",hmt[i][j]);
      }
      fprintf(file,"\n");
   }
}