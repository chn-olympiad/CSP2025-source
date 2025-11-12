#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int h[21001],ne[51011],ed[51011],w[51011],idx;//记得改数组大小 
struct edge{
	int u,v,w;
}e[1001011];
int eidx=0;
int n,m,k;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int id[101011];
int fid(int x){
	if(id[x]==x){
		return id[x];
	}
	else return id[x]=fid(id[x]);
}
void add(int a,int b,int c){
	ne[++idx]=h[a];
	h[a]=idx;
	ed[idx]=b;
	w[idx]=c;
}
int kk[1010],kn[101011];
long long ans,nans,ii;
void dfs(int x,int fa,int lalong){
	if(x<=n){
		if(lalong>kn[x]){
			nans=nans+kn[x];
			e[++eidx].u=n+ii;
			e[eidx].v=x;
			e[eidx].w=kn[x];
		}
		else{
			nans+=lalong;
			e[++eidx].u=fa;
			e[eidx].v=x;
			e[eidx].w=lalong;
		}
	}
	else{
		nans+=lalong;
		e[++eidx].u=fa;
		e[eidx].v=x;
		e[eidx].w=lalong;
	}
	for(int i=h[x];i;i=ne[i]){
		int v=ed[i];
		if(v!=fa){
			dfs(v,x,w[i]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)	id[i]=i;
	for(int i=1;i<=m;i++){
		int a=e[i].u;
		int b=e[i].v;
		if(fid(a)!=fid(b)){
			id[fid(a)]=fid(b);
			add(e[i].u,e[i].v,e[i].w);
			add(e[i].v,e[i].u,e[i].w);
			ans+=e[i].w;
		}
	}
	for(ii=1;ii<=k;ii++){
		cin>>kk[ii];
		int mi=2e9,miid;
		for(int j=1;j<=n;j++){
			cin>>kn[j];
			if(kn[j]<mi){
				mi=kn[j];
				miid=j;
			}
		}
		nans=kk[ii];
		eidx=0;
		dfs(miid,n+ii,mi);
		if(nans>=ans){
			continue;
		}
		ans=nans;
		memset(h,0,sizeof(h));
		memset(ne,0,sizeof(ne));
		memset(ed,0,sizeof(ed));
		memset(w,0,sizeof(w));
		idx=0;
		for(int j=1;j<=eidx;j++){
			add(e[j].u,e[j].v,e[j].w);
			add(e[j].v,e[j].u,e[j].w);
		}
	} 
	cout<<ans;
	return 0;
}
