#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter String: " << endl;
    cin >> s;

    int max = -1;
    string currStr = "";

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            currStr += s[i];
        } else {
            if (!currStr.empty()) {
                int num = stoi(currStr);
                if (num > max) {
                    max = num;
                    cout << "max: " << max << endl;
                }
                currStr.clear();
            }
        }
    }

    if (!currStr.empty()) {
        int num = stoi(currStr);
        if (num > max) {
            max = num;
        }
    }

    if (max != -1) {
        cout << "The maximum number in the string is: " << max << endl;
    } else {
        cout << "No numbers found in the string." << endl;
    }

    return 0;
}


/*
int main()
{

    string s;

    cout<<"Enter String : "<<endl;
    cin>>s;

    string maxNumStr = "";
    string currentNumStr = "";

    for (char ch : s) {
        if (isdigit(ch)) {
            //cout<<"isdigit(ch) "<<isdigit(ch)<<endl;
            currentNumStr += ch;
            cout<<"currentNumStr "<<currentNumStr<<endl;
        } else {
            if (!currentNumStr.empty()) {
                if (maxNumStr.empty() || stoi(currentNumStr) > stoi(maxNumStr)) {
                    maxNumStr = currentNumStr;
                    cout<<"maxNumStr "<<maxNumStr<<endl;
                }
                currentNumStr.clear();
            }
        }
    }

    // Check the last number segment if the string ended with a number
    if (!currentNumStr.empty() && (maxNumStr.empty() || stoi(currentNumStr) > stoi(maxNumStr))) {
        maxNumStr = currentNumStr;
        cout<<"maxNumStr "<<maxNumStr<<endl;
    }

    if (!maxNumStr.empty()) {
        cout << "The maximum number in the string is: " << maxNumStr <<endl;
    } else {
        cout << "No numbers found in the string." <<endl;
    }

    return 0;
}
*/
