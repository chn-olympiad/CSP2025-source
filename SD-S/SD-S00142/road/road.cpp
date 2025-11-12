#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int M=1e7+50;
int n,m,k;
int fa[M],e[M],cnt,ans,num,vis[M],cuncnt;
struct node{
	int w,u,v;
	int cun;
}a[M];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[++cnt].w=w;
		a[cnt].u=u;
		a[cnt].v=v;
		a[cnt].cun=0;
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>e[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[++cnt].w=w+e[i];
			a[cnt].cun=1;
			a[cnt].u=i+n;
			a[cnt].v=j;
		}
	} 
	sort(a+1,a+cnt+1,cmp);
	int cnt1=0,duosuan=0,fsame;
	for(int i=1;i<=cnt;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w,cun=a[i].cun,f=0;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		cnt1++;
		fa[u]=fv;
		ans+=w;
		if(cun){
			cuncnt++;
			if(a[i].u>n&&!vis[a[i].u]){
				vis[a[i].u]=1;
				duosuan+=e[a[i].u-n];
			}
			if(a[i].v>n&&!vis[a[i].v]){
				vis[a[i].v]=1;
				duosuan+=e[a[i].v-n];
			}
		}
		if(cnt1==n-1+cuncnt/2) break;
	}
	cout<<ans-duosuan<<endl;
	return 0;
}
