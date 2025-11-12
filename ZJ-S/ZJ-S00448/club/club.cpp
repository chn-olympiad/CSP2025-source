#include <bits/stdc++.h>
using namespace std;

#define int long long
#define spa putchar(' ')
#define ero putchar('\n')
#define pii pair<int,int>
#define fi first
#define se second

const int N=1e5+10;

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

int n;
int a[N][4];
int ans=0;

int vis[N];
void dfs(int d,int len1,int len2,int len3){
    if(d>n){
        int res=0;
        for(int i=1;i<=n;i++){
            res+=a[i][vis[i]];
        }
        ans=max(ans,res);
    }
    if(len1<n/2){
        vis[d]=1;
        dfs(d+1,len1+1,len2,len3);
        vis[d]=0;
    }
    if(len2<n/2){
        vis[d]=2;
        dfs(d+1,len1,len2+1,len3);
        vis[d]=0;
    }
    if(len3<n/2){
        vis[d]=3;
        dfs(d+1,len1,len2,len3+1);
        vis[d]=0;
    }
}

int b[N];

bool cmp(int i,int j){
    return i>j;
}
pii p[N];

// bool cmp2(int i,int j){
//     return a[i][1]==a[j][1]?a[i][2]>a[j][2]:a[i][1]>a[j][1];
// }

priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > >q;

void solve(){
    n=read();
    ans=0;
    bool fl=1;
    bool fl2=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            a[i][j]=read();
        }
        b[i]=a[i][1];
        fl&=(a[i][2]==0&&a[i][3]==0);
        fl2&=(a[i][3]==0);
    }
    if(fl){
        sort(b+1,b+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++)ans+=b[i];
        write(ans),ero;
        return ;
    }
    if(fl2){
        ans=0;
        // sort(a+1,a+n+1,cmp2);
        int len1=0,len2=0;
        for(int i=1;i<=n;i++){
            p[i]={a[i][1],a[i][2]};
        }
        sort(p+1,p+n+1);
        for(int i=n;i;i--){
            if((p[i].fi>p[i].se&&len1<n/2)||len2==n/2){
                ans+=p[i].fi;
                len1++;
            }
            else {
                ans+=p[i].se;
                len2++;
            }
            // q.push({a[i][1],{a[i][1]-a[i][2],a[i][2]}});
            // q.push({a[i][1]-a[i][2],{a[i][1],a[i][2]}});
        }
        write(ans);
        ero;
        return ;
        // int now=n/2;
        // while(now--){
        //     ans+=q.top().fi;
        //     q.pop();
        // }
        // while(!q.empty()){
        //     ans+=q.top().se.se;
        //     q.pop();
        // }
        write(ans);ero;
        return ;
    }
    dfs(1,0,0,0);
    write(ans),ero;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    // int T=1;
    while(T--){solve();}
    return 0;
}