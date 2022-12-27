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

int dpOfBag_2(int bag){
    vector<int> weight = {4,5,6,2,2};
    vector<int> value = {6,4,5,3,6};
    vector<int> dp(bag,0);
    for(int i = weight[0]-1;i<bag;i++) dp[i] = value[0];
    for(int i = 1;i<weight.size();i++){
        for(int j = bag;j>=weight[i];j--){
            if(j>=weight[i]) dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[bag-1];

}



int main() {
    int bag;
    cin>>bag;
    auto maxValue = dpOfBag_2(bag);
    cout<<"Max Value of Bag of "<<bag<<" kg is: "<<maxValue<<std::endl;
    return 0;
}
