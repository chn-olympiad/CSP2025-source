#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w,f;
}e[3000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long n,m,k,c[10005],a[20][20005],fa[10005],usd[10005],pos=0,tp=1;
vector<long long>vis[20];
long long find(long long x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
long long kruskal(){
	long long cnt=0,ans=0;
	for(long long i=1;i<=m;i++){
		long long u=e[i].u,v=e[i].v,w=e[i].w,f=e[i].f;
		long long fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			ans+=w;
			if(f){
				if(!usd[f]){
					usd[f]=1;
					for(long long jj=0;jj<vis[f].size();jj++){
						long long j=vis[f][jj];
						e[j].w-=c[f];
					}
				}
				for(long long jj=0;jj<vis[f].size();jj++){
					long long j=vis[f][jj];
					if(e[j].u==u||e[j].v==u) e[j].w-=a[f][u];
					if(e[j].v==v||e[j].u==v) e[j].w-=a[f][v];
				}
				sort(e+i+2,e+m+1,cmp);
			}
		}
		if(cnt==n-1+pos) return ans;
	}
	return -1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) fa[i]=i;
	for(long long i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		tp=(tp&&c[i]==0);
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
			tp=(tp&&a[i][j]==0);
		}
	}
	if(tp){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n;j++){
			for(long long jj=j+1;jj<=n;jj++){
				e[++m]={j,jj,c[i]+a[i][j]+a[i][jj],i};
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for(long long i=1;i<=m;i++){
		if(e[i].f) vis[e[i].f].push_back(i);
	}
	cout<<kruskal();
	return 0;
}
