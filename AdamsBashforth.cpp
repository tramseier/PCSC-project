/*
 * AdamsBashforthsolver.cpp
 *
 */

#include "AdamsBashforth.hpp"

#include <cmath>
#include <vector>
#include <iostream>

AdamsBashforthSolver::AdamsBashforthSolver() {}

AdamsBashforthSolver::~AdamsBashforthSolver() {}

void AdamsBashforthSolver::SolveEquation(std::ostream &stream) {

    double h = GetStepSize();
    int n = static_cast<int>(std::floor((GetFinalTime() - GetInitialTime()) / h));
    std::vector<double> y(n); //vector for storing the 4 steps of y
    std::vector<double> p(n); //predictor vector
    std::vector<double> t(n);

    //initializing
    y[0] = GetInitialValue();
    t[0] = GetInitialTime();

    for (int i = 1; i <= n; ++i) { //Use Runge-kutta for the four initial values
        if (i <= 4) {
            double k1 = h * RightHandSide(y[i-1], t[i-1]);
            double k2 = h * RightHandSide(y[i-1] + 0.5 * k1, t[i-1] + 0.5 * h);
            double k3 = h * RightHandSide(y[i-1] + 0.5 * k2, t[i-1] + 0.5 * h);
            double k4 = h * RightHandSide(y[i-1] + k3, t[i-1] + h);

            y[i] = y[i-1] + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);

        }

        else {
            p[i] = y[i-1] + h/24.0*(55*RightHandSide(y[i-1], t[i-1]) - 59*RightHandSide(y[i-2],t[i-2]) + 37*RightHandSide(y[i-3],t[i-3]) - 9*RightHandSide(y[i-4],t[i-4]));
            y[i] = y[i-1] + h/24.0*(9*RightHandSide(p[i],t[i]) + 19*RightHandSide(y[i-1],t[i-1]) -5*RightHandSide(y[i-2],t[n-2]) + RightHandSide(y[n-3],t[n-3]));
        }
        stream << t[i-1] << " " << y[i-1] << "\n";
        t[i] = t[i-1] + h;

    }
}
