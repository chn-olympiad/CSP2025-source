#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<array>
#include<tuple>
#include<map>
#include<set>
#include<bitset>
#include<ctime>
#include<random>
#include<cassert>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define y0 yy0
#define y1 yy1
#define yn yyn
#define j0 jj0
#define j1 jj1
#define jn jjn
#define IOS ios::sync_with_stdio(false)
#define PY puts("Yes")
#define PN puts("No")
#define PW puts("-1")
#define P0 puts("0")
#define P__ puts("")
#define PU puts("--------------------")
#define rep(a,b,c) for(int a=(b);a<=(c);++a)
#define per(a,b,c) for(int a=(b);a>=(c);--a)
#define reprange(a,b,c,d) for(int a=(b);a<=(c);a+=(d))
#define perrange(a,b,c,d) for(int a=(b);a>=(c);a-=(d))
#define graph(i,j,k,l) for(int i=k[j];i;i=l[i].nxt)
#define mp make_pair
#define pc putchar
#define fi first
#define se second
#define pb emplace_back
#define un using namespace
#define il inline
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof x)
#define lson(p) ((p)<<1)
#define rson(p) ((p)<<1|1)
#define lowbit(p) ((p)&-(p))
//#define double long double
//#define int long long
//#define int __int128
using namespace std;
un __gnu_pbds;
template<typename T1,typename T2>inline bool ckmx(T1 &x,T2 y){return x>=y?0:(x=y,1);}
template<typename T1,typename T2>inline bool ckmn(T1 &x,T2 y){return x<=y?0:(x=y,1);}
using i64=long long;
using u64=unsigned long long;
using pii=pair<int,int>;
inline auto rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;
}
template<typename T>inline void write(T x,char ch='\n'){
	if(x<0)putchar('-'),x=-x;
	int y=0;static char z[50];
	while(x||!y)z[y++]=x%10+48,x/=10;
	while(y--)putchar(z[y]);if(ch)putchar(ch);
}
bool Mbg;
const int mod=998244353;
template<typename T1,typename T2>inline void adder(T1 &x,T2 y){x+=y,x=x>=mod?x-mod:x;}
template<typename T1,typename T2>inline void suber(T1 &x,T2 y){x-=y,x=x<0?x+mod:x;}
const int maxn=1e4+15,maxm=1e6+5,inf=0x3f3f3f3f;
const long long llinf=0x3f3f3f3f3f3f3f3f;
int n,m,k,a[15][maxn],c[15],cnt;
struct edge{
	int u,v,w,t;
	bool operator<(const edge &p)const{return w<p.w;}
}e[maxm],b[maxm];
int fa[maxn],siz[maxn];
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
bool merge(int x,int y){
	x=getf(x),y=getf(y);
	if(x==y)return 0;
	if(siz[x]>siz[y])swap(x,y);
	fa[x]=y,siz[y]+=siz[x];
	return 1;
}
void init(){rep(i,1,n+k)fa[i]=i,siz[i]=1;}
inline void solve_the_problem(){
	n=rd(),m=rd(),k=rd();
	rep(i,1,m){
		int x=rd(),y=rd(),z=rd();
		e[i]=(edge){x,y,z,-1};
	}
	init();
	sort(e+1,e+m+1);
	rep(i,1,m)if(merge(e[i].u,e[i].v))b[++cnt]=e[i];
	rep(i,1,k){
		c[i]=rd();
		rep(j,1,n)a[i][j]=rd(),b[++cnt]=(edge){i+n,j,a[i][j],i-1};
	}
	sort(b+1,b+cnt+1);
	i64 ans=llinf;
	rep(S,0,(1<<k)-1){
		i64 res=0;
		int tot=n-1;
		rep(i,1,k)if((S>>(i-1))&1)res+=c[i],++tot;
		init();
		rep(i,1,cnt){
			if(b[i].t==-1||((S>>b[i].t)&1)){
				if(merge(b[i].u,b[i].v))res+=b[i].w,--tot;
				if(!tot)break;
			}
		}
		ckmn(ans,res);
	}
	write(ans);
}
bool Med;
signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	fprintf(stderr,"%.3lfMB\n",(&Mbg-&Med)/1048576.0);
	int _=1;
	rep(__,1,_)solve_the_problem();
}
/*

*/

