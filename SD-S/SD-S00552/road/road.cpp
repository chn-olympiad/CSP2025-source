#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

const int N=1e4+5;

int mp[1010][1010];
bool vis[1010][1010];
int a[N];

struct DSU{
	int fa[N];
	void init(int n){
		for(int i=0;i<=n;i++){
			fa[i]=i;
		}
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return 0;
		fa[y]=x;
		return 1;
	}
}dsu;

struct edge{
	int u,v,w;
};

vector<edge> e;

bool cmp(edge a,edge b){
	return a.w<b.w;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mp,0x3f,sizeof mp);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		//if(u<v) swap(u,v);
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
		//cout<<mp[u][v]<<"\n";
	}
	dsu.init(n);
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(j==l) mp[j][l]=0;
				else mp[j][l]=min(mp[j][l],a[j]+c+a[l]);
			}
		}
	}
	int fi=0;
	for(int j=1;j<=n;j++){
		for(int l=1;l<=n;l++){
			if(mp[j][l]>=INF or j==l or vis[l][j] or vis[j][l]) continue;
			e.push_back({j,l,mp[j][l]});
			vis[l][j]=vis[j][l]=1;
			fi++;
			//cout<<j<<' '<<l<<' '<<mp[j][l]<<"\n";
		}
	}
	int sum=0,cnt=0;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<fi;i++){
		//cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
		if(dsu.merge(e[i].u,e[i].v)){
			sum+=e[i].w;cnt++;
		}
		if(cnt>=n-1) break;
	}
	cout<<sum;
}

