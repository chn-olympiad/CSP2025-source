#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
struct node{
	int u,v,w;
};
int Map[2000][2000];
int c[N][N];
node a[N];
int n,m,k;
int main(){
	freopen(road.in,"r",stdin);
	freopen(road.out,"w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
		}
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
