#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int u[N],v[N],w[N];
int c[20],a[20][10010];
map<int,int>f[10110],x;//f[][N];
int m,mi=1e9;
void dfs(int d[10010],int r,int ans){
	int flag=1;
	for(int i=1;i<=m;i++){
		if(d[i]!=1)flag=0;
	}
	if(flag==1){
		mi=min(mi,ans);
	}
	for(int i=1;i<=x[r];i++){
		if(d[i]==1)continue;
		d[r]=1;
		dfs(d,f[r][i],ans+w[i]);
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int d=m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			u[++d]=k+i;
			v[d]=j;
			w[d]=a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		f[u[i]][++x[u[i]]]=v[i];
		f[v[i]][++x[v[i]]]=u[i];
	}
	int c[114514];
	dfs(c,1,0);
	cout<<mi;
	return 0;
}
