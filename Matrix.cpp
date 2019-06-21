#include <vector>
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Matrix.h"
#include "Vector.h"
#include <Exception/DivideByZeroError.h>
#include "DivideByZeroError.h"
#include "MatrixOutOfBoundsError.h"
#include "MatrixInnerDimensionMismatchError.h"
#include "MatrixDimensionMismatchError.h"


Matrix::Matrix::Matrix(SizeType numRows, SizeType numCols, const ValueType& val):
contents(numRows, {numCols, val}), numRows(numRows), numCols(numCols) 
{

}

Matrix::Matrix::Matrix(SizeType numRows, SizeType numCols) : numRows(numRows), numCols(numCols) {
  contents = std::vector<Vector>(numRows, {numCols, 0});
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      contents.at(i).at(j) = 0;
    }
  }

}

Matrix::Matrix::Matrix(const std::vector<Vector>& contents):contents(contents), numRows(contents.size()), numCols(contents[0].size())  {

}

Matrix::Matrix::Matrix(const std::vector<std::vector<ValueType>>& contents) {
  numRows = contents.size();
  numCols = contents.at(0).size();
  (*this).contents = std::vector<Vector>(numRows, {numCols, 0});
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      (*this).contents.at(i).at(j) = contents.at(i).at(j);
    }
  }
}

Matrix::SizeType Matrix::Matrix::getNumRows() const{
  return numRows;
}

Matrix::SizeType Matrix::Matrix::getNumCols() const{
  return numCols;
}


//gives the vector at row
Matrix::Vector& Matrix::Matrix::at(int row) {
  if (row < 0 || row > getNumRows()-1) {
    throw MatrixOutOfBoundsError(*this, row);
  }
  return contents.at(row);
}

const Matrix::Vector& Matrix::Matrix::at(int row) const{
  if (row < 0 || row > getNumRows()-1){
    throw MatrixOutOfBoundsError(*this, row);
  }
  return contents.at(row);
}

Matrix::Vector& Matrix::Matrix::operator[](int row){
  if (row < 0 || row > getNumRows()-1){
    throw MatrixOutOfBoundsError(*this, row);
  }
  return contents.at(row);
}

const Matrix::Vector& Matrix::Matrix::operator[](int row) const{
  if (row < 0 || row > getNumRows()-1){
    throw MatrixOutOfBoundsError(*this, row);
  }
  return contents.at(row);
}

Matrix::ValueType& Matrix::Matrix::at(int row, int col){
  if (row < 0 || row > getNumRows()-1){
    throw MatrixOutOfBoundsError(*this, row);}
    if (col < 0 || col > getNumCols()-1){
      throw MatrixOutOfBoundsError(*this, row, col);
  }
  return contents.at(row).at(col);
}


const Matrix::ValueType& Matrix::Matrix::at(int row, int col) const{
  if (col < 0 || col > getNumCols()-1){
    throw MatrixOutOfBoundsError(*this, row, col);
  }
  if (row < 0 || row > getNumRows()-1){
    throw MatrixOutOfBoundsError(*this, row);}
  return contents[row][col];
}



Matrix::Matrix Matrix::Matrix::transpose() const { // matrix transpose returned
  Matrix transposeMatrix(numCols, numRows);
  for (int i = 0; i < numCols; ++i) {
    for (int j = 0; j < numRows; ++j) {
      transposeMatrix.at(i).at(j) = contents[j][i];
    }
  }
  return transposeMatrix;
}

Matrix::Vector Matrix::Matrix::getContents() const{ /// done at CSIF
  for (int i = 0; i < numRows ; ++i)  {
    return contents.at(i);
  }
  return 0;
}

Matrix::Matrix Matrix::Matrix::ident(Matrix::SizeType dim) {
  Matrix matrix = Matrix(dim, dim);
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      if (j == i) {
        matrix.at(j).at(i) = 1;
      } else {
        matrix.at(j).at(i) = 0;

      }
    }
  }
  return matrix;
}

