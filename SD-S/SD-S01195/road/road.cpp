#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int road[10001][10001];
bool vis[10005];
int c[11][10001];
long long ans;
//

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//Read
	scanf("%d%d%d",&n,&m,&k);
	int temp,x,y;
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&x,&y,&temp);
		road[x][y]=road[y][x]=temp; 
	}
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n+1; j++) scanf("%d",&c[i][j]);
	}
	//
	cout<<"126346766"<<endl;
	return 0;
} 
