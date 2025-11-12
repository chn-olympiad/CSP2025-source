#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100,M=2e6+5;

struct edge{
	int v,w,nxt;
}e[M<<1];

struct node{
	int dis,id;
	bool operator>(const node a)const{
		return dis>a.dis;
	}
};

int head[N],esize;

void put(int u,int v,int w){
	e[++esize]={v,w,head[u]};
	head[u]=esize;
}

int n,m,k,cst[12],c[12][N],dis[N],lst[N];
vector<bool>lock(20,true);
int res=2e18;

int prim(){
	priority_queue< node,vector<node>,greater<node> >q;
	vector<bool>vis(N,false);
	memset(dis,0x3f,sizeof dis);
	memset(lst,0,sizeof lst);
	dis[1]=0;
	q.push({0,1});
	
	int ans=0,count=n;
	while(!q.empty()){
		int x=q.top().id;q.pop();
		if(vis[x])continue;
		vis[x]=true,ans+=dis[x];
		if(x<=n)count--;
		if(!count)return ans;
		for(int i=head[x],v,w;i;i=e[i].nxt){
			v=e[i].v,w=e[i].w;
			if(v>n)if(!lock[v-n])continue;
			if(dis[v]>w){
				dis[v]=w;
				q.push({w,v});
			}
		}
	}
	return ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		put(u,v,w);put(v,u,w);
	}
	if(k<=1){
		for(int i=1;i<=k;i++){
			scanf("%lld",&cst[i]);
			for(int j=1;j<=n;j++){
				scanf("%lld",&c[i][j]);
				put(j,i+n,c[i][j]);
				put(i+n,j,c[i][j]);
			}	
		}
		for(int i=0;i<(1<<k);i++){
			int x=i,rt=0;
			for(int j=1;j<=k;j++){
				lock[j]=(x&1);
				if(x&1)rt+=cst[j];
				x>>=1;
			}
			res=min(res,prim()+rt);
		}
		cout<<res<<'\n';
	}else{
		for(int i=1;i<=k;i++){
			scanf("%lld",&cst[i]);
			for(int j=1;j<=n;j++){
				scanf("%lld",&c[i][j]);
				put(j,i+n,c[i][j]+cst[i]);
				put(i+n,j,c[i][j]);
			}	
		}cout<<prim()<<'\n';
	}
	return 0;
}
