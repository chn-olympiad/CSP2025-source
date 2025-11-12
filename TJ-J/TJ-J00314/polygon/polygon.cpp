#include <bits/stdc++.h>
using namespace std;

const int P=998244353;
int n,a[5005],ans;

inline void solve1(){
    if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
        cout<<1;
    }else{
        cout<<0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3){
        cout<<0;return 0;
    }else if(n==3){
        solve1();
    }
    return 0;
}
// I love you,SYH;
