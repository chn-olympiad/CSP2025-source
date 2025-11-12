#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct edge{
	int to,next,dis;
}e[100005];
int dis[1000005],vis[1000005],cnt,head[1000005];
void add(int u,int v,int w){
	cnt++;
	e[cnt].dis=w;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
struct node{
	int pos,dis;
	bool operator <(const node &x) const{
		return x.dis<dis;
	}
};
priority_queue <node> q;
void dij(){
	q.push((node){1,0});
	dis[1]=0;
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int x=tmp.pos,d=tmp.dis;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].next;
			if(dis[y]>dis[x]+e[i].dis){
				dis[y]=dis[x]+e[i].dis;
				if(!vis[y]){
					q.push((node){y,dis[y]});
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=n+1;i<=n+k;i++){
		int w,f;
		scanf("%d",&f);
		ans+=f;
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
