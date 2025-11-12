#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MAXN=1e6+12;
struct Node{
	int u,v,w;
	bool operator < (const Node &rhs )const {
		return w>rhs.w;
	}
};
int n,m,k,sumc,fnans=0x3f3f3f3f3f3f3f3f;
int u[MAXN],v[MAXN],w[MAXN],fa[MAXN],a[11][MAXN],c[11],used[11];
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
signed main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		sumc+=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
			int op=i,idx=0,ans=0;
			priority_queue<Node>road;
			for(int j=1;j<=m;j++)road.push({u[j],v[j],w[j]});
			for(int j=1;j<=n+k;j++)fa[j]=j;
			while(op){
				idx++;
				if(op&1){	
					ans+=c[idx];
					for(int j=1;j<=n;j++){
						road.push({idx+n,j,a[idx][j]});
					}
				}op>>=1;
			}
			int cnt=n;
			while(!road.empty()&&cnt>1){
				int u=road.top().u;
				int v=road.top().v;
				int w=road.top().w;
				road.pop();
				if(find(u)==find(v))continue;
			//	cout<<u<<" "<<v<<" "<<w<<endl;
				merge(u,v);
				if(u<=n&&v<=n)cnt--;
				ans+=w;
			}
		//	cout<<ans<<endl;
			fnans=min(fnans,ans);
		}
	cout<<fnans;
	return 0;
}
