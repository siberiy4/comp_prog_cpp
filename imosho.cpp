//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2013
#include<bits/stdc++.h>
using namespace std;
#define KAZU 86400
#define rep(i, n) for (int i = 0;i<(n);i++)

int n;
int imos[86400];

void solve(){
     rep(i, n){
         int s[3];
         int t[3];
        scanf("%d:%d:%d", &s[0], &s[1], &s[2]);
        scanf("%d:%d:%d", &t[0], &t[1], &t[2]);

        //hh:mm:ssを秒に変換
        int S=s[2]+60*(s[1]+s[0]*60);
        int T=t[2]+60*(t[1]+t[0]*60);

        //入る時間に　＋1
        imos[S]++;

        //出る時間に　-１
        imos[T]--;
        
        //ナイーブな実装
        // for(int j=s;j<=T;j++) imos[j]++; 
    }
    //累積和を計算する
    rep(i,KAZU) if(i)imos[i]+=imos[i-1];

    int ans=0;
    rep(i,KAZU)ans=max(ans,imos[i]);

    cout<<ans<<endl;
    
}

int main(){
    //こう書くとn==0のときにwhileループが停止
    while(cin>>n, n){
        rep(i,KAZU)imos[i]=0;
        solve();
    }
}