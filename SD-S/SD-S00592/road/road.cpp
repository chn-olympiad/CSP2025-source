#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,ecnt,fa[20005],dis[1005][1005];
ll c[15],a[15][10005];
struct edge{
	int u,v;
	ll w;
}e[4000005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void krus(){
	sort(e+1,e+ecnt+1,cmp);
//	cout<<ecnt<<endl;
	ll sum=0;
	int cnt=0;
	for(int i=1;i<=ecnt;i++){
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			fa[f1]=f2;
			sum+=e[i].w;
			cnt++;
		}
//		if(cnt==n-1) break;
	}
	printf("%lld",sum);
	return;
}
void solve1(){
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			ll minn=1e18;
			for(int i=1;i<=k;i++){
				minn=min(minn,a[i][u]+a[i][v]);
			}
			if(dis[u][v]!=-1) e[dis[u][v]].w=min(e[dis[u][v]].w,minn);
			else e[++ecnt]={u,v,minn},dis[u][v]=ecnt;
		}
	}
//	cout<<ecnt<<endl;
	krus();
	return;
} 
void solve2(){
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);
	}
	ecnt=m;
	krus();
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	if(k==0){
		solve2();
		return 0;
	}
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++) dis[i][j]=-1;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d %d %lld",&u,&v,&w);
		if(dis[u][v]==-1){
			e[++ecnt]={u,v,w};
			dis[u][v]=ecnt;
		}else{
			e[dis[u][v]].w=min(e[dis[u][v]].w,w);
		}
	}	
	ll f=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		f+=c[i];
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
//	cout<<f<<endl;
	if(f==0){
		solve1();
	}
	return 0;
}
