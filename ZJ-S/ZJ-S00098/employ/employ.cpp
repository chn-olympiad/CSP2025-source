#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ent putchar('\n')
#define sp putchar(' ')
#define pii pair<int,int>
#define dbg puts("-----------------qaq----------------")
#define fi first
#define se second
#define pl (p<<1)
#define pr ((p<<1)|1)
const int mod=998244353,inf=LONG_LONG_MAX/4;
int read(){int t;scanf("%lld",&t);return t;}
void write(int x){printf("%lld",x);return;}
const int N=5e2+10,RN=5e2;
int n,m,ans;
string s;
int a[N],vis[N],mark[N],p[N];
void dfs(int x){
    if(x==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||a[p[i]]<=cnt){
                cnt++;
                if(n-cnt<m) return;
            }
        }
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            p[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>s,s="$"+s;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    if(n<=10) dfs(1);
    write(ans);
    return 0;
}
