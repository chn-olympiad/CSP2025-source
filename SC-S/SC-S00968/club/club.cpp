#include<bits/stdc++.h>
#define str string
#define endl '\n'
#define d(x) fixed<<setprecision(x)
#define go(i,a,b) for(int i=a;i<=b;i++)
#define re(i,a,b) for(int i=a;i>=b;i--)
using namespace std;using ll = long long;const int N=2e2+5;int dp[4][N][N],t,ans=0,d[N],n;struct node {int a,b,c;}g[N];bool cmp(node l,node r) {return l.a>r.a; }bool cmp1(node l,node r) {return l.a+r.b>l.b+r.a;}inline int read() {char c;int f=1,x=0;c=getchar();if(c=='-') f=-1;else if('0'<=c&&'9'>=c) x=c-'0';c=getchar();while('0'<=c&&'9'>=c) x=x*10+c-'0',c=getchar();return f*x;}void solve1() {sort(g+1,g+1+n,cmp);go(i,1,n/2) ans+=g[i].a;return ; }void solve2() {sort(g+1,g+1+n,cmp1) ;go(i,1,n) {if(i<=n/2) {ans+=g[i].a;}else {ans+=g[i].b;}}return ;}
void dfs(int cur,int c1,int c2,int c3,int sum) {if(cur==n+1) {if(c1<=n/2&&c2<=n/2&&c3<=n/2) ans=max(ans,sum);return ;}
dfs(cur+1,c1+1,c2,c3,sum+g[cur].a);dfs(cur+1,c1,c2+1,c3,sum+g[cur].b);dfs(cur+1,c1,c2,c3+1,sum+g[cur].c);return ;}
int main() {ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);freopen("club.in","r",stdin);freopen("club.out","w",stdout);
t=read();while(t--) {n=read();bool flag_a=1,flag_b=1;go(i,1,n){g[i].a=read();g[i].b=read();g[i].c=read();if(g[i].c!=0) flag_a=flag_b=0;
if(g[i].b!=0) flag_a=0;}if(flag_a) solve1();else if(flag_b) solve2();else dfs(1,0,0,0,0);cout<<ans<<endl;ans=0;}return 0;}