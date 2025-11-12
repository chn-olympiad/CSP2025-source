#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long answers=LONG_LONG_MAX;
struct edge{
	int s,e;
	long long w;
}edges[3000005];
int cnt;
bool available[15];
long long openings[15];
long long fares;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
struct sets{
	int fa[20100],n;
	int size[20100];
	void set(int N){
		n=N;
		for(int i=1;i<=n;++i)fa[i]=i,size[i]=1;
	}
	int find(int x){
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx==fy)return ;
		if(size[fx]>size[fy]){
			fa[fy]=fx;
			size[fx]+=size[fy];
		}else{
			fa[fx]=fy;
			size[fy]+=size[fx];
		}
		return ;
	}
	inline bool query(int x,int y){
		return find(x)==find(y);
	}
}bcq;
long long work(){
	bcq.set(n+k);
	long long ans=0;
	for(int i=0;i<cnt;++i){
		if(edges[i].s>n&&!available[edges[i].s-n-1]){
			continue;
		}
		if(!bcq.query(edges[i].s,edges[i].e)){
			ans+=edges[i].w;
			bcq.merge(edges[i].s,edges[i].e);
		}
	}
	return ans;
}
void dfs(int now){
	if(now==k){
		fares=0;
		for(int i=0;i<k;++i){
			if(available[i]==true)fares+=openings[i];
		}
		long long tmp=work();
		answers=min(answers,tmp+fares);
		return ;
	}
	available[now]=false;
	dfs(now+1);
	available[now]=true;
	dfs(now+1);
	return ;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;++i){
	//	scanf("%d%d%lld",&edges[i].s,&edges[i].e,&edges[i].w);
		cin>>edges[i].s>>edges[i].e>>edges[i].w;
	}
	cnt=m;
	for(int i=0;i<k;++i){//n+1~n+k
	//	scanf("%lld",&openings[i]);
		cin>>openings[i];
		for(int j=1;j<=n;++j){
			edges[cnt].s=n+i+1;
			edges[cnt].e=j;
			//scanf("%lld",&edges[cnt].w);
			cin>>edges[cnt].w;
			cnt++;
		}
	}
	sort(edges,edges+cnt,cmp);
	dfs(0);
	//printf("%lld",answers);
	cout<<answers;
	return 0;
}
