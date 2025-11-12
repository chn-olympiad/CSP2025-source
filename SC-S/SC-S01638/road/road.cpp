#include<bits/stdc++.h>
#define int long long
using namespace std;
struct pii{
	int x,y;
};
int n,m,k,d[200005],s;
vector<pii>p[200005];
map<int,map<int,bool> >f;
void dij(){
	memset(d,0x3f,sizeof(d));
	queue<int>q;
	d[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<p[u].size();i++){
			int v=p[u][i].x,w=p[u][i].y;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				f[v][u]=1;
				f[u][v]=1;
				q.push(v);
			}
		}
		
	}
}
signed main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	int x;
	for(int i=1;i<=k;i++){
		cin>>w;
		for(int j=1;j<=n;j++){
			cin>>x;
			p[i+n].push_back({j,x});
			p[j].push_back({i+n,w+x});
		}
	}
	dij();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]){
				s+=p[j][i].y;
				f[i][j]=0;
			}
		}
	}
	cout<<s;
	return 0;
} 