#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define db double
#define mp make_pair
#define eb emplace_back
#define pii pair<int,int>
const int N=2e5+10,M=1e6+10,mod=1e9+7;
int n,m,k;
int f[N],tot,c[15];
int a[15][N];
ll ans;
struct node{
	int u,v,w;
	node(){}
	node(int x,int y,int z){
		u=x,v=y,w=z;
	}
	bool operator < (const node &rho) const{
		return w<rho.w;
	}
}e[M<<1],ed[N];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
ll kruscal(int p){
	ll ans=0;
	for(int i=1;i<=p;++i) f[i]=i;
	sort(e+1,e+1+tot);
	int cnt=0;
	for(int i=1,u,v,w;i<=tot;++i){
		u=e[i].u,v=e[i].v,w=e[i].w;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			f[fx]=fy;
			cnt++;
			if(p==n) ed[cnt]=node(u,v,w);
			ans+=w;
		}
		if(cnt==p-1) break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;++i){
		cin>>x>>y>>z;
		e[++tot]=node(x,y,z);
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	ans=kruscal(n);
	for(int S=1;S<(1<<k);++S){
		ll res=0;
		vector<int> ve;
		tot=0;
		int sum=0;
		for(int i=1;i<n;++i) e[++tot]=ed[i];
		for(int i=1;i<=k;++i){
			if(S&(1<<(i-1))){
				sum++;
				for(int j=1;j<=n;++j)
					e[++tot]=node(n+i,j,a[i][j]);
				res+=c[i];
			}
			else e[++tot]=node(n+i,1,0);
		}
		res+=kruscal(n+k);
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
