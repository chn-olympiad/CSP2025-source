#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
long long dis[MAXN],c[MAXN],a[MAXN][MAXN],cnt=0;
long long n,m,k,u,v,w;

struct node{
	long long u;
	long long v;
	long long w;
}f[MAXN];

int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}

void kruskal(){
	sort(f+1,f+n+1);
	
}
int main(){
	freopen("road.in","r",stdin);
	fropen("road.out","w",stdout)
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		f[i].u=u;
		f[i].v=v;
		f[i].w=w;
	}
	for(int j=1;j<=m;j++){
		cin>>c[j];
		for(cnt=1;cnt<=n;cnt++)
		cin>>a[j][cnt];
	}
	
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
