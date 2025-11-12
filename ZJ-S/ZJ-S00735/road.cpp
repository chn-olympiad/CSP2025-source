#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=1e4+10,K=10,S=1<<K,M=1e6+10,inf=0x3f3f3f3f;
void read(){}
template<class T,class...T2>
void read(T&ret,T2&...rest){
    ret=0;int c=gc();bool f=0;
    for(;!isdigit(c);c=gc())f=c=='-';
    for(;isdigit(c);c=gc())ret=ret*10+c-'0';
    f&&(ret=-ret),read(rest...);
}
#define cin(...) read(__VA_ARGS__)
template<class T>
void print(T x){
    static short sta[35],t=0;
    bool f=0;if(x<0)x=-x,f=1;
    do sta[++t]=x%10;while(x/=10);
    for(f&&pc('-');t;)pc(sta[t--]+'0');
}
using pi3=array<int,3>;
int n,m,k,c[K],a[K][N],fa[N*2];
ll res,f[N][S],sm[2][S];
pi3 e[M*2];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void chkmn(ll&a,ll b){a=min(a,b);}
namespace A{
    void solve(){
        for(int i=0;i<k;i++)
            for(int j=1;j<=n;j++)
                e[++m]={a[i][j],n+i+1,j};
        sort(e+1,e+m+1);
        iota(fa+1,fa+n+k+1,1);
        for(int i=1;i<=m;i++){
            auto[w,u,v]=e[i];
            u=find(u),v=find(v);
            if(u==v)continue;
            fa[u]=v,res+=w;
        }
        print(res),pc(endl);
    }
}
signed main(){
#ifdef local
    freopen("road1.in","r",stdin);
#else
    freopen("road.in","r",stdin);
#endif
    freopen("road.out","w",stdout);
    cin(n,m,k);
    for(int i=1,u,v,w;i<=m;i++)
        cin(u,v,w),e[i]={w,u,v};
    int mv=0;
    for(int i=0;i<k;i++){
        cin(c[i]);
        mv=max(mv,c[i]);
        for(int j=1;j<=n;j++)cin(a[i][j]);
        mv=max(mv,*min_element(a[i]+1,a[i]+n+1));
    }
    if(mv==0)
        return A::solve(),0;
    sort(e+1,e+m+1);
    iota(fa+1,fa+n*2+1,1);
    int ct=n;
    for(int i=1;i<=m;i++){
        auto[w,u,v]=e[i];
        u=find(u),v=find(v);
        if(u==v)continue;
        fa[u]=fa[v]=++ct;
        ll*g=f[ct-n];
        fill(g,g+(1<<k),(ll)1e17);
        if(u<=n&&v<=n){
            fill(sm[0],sm[0]+(1<<k),0);
            fill(sm[1],sm[1]+(1<<k),0);
            for(int j:{0,1})
                for(int s=1;s<(1<<k);s++)
                    sm[j][s]=sm[j][s^(s&-s)]+a[__lg(s&-s)][j?v:u];
            for(int s0=0;s0<(1<<k);s0++){
                for(int s1=0;s1<(1<<k);s1++){
                    chkmn(g[s0|s1],sm[0][s0]+sm[1][s1]+(s0&s1?0:w));
                }
            }
        }
        else if(u<=n||v<=n){
            if(v<=n)swap(u,v);
            fill(sm[0],sm[0]+(1<<k),0);
            for(int s=1;s<(1<<k);s++)
                sm[0][s]=sm[0][s^(s&-s)]+a[__lg(s&-s)][u];
            for(int s0=0;s0<(1<<k);s0++){
                for(int s1=0;s1<(1<<k);s1++){
                    chkmn(g[s0|s1],sm[0][s0]+f[v-n][s1]+(s0&s1?0:w));
                }
            }
        }
        else{
            for(int s0=0;s0<(1<<k);s0++){
                for(int s1=0;s1<(1<<k);s1++){
                    chkmn(g[s0|s1],f[u-n][s0]+f[v-n][s1]+(s0&s1?0:w));
                }
            }
        }
    }
    fill(sm[0],sm[0]+(1<<k),0);
    for(int s=1;s<(1<<k);s++)
        sm[0][s]=sm[0][s^(s&-s)]+c[__lg(s&-s)];
    res=1e17;
    for(int s=0;s<(1<<k);s++)
        chkmn(res,f[ct-n][s]+sm[0][s]);
    print(res),pc(endl);
    return 0;
}
//g++ road.cpp -o road -Wall -Wextra -Og -g -std=c++14 -fsanitize=address,undefined -Dlocal