/*
Product Name Transformation

Report

You are managing an e-commerce platform and have two product names productA and products that may have slight differences in their spelling due. to typos or variations in data entry. Your task is to determine the minimum number of operations required to convert productA into productB The allowed operations are:

1. Inserting a character

2. Deleting a character

3. Replacing a character

Example 1:

Input:

productA= "abcdef", productB = "azced"

Output:

3

Explanation:

abcdef azcdef (replace b with z)

azcdef azcde (remove f)

azcde azced (replace d with e)


Example 2:

Input:

productA= "bat", productB "ball"

Output:

1

Explanation:

bat bal (replace t with 1)

bal ball (insert 1)

Your Task

Complete the provided function productNameTransformation that takes two arguments:

• productA: A string representing the first product name.

productB A string representing the second product name.

Constraints:

0 <= productA.length productB.length <= 400

productA and productB consist of lowercase English letters.

Input Format:

The first line contains the string productA

The second line contains the string product

Output Format:

• The output is a single integer representing the minimum number of operations required to convert productA into productB.

Sample Input 1

abodef azced

Sample Output 1

3

Sample input 2

bat

ball

Sample Output 2

2
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int productNameTransformation(string productA, string productB) {
    int m = productA.length();
    int n = productB.length();

    // Create a matrix to store the edit distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and column
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the dp matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (productA[i - 1] == productB[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],     // deletion
                                    dp[i][j - 1],     // insertion
                                    dp[i - 1][j - 1]  // replacement
                                   });
            }
        }
    }

    // Return the minimum number of operations
    return dp[m][n];
}

int main() {
    string productA, productB;

    // Read input
    getline(cin, productA);
    getline(cin, productB);

    // Calculate and output the result
    cout << productNameTransformation(productA, productB) << endl;

    return 0;
}
