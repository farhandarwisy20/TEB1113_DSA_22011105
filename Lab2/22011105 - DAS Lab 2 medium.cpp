#include <iostream>
#include <vector>
using namespace std;

void booleanMatrix(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1) {
              
              	for (int idx = 0; idx < rows; idx++) {
                  	if (mat[idx][j] == 0) {
                      	mat[idx][j] = -1;
                    }
                }
              	
              	for (int idx = 0; idx < cols; idx++) {
                  	if (mat[i][idx] == 0) {
                      	mat[i][idx] = -1;
                    }
                }
            }
        }
    }
  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == -1) {
                mat[i][j] = 1;
            }
        }
    }
}

int main() {
    vector<vector<int>> mat = {{1, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    booleanMatrix(mat);
    for (const vector<int>& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
