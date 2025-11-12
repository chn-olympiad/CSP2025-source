#include<bits/stdc++.h>
#define int long long
#define typ array<int,4>
using namespace std;
const int N=4e5+5;
int n;
typ a[N];
int Ans;
bool solve1(){
    int cnt[3];
    cnt[0]=cnt[1]=cnt[2]=0;
    int ans=0;
    for(int i=1;i<=n;++i){
        int p=max_element(a[i].begin(),a[i].begin()+3)-a[i].begin();
        cnt[p]++;
        ans+=a[i][p];
    }
    for(int i=0;i<=2;++i)if(cnt[i]>n/2)return 0;
    Ans=max(Ans,ans);
    return 1;
}
void solve2(int id){
    for(int i=1;i<=n;++i){
        a[i][3]=0;
        for(int j=0;j<=2;++j)if(j!=id)a[i][3]=max(a[i][3],a[i][j]);
    }
    sort(a+1,a+n+1,[&](typ x,typ y){
        return x[id]-x[3]>y[id]-y[3];
    });
    int ans=0;
    for(int i=1;i<=n/2;++i){
        ans+=a[i][id];
    }
    for(int i=n/2+1;i<=n;++i){
        ans+=a[i][3];
    }
    Ans=max(Ans,ans);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=2;++j)cin>>a[i][j];
    }
    Ans=0;
    if(solve1()){
        cout<<Ans<<"\n";
        return;
    }
    solve2(0),solve2(1),solve2(2);
    cout<<Ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
}