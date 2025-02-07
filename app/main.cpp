#include<iostream>
using namespace std;

#include "propagation.h"

#define PI 3.1415926535897932

int main()
{
    wavefunction wf;
   
    int ntime, ncstep, istate, flqchnl;
    int ncsf, noptc;
    double xmin, xmax, epsln, omga;
    double tau, totime;
  
    ncsf = 20; flqchnl = 5; xmin = 0 ; xmax = 10.0;
    epsln = 0.5; omga = 0.5;
    noptc = 5; istate = 1;           //keep istate as 1, 0 giving wrong result
  
    tau = 2.0*PI/omga;
    totime = noptc*tau;
    ntime = (int)totime;

    double mass = 10000.0;
    double dtim = totime/ntime;
    double dx = (xmax-xmin)/(ncsf-1);
    int tchnl = 2*flqchnl+1;
    int nfloq = ncsf*tchnl;
    int inzr = flqchnl*ncsf;
    
    FILE* file;
    
    wf.init(ncsf);    

    file = fopen("./result/psi.txt","w");
    wf.print_1d(file, ncsf); 
    fclose(file);

    wf.kinetic_energy(ncsf,dx);
    file = fopen("./result/kinetic.txt","w"); 
    wf.print_2d(file, ncsf);
    fclose(file);


    
    return 0;
}