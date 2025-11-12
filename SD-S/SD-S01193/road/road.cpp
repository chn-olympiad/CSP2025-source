#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=2e6+10;
ll n,m,k,cnt=0,ans=0,head[M],dis[N],c[11][N];
bool vis[N];
stack <int> s;
struct Edge{
	int to,val,nxt;
}e[M];
void dij(){
	while(!s.empty()){
		int t=s.top();
		if(!vis[t]){
			vis[t]=1;
			for(int i=head[t];i;i=e[i].nxt){
				for(int j=0;j<k;j++){
					dis[e[i].to]=min(dis[e[i].to],dis[t]+c[j][0]+c[j][t]+c[j][e[i].to]);
				}
				if(dis[e[i].to]>dis[t]+e[i].val){
					dis[e[i].to]=dis[t]+e[i].val;
					s.push(e[i].to);
				}
			}
		}
	}
}
void edge(int u,int v,int w){
	head[++cnt]=u;
	e[u].nxt=cnt;
	e[cnt].to=v;
	e[cnt].val=w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge(u,v,w);
		edge(v,u,w);
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=2;i<=n;i++){
		dis[i]=1e9;
	}
	s.push(1);
	dij();
	for(int i=1;i<=n;i++){
		if(dis[i]==1e9){
			for(int j=0;j<k;j++){
				dis[i]=min(dis[i],c[j][0]+c[j][1]+c[j][i]);
			}
		}
		ans+=dis[i];
	}
	cout<<ans<<endl;
	return 0;
}
