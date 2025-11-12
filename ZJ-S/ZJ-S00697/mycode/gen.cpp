#include<bits/stdc++.h>
using namespace std;

const int N=20000,M=100000;
mt19937 rnd(time(0));
signed main(){
    int n=1000,m=100000,K=5;
    cout<<n<<" "<<m<<" "<<K<<"\n";
    for(int i=2;i<=n;++i){
        cout<<i<<" "<<rnd()%(i-1)+1<<" "<<rnd()%M<<"\n";
    }
    m-=(n-1);
    for(int i=1;i<=m;++i){
        int u=rnd()%n+1,v=rnd()%n+1;
        if(u==v)v=rnd()%n+1;
        cout<<u<<' '<<v<<" "<<rnd()%M<<"\n";
    }
    for(int i=1;i<=K;++i){
        cout<<rnd()%M<<" ";
        for(int j=1;j<=n;++j)cout<<rnd()%M<<" ";
        cout<<"\n";
    }
}