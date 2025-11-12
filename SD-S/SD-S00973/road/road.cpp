#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
const int N=1e4+10;
const int M=1e6+10;
struct Edge{
	int u,v;
	int iloc; 
	long long w;
};
Edge edge[M*2],edge2[M*2];
int head[N],head2[N];
int idx=0,idx2=0;
void addedge(int uu,int vv,long long ww){
	idx++;
	edge[idx].v=vv;
	edge[idx].u=head[uu];
	edge[idx].w=ww;
	edge[idx].iloc=uu;
	head[uu]=idx;
}
void addedge2(int uu,int vv,long long ww){
	idx2++;
	edge2[idx2].v=vv;
	edge2[idx2].u=head2[uu];
	edge2[idx2].w=ww;
	head2[uu]=idx2;
}
int uu,vv;
long long ww;
long long wi[20][N];
long long c[20];
int fa[N];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int fd(int u){
	if(fa[u]==u) return u;
	return fa[u]=fd(fa[u]);
}
long long ans=0;
const int NN=1e3+10;
int dis[NN][NN];
void dfs(int u,int fa,long long step,int st){
	dis[u][st]=step;
	dis[st][u]=step;
	for(int i=head2[u];i;i=edge2[i].u){
		int v=edge2[i].v;
		if(v==fa) continue;
		dfs(v,u,step+edge2[i].w,st);
	}
}
bool vis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	while(m--){
		cin>>uu>>vv>>ww;
		addedge(uu,vv,ww);
		addedge(vv,uu,ww);
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
//		if(c[n+i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			cin>>wi[i][j];
//			if(ww!=0) flag=false;
		}
	}
	sort(edge+1,edge+1+idx,cmp);
	for(int i=1;i<=idx;i++){
		int iLoc=edge[i].iloc;
		int v=edge[i].v;
		if(fd(iLoc)!=fd(v)){
			ans+=edge[i].w;
			fa[fd(iLoc)]=fd(v);
			addedge2(iLoc,v,edge[i].w);
			addedge2(v,iLoc,edge[i].w);
		}
	}		
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,i,0,i);
	}
	for(int i=1;i<=k;i++){
		for(int l=1;l<n;l++){
			for(int r=l+1;r<=n;r++){
				if(wi[i][l]+wi[i][r]+(vis[i]==0?c[i]:0)<dis[l][r]){
					ans=ans-dis[l][r]+wi[i][l]+wi[i][r]+(vis[i]==0?c[i]:0);
					dis[l][r]=wi[i][l]+wi[i][r]+(vis[i]==0?c[i]:0);
					vis[i]=1;
				} 
			}
		}
	}
	cout<<ans;
	return 0;
}
