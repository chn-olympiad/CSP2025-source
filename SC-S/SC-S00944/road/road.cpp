#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
using pii=pair<long long,pair<int,int>>;
int n,m,k;
pii dis[N];
int cnt_node[N],cnt_vil[N];
long long ans,c[N],d[N][N],vil[N][N],temp[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=min(d[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int v=1;v<=n;v++){
			cin>>temp[v];
			for(int u=1;u<v;u++){
				if(d[u][v]>temp[u]+temp[v]+c[i]){
					d[u][v]=d[v][u]
					=temp[u]+temp[v]+c[i];
					vil[u][v]=vil[v][u]=i;
				}
			}
		}
	}
	int t=0;
	for(int v=2;v<=n;v++){
		for(int u=1;u<v;u++){
			dis[++t]={d[u][v],{u,v}};
		}
	}
	sort(dis+1,dis+1+t);
	int p=0;
	for(int i=1;i<n;i++){
		pii e=dis[++p];
		long long w=e.first;
		int u=e.second.first,
		v=e.second.second;
		if(cnt_node[u]&&cnt_node[v]){
			continue;
			i--;
		}
		cnt_node[u]++; cnt_node[v]++;
		cnt_vil[vil[u][v]]++;
		ans+=w;
		if(cnt_vil[vil[u][v]]>1)
			ans-=c[vil[u][v]];
	}
	cout<<ans;
	return 0;
}