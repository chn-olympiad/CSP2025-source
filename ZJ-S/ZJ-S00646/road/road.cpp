#include<bits/stdc++.h>
using namespace std;
int mi,x,y,k,f[1001][1001],op,sum,p[1001],n,m,d[1001];
vector<int>a[1001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>op;
		a[x].push_back(y);
		a[y].push_back(x);
		f[x][y]=f[y][x]=op;
		sum+=op;
	}
	for(int i=1;i<=k;i++){
		cin>>op;
		for(int j=1;j<=n;j++){
			cin>>p[j];
		}
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				a[j].push_back(k),a[k].push_back(j),f[j][k]=f[k][j]=op+p[j]+p[k];
	}
	cout<<sum;
	return 0;
}

