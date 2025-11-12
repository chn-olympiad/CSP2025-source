#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<cstring>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int vis[10100];
int n,m,k,head[10100],tot=0,ll[10100];
map<int,int>mp[10100];
queue<int,int>q;
long long c[10100],ans;
struct node1{
	long long d;
	int f=1;
}dis[20000];
struct node{
	long long nxt,v,w;
}a[2000000];
void add(int u,int v,int w){
	a[++tot]=node{head[u],v,w};
	head[u]=tot;
	a[++tot]=node{head[v],u,w};
	head[v]=tot;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i+n];
		for(int j=1;j<=n;j++){
			int t;
			scanf("%d",&t);
			add(i+n,j,t);
		}
	}
	for(int i=1;i<=n;i++){
		mp[i][1]=mp[1][i]=1;
	}
	dis[1].d=0;
	q.push(1);
	while(!q.empty()){
		int cnt=0;
		while(!q.empty()){
			ll[++cnt]=q.front();
			q.pop();
		}
		sort(ll+1,ll+1+cnt);
		for(int i=2;i<=cnt;i++)q.push(ll[i]);
		int t=ll[1];
		vis[t]=1;
		for(int i=head[t];i;i=a[i].nxt){
			int vv=a[i].v,ww=a[i].w;
			if(vis[vv]==1)continue;
			if(dis[vv].d>dis[t].d+ww+c[t]){
				dis[vv].d=dis[t].d+ww;
				mp[i][dis[vv].f]=mp[dis[vv].f][i]=0;
				mp[i][t]=mp[t][i]=1;
				dis[vv].f=t;
				if(vis[vv]==0){
					q.push(vv);
					vis[vv]=2;
				}
			}
		}
	}
	for(int i=n+1;i<=n+k;i++){
		int ji=0,jii;
		for(int j=head[i];j;j=a[j].nxt){
			int vv=a[j].v;
			if(mp[vv][i]){
				ji++;
				jii=vv;
			}
			if(ji>1)break;
		}
		if(ji==1)mp[jii][i]=mp[i][jii]=0;
	}
	for(int i=1;i<=n+k;i++){
		for(int j=head[i];j;j=a[j].nxt){
			int vv=a[j].v;
			if(mp[vv][i]&&vv>i)ans+=a[j].w;
			if(i>n){
				ans+=c[i];
				c[i]=0;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
//呜呜，这辈子有了 
