#include<bits/stdc++.h>
//#define int long long
#define gcd __gcd
using namespace std;
const int M=2e6+5;
const int N=1e4+5;
int n,m,k;
int c[N];
struct edge{
	int v,w;
};
vector<edge>g[N]; 
int a[15][N];
struct Prim{
	struct node{
		int u,v,w;
		bool operator < (const node &b) const{
			return w<b.w;
		}
	}g[N];
	int p[N];
	int find(int x){
		if(x==p[x]) return x;
		return p[x]=find(p[x]);
	}
}T;
void chu(){
		for(int i=1;i<=n;i++) T.p[i]=i;
		for(int i=1;i<=m;i++){
			int u,v,w;cin>>u>>v>>w;
			T.g[i].u=u;T.g[i].v=v;T.g[i].w=w;
		}sort(T.g+1,T.g+m+1);
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			int u=T.g[i].u;
			int v=T.g[i].v;
			if(T.find(u)!=T.find(v)){
				T.p[T.find(u)]=v;
				ans+=T.g[i].w;
				cnt++;
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
}
struct node{
	int u,v,w;
	bool operator <(const node &b) const{
		return w<b.w;
	} 
}e[N];
int cnt=0;
int fp[N];
int find(int x){
	if(x==fp[x]) return x;
	return fp[x]=find(fp[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){chu();return 0;}
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		e[++cnt].u=u;e[cnt].v=v;
		e[cnt].w=w;
	}bool lp=0;
	bool ok=0;
	int jb=n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		jb++;
		if(c[i]!=0) ok=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			g[j].push_back({jb,a[i][j]});
			g[jb].push_back({j,a[i][j]});
			if(c[i]!=0||a[i][j]!=0) lp=1;
		}
	}
	if(!lp){cout<<0<<'\n';return 0;}
	if(!ok){
		for(int j=1;j<=n;j++)
		for(int l=1;l<=k;l++)
		a[1][j]=min(a[l][j],a[1][j]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				cout<<"adsf"<<'\n';
				e[++cnt].u=i;
				e[cnt].v=j;
				e[cnt].w=a[1][i]+a[1][j];
			}
		}
//		cout<<cnt<<'\n';
		sort(e+1,e+cnt+1);
//		for(int i=1;i<=cnt;i++) cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
		for(int i=1;i<=n;i++) fp[i]=i;
		int ans=0;int shu=0;
		for(int i=1;i<=cnt;i++){
			int u=e[i].u;
			int v=e[i].v;
			if(find(u)!=find(v)){
				fp[find(u)]=v;
				shu++;
				ans+=e[i].w;
			}
			if(shu==n-1) break;
		}cout<<ans;
	}
	return 0;
}
