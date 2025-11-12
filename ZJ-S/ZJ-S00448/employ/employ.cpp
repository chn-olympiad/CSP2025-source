#include <bits/stdc++.h>
using namespace std;

#define int long long
#define spa putchar(' ')
#define ero putchar('\n')
#define pii pair<int,int>
#define fi first
#define se second

const int N=1e6+10;

#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n";

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(!x)putchar('0');
    if(x<0){putchar('-'),x=-x;}
    int a[60],cnt=0;
    while(x){a[++cnt]=x%10;x/=10;}
    while(cnt--){putchar(a[cnt+1]+48);}
}

char s[N];
int a[N],c[N];
bool vis[N];

int n,k;
int ans;

void dfs(int d){
    if(d>n){
        int now=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'&&now<c[a[i]]){
                continue;
            }
            now++;
        }
        if(n-now>=k)ans++;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            a[d]=i;
            dfs(d+1);
            a[d]=0;
            vis[i]=0;
        }
    }
}

void solve(){
    n=read(),k=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        c[i]=read();
        a[i]=i;
    }
    ans=0;
    dfs(1);
    write(ans);
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // int T=read();
    int T=1;
    while(T--){solve();}
    return 0;
}