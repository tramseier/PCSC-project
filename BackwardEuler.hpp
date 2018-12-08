//
// Created by Pablo on 12/2/18.
//

#ifndef PROJECT_BACKWARDEULER_HPP
#define PROJECT_BACKWARDEULER_HPP
#include "AbstractOdeSolver.hpp"

class BackwardEulerSolver : public AbstractOdeSolver {
public:
    BackwardEulerSolver();
    virtual ~BackwardEulerSolver();

    virtual void SolveEquation(std::ostream &stream) override;
};


#endif //PROJECT_BACKWARDEULER_HPP
