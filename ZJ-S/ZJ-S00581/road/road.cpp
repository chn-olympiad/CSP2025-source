#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,fa[10005],c[15],go[15][10005],qu[15][10005];bool flag=0;
long long ans;
struct ed{
	int u,v,w;
}kk[2000005];
bool cmp(ed xx,ed yy){
	return xx.w<yy.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;++i){
			cin>>kk[i].u>>kk[i].v>>kk[i].w;
		}
		sort(kk+1,kk+1+m,cmp);
		for(int i=1;i<=n;++i){
			fa[i]=i;
		}
		for(int i=1;i<=m;++i){
			if(find(kk[i].v)!=find(kk[i].u)){
				ans=ans+kk[i].w;
				fa[find(kk[i].v)]=find(kk[i].u);
				++tot;
			}
			if(tot==n-1){
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&kk[i].u,&kk[i].v,&kk[i].w);
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		int y=1;
		for(int j=1;j<=n;++j){
			scanf("%d",&go[i][j]);
			if(!go[i][j]){
				y=j;
			}
		}
		for(int j=1;j<=n;++j){
			if(j==y){continue;}
			kk[++m].u=y;kk[m].v=j;kk[m].w=go[i][j]+c[i];
		}
	}
	sort(kk+1,kk+1+m,cmp);
	int cntt=0;
	for(int i=1;i<=m;++i){
		if(find(kk[i].v)!=find(kk[i].u)){
			ans+=kk[i].w;
			fa[find(kk[i].v)]=fa[find(kk[i].u)];
			++cntt;
		}
		if(cntt==n-1){
			break;
		}
	}
	cout<<ans;
}