std::ostream& Matrix::operator<<(std::ostream& out, const Matrix& matrix) {
  for (int i = 0; i <  matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      out << matrix.at(i).at(j);
    }
  }
  return out;
}

std::istream& Matrix::operator>>(std::istream& in, Matrix& matrix) {
  for (int i = 0; i <  matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      in >> matrix.at(i).at(j);
    }
  }
  return in;
}

Matrix::Matrix Matrix::operator-(const Matrix& self) {
  Matrix newMatrix = self.getContents();
  for (int i = 0; i < self.getNumRows(); ++i) {
    for (int j = 0; j < self.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = -(newMatrix.at(i).at(j));
    }
  }
  return newMatrix;
}

Matrix::Matrix Matrix::operator+(const Matrix& matrix, const Matrix::ValueType& scalar) {
  Matrix newMatrix = Matrix(matrix.getNumRows(), matrix.getNumCols());
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = matrix.at(i).at(j) + scalar;
    }
  }
  return newMatrix;
}

Matrix::Matrix& Matrix::operator-=(Matrix& matrix, const Matrix::ValueType& scalar) {
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      matrix.at(i).at(j) = matrix.at(i).at(j) - scalar;
    }
  }
  return matrix;
}

Matrix::Matrix& Matrix::operator+=(Matrix& matrix, const Matrix::ValueType& scalar) { //
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      matrix.at(i).at(j) = matrix.at(i).at(j) + scalar;
    }
  }
  return matrix;
}

Matrix::Matrix Matrix::operator+(const Matrix::ValueType& scalar, const Matrix& matrix) {
  Matrix newMatrix = Matrix(matrix.getNumRows(), matrix.getNumCols());
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = matrix.at(i).at(j) + scalar;
    }
  }
  return newMatrix;
}

Matrix::Matrix Matrix::operator-(const Matrix& matrix, const Matrix::ValueType& scalar) {
  Matrix newMatrix = Matrix(matrix.getNumRows(), matrix.getNumCols());
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = matrix.at(i).at(j) - scalar;
    }
  }
  return newMatrix;
}

Matrix::Matrix Matrix::operator-(const ValueType& scalar, const Matrix& matrix) {
  Matrix newMatrix = Matrix(matrix.getNumRows(), matrix.getNumCols());
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    //newMatrix[i] = std::vector<ValueType>(numCols);
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = scalar - matrix.at(i).at(j) ;
    }
  }
  return newMatrix;
}

Matrix::Matrix& Matrix::operator*=(Matrix& matrix, const Matrix::ValueType& scalar) {
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      matrix.at(i).at(j) = matrix.at(i).at(j) * scalar;
    }
  }
  return matrix;
}

Matrix::Matrix Matrix::operator*(const Matrix& matrix, const Matrix::ValueType& scalar) {
  Matrix newMatrix = Matrix(matrix.getNumRows(), matrix.getNumCols());
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = matrix.at(i).at(j) * scalar;
    }
  }
  return newMatrix;
}

Matrix::Matrix Matrix::operator*(const Matrix::ValueType& scalar, const Matrix& matrix) {
  Matrix newMatrix = Matrix(matrix.getNumRows(), matrix.getNumCols());
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = matrix.at(i).at(j) * scalar;
    }
  }
  return newMatrix;
}

Matrix::Matrix& Matrix::operator/=(Matrix& matrix, const Matrix::ValueType& scalar) {
  if (scalar == 0){
    throw DivideByZeroError(scalar);
  }
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      matrix.at(i).at(j) = matrix.at(i).at(j) / scalar;
    }
  }
  return matrix;
}

Matrix::Matrix Matrix::operator/(const Matrix& matrix, const Matrix::ValueType& scalar) {
  if (scalar == 0){
    throw DivideByZeroError(scalar);
  }
  Matrix newMatrix = Matrix(matrix.getNumRows(), matrix.getNumCols());
  for (int i = 0; i < matrix.getNumRows(); ++i) {
    for (int j = 0; j < matrix.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = matrix.at(i).at(j) / scalar;
    }
  }
  return newMatrix;
}

