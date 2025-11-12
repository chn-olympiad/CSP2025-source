#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define fo(a,i,b) for(ll i=(a);i<=(b);++i)
#define Fo(a,i,b) for(ll i=(a);i>=(b);--i)
#define fi first
#define se second
#define pii pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define lbd lower_bound
#define ubd upper_bound
#define bct __builtin_popcount
#define pr putchar('\n')
#define pp putchar(' ')
#define lowbit(x) (x&(-x))
#define gb(x,i) ((x>>i)&1)
#define IT iterator
#define IOS ios::sync_with_stdio(false),cin.tie(0)

typedef long long i64;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef double db;

typedef int ll;
//typedef long long ll;
//typedef __int128 ll;
const ll mod=1e9+7;

//#define getchar getchar_unlocked
//#define putchar putchar_unlocked

template <class T> inline bool ckmn(T &x,T y){return x>y?x=y,1:0;}
template <class T> inline bool ckmx(T &x,T y){return x<y?x=y,1:0;}
template <class T> inline void _A(T &x,T y){x=(x+y>=mod?x+y-mod:x+y);}
template <class T> inline void _M(T &x,T y){x=1ll*x*y%mod;}
template <class T> inline ll A_(T x,T y){return (x+y>=mod?x+y-mod:x+y);}
template <class T> inline ll M_(T x,T y){return 1ll*x*y%mod;}
template <class T> inline void read(T &s)
{
	s=0;int f=1;char c=getchar();while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) s=(s<<3)+(s<<1)+(c^48),c=getchar();s*=f;return;
}
template <class T> inline void wr(T x)
{
	if(x<0) putchar('-'),x=-x;int buf[21],top=0;while(x) buf[++top]=x%10,x/=10;
	if(!top) buf[++top]=0;while(top) putchar(buf[top--]^'0');return;
}
template <class T, class ...A> inline bool ckmn(T &x,T y,A ...a){return ckmn(x,y)|ckmn(x,a...);}
template <class T, class ...A> inline bool ckmx(T &x,T y,A ...a){return ckmx(x,y)|ckmx(x,a...);}
template <class T, class ...A> inline void _A(T &x,T y,A ...a){_A(x,y);_A(x,a...);}
template <class T, class ...A> inline void _M(T &x,T y,A ...a){_M(x,y);_M(x,a...);}
template <class T, class ...A> inline ll A_(T x,T y,A ...a){return A_(A_(x,y),a...);}
template <class T, class ...A> inline ll M_(T x,T y,A ...a){return M_(M_(x,y),a...);}
template <class T, class ...A> inline void read(T &s,A &...a){read(s);read(a...);}

const ll _N=1e6+5;ll Pre[_N],Inv[_N];
inline ll qpow(ll a,ll b){return (!b?1ll:M_(qpow(M_(a,a),b>>1),(b&1)?a:1));}
inline ll C(ll n,ll m){return (n<m||n<0||m<0)?0ll:M_(Pre[n],Inv[m],Inv[n-m]);}
inline void InitC(ll n){Pre[0]=1;fo(1,i,n) Pre[i]=M_(Pre[i-1],i);Inv[n]=qpow(Pre[n],mod-2);Fo(n-1,i,1) Inv[i]=M_(Inv[i+1],i+1);Inv[0]=1;}

using namespace std;

const ll N=2e4+5,M=1e5+5;
ll n,m,k,u,v,w,fa[N],c[N],a[11][N];i64 ans,sum;
struct node{ll w,u,v;};vector<node> E,_E,E_;
inline ll Find(ll x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
inline void Link(ll x,ll y){x=Find(x),y=Find(y);if(x!=y) fa[x]=y;}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	double st = clock();
	read(n,m,k);fo(1,i,m) read(u,v,w),E.pb({w,u,v});
	sort(all(E),[&](node i,node j){return i.w<j.w;});fo(1,i,n+k) fa[i]=i;
	fo(0,i,E.size()-1)
	{
		ll w=E[i].w,u=E[i].u,v=E[i].v;
		if(Find(u)!=Find(v)) 
			Link(u,v),_E.pb({w,u,v}),ans+=w;
	}
	fo(1,i,k){read(c[i]);fo(1,j,n) read(a[i][j]);}
	fo(1,S,(1<<k)-1)
	{
		E_=_E;ll num=n+bct(S);sum=0;
		fo(1,i,k) if(gb(S,i-1))
		{
			fo(1,j,n) 
				E_.pb({a[i][j],i+n,j});
			sum+=c[i]; 
		}
		fo(1,i,n+k) fa[i]=i;ll cnt=0;
		sort(all(E_),[&](node i,node j){return i.w<j.w;});fo(0,i,E_.size()-1)
		{
			ll w=E_[i].w,u=E_[i].u,v=E_[i].v;
			if(Find(u)!=Find(v)) Link(u,v),sum+=w,++cnt;
			if(cnt==num-1||sum>=ans) break;
		}if(cnt!=num-1) sum=inf;
		ckmn(ans,sum);
	}wr(ans),pr;
//	double ed = clock();
//	cerr << (ed - st) << " ms\n";
	return 0;
}

