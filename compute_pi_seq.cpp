#include<iostream>
#include "autotimer.h"

using namespace std;

double compute_pi_seq(const long num_steps)
{
    double step = 1.0 / num_steps;
    double sum = 0.0;
    for (long i = 0; i < num_steps; i++)
    {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    return sum * step;
}

double compute_pi_parallel(const long num_steps)
{
    double step = 1.0 / num_steps;
    double sum = 0.0;
    // parallelize loop and reduce
#pragma omp parallel for reduction(+ : sum)
    for (long i = 0; i < num_steps; i++)
    {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    return sum * step;
}

int main()
{
    const int N = 1000000000L;
    double pi = 0;

    {
        AutoTimer autoTimer("顺序计算Pi");
        pi = compute_pi_seq(N);
    }

    cout<<pi<<endl;

    {
        AutoTimer autoTimer("openmp并行计算pi");
        pi = compute_pi_parallel(N);

    }

    cout<<pi<<endl;
}