#include<bits/stdc++.h>
using namespace std;
long long n,m,k,gsa=0,gs=0;
struct li{
	long long u,v,w;
}ed[1000005];
long long fa[10005]={0},sz[10005]={0};
long long a[10005];
bool cmp(li x,li y){
	return x.w<y.w;
}
long long f(long long x){
	if(x==fa[x]){
		return x;
	}return fa[x]=f(fa[x]);
}
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++){
			cin>>a[j];
			for(int z=1;z<j;z++){
				m++;
				ed[m].u=z;
				ed[m].v=j;
				ed[m].w=a[j]+a[z]+c;
			}
		}
	}sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w; 
		if(f(u)==f(v)){
			continue;
		}
		if(f(u)!=f(v)){
			gsa+=w;
			if(f(u)<f(v)){
				fa[v]=f(u);
				sz[f(u)]+=sz[f(v)];
			}if(f(u)>f(v)){
				fa[u]=f(v);
				sz[f(v)]+=sz[f(u)];
			}
		}if(sz[1]==n){
			break;
		}
	}cout<<gsa;
	return 0;
}