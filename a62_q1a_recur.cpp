#include <bits/stdc++.h>
using namespace std;

vector <int> /* matrix element */ MatrixConstructor (int matrix_a_Value, int matrix_b_Value)
{
  // Base case
  if (!matrix_a_Value /* matrix_a_Value is 0 */) return {matrix_b_Value};

  // recursion Call
  int subMatrixDimension = pow(2, matrix_a_Value - 1);
  int subMatrixElementNum = subMatrixDimension * subMatrixDimension;
  vector <int> topLeft(subMatrixElementNum);
  topLeft = MatrixConstructor(matrix_a_Value - 1, matrix_b_Value);
  vector <int> topRight(subMatrixElementNum);
  topRight = MatrixConstructor(matrix_a_Value - 1, matrix_b_Value - 1);
  vector <int> bottomLeft(subMatrixElementNum);
  bottomLeft = MatrixConstructor(matrix_a_Value - 1, matrix_b_Value + 1);
  vector <int> bottomRight(subMatrixElementNum);
  bottomRight = MatrixConstructor(matrix_a_Value - 1, matrix_b_Value);

  // matrix vector creation
  int MatrixElementNum = subMatrixElementNum * 4;
  vector <int> fullMatrix;
  fullMatrix.reserve(MatrixElementNum);
  int currPosition{};
  for (int i = 0; i < subMatrixDimension; i++)
  {
    for (int j = currPosition; j < currPosition + subMatrixDimension; j++)
    {
      fullMatrix.push_back(topLeft.at(j));
    }

    for (int j = currPosition; j < currPosition + subMatrixDimension; j++)
    {
      fullMatrix.push_back(topRight.at(j));
    }
    currPosition += subMatrixDimension;
  }

  currPosition = 0;
  for (int i = 0; i < subMatrixDimension; i++)
  {
    for (int j = currPosition; j < currPosition + subMatrixDimension; j++)
    {
      fullMatrix.push_back(bottomLeft.at(j));
    }

    for (int j = currPosition; j < currPosition + subMatrixDimension; j++)
    {
      fullMatrix.push_back(bottomRight.at(j));
    }
    currPosition += subMatrixDimension;
  }

  return fullMatrix;
}

int main()
{
  int a{}, b{};
  cin >> a >> b;
  vector <int> completedMatrix = MatrixConstructor(a, b);
  int matrixDimension = pow(2, a);
  int currPosInLine{};
  for (int i = 0; i < matrixDimension * matrixDimension; i++)
  {
    cout << completedMatrix.at(i) << " ";
    if ((i + 1) % matrixDimension == 0) cout << "\n";
  }

  return 0;
}