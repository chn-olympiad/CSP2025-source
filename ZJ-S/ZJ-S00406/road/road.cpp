#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,k,a[10001][10001],ans,minn;
int b[10001][10001];
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int u,v,x;
	for(int i=0;i<m;i++){
		cin>>u>>v>>x;
		a[u][v]=x;
		a[v][u]=x;
	}
	int p=1e9;
	for(int i=0;i<n-1;i++){
		p=1e9;
		for(int j=0;j<10001;j++){
			if(a[i][j]<p&&a[i][j]&&b[i][j]==0){
				p=a[i][j];
				b[i][j]=1;
				b[j][i]=1;
			}
		}
		ans+=p;
	}
	cout<<ans;
	return 0;
}
