#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string boldenKeywords(const vector<string>& keywords, const string& text) {
    vector<pair<int, int>> intervals;

    // Find all occurrences of keywords in the text
    for (const string& keyword : keywords) {
        size_t pos = text.find(keyword);
        while (pos != string::npos) {
            intervals.push_back({pos, pos + keyword.length()});
            pos = text.find(keyword, pos + 1);
        }
    }

    // Sort intervals by start position
    sort(intervals.begin(), intervals.end());

    // Merge overlapping intervals
    vector<pair<int, int>> mergedIntervals;
    for (const auto& interval : intervals) {
        if (mergedIntervals.empty() || interval.first > mergedIntervals.back().second) {
            mergedIntervals.push_back(interval);
        } else {
            mergedIntervals.back().second = max(mergedIntervals.back().second, interval.second);
        }
    }

    // Construct the result string
    string result;
    int lastPos = 0;
    for (const auto& interval : mergedIntervals) {
        result += text.substr(lastPos, interval.first - lastPos);
        result += "<b>" + text.substr(interval.first, interval.second - interval.first) + "</b>";
        lastPos = interval.second;
    }
    result += text.substr(lastPos);

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<string> keywords(N);
    for (int i = 0; i < N; i++) {
        cin >> keywords[i];
    }

    string text;
    cin >> text;

    cout << boldenKeywords(keywords, text) << endl;

    return 0;
}

/*

Keyword Boldening in Text

In a given text, you are to bolden specific keywords using HTML-like tags. You will receive a list of keywords and a text string. Your goal is to insert and tags around all occurrences of these keywords in the text. The output should contain the minimum number of tags required, and the tags must not overlap Improperty.

Example 1:

Input:

keywords = ["pro", "gram"], text = "programit"

Output:

"<b>program</b>it"

Explanation:

The keyword "pro" starts at the beginning and "gram" continues from the third character. Using one set of tags from the start of "pro" to the end of "gram" is most efficient.

Example 2:

Input:

200

keywords = ["gram", "ing"], text = "programmingisfun"

Input Format:

The first line contains an integer N representing the number of keywords.

The following N lines contain the keywords.

The next line contains the text string.

Output Format:

A string with the keywords bolded using the <b> and </b> tags, formatted to use the minimal number of tags.

Sample Input 1-

2 pro gram programit

Sample Output 1

<b>program</b>it

A

Sample Input 2

2

gran

ing

programmingisfun

Sample Output 2

20CA1

20

pro<b>gram</b>m<b>ing</b>isfun

Output:

"pro<b>gram</b>m<b>ing</b>isfun"

Explanation:

The keyword "gram" starts from the fourth character and ends at the seventh. "Ing" starts at the eighth character and ends at the tenth. Since these two segments don't overlap, they are enclosed in separate sets of bold tags.

Constraints:

0s len(keywords) $50

1s len(text) 5500

1s len(keywords[i]) ≤10

A

keywords and text consist of lowercase English letters.

Input Format:

The first line contains an integer N representing the number of keywords.

The following N lines contain the keywords.

The next line contains the text string.

Output Format:

20043

A string with the keywords bolded using the <b> and </b> tags, formatted to use the minimal number of tags.

*/
