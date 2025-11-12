#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N][4],n,cnt[4],np[N],b[N],cc;
void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=3;i++) cnt[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int mxp=1;
        for(int j=1;j<=3;j++){
            scanf("%lld",&a[i][j]);
            if(a[i][j]>=a[i][mxp]) mxp=j;
        }
        cnt[mxp]++;
        np[i]=mxp;
        ans+=a[i][mxp];
    }
    int p=-1;
    for(int i=1;i<=3;i++) if(cnt[i]>(n/2)) p=i;
    if(p==-1){
        printf("%lld\n",ans);
        return ;
    }
    cc=0;
    for(int i=1;i<=n;i++){
        if(np[i]!=p) continue;
        int mx=0;
        for(int j=1;j<=3;j++){
            if(j==np[i]) continue;
            mx=max(mx,a[i][j]);
        }
        b[++cc]=(a[i][p]-mx);
    }
    sort(b+1,b+cc+1);
    for(int i=1;i<=cc;i++){
        ans-=b[i];
        cnt[p]--;
        if(cnt[p]<=(n/2)) break;
    }
    printf("%lld\n",ans);
}
signed main(){
    int T;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--) solve();
}