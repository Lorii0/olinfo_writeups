#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

ifstream inputFile("input.txt");
ofstream outputFile("output.txt");

int main() {
  int testCases;
  inputFile >> testCases;

  for (int caseNum = 1; caseNum <= testCases; ++caseNum) {
    int rows, cols, obstacles, height, width;
    inputFile >> rows >> cols >> obstacles >> height >> width;

    vector<vector<char>> forest(rows, vector<char>(cols, 0));
    for (int i = 0; i < obstacles; ++i) {
      int x, y;
      inputFile >> x >> y;
      forest[x][y] += 1;
    }

    vector<vector<int>> rowPrefixSum(rows, vector<int>(cols, 0));
    for (int r = 0; r < rows; ++r) {
      rowPrefixSum[r][0] = forest[r][0];
      for (int c = 1; c < cols; ++c) {
        rowPrefixSum[r][c] = rowPrefixSum[r][c - 1] + forest[r][c];
      }
    }

    int minSum = INT_MAX;
    vector<vector<int>> rectSums(rows, vector<int>(cols, 0));

    for (int c = width - 1; c < cols; ++c) {
      int initialSum = 0;
      for (int r = 0; r < height; ++r) {
        initialSum +=
            rowPrefixSum[r][c] - (c >= width ? rowPrefixSum[r][c - width] : 0);
      }
      rectSums[height - 1][c] = initialSum;
      minSum = std::min(minSum, initialSum);
    }

    for (int r = height; r < rows; ++r) {
      for (int c = width - 1; c < cols; ++c) {
        rectSums[r][c] =
            rectSums[r - 1][c] +
            (rowPrefixSum[r][c] -
             (c >= width ? rowPrefixSum[r][c - width] : 0)) -
            (rowPrefixSum[r - height][c] -
             (c >= width ? rowPrefixSum[r - height][c - width] : 0));
        minSum = std::min(minSum, rectSums[r][c]);
      }
    }

    outputFile << "Case #" << caseNum << ": " << minSum << '\n';
  }

  return 0;
}
