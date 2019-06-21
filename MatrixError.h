//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_MATRIXERROR_H
#define MATRIX_MATRIXERROR_H
#include <iostream>
#include <exception>
#include <string>
#include "Matrix.h"

//base class used to signify an error happened in
//a vector or matrix
namespace Matrix {

//should inherit from std::exception
 class MatrixError  : public std::exception{
 public:
  //void catchMatrixError();
  //MatrixError();
  const char* what() const noexcept override;
 protected:
  std::string error;
};
}

#endif //MATRIX_MATRIXERROR_H
