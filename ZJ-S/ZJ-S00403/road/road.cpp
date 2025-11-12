#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
vector<int>E[1145];
int a[1145][1145];
int nk[1145][1145];
int vis[1145];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		E[x].push_back(y);
		E[y].push_back(x);
		a[x][y]=z;
		a[y][x]=z;
		ans+=z;
	}
	for(int i=1;i<=k;i++){
		int v;
		cin>>v;
		for(int i=1;i<=n;i++){
			cin>>nk[v][i];
		}
	}
	printf("%d",ans);
	return 0;
}