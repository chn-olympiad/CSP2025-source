#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,k,u,v,w,h[10010],nt[10010],ver[10010],a[10010],c[10010],tot,ans,vi[10010],minn;
queue<int> q;
void add(int u,int v,int w){
	nt[++tot]=v;
	h[u]=tot;
	ver[tot]=w;
}
void bfs(int x){
	vi[x]=1;
	q.push(x);
	while(!q.empty()){
		int y=q.front();
		q.pop();
		vi[y]=1;
		for(int i=h[y];i;i=nt[i]){
//			cout<<i<<" "<<y<<" "<<nt[i]<<" "<<ver[i]<<"\n";
			minn=2147483647;
			if(!vi[nt[i]]){
				q.push(nt[i]);
				vi[nt[i]]=1;
				minn=min(minn,ver[i]);
			}
		}
		ans+=minn==2147483647?0:minn;
	}
}
void bfss(int x){
	vi[x]=1;
	q.push(x);
	while(!q.empty()){
		int y=q.front();
		q.pop();
		vi[y]=1;
		for(int i=h[y];i;i=nt[i]){
			minn=2147483647;
			if(!vi[i]){
				q.push(i);
				minn=min(minn,ver[i]);
			}
		}
		ans+=minn==2147483647?0:minn;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ans+=k;
		add(u,v,w);
		add(v,u,w);
	}
	cout<<ans;
    return 0;
}

