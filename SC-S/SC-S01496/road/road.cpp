#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10,K=15;
const long long inf=1e18;
int n,m,k,vis[N];
long long ans=inf;
int a[K][N],c[K];
vector<array<int,3>>edge;

struct DSU{
	vector<int>f;
	DSU(int n):f(n+1){};
	int find(int x){
		if(f[x]==0||x==f[x])return x;
		return f[x]=find(f[x]); 
	} 
	void merge(int a,int b){
		int fa=find(a),fb=find(b);
		f[fb]=fa;
	}
	bool check(int a,int b){
		return find(a)==find(b);
	}
};

void solve1(int chose){
	long long sum=0;
	DSU dsu(n+k);
	for(int i=0;i<k;i++){
		if(chose>>i&1)
			vis[i+1+n]=1,sum+=c[i+1]; 
	}
	for(array<int,3> x:edge){
		long long w=x[0];
		int u=x[1],v=x[2];
		if((u>n&&vis[u]==0)||(v>n&&vis[v]==0))continue;
		if(dsu.check(u,v))continue;
		dsu.merge(u,v);
		sum+=w;
	}
	for(int i=n+1;i<=n+k;i++)
		vis[i]=0;
//	cout<<sum<<'\n';
//	cout<<"\n";
	ans=min(ans,sum);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back({w,u,v});
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			edge.push_back({a[i][j],i+n,j});
		}
	}
	sort(edge.begin(),edge.end());
	for(int S=0;S<(1<<k);S++)
		solve1(S);	
	cout<<ans; 
	return 0;
} 