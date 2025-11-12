#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1e5+5;
struct edge{
	int u,v,w;
}e[maxn];

int cnt,n,m,k;
int vis[11],num[11],sum[11];

int cmp(edge a,edge b){
	return a.w<b.w;
}

int f[11111];

int finds(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=finds(f[x]);
}

long long ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i){
		f[i]=i;
	}
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf(" %d%d%d",&u,&v,&w);
		e[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;++i){
		cin>>sum[i];
		for(int j=1;j<=n;++j){
			int x;
			scanf(" %d",&x);
			e[++cnt]={n+i,j,x+sum[i]};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int cntt=0;
	for(int i=1;i<=cnt;++i){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int uu=finds(u),vv=finds(v);
		if(uu==vv){
			continue;
		}
		f[uu]=vv;
		cntt++;
		if(u>n){
			if(!vis[u-n]){
				vis[u-n]++;
				ans+=w;
				num[u-n]+=w;
			}else{
				vis[u-n]++;
				ans=ans+w-sum[u-n];
				num[u-n]=num[u-n]+w-sum[u-n];
			}
		}else{
			ans+=w;
		}
		if(cntt==n+k-1){
			break;
		}
	}
	for(int i=1;i<=k;++i){
		if(vis[i]==1){
			ans-=num[i];
		}
	}
	cout<<ans;
	return 0;
}