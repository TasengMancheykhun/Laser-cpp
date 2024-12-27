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

    void init(long size);
    void print();

    void kinetic_energy(long size, double dx);

    void printhmt(FILE* file, long size);

    private:
    long wf_dim;
    cplxd *start;
    double **hmt;
};

#endif 