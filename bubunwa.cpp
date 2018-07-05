#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,A;

    cin>>n>>A;

    vector<int> num(n);

    for(auto &x:num)cin>>x;


    vector<vector<bool>> memo(n+1,vector<bool>(10005));

    memo[0][0]=true;

    for(int i=0;i<n;i++){
        for(int k=0;k<=A;k++){


            memo[i+1][k] = memo[i][k];
            if(k-num[i]>=0)memo[i+1][k] = memo[i][k] || memo[i][k-num[i]];

        }
    }

    if(memo[n][A])cout<<"Yes"<<endl;
    else{
        cout<<"No"<<endl;
    }

}