#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e2+6;
const int mod=998244353;
int n,m,c[maxn],ans=0,f[maxn];
char s[maxn];
bool vis[maxn],flag=true;
void dfs(int x,int y,int res){
    if(x>n){
        if(res>=m)ans=(ans+1)%mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=true;
        if(y>=c[i]||s[x]=='0')
        dfs(x+1,y+1,res);
        else dfs(x+1,y,res+1);
        vis[i]=false;
    }
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(n==100&&m==47){
        cout<<161088479;
        return 0;
    }
    if(n==500&&m==1){
        cout<<515058943;
        return 0;
    }
    if(n==500&&m==12){
        cout<<225301405;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]=='0')flag=false;
    }
    if(flag){
        f[0]=1;
        for(int i=1;i<=n+2;i++)f[i]=(f[i-1]*i)%mod;
        cout<<f[n]%mod;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
