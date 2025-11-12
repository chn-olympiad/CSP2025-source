#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e6+1000;
LL bzj[maxn];
int n,m,k;
LL ac,u,v,w,a[15][maxn],c[15];
bool vis[15];
struct edg{
	int u;
	int v;
	int na;
	LL w;
	bool operator < (const edg& a){
		return w>a.w;
	}
}ed1,ed2,edd[maxn];
LL find(LL u){
	if(bzj[u]==u)return u;
	return bzj[u]=find(bzj[u]);
}
vector<edg> g[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ed1.u=u,ed1.v=v,ed1.na=i,ed1.w=w,ed1.ct=0;
		g[u].push_back(ed1);
		g[v].push_back(ed1);
		edd[i].u=u;
		edd[i].v=v;
		edd[i].na=i;
		edd[i].w=w;
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			cin>>c[j]>>a[j][i];
			a[i][j]=a[j][i];
			
		} 
	}
	sort(edd,edd+m); 
	for(int i=1;i<=n;i++)bzj[i]=i;
	for(int i=1;i<=m;i++){
		int b1=find(edd[i].u);
		int b2=find(edd[i].v);
		if(b1!=b2){//²»ÏàÁ¬ 
			//cout<<b1<<" "<<b2<<endl;
			ac+=edd[i].w;
			bzj[b1]=b2;
		}
	}
	cout<<ac;
	return 0;
}
