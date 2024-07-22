#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    if (arr[0] == 0) return -1;

    int maxReach = arr[0];
    int stepsLeft = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;

        maxReach = max(maxReach, i + arr[i]);
        stepsLeft--;

        if (stepsLeft == 0) {
            jumps++;

            if (i >= maxReach) return -1;

            stepsLeft = maxReach - i;
        }
    }

    return -1;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << minJumps(arr) << endl;

    return 0;
}

/*
Hops to Reach the end

You are given an array of N integers, arr[], where each element represents the maximum distance you can jump forward from that position. In other words, if arr[i]x, you can jump any distance y such that ysx

Your task is to find the minimum number of jumps needed to reach the end of the array, starting from the first element. If an element is 0, it means you cannot move through that element.

If it is not possible to reach the end of the array, print -1.

Example:

Input:

11

13589267689

Output:

3

Explanation:

The first jump is from the 1st element to the 2nd element with a value of 3

The second jump is from the 2nd element to the 5th element with a value of 9.

The third jump is from the 5th element to the last element.

Constraints:

15 N10^2

0 arr[i] 10^2

Input Format:

The input consists of two lines.

The first line contains an integer N, representing the number of elements in the array.

The second line contains N space-separated integers, representing the elements in the array.

Output Format:

The output should be a single line containing the minimum number of jumps required to reach the end of the array, starting from the first element.

Sample Input 1

11
1 3 5 8 9 2 6 7 6 8 9

Sample Output 1
3

Sample Input 2
6
1 4 3 2 6 7

Sample Output 2
2
*/
