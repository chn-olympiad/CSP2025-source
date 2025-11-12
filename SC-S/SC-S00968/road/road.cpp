#include<bits/stdc++.h>
#define str string
#define endl '\n'
#define d(x) fixed<<setprecision(x)
#define go(i,a,b) for(int i=a;i<=b;i++)
#define re(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
using ll = long long;
const int N=1e6+5;
int c[N],n,m,k,ans=0;
struct node {
int u,v,w;} cy[N];
inline int read() {
    char c;
    int f=1,x=0;
    c=getchar();
    if(c=='-') f=-1;
    else if('0'<=c&&'9'>=c) x=c-'0';
    c=getchar();
    while('0'<=c&&'9'>=c) x=x*10+c-'0',c=getchar();
    return f*x;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    map<pair<int,int>,int> mp,f;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    n=read(),m=read(),k=read();
    go(i,1,m) {
        cy[i].u=read(),cy[i].v=read(),cy[i].w=read();
    }
    go(i,1,k)
    {
        c[i]=read();
        go(j,1,n) {
            int p=read();
            mp[{p,c[i]}]=mp[{c[i],p}]=f[{c[i],p}]=f[{p,c[i]}]=1;
        }
    }
    go(i,1,m) {
        if(mp[{cy[i].v,cy[i].u}]) f[{cy[i].v,cy[i].u}]=1;
        else ans+=cy[i].w;
    }
    cout<<ans;
    return 0;
}

