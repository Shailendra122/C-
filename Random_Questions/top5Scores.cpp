#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> calculateTopFiveAverage(const vector<pair<int, int>>& scores) {
    map<int, priority_queue<int, vector<int>, greater<int>>> studentScores;

    // Group scores by student ID
    for (const auto& score : scores) {
        int studentId = score.first;
        int scoreValue = score.second;

        auto& pq = studentScores[studentId];
        pq.push(scoreValue);
        if (pq.size() > 5) {
            pq.pop(); // Keep only top 5 scores
        }
    }

    vector<pair<int, int>> result;

    // Calculate averages
    for (const auto& student : studentScores) {
        int studentId = student.first;
        auto pq = student.second;

        int sum = 0;
        int count = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
            count++;
        }

        int average = sum / count; // Integer division
        result.emplace_back(studentId, average);
    }

    // Sort by student ID
    sort(result.begin(), result.end());

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> scores;
    for (int i = 0; i < N; i++) {
        int studentId, score;
        cin >> studentId >> score;
        scores.emplace_back(studentId, score);
    }

    vector<pair<int, int>> result = calculateTopFiveAverage(scores);

    for (const auto& student : result) {
        cout << student.first << " " << student.second << endl;
    }

    return 0;
}

/*
Top Five Scores

Report

You are tasked with analyzing academic performance data. For each student, multiple test scores are recorded, and your goal is to calculate the average of their top five scores. This average should be computed using integer division.

Create a function that takes a list of score records, where each record is a pair (StudentID, Score] The function should return a list of pairs [StudentID, AverageTopFive], where Average TopFive is the integer average of the top five scores for that student. The resulting list should be sorted by StudentID in ascending order.

Example 1:

Input: scores = [[101,85], [101,82], [102,90], [102,96], [101,70], [102,85], [101,

Output: [[101,85], [102,90]]

Explanation:

The scores for StudentID = 101 are 85, 82, 70, 75, 88, and 95. The top five are 95, 88, 85, 82, and 75, leading to an average of (95+ 88858275)/5-84.

The scores for StudentID 102 are 90, 96, 85, 91, and 89. All scores are used, leading to an average of (96+91-90+89+85)/590.

Sample input i

11

101 85

181 82

102 90

182 96

181 78

102 85

101 75

101 88

101 95

182 91

162 89

Sample Output 1

101 85

102 90

Sample Input 2

10

261 188

202 198

201 100

202 108

281 108

282 100

201 100

282 188

281 108

282 168

Sample Output 2

201 188

202 180


Explanation:

Both students have the same top five scores: 100, 100, 100, 100, and 100. Thus, their top five average is 100.

Constraints:

5< N < 1000

1<= StudentID <= 1000

0< Score <= 100

Each student has at least five score records.

Input Format:

The first line contains an integer N, representing the number of score records.

The next N lines each contain two integers, StudentID and Score, separated by a

*/
