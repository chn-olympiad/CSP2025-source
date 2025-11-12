//T2
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

const ll INF=0x3f3f3f3f;
const ll mod=998244353;
const ll N=1e4+20;
const ll K=12;

#define rint FastRead()
ll FastRead/*readint*/() {
	ll ch=getchar(),sgn=0; ll ans=0;
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='+';ch=getchar());
	if(ch=='-') sgn=1,ch=getchar();
	for(;isdigit(ch);ch=getchar()) ans=ans*10+ch-'0';
	return sgn?-ans:ans;
}

ll fa[N],n;
struct edge{
	ll u,v,w;
}; vector<edge> g;

bool cmp(edge& x,edge& y) {
	return x.w<y.w;
}

void Init(ll n=N-1) {for(ll i=0;i<=n;i++) fa[i]=i;} 
ll Find(ll u) {return fa[u]=fa[u]==u?u:Find(fa[u]);}
void Merge(ll u,ll v) {fa[Find(u)]=Find(v);}

ll c[K],a[K][N];

ll Kruskal() {
	ll cnt=0,ans=0;
	sort(g.begin(),g.end(),cmp);
	for(auto __x:g) {
		ll u=__x.u,v=__x.v,w=__x.w;
		if(Find(u)==Find(v)) continue;
		Merge(u,v);
		ans+=w;
		if(++cnt==n-1) return ans;
	}
	return -1;
}

void Solve(void) {
	n=rint;
	ll m=rint,k=rint; 
	Init(n);
	for(ll i=1;i<=m;i++) {
		ll u=rint,v=rint,w=rint;
		g.push_back({u,v,w});
	}
	if(k==0) {
		cout<<Kruskal();
		return ;
	}
	for(ll i=1;i<=k;i++) {
		ll pos=-1;
		c[i]=rint;
		for(ll j=1;j<=n;j++) {
			a[i][j]=rint;
			if(a[i][j]==0) pos=j;
		}
		if(pos==-1) {
			
		}
		else for(ll j=1;j<=n;j++) {
			if(j==pos) continue;
			g.push_back({pos,j,a[i][j]});
		}
	}
	cout<<Kruskal();
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	//ll T; cin>>T; for(;T--;)
	Solve();
	return 0;
}
