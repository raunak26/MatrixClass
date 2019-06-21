//
// Created by mfbut on 5/19/2019.
//

#include "DivideByZeroError.h"
#include "MatrixTypeDefs.h"
#include <iostream>
#include <sstream>

// TODO : Finish DivideByZeroError constructor

Matrix::DivideByZeroError::DivideByZeroError(double scalar): scalar(scalar) { // to prevent divide by zero error
  std::stringstream ZeroError;
  ZeroError << "Index out of bounds error" << std::endl;
  error = ZeroError.str();
}