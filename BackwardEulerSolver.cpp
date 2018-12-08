//
// Created by Pablo on 12/2/18.
//

#include "BackwardEuler.hpp"
#include <cmath>

#define THRESH 50 //Max iter for fixed point method


BackwardEulerSolver::BackwardEulerSolver() {}

BackwardEulerSolver::~BackwardEulerSolver() {}

void BackwardEulerSolver::SolveEquation(std::ostream &stream) {
    double y_prev = GetInitialValue();
    double y_next;

    double t_prev = GetInitialTime();
    double t_next;

    double h = GetStepSize();
    int n = static_cast<int>(std::floor((GetFinalTime() - GetInitialTime()) / h));

    stream << t_prev << " " << y_prev << "\n";

    for (int i = 1; i <= n; ++i) {
        y_next = y_prev;
        t_next = t_prev + h;
        // Fixed point iteration
        for (int j = 1; j <= THRESH; ++j) {
            y_next = y_prev + h * RightHandSide(y_next, t_next);
        }

        stream << t_next << " " << y_next << "\n";
        y_prev = y_next;
        t_prev = t_next;
    }
}
