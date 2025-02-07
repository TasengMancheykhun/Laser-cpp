#ifndef PROPAGATION_H
#define PROPAGATION_H

#include<iostream>
#include<complex>

using namespace std;

typedef std::complex<double> cplxd;

class wavefunction
{
    public:
    // wavefunction(long x=0){
    //     wf_dim = x;

    //     start = new cplxd[x];
    // }

    void init(int size);
    void print_1d(FILE* file, int size);

    void kinetic_energy(int size, double dx);

    void print_2d(FILE* file, int size);

    private:
    double wf_dim;
    cplxd *psi;
    double **hmt;
};

#endif 