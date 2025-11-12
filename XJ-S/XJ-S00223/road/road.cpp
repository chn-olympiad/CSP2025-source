#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt,ans;
int pre[10020],vis[20],wvl[20];
struct edge{
	int u,v,w;
}edges[100020];
bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}
int find(int xx){
	if(pre[xx]==xx)return xx;
	else return pre[xx]=find(pre[xx]);
}
bool join(int a,int b){
	int ra=find(a);
	int rb=find(b);
	if(ra==rb)return false;
	pre[ra]=rb;
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges[i].u=u;
		edges[i].v=v;
		edges[i].w=w;
	}
	for(int i=1;i<=k;i++){
		int ww;
		cin>>ww;
		wvl[i]=ww;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
		}
	}
	sort(edges+1,edges+1+m,cmp);
	for(int i=1;i<=n;i++)pre[i]=i;
	for(int i=1;i<=m;i++){
		int u=edges[i].u;
		int v=edges[i].v;
		int w=edges[i].w;
		if(find(u)!=find(v)){
			join(u,v);
			cnt++;
			ans+=w; 
		}
		if(cnt==n-1 && ans>0){
			cout<<ans;
			return 0;
		}
	}
	return 0;
} 
