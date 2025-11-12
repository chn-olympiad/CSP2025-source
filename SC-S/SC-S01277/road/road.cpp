#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define db double
#define i128 __int128
#define ull unsigned long long
#define ui unsigned int

const int N=1e4;
const int M=1e6;
const int K=10;
int n,m,k;
struct node{
    int u,v,w;
}e_1[M+10],e_2[N+10];
bool cmp(node A,node B){return A.w<B.w;}
int f[N+10];
int find(int x){
    return (f[x]==x?x:(f[x]=find(f[x])));
}

ll c[K+10],a[K+10][N+10];
vector<node> now;
ll sol(ll state){
    ll res=0;
    now.clear();
    for(int i=1;i<=m;i++) now.push_back(e_2[i]);
    for(int i=1;i<=n+k;i++) f[i]=i;
    for(int i=1;i<=k;i++)
        if((state>>i-1)&1){
            res+=c[i];
            for(int j=1;j<=n;j++)
                now.push_back((node){j,n+i,(int)a[i][j]});
        }
    sort(now.begin(),now.end(),cmp);
    for(node now_2:now){
        ll u=now_2.u,v=now_2.v,w=now_2.w;
        if(find(u)!=find(v)){
            f[find(u)]=find(v);
            res+=w;
        }
    }
    return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e_1[i]=(node){u,v,w};
    }
    sort(e_1+1,e_1+m+1,cmp);
    int m_2=0;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int u=e_1[i].u,v=e_1[i].v;
        if(find(u)==find(v)) continue;
        f[find(u)]=find(v);
        e_2[++m_2]=e_1[i];
    }
    m=m_2;

    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    ll ans=1e18;
    for(int i=0;i<(1<<k);i++) ans=min(ans,sol(i));
    cout<<ans<<'\n';
    return 0;
}
/*
W_init [,14:41]
T_B [15:05,15:11]
W [,15:27]
stuck [15:30,15:40](......)
C [,15:42](ok 10^9 is ok,<2s)

road3 1.2s

ulimit -s 1024000
g++ road.cpp -o test -std=c++14 -O2 -static -Wall -Wshadow -Wextra
g++ road.cpp -o test -std=c++14 -O2 -Wall -Wshadow -Wextra -fsanitize=address,undefined
fc road1.ans road.out
./test 
*/