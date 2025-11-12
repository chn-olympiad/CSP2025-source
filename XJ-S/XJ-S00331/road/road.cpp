#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,lg=0;
struct node{
	int u,v;
	long long w;
}g[M<<1];
int f[N],c[15];
long long a[15][N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void kscl(){
	for(int i=1;i<=n;i++)f[i]=i;
	sort(g+1,g+1+lg,cmp);
	long long ans=0;
	for(int i=1;i<=lg;i++){
		int u=g[i].u,v=g[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fu]=fv;
			ans+=g[i].w;
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		lg++;
		cin>>g[lg].u>>g[lg].v>>g[lg].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0)kscl();
	else{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				long long ww=1e18;
				for(int l=1;l<=k;l++)
					 ww=min(ww,a[l][i]+a[l][j]);
				lg++;
				g[lg].u=i;g[lg].v=j;g[lg].w=ww;
			}
		kscl();
	}
	return 0;
}
