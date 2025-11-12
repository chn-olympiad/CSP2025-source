#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const int M=4e6+5;
int n,mm,k;
int res=0;
int m,ans,fa[N];
struct wcy{
	int u,v,w;
	bool operator < (wcy a) const{
		return w<a.w;
	}
}t[M];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void Kruskal(){
	sort(t+1,t+m+1);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u=t[i].u;
		int v=t[i].v;
		int w=t[i].w;
		int fu=find(u);
		int fv=find(v);
		if(fu!=fv){
			ans+=w;
			fa[fu]=fv;
			if(ans>=res&&res) break;
		}
	}
}
int c[11];
int cc[11][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>mm>>k;
	while(mm--){
		int u,v,w;
		cin>>u>>v>>w;
		t[++m]={u,v,w};
		t[++m]={v,u,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cc[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
		int tempm=m;
		ans=0;
		for(int j=1;j<=k;j++){
			if(i>>(j-1)&1){
				ans+=c[j];
				for(int k=1;k<=n;k++){
					t[++m]={n+j,k,cc[j][k]};
					t[++m]={k,n+j,cc[j][k]};
				}
			}
		}
		Kruskal();
		if(!res) res=ans;
		else res=min(res,ans);
		m=tempm;
	}
	cout<<res<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
