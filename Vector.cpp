#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Matrix.h"
#include "Vector.h"
#include "VectorOutOfBoundsError.h"
#include "DivideByZeroError.h"
#include "VectorDimensionMismatchError.h"


// TODO: Vector Constructors

Matrix::Vector::Vector(const SizeType &numElements) : numElements(numElements) {
  for (int i = 0; i < numElements; ++i) {
    contents.push_back(0);
  }
} // vector where all elements initialize to 0

Matrix::Vector::Vector(const std::vector<ValueType> &contents){
  numElements = contents.size();
  (*this).contents.resize(numElements);
  for (int i = 0; i < numElements; ++i){
    (*this).contents.at(i) = contents.at(i);
  }
}

Matrix::SizeType Matrix::Vector::size() const {
  return numElements;
}

Matrix::Vector::Vector(const SizeType &numElements, const ValueType &value) : numElements(numElements){
  for (int i = 0; i < numElements; ++i) {
    contents.push_back(value);
  }
} //creating a vector numElements -> elements initialized to value


//conversion to matrix functions

//convert this vector to an N X 1 vector
Matrix::Matrix Matrix::Vector::asColMatrix() const {
  Matrix newContents = Matrix(size(), 1);

  for (int i = 0; i < newContents.getNumRows(); ++i) {
    for (int j = 0; j < 1; ++j) {
      newContents.at(i)[j] = contents.at(i);
    }
  }
  return newContents;
}

//convert this vector to a 1 X N vector
Matrix::Matrix Matrix::Vector::asRowMatrix() const {

  Matrix newContents = Matrix(1, size());

  for (int i = 0; i < 1; ++i) {
    for (int j = 0; j < newContents.getNumCols(); ++j) {
      newContents.at(i)[j] = contents[j];
    }
  }
  return newContents;
}

//return the element at index of that vector
const Matrix::ValueType &Matrix::Vector::at(int index) const {
  verifyInBounds(index);
  return contents.at(index);
}

Matrix::Vector::operator Matrix() const {
  Matrix newMatrix = (*this).asRowMatrix();
  return newMatrix;
}

Matrix::ValueType &Matrix::Vector::at(int index) {
  verifyInBounds(index);
  return contents.at(index);
}



// TODO : Operator functions


std::ostream &Matrix::operator<<(std::ostream &out, const Vector &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    out << vec.at(i) << " ";
  }
  return out;
}

std::istream &Matrix::operator>>(std::istream &in, Vector &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    in >> vec.at(i);
  }
  return in;
}

Matrix::Vector &Matrix::operator+=(Vector &vector, const Matrix::ValueType &scalar) {
  for (int i = 0; i < vector.size(); ++i) {
    vector.at(i) = vector.at(i) + scalar;
  }
  return vector;
}

Matrix::Vector Matrix::operator-(const Vector &self) {
  Vector newSelf(self.size());
  for (int i = 0; i < self.size(); ++i) {
    newSelf.at(i) = -(self.at(i));
  }
  return newSelf;
}

Matrix::Vector Matrix::operator+(const Vector &vector, const Matrix::ValueType &scalar) {
  Vector newVector(vector.size());
  for (int i = 0; i < vector.size(); ++i) {
    newVector.at(i) = vector.at(i) + scalar;
  }
  return newVector;
}

Matrix::Vector Matrix::operator+(const Matrix::ValueType &scalar, const Vector &vector) {
  Vector newVector(vector.size());
  for (int i = 0; i < vector.size(); ++i) {
    newVector.at(i) = vector.at(i) + scalar;
  }
  return newVector;
}

Matrix::Vector &Matrix::operator-=(Vector &vector, const Matrix::ValueType &scalar) {
  for (int i = 0; i < vector.size(); ++i) {
    vector.at(i) = vector.at(i) - scalar;
  }
  return vector;
}

Matrix::Vector Matrix::operator-(const Vector &vector, const Matrix::ValueType &scalar) {
  Vector newVector(vector.size());
  for (int i = 0; i < vector.size(); ++i) {
    newVector.at(i) = vector.at(i) - scalar;
  }
  return newVector;
}

Matrix::Vector Matrix::operator-(const Matrix::ValueType &scalar, const Vector &vector) {
  Vector newVector(vector.size());
  for (int i = 0; i < vector.size(); ++i) {
    newVector.at(i) = scalar - vector.at(i);
  }
  return newVector;
}

