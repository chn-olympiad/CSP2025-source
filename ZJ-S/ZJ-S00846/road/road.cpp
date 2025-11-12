#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,k,a[10010][10010],c[20],u,v,w,ans,b[10010][10010];
struct node{
	int u,v;
}d[10010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d[i].u>>d[i].v>>w;
		a[d[i].u][d[i].v]=a[d[i].v][d[i].u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i]>>w;
		if(c[i]==0){
			b[n+1][i]=b[i][n+1]=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(d[i].u==d[j].u||d[i].v==d[j].u){
				b[i][j]=b[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==0){
				ans+=a[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/