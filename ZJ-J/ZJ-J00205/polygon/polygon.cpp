#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,lst[5005],ans;
bool vis[5005];

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int slowpow(int x){
    int res=1;
    while(x--) (res*=2)%=mod;
    return res;
}

bool check(int maxid){
    int res=0,maxed=lst[maxid];
    for(int i=1;i<maxid;i++){
        if(!vis[i]) continue;
        res+=lst[i];
    }
    return res>maxed;
}

void dfs(int now,int cnt,int maxid){
    if(now==maxid){
        if(cnt>=2) ans+=(check(maxid));
        return;
    }
    dfs(now+1,cnt,maxid);
    vis[now]=1;
    dfs(now+1,cnt+1,maxid);
    vis[now]=0;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) lst[i]=read();
    sort(lst+1,lst+1+n);
    if(lst[n]==1)
        cout<<((slowpow(n)-1-n-n*(n-1)/2)%mod+mod)%mod;
    else{
        for(int i=1;i<=n;i++) dfs(1,0,i);
        cout<<ans<<endl;
    }
    return 0;
}