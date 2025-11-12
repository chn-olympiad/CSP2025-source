#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5;
int n,a[N][3],tmp[N];
bool vis[N];
void solve(){
    cin>>n;
    int c0=0,c1=0,c2=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(a[i][0]>a[i][1]){
            if(a[i][0]>a[i][2])c0++,ans+=a[i][0];
            else c2++,ans+=a[i][2];
        }else{
            if(a[i][1]>a[i][2])c1++,ans+=a[i][1];
            else c2++,ans+=a[i][2];
        }
    }
    // cout<<c0<<' '<<c1<<' '<<c2<<' ';
    int id=-1;
    if(c0>n/2)id=0;
    if(c1>n/2)id=1;
    if(c2>n/2)id=2;
    if(~id){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i][0]>a[i][1]){
                if(a[i][0]>a[i][2]){if(id==0)tmp[++cnt]=a[i][0]-max(a[i][1],a[i][2]);}
                else if(id==2)tmp[++cnt]=a[i][2]-max(a[i][0],a[i][1]);
            }else{
                if(a[i][1]>a[i][2]){if(id==1)tmp[++cnt]=a[i][1]-max(a[i][0],a[i][2]);}
                else if(id==2)tmp[++cnt]=a[i][2]-max(a[i][0],a[i][1]);
            }
        }
        sort(tmp+1,tmp+cnt+1);
        for(int i=cnt-n/2;i>=1;i--)ans-=tmp[i];
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}