#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T,n;
int fa[100050][3];
int ts[100050],xz[100050];
void solve(){
    int l0=0,l1=0,l2=0;
    ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&fa[i][0],&fa[i][1],&fa[i][2]);
        if(fa[i][0]>=fa[i][1]&&fa[i][0]>=fa[i][2]){
            l0++; ans+=fa[i][0]; xz[i]=0;
        }
        else if(fa[i][1]>=fa[i][0]&&fa[i][1]>=fa[i][2]){
            l1++; ans+=fa[i][1]; xz[i]=1;
        }
        else{
            l2++; ans+=fa[i][2]; xz[i]=2;
        }
    }
    int st1=0,st2=0,st=0,dk=-1;
    if(l0>n/2) st1=1,st2=2,st=0,dk=l0-n/2;
    if(l1>n/2) st1=0,st2=2,st=1,dk=l1-n/2;
    if(l2>n/2) st1=0,st2=1,st=2,dk=l2-n/2;
    if(dk==-1){
        printf("%lld\n",ans);
        return;
    }
    int tp=0;
    for(int i=1;i<=n;i++){
        if(xz[i]==st){
            ts[++tp]=min(fa[i][st]-fa[i][st1],fa[i][st]-fa[i][st2]);
        }
        
    }
    sort(ts+1,ts+tp+1);
    for(int i=1;i<=dk;i++){
        ans-=ts[i];
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        solve();
    }
}