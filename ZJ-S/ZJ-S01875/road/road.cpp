#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long n,m,k,r[N][N],p[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		r[x][y]=z;
		r[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>p[i][j];
		}
	}
	return 0;
}