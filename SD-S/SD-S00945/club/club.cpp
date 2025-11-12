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
const int maxn=1e5+5,inf=0x3f3f3f3f;
const long long llinf=0x3f3f3f3f3f3f3f3f;
int n,a[maxn][3],b[maxn];
vector<int>vec[3];
inline void solve_the_problem(){
	n=rd();
	rep(i,1,n)rep(j,0,2)a[i][j]=rd();
	rep(i,0,2)vec[i].clear();
	int ans=0;
	rep(i,1,n){
		int mx=-inf,p=-1;
		rep(j,0,2)if(ckmx(mx,a[i][j]))p=j;
		ans+=a[i][p],vec[p].pb(i);
		b[i]=-inf;
		rep(j,0,2)if(j!=p)ckmx(b[i],a[i][j]-a[i][p]);
	}
	int mxsiz=0;
	rep(i,0,2)ckmx(mxsiz,vec[i].size());
	if(mxsiz>n/2){
		int p=0;
		rep(i,0,2)if((int)vec[i].size()>n/2){p=i;break;}
		sort(all(vec[p]),[](int x,int y){return b[x]>b[y];});
		int rem=(int)vec[p].size()-n/2;
		rep(i,0,rem-1)ans+=b[vec[p][i]];
	}
	write(ans);
}
bool Med;
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	fprintf(stderr,"%.3lfMB\n",(&Mbg-&Med)/1048576.0);
	int _=rd();
	rep(__,1,_)solve_the_problem();
}
/*

*/

