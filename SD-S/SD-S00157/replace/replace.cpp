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
#define mk make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef double db;

//typedef int ll;
typedef long long ll;
//typedef __int128 ll;
const ll mod=1e9+9,base=231;

//#define getchar getchar_unlocked
//#define putchar putchar_unlocked

template <class T> inline bool ckmn(T &x,T y){return x>y?x=y,1:0;}
template <class T> inline bool ckmx(T &x,T y){return x<y?x=y,1:0;}
template <class T> inline void _A(T &x,T y){x=(x+y>=mod?x+y-mod:x+y);}
template <class T> inline void _M(T &x,T y){x=1ll*x*y%mod;}
template <class T> inline ll A_(T x,T y){return (x+y>=mod?x+y-mod:x+y);}
template <class T> inline ll M_(T x,T y){return 1ll*x*y%mod;}
template <class T, class ...A> inline bool ckmn(T &x,T y,A ...a){return ckmn(x,y)|ckmn(x,a...);}
template <class T, class ...A> inline bool ckmx(T &x,T y,A ...a){return ckmx(x,y)|ckmx(x,a...);}
template <class T, class ...A> inline void _A(T &x,T y,A ...a){_A(x,y);_A(x,a...);}
template <class T, class ...A> inline void _M(T &x,T y,A ...a){_M(x,y);_M(x,a...);}
template <class T, class ...A> inline ll A_(T x,T y,A ...a){return A_(A_(x,y),a...);}
template <class T, class ...A> inline ll M_(T x,T y,A ...a){return M_(M_(x,y),a...);}

const ll _N=1e6+5;ll Pre[_N],Inv[_N];
inline ll qpow(ll a,ll b){return (!b?1ll:M_(qpow(M_(a,a),b>>1),(b&1)?a:1ll));}
inline ll C(ll n,ll m){return (n<m||n<0||m<0)?0ll:M_(Pre[n],Inv[m],Inv[n-m]);}
inline void InitC(ll n){Pre[0]=1;fo(1,i,n) Pre[i]=M_(Pre[i-1],i);Inv[n]=qpow(Pre[n],mod-2);Fo(n-1,i,1) Inv[i]=M_(Inv[i+1],i+1);Inv[0]=1;}

using namespace std;

const ll N=1e6+5,M=1e5+5;
ll n,q,a[N],l1[N],l2[N],pw[N],L1[N],R1[N],L2[N],R2[N],mx,num1[N][2],num2[N][2],ans[N],opt;string s[N][2],t[N][2];
vector<ll> hs1[N][2],hs2[N][2],b;
inline ll RMQ1(ll i,ll op,ll l,ll r){if(l>r||l<0||r>mx) return -inf;return A_(M_(hs1[i][op][r],pw[mx-r]),mod-M_(hs1[i][op][l-1],pw[mx-r]));}
inline ll RMQ2(ll i,ll op,ll l,ll r){if(l>r||l<0||r>mx) return inf;return A_(M_(hs2[i][op][r],pw[mx-r]),mod-M_(hs2[i][op][l-1],pw[mx-r]));}
struct node{ll id,op,len;};vector<node> E[N]; 
map<pii,ll> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));fo(0,i,25) a[i]=rand();
	IOS;cin>>n>>q;fo(1,i,n) cin>>s[i][0]>>s[i][1],l1[i]=s[i][0].size(),s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1],ckmx(mx,l1[i]);
	fo(1,i,q) cin>>t[i][0]>>t[i][1],l2[i]=t[i][0].size(),t[i][0]=" "+t[i][0],t[i][1]=" "+t[i][1],ckmx(mx,l2[i]);
	pw[0]=1;fo(1,i,mx) pw[i]=M_(pw[i-1],base);
	fo(1,i,n)
	{
		hs1[i][0].resize(l1[i]+2,0);
		hs1[i][1].resize(l1[i]+2,0);
		fo(1,j,l1[i]) 
			hs1[i][0][j]=A_(hs1[i][0][j-1],M_(a[s[i][0][j]-'a'],pw[j])),
			hs1[i][1][j]=A_(hs1[i][1][j-1],M_(a[s[i][1][j]-'a'],pw[j]));
	}
	fo(1,i,q)
	{
		hs2[i][0].resize(l2[i]+2,0);
		hs2[i][1].resize(l2[i]+2,0);
		fo(1,j,l2[i]) 
			hs2[i][0][j]=A_(hs2[i][0][j-1],M_(a[t[i][0][j]-'a'],pw[j])),
			hs2[i][1][j]=A_(hs2[i][1][j-1],M_(a[t[i][1][j]-'a'],pw[j]));
	}
	fo(1,i,n)
	{
		ll l=1,r=l1[i];
		while(l<=l1[i]&&s[i][0][l]==s[i][1][l]) ++l;
		while(r>=1&&s[i][0][r]==s[i][1][r]) --r;
		if(l<=r) num1[i][0]=RMQ1(i,0,l,r),num1[i][1]=RMQ1(i,1,l,r);
		else num1[i][0]=num1[i][1]=-1;
		if(!mp.count(mk(num1[i][0],num1[i][1]))) mp[mk(num1[i][0],num1[i][1])]=++opt;
		E[mp[mk(num1[i][0],num1[i][1])]].pb({i,0,l1[i]});
		L1[i]=l-1,R1[i]=l1[i]-r;
	}
	fo(1,i,q)
	{
		ll l=1,r=l2[i];
		while(l<=l2[i]&&t[i][0][l]==t[i][1][l]) ++l;
		while(r>=1&&t[i][0][r]==t[i][1][r]) --r;
		if(l<=r) num2[i][0]=RMQ2(i,0,l,r),num2[i][1]=RMQ2(i,1,l,r);
		else num2[i][0]=num2[i][1]=-1;
		if(!mp.count(mk(num2[i][0],num2[i][1]))) mp[mk(num2[i][0],num2[i][1])]=++opt;
		E[mp[mk(num2[i][0],num2[i][1])]].pb({i,1,l2[i]});
		L2[i]=l,R2[i]=r;
	}
	fo(1,id,opt) if(E[id].size())
	{
		sort(all(E[id]),[&](node i,node j){return i.len==j.len?i.op<j.op:i.len<j.len;});
		vector<ll> c;
		fo(0,i,E[id].size()-1)
		{
			ll x=E[id][i].id,y=E[id][i].op;
			if(!y) c.pb(x);
			else
			{
				for(ll j:c)
				{
					ll L=L1[j],R=R1[j];
					ans[x]+=(RMQ1(j,0,1,l1[j])==RMQ2(x,0,L2[x]-L,R2[x]+R));
				}
			}
		}c.clear();
	}
	fo(1,i,q) cout << ans[i] << '\n';
	return 0;
}