Matrix::Matrix& Matrix::operator+=(Matrix& lhs, const Matrix& rhs) {
  if (lhs.getNumRows() != rhs.getNumRows() && lhs.getNumCols() != rhs.getNumCols()) {
    throw MatrixDimensionMismatchError();
  }
  for (int i = 0; i < lhs.getNumRows(); ++i) {
    for (int j = 0; j < lhs.getNumCols(); ++j) {
      lhs.at(i).at(j) = lhs.at(i).at(j) + rhs.at(i).at(j);
    }
  }

  return lhs;
}

Matrix::Matrix Matrix::operator+(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.getNumRows() != rhs.getNumRows() && lhs.getNumCols() != rhs.getNumCols()) {
    throw MatrixDimensionMismatchError();
  }
    Matrix newMatrix = Matrix(lhs.getNumRows(), lhs.getNumCols());

    for (int i = 0; i < lhs.getNumRows(); ++i) {
      for (int j = 0; j < lhs.getNumCols(); ++j) {
        newMatrix.at(i).at(j) = lhs.at(i).at(j) + rhs.at(i).at(j);
      }
    }

    return newMatrix;
  }


Matrix::Matrix& Matrix::operator-=(Matrix& lhs, const Matrix& rhs) {
  if (lhs.getNumRows() != rhs.getNumRows() && lhs.getNumCols() != rhs.getNumCols()) {
    throw MatrixDimensionMismatchError();
  }
    for (int i = 0; i < lhs.getNumRows(); ++i) {
      for (int j = 0; j < lhs.getNumCols(); ++j) {
        lhs.at(i).at(j) = lhs.at(i).at(j) - rhs.at(i).at(j);
      }
    }
  return lhs;
}

Matrix::Matrix Matrix::operator-(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.getNumRows() != rhs.getNumRows() && lhs.getNumCols() != rhs.getNumCols()) {
    throw MatrixDimensionMismatchError();
  }

  Matrix newMatrix = Matrix(lhs.getNumRows(), lhs.getNumCols());

    for (int i = 0; i < lhs.getNumRows(); ++i) {
      for (int j = 0; j < lhs.getNumCols(); ++j) {
        newMatrix.at(i).at(j) = lhs.at(i).at(j) - rhs.at(i).at(j);
      }
    }

  return newMatrix;
}

Matrix::Matrix& Matrix::operator*=(Matrix& lhs, const Matrix& rhs) {
  if (lhs.getNumCols() != rhs.getNumRows()){
    throw MatrixInnerDimensionMismatchError();
  }
  if (lhs.getNumRows() != rhs.getNumRows() && lhs.getNumCols() != rhs.getNumCols()) {
    throw MatrixDimensionMismatchError();
  }
  Matrix newMatrix = Matrix(lhs.getNumRows(), rhs.getNumCols());
  for (int i = 0; i < lhs.getNumRows(); ++i) {
    for (int j = 0; j < rhs.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = 0;
      for(int k=0; k< rhs.getNumRows(); ++k){
        newMatrix.at(i).at(j) += lhs.at(i).at(k) * rhs.at(k).at(j);
      }
    }
  }
  lhs = newMatrix;
  return lhs;
}

Matrix::Matrix Matrix::operator*(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.getNumCols() != rhs.getNumRows()){
    throw MatrixInnerDimensionMismatchError();
  }
  if (lhs.getNumRows() != rhs.getNumRows() && lhs.getNumCols() != rhs.getNumCols()) {
    throw MatrixDimensionMismatchError();
  }
  Matrix newMatrix = Matrix(lhs.getNumRows(), rhs.getNumCols());
  for (int i = 0; i < lhs.getNumRows(); ++i) {
    for (int j = 0; j < rhs.getNumCols(); ++j) {
      newMatrix.at(i).at(j) = 0;
      for (int k = 0; k < rhs.getNumRows(); ++k) {
        newMatrix.at(i).at(j) += lhs.at(i).at(k) * rhs.at(k).at(j);
      }
    }
  }
  return newMatrix;

}
