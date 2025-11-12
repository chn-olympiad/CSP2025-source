#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define mk make_pair
#define x first
#define y second
#define N 200005
#define mod 3
using namespace std;
struct mint{
	int x;
	mint(ll y=0,bool fg=0){
		if(fg)x=(int)(y);
		else x=(int)((y%mod+mod)%mod);
	}
	friend mint ksm(mint a,ll b);
	const mint inv(){
		return ksm(*this,mod-2);
	}
};
mint operator +(const mint a,const mint b){
	int res=a.x+b.x;
	if(res>=mod)res-=mod;
	return mint(res,1);
}
mint operator -(const mint a,const mint b){
	int res=a.x-b.x;
	if(res<0)res+=mod;
	return mint(res,1);
}
mint operator *(const mint a,const mint b){
	return mint(1ll*a.x*b.x%mod,1);
}
mint operator +=(mint &a,const mint b){
	a=a+b;
	return a;
}
mint operator -=(mint &a,const mint b){
	a=a-b;
	return a;
}
mint operator *=(mint &a,const mint b){
	a=a*b;
	return a;
}
istream& operator >>(istream &in,mint &b){
	ll y;in>>y;
	b=mint(y);
	return in;
}
ostream& operator <<(ostream &out,mint b){
	return out<<b.x;
}
mint ksm(mint a,ll b){
	mint res=1;
	for(;b;b>>=1,a*=a)
		if(b&1)res*=a;
	return res;
}
struct ee{
	int u,v,w;
	bool operator <(const ee &b)const{
		return w<b.w;
	}
};
vector<ee> p,z,a[15];
int c[N];
int f[N],siz[N];
int n,k,m;
void init(){
	for(int i=1;i<=n+15;++i){
		f[i]=i,siz[i]=1;
	}
}
int findf(int k){
	if(f[k]==k)return k;
	return f[k]=findf(f[k]);
}
int merge(int u,int v){
	int fx=findf(u),fy=findf(v);
	if(fx==fy)return 0;
	if(siz[fx]<siz[fy])swap(fx,fy);
	siz[fx]+=siz[fy];
	f[fy]=fx;
	return 1;
}
ll ans=1e18;
void dfs(int u,vector<ee> s,ll ss){
//	cerr<<u<<' '<<ss<<"pp\n";
	if(u==k+1){
		ll sum=0;
		for(ee o:s){
			sum+=o.w;
		}
		ans=min(ans,sum+ss);
		return ;
	}
	dfs(u+1,s,ss);
	init();
	vector<ee> xin;
	int l1=0,l2=0;
	while(l1!=s.size()||l2!=a[u].size()){
		if(l1==s.size()||(l2!=a[u].size()&&a[u][l2]<s[l1])){
			if(merge(a[u][l2].u,a[u][l2].v))
				xin.push_back(a[u][l2]);
			++l2;
		}
		else{
			if(merge(s[l1].u,s[l1].v))
				xin.push_back(s[l1]);
			++l1;
		}
	}
	dfs(u+1,xin,ss+c[u]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		p.push_back({u,v,w});
	}
	sort(p.begin(),p.end());
	init();
	for(ee o:p){
		int u=o.u,v=o.v,w=o.w;
		if(merge(u,v)){
			z.push_back(o);
		}
	}
	
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			int o;
			cin>>o;
			a[i].push_back({i+n,j,o});
		}
		sort(a[i].begin(),a[i].end());
	}
//	return 0;
	dfs(1,z,0);
	cout<<ans<<'\n';
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
