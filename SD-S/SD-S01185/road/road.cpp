#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e4+10,K=1e5+10;
int n,m,k,c[15],f[M],cnt;
long long ans,egege[15][M];
bool vis[15];
bool cp=1;
struct edge{
	int u,v;
	long long w;
}ege[N+K];
bool cmp(edge aa,edge bb){
	return aa.w<bb.w;
}
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}void merge(int u,int v){
	u=find(u),v=find(v);
	f[u]=f[v];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ege[i].u>>ege[i].v>>ege[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			long long w;cin>>w;
			egege[i][j]=w;
		}
	}
	sort(ege+1,ege+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int ii=1;ii<=m;ii++){
		edge i=ege[ii];
		int u=i.u,v=i.v,choos=0;
		if(find(u)==find(v))continue;
		long long miner=100000000000,w=i.w;
		for(int i=1;i<=k;i++){
			if(!vis[i]){
				if(egege[i][u]+egege[i][v]+c[i]<=miner){
					choos=i;
					miner=egege[i][u]+egege[i][v]+c[i];
				}
			}else{
				if(egege[i][u]+egege[i][v]<=miner){
					choos=i;
					miner=egege[i][u]+egege[i][v];
				}
			}
		}
		if(w>=miner){
			w=miner;
			vis[choos]=1;
			egege[choos][u]=egege[choos][v]=0;
		}
		merge(u,v);
		cnt++;
		ans+=w;
		if(cnt==n-1)break;
	}cout<<ans;
	return 0;
}



