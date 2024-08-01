#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here

        int n = matrix.size(),m=matrix[0].size(),s=n*m;
        //a -> row start, b -> col start, c -> row end, d -> col end
        int a=0,b=0,c=n-1,d=m-1;
        vector<int> ans;
        while(ans.size()<s){
            for(int i=b;i<=d && ans.size()<s;i++)ans.push_back(matrix[a][i]);
            a++;
            for(int i=a;i<=c && ans.size()<s;i++)ans.push_back(matrix[i][d]);
            d--;
            for(int i=d;i>=b && ans.size()<s;i--)ans.push_back(matrix[c][i]);
            c--;
            for(int i=c;i>=a && ans.size()<s;i--)ans.push_back(matrix[i][b]);
            b++;
        }
        return ans;

    }
};

int main(){

    int row, col;
    cin>>row>>col;

    vector<vector<int>> matrix (row, vector<int> (col, 0));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>> matrix[i][j];
        }
    }

    Solution s;
    vector<int> result = s.spirallyTraverse(matrix);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}

