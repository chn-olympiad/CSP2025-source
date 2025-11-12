#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
int v[N+N],nex[N+N],h[N+N],e[N+N],tot=0,tt[N],ans=0;
int xiang[N][4];
void add(int x,int y,int z){
	tot++;
	v[tot]=y;
	e[tot]=z;
	nex[tot]=x;
	h[x]=tot;
}
void dfs(int x){
	for(int i=h[x];i=nex[i];i){
		int u=v[i];
		if(tt[u]!=tt[i]){
			ans+=e[i];
			tt[u]=tt[i];
			dfs(u);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int x,y,z,flag=1000000000,idx;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		add(x,y,z);
		tt[i]=i;
		if(z<flag){
			flag=z;
			idx=i;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>xiang[i][1]>>xiang[i][2]>>xiang[i][3];
	}
	dfs(idx);
	cout<<ans;
	return 0;
}