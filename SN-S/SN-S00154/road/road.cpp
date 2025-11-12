#include<bits/stdc++.h>
#define ll long long
#define il inline

namespace Usd{bool St;void out();}
namespace My_Rand{std::random_device sd;auto rnd=std::mt19937_64(sd());}
namespace _Dsu{
	template<ll Num>
	class Dsu{
		ll fa[Num+5];
	public:
		void init(ll num){for(ll i=1;i<=num;++i)fa[i]=i;}
		ll fd(ll x){return x==fa[x]?x:(fa[x]=fd(fa[x]));}
		void merg(ll x,ll y){fa[fd(y)]=fa[x];}
	};
}
class IO{
	const ll maxn=1<<20;
	char buf[1<<20],*p1=buf,*p2=buf,*p3=buf;
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++)
	#define flush()(fwrite(buf,1,p3-buf,stdout))
	#define pc(x) (p3==buf+maxn&&(flush(),p3=buf),*p3++=(x))
public:
	~IO(){flush();}
	template<typename T>
	il IO &operator>>(T &x){
		x=0;bool flag(0);char ch=gc();
		while(!isdigit(ch)) flag^=ch=='-',ch=gc();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=gc();
		flag?x=-x:0;return *this;
	}
	template<typename T>
	il IO &operator<<(T x){
		x<0?x=-x,pc('-'):0;
		static short st[50],top(0);
		do st[++top]=x%10,x/=10;while(x);
		while(top) pc(st[top--]|48);return *this;
	}
	il IO &operator>>(char &x){do x=gc();while(isspace(x));return *this;}
	il IO &operator>>(char *x){char ch;*this>>ch;do *(x++)=ch;while(!isspace(ch=gc())&&~ch);*x='\0';return *this;}
	il IO &operator<<(char x){pc(x);return *this;}
	template<typename type>il IO &operator<<(type *x){while(*x)pc(*(x++));return *this;}
}fin,fout;
using namespace std;

constexpr ll N=1e4,M=1e6,K=10,Inf=0x3f3f3f3f3f3f3f3f;
ll n,m,k,c[K+5],a[K+5][N+5];
struct node{ll u,v,w;}b[M+5];
struct edge{ll to,w;};
vector<edge> e[N+5];
namespace solve1{
	using _Dsu::Dsu;
	Dsu<N> ds;
	ll ans=0;
	bool cmp(node x,node y){return x.w<y.w;}
	ll solve(){
		sort(b+1,b+m+1,cmp);
		ds.init(n);
		for(ll i=1;i<=m;++i){
			b[i].u=ds.fd(b[i].u);
			b[i].v=ds.fd(b[i].v);
			if(b[i].u!=b[i].v){
				ans+=b[i].w;
				ds.merg(b[i].u,b[i].v);
			}
		}
		fout<<ans<<"\n";
		return 0;
	}
}
namespace solve2{
	ll dis[N+5],vis[N+5],ans=0;
	set<ll> g;
	ll solve(){
		dis[1]=0;
		for(auto j:e[1]) dis[j.to]=min(dis[j.to],j.w);
		for(ll i=2;i<=n;++i){
			for(ll j=1;j<=k;++j) dis[i]=min(dis[i],a[j][i]+a[j][1]);
		}
		for(ll i=2;i<=n;++i) g.insert(i);
		for(ll kkk=1;kkk;){
			ll nw=0;
			for(ll i:g){
				if(nw==0||dis[i]<dis[nw]) nw=i;
			}
			kkk=(nw>0);
			if(nw){
				ans+=dis[nw];
				g.erase(nw);
				for(auto j:e[nw]) dis[j.to]=min(dis[j.to],j.w);
				for(ll i:g){
					for(ll j=1;j<=k;++j) dis[i]=min(dis[i],a[j][i]+a[j][nw]);
				}
			}
		}
		fout<<ans<<"\n";
		return 0;
	}
}
namespace solve3{
	ll ans=Inf,lg_2[(1<<K)+5],tot;
	ll dis[N+5];
	set<ll> g;
	vector<ll> h;
	bool cmp(node x,node y){return x.w<y.w;}
	void _get(ll &nw_ans){
		for(ll i=1;i<=n;++i) dis[i]=Inf;
		dis[1]=0;
		for(auto j:e[1]) dis[j.to]=min(dis[j.to],j.w);
		for(ll i=2;i<=n;++i) g.insert(i);
		for(ll i:g){
			for(ll j:h) dis[i]=min(dis[i],a[j][i]+a[j][1]);
		}
		for(ll kkk=1;kkk;){
			ll nw=0;
			for(ll i:g){
				if(nw==0||dis[i]<dis[nw]) nw=i;
			}
			kkk=(nw>0);
			if(nw){
				nw_ans+=dis[nw];
				g.erase(nw);
				dis[nw]=0;
				for(auto j:e[nw]) dis[j.to]=min(dis[j.to],j.w);
				for(ll i:g){
					for(ll j:h) dis[i]=min(dis[i],a[j][i]+a[j][nw]);
				}
			}
		}
	}
	ll solve(){
		ll ans=Inf;
		for(ll i=1;i<=k;++i) lg_2[1<<i]=i;
		for(ll s=0;s<(1<<k);++s){
			ll nw_ans=0;
			h.clear();
			for(ll t=s;t;t-=(t&(-t))) h.push_back(lg_2[t&(-t)]+1);
			for(ll i:h) nw_ans+=c[i];
			_get(nw_ans);
			ans=min(ans,nw_ans);
		}
		fout<<ans<<"\n";
		return 0;
	}
}

namespace Usd{bool Ed;void out(){fout<<"\n    time: "<<(ll)((double)clock()/CLOCKS_PER_SEC)*1000<<"ms\n mermory: "<<(ll)((&St-&Ed)/1024.0/1024.0)<<"MiB\n";}}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fin>>n>>m>>k;
	for(ll i=1;i<=m;++i){
		fin>>b[i].u>>b[i].v>>b[i].w;
		e[b[i].u].push_back({b[i].v,b[i].w});
		e[b[i].v].push_back({b[i].u,b[i].w});
	}
	for(ll i=1;i<=n;++i) e[i].shrink_to_fit();
	bool flag1=1;
	for(ll j=1;j<=k;++j){
		fin>>c[j];
		flag1&=(c[j]==0);
		for(ll i=1;i<=n;++i) fin>>a[j][i];
	}
	if(k==0){return solve1::solve();}
	if(flag1){return solve2::solve();}
	return solve3::solve();
	return 0;
}
