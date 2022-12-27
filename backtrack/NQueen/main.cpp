#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> element;

    bool isValid(vector<int> element){
        int size = element.size();
        for(int i = 0 ; i < size ;i++ ){
            for( int j = i+1;j<size;j++)
                if( abs(element[j]-element[i]) == abs(j-i) ) return false;
        }
        return true;
    }

    void backtrack(int n, int row, vector<bool> used){
        if( !isValid(element) ) return;

        if(element.size()==n) {
            result.push_back(element);
            return;
        }


        for(int i = 0; i < n; i++){
            if (used[i] == true) continue;
            element.push_back(i);
            used[i] = true;
            backtrack(n, row + 1, used);
            used[i] = false;
            element.pop_back();

        }
    }
public:
    vector<vector<int>> solveNQueens(int n) {
        vector<bool> used(n,false);
        backtrack(n,0,used);
        return result;
    }
};



int main() {
    Solution s1;
    int n =8;
    auto array = s1.solveNQueens(n);
    for(int i = 0;i<array.size();i++){
        for(int j =0;j<n;j++) cout<<array[i][j]<<" ";
        cout<<endl;
    }
    cout<<array.size();
    return 0;
}
