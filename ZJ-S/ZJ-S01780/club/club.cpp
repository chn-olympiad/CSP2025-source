#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[100100][4];
vector<int>v[4];
void solve(){
    cin>>n;
    v[1].clear(),v[2].clear();v[3].clear();
    for (int i=1;i<=n;i++)
    cin>>a[i][1]>>a[i][2]>>a[i][3];
    int ans=0;
    for (int i=1;i<=n;i++){
        int mx=-1,tmx=-1;
        for (int j=1;j<=3;j++)
        if(a[i][j]>mx)tmx=mx,mx=a[i][j];
        else tmx=max(tmx,a[i][j]);
        for (int j=1;j<=3;j++)
        if(mx==a[i][j]){
            v[j].push_back(mx-tmx);
            break;
        }
        ans+=mx;
    }
    for (int i=1;i<=3;i++)
    if(v[i].size()>n/2){
        sort(v[i].begin(),v[i].end());
        int sz=v[i].size();
        for (int j=0;j<sz-n/2;j++)
        ans-=v[i][j];
        break;
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
}