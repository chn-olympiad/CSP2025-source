#include <iostream>
#include <vector>
using namespace std;
struct node{
	long long u,v,w;
};
vector <node> g[100005];
long long c[15][50005],tot,sum;
long long minc[100005];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[v].push_back({v,u,w});
		g[u].push_back({u,v,w});
		if(k==0) tot+=w;
	}
	if(k==0){
		cout<<tot;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]==0) minc[j]=i;
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(auto vi:g[i]){
			if(vi.w>(min(c[minc[vi.u]][vi.u],c[minc[vi.v]][vi.v]))){
				vi.w=(min(c[minc[vi.u]][vi.u],c[minc[vi.v]][vi.v]));
				g[i].push_back({vi.u,vi.v,vi.w});
			}
			tot+=vi.w;
		}
	}
	cout<<tot;
}
