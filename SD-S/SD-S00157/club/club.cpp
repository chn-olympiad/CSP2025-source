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

//typedef int ll;
typedef long long ll;
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
inline ll qpow(ll a,ll b){return (!b?1ll:M_(qpow(M_(a,a),b>>1),(b&1)?a:1ll));}
inline ll C(ll n,ll m){return (n<m||n<0||m<0)?0ll:M_(Pre[n],Inv[m],Inv[n-m]);}
inline void InitC(ll n){Pre[0]=1;fo(1,i,n) Pre[i]=M_(Pre[i-1],i);Inv[n]=qpow(Pre[n],mod-2);Fo(n-1,i,1) Inv[i]=M_(Inv[i+1],i+1);Inv[0]=1;}

using namespace std;

const ll N=1e6+5,M=1e5+5;
ll n,a[N][3],sum[3],ans,b[N],id[N],bb[N]; 
inline void solve()
{
	read(n);fo(1,i,n) read(a[i][0],a[i][1],a[i][2]);
	fo(1,i,n)
	{
		ll mx=max({a[i][0],a[i][1],a[i][2]});ans+=mx;
		if(mx==a[i][0]) sum[0]++,bb[i]=0;
		else if(mx==a[i][1]) sum[1]++,bb[i]=1;
		else if(mx==a[i][2]) sum[2]++,bb[i]=2;
	}if(sum[0]<=n/2&&sum[1]<=n/2&&sum[2]<=n/2) return wr(ans),pr,void();
	ll fl=0;if(sum[0]>n/2) fl=0;else if(sum[1]>n/2) fl=1;else fl=2;
	fo(1,i,n)
	{
		if(bb[i]==fl) b[i]=max(a[i][(fl+1)%3]-a[i][fl],a[i][(fl+2)%3]-a[i][fl]);
		else b[i]=-inf;id[i]=i;
	}
//	fo(1,i,n) wr(b[i]),pp;pr;
	sort(id+1,id+1+n,[&](ll i,ll j){return b[i]>b[j];});
	fo(1,j,n)
	{
		ll i=id[j],bl=0,bl1=0,num=0;
		if(b[i]==a[i][(fl+1)%3]-a[i][fl]) bl=(fl+1)%3,bl1=(fl+2)%3,num=a[i][(fl+2)%3]-a[i][fl];
		else bl=(fl+2)%3,bl1=(fl+1)%3,num=a[i][(fl+1)%3]-a[i][fl];
		if(sum[bl]<n/2) sum[bl]++,ans+=b[i];else sum[bl1]++,ans+=num;
		sum[fl]--;if(sum[fl]<=n/2) break;
	}wr(ans),pr;
}
inline void cls()
{
	fo(0,i,n+1) a[i][0]=a[i][1]=a[i][2]=0,b[i]=0,id[i]=0;
	sum[0]=sum[1]=sum[2]=0,ans=0,n=0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;read(T);while(T--) solve(),cls();
	return 0;
}
