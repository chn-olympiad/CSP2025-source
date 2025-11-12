#include<bits/stdc++.h>
using namespace std;
const int maxm=2e6+10;
const int maxk=15;
const int maxn=1e4+10;
int n,m,k,f[maxn],a[maxk][maxn],c[maxn],cnt;
long long sum;
struct node{
	int u,v,w;
}e[maxm];
bool cmp(node xx,node yy){
	return xx.w<yy.w;
}
int fd(int x){
	return f[x]==x?x:f[x]=fd(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
		
	}
	bool vis=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) vis=false;
		bool fg=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(!a[i][j]) fg=true;
		}
		if(!fg) vis=false;
	}
	if(vis){
		for(int i=1;i<=k;i++){
			int s=0;
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					s=j;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				if(j==k) continue;
				e[++m]={s,j,a[i][j]};
			}
			if(!s) break;
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		if(fd(x)==fd(y)) continue;
		f[fd(x)]=f[fd(y)];
		cnt++;
		sum+=e[i].w;
		if(cnt==n-1){
			cout<<sum<<"\n";
			break;
		}
	}
	return 0;
}