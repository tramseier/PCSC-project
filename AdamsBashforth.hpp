/*
 * AdamsBashforth.hpp
 *
 */

#ifndef ADAMSBASHFORTH_HPP_
#define ADAMSBASHFORTH_HPP_

#include "AbstractOdeSolver.hpp"

class AdamsBashforthSolver : public AbstractOdeSolver {
public:
    AdamsBashforthSolver();
    virtual ~AdamsBashforthSolver();

    virtual void SolveEquation(std::ostream &stream) override;
};

#endif /* ADAMSBASHFORTHSOLVER_HPP_ */
