#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the dp table for single matrix (cost is 0)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dimensions[i] * dimensions[k+1] * dimensions[j+1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    int N;
    cin >> N;

    vector<int> dimensions(N);
    for (int i = 0; i < N; i++) {
        cin >> dimensions[i];
    }

    cout << matrixChainMultiplication(dimensions) << endl;

    return 0;
}

/*

Grid Multiplication

Report

Given a sequence of grids with dimensions specified in an array arr[] of size N (where N represents the number of grids plus one), the task is to determine the most efficient approach to multiply these grids. Efficiency, in this context, refers to minimizing the total number of multiplications required.

The dimension of the ith matrix is arr[i-1] x arr[i]

Example:

Input:

5

40

20

30 10

30

Output:

26000

Explanation:

There are four grids denoted as A, B, C and D with dimensions 40 * 20 20 * 30 30 * 10 , and 10 * 30 respectively.

The most efficient sequence of multiplications is ((Ax (B x C)) x D)

The minimum is 20 * 30 * 10 40 * 20 * 10 40×10×30 26000 multiplications.

Constraints:

2≤ N ≤100

1s arr[i] ≤500

Input Format:

The first line contains an integer N, representing the number of grids.

The second line contains N space-separated integers, representing the dimensions of the grids.

Output Format:

The output consists of a single line containing an integer, representing the minimum number of multiplications required to efficiently multiply the given sequence of grids.

Sample Input 1

4

18 38 5 60

Sample Output 1

4506

A

Sample Input 2

5

48 29

30 18 38

120.45

Sample Output 2

26009


*/
