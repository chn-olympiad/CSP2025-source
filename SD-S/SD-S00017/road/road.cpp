#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5,M=2e6+5;
int n,m,k,c[20],a[20][N],tot,ans=1e18;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &p)const{
		return w<p.w;
	}
}E[M],EE[M];
int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void Solve(int S){
	vector<int> p;
	for(int i=0;i<k;i++){
		if((S>>i)&1) p.push_back(i+1);
	}
	int cnt=tot;
	for(int i=1;i<=tot;i++) EE[i]=E[i];
	int now=0;
	for(int x:p){
		now+=c[x];
		for(int i=1;i<=n;i++){
			EE[++cnt]=(Edge){x+n,i,a[x][i]};
		}
	}
	iota(f+1,f+1+k+n,1);
	sort(EE+1,EE+1+cnt);
	for(int i=1;i<=cnt;i++){
		int x=EE[i].u,y=EE[i].v,w=EE[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			f[fx]=fy;
			now+=w;
		}
	}
	ans=min(ans,now);
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		EE[i]=(Edge){u,v,w};
	}
	sort(EE+1,EE+1+m);
	iota(f+1,f+1+n,1);
	for(int i=1;i<=m;i++){
		int x=EE[i].u,y=EE[i].v,w=EE[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			f[fx]=fy;
			E[++tot]=(Edge){x,y,w};
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++){
		Solve(i);
	}
	cout<<ans;
	return 0;
}
