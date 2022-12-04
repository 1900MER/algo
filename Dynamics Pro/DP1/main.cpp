#include <iostream>
#include <vector>
using namespace std;
int dpOfBag(int bag){
    vector<int> weight = {4,5,6,2,2};
    vector<int> value = {6,4,5,3,6};
    vector<vector<int>> dp{5,vector<int>(bag+1,0)};

    for(int i = weight[0];i<=bag;i++) dp[0][i] = value[0];

    for(int i = 1;i < weight.size(); i++){
        for(int j =1;j<=bag;j++){
            if(j<weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j-weight[i]]+value[i] >= dp[i-1][j]? dp[i-1][j-weight[i]]+value[i]:dp[i-1][j];
        }
    }
    return dp[weight.size()-1][bag];
}



int main() {
    int bag;
    cin>>bag;
    auto maxValue = dpOfBag(bag);
    cout<<"Max Value of Bag of "<<bag<<" kg is: "<<maxValue<<std::endl;
    return 0;
}
