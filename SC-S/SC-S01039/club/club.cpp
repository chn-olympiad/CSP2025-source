#include<bits/stdc++.h>
using namespace std;
bool Mbe;
const int N=1e5+7;
int n;
struct node{int w[3],val;}a[N];
int getmid(int x,int y,int z){
    int w[3]={x,y,z};sort(w+0,w+3);return w[1];
}
bool cmp(const node &x,const node &y){return x.val>y.val;}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].w[0]>>a[i].w[1]>>a[i].w[2],a[i].val=max(a[i].w[0],max(a[i].w[1],a[i].w[2]))-getmid(a[i].w[0],a[i].w[1],a[i].w[2]);
    sort(a+1,a+n+1,cmp);
    int cnt[3]={0,0,0},ans=0;
    for(int i=1;i<=n;i++){
        int id=0;
        for(int j=1;j<3;j++)if(a[i].w[id]<a[i].w[j])id=j;
        if(cnt[id]==n/2)ans+=getmid(a[i].w[0],a[i].w[1],a[i].w[2]);
        else cnt[id]++,ans+=max(a[i].w[0],max(a[i].w[1],a[i].w[2]));
        // for(int j=0;j<3;j++)cout<<"* "<<cnt[j]<<' ';
        // cout<<'\n'<<id<<'\n';
    }
    cout<<ans<<'\n';
}
bool Med;
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;while(T--)solve();
    cerr<<'\n'<<fabs(&Mbe-&Med)/1048576.0<<"Mb\n";
    return 0;
}