/*
 * ODE solver for Project 3
 *
 * 	   Author: Thomas Ramseier and Pablo Guilland
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"
#include "AdamsBashforth.hpp"

double fRhs(double y, double t) { return 1 + t; } //set the function to solve

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Missing paremeter. Please run as:\n"
              << "  ./main <stepsize_euler> <stepsize_rk>\n"
              << "Aborting.\n";
    return 1;
  }
  // Pour runner le programme : faire make dans le folder cmake_build_debug
  // et ensuite run avec ./main 0.00001 0.0001 par exemple

  double initialTime = 0.0;
  double finalTime = 3.0;
  double initialValue = 2.0;

  AbstractOdeSolver *pSolver = 0;

  // Solving with forward-Euler
  double stepSizeEuler = std::atof(argv[1]);
  pSolver = new ForwardEulerSolver;
  pSolver->SetInitialValue(initialValue);
  pSolver->SetTimeInterval(initialTime, finalTime);
  pSolver->SetStepSize(stepSizeEuler);
  pSolver->SetRightHandSide(fRhs);

  std::ofstream eulerSolutionFile("solution_euler.dat");
  if (eulerSolutionFile.is_open()) {
    pSolver->SolveEquation(eulerSolutionFile);
    eulerSolutionFile.close();
  } else {
    std::cout << "Couldn't open solution_euler.dat. Aborting." << std::endl;
    return 1;
  }

  double stepSizeRK = std::atof(argv[2]);
  pSolver = new RungeKuttaSolver;
  pSolver->SetInitialValue(initialValue);
  pSolver->SetTimeInterval(initialTime, finalTime);
  pSolver->SetStepSize(stepSizeRK);
  pSolver->SetRightHandSide(fRhs);

  std::ofstream RKSolutionFile("solution_rk.dat");
  if (RKSolutionFile.is_open()) {
    pSolver->SolveEquation(RKSolutionFile);
    RKSolutionFile.close();
  } else {
    std::cout << "Couldn't open solution_rk.dat. Aborting." << std::endl;
    return 1;
  }

    double stepSizeAd = std::atof(argv[3]);
    pSolver = new AdamsBashforthSolver;
    pSolver->SetInitialValue(initialValue);
    pSolver->SetTimeInterval(initialTime, finalTime);
    pSolver->SetStepSize(stepSizeAd);
    pSolver->SetRightHandSide(fRhs);

    std::ofstream AdSolutionFile("solution_ad.dat");
    if (AdSolutionFile.is_open()) {
        pSolver->SolveEquation(AdSolutionFile);
        AdSolutionFile.close();
    } else {
        std::cout << "Couldn't open solution_ad.dat. Aborting." << std::endl;
        return 1;
    }

  return 0;
}