Matrix::Vector &Matrix::operator*=(Vector &vector, const Matrix::ValueType &scalar) {
  for (int i = 0; i < vector.size(); ++i) {
    vector.at(i) = vector.at(i) * scalar;
  }
  return vector;
}

Matrix::Vector Matrix::operator*(const Vector &vector, const Matrix::ValueType &scalar) {
  Vector newVector(vector.size());
  for (int i = 0; i < vector.size(); ++i) {
    newVector.at(i) = vector.at(i) * scalar;
  }
  return newVector;
}

Matrix::Vector Matrix::operator*(const Matrix::ValueType &scalar, const Vector &vector) {
  Vector newVector(vector.size());
  for (int i = 0; i < vector.size(); ++i) {
    newVector.at(i) = vector.at(i) * scalar;
  }
  return newVector;
}

Matrix::Vector &Matrix::operator/=(Vector &vector, const Matrix::ValueType &scalar) {
  if (scalar == 0) {
    throw DivideByZeroError(scalar);
  } else {
    for (int i = 0; i < vector.size(); ++i) {
      vector.at(i) = vector.at(i) / scalar;
    }
    return vector;
  }
}

Matrix::Vector Matrix::operator/(const Vector &vector, const Matrix::ValueType &scalar) {
  if (scalar == 0) {
    throw DivideByZeroError(scalar);
  } else {
    Vector newVector(vector.size());
    for (int i = 0; i < vector.size(); ++i) {
      newVector.at(i) = vector.at(i) / scalar;
    }
    return newVector;
  }
}

Matrix::Vector &Matrix::operator+=(Vector &lhs, const Vector &rhs) {
  if (lhs.size() != rhs.size()) {
    throw VectorDimensionMismatchError(lhs.size());
  }
  std::vector<ValueType> contentsTwo;
  for (int i = 0; i < lhs.size(); ++i) {
    lhs.at(i) = lhs.at(i) + rhs.at(i);
  }

  return lhs;
}

Matrix::Vector Matrix::operator+(const Vector &lhs, const Vector &rhs) {
  if (lhs.size() != rhs.size()) {
    throw VectorDimensionMismatchError(lhs.size());
  }
  Vector newVector(lhs.size());

  for (int i = 0; i < lhs.size(); ++i) {
    newVector.at(i) = lhs.at(i) + rhs.at(i);
  }

  return newVector;
}

Matrix::Vector &Matrix::operator-=(Vector &lhs, const Vector &rhs) {
  if (lhs.size() != rhs.size()) {
    throw VectorDimensionMismatchError(lhs.size());
  }
  for (int i = 0; i < lhs.size(); ++i) {
    lhs.at(i) = lhs.at(i) - rhs.at(i);
  }

  return lhs;
}

Matrix::Vector Matrix::operator-(const Vector &lhs, const Vector &rhs) {
  if (lhs.size() != rhs.size()) {
    throw VectorDimensionMismatchError(lhs.size());
  }
  Vector newVector(lhs.size());
  for (int i = 0; i < lhs.size(); ++i) {
    newVector.at(i) = lhs.at(i) - rhs.at(i);
  }
  return newVector;
}

Matrix::ValueType Matrix::operator*=(Vector &lhs, const Vector &rhs) {
  if (lhs.size() != rhs.size()) {
    throw VectorDimensionMismatchError(lhs.size());
  }
  ValueType total = 0;
  for (int i = 0; i < lhs.size(); ++i) {
    lhs.at(i) = lhs.at(i) * rhs.at(i);
  }
  for (int j = 0; j < lhs.size(); ++j) {
    total += lhs[j];
  }
  lhs = Vector(1, total);
  return total;
}

Matrix::ValueType Matrix::operator*(const Vector &lhs, const Vector &rhs) {
  if (lhs.size() != rhs.size()) {
    throw VectorDimensionMismatchError(lhs.size());
  }
  Vector newVector(lhs.size());
  ValueType total = 0;
  for (int i = 0; i < lhs.size(); ++i) {
    newVector.at(i) = lhs.at(i) * rhs.at(i);
  }
  for (int j = 0; j < lhs.size(); ++j) {
    total += newVector[j];
  }

  return total;
}

void Matrix::Vector::verifyInBounds(int index) const {
  if (index < 0 || index > size() - 1) {
    throw VectorOutOfBoundsError(*this, index);
  }
}