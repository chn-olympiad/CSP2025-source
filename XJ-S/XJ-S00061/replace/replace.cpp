#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,c[10],w,a,p[10011][10011];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(p,0,sizeof(p));
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		p[u][v]=w;
	}for(int i=0;i<=k;i++){
		cin>>c[i];
		for(int j=0;j<n;i++){
			cin>>a;
			p[n+i][j]=a;
		}
	}n+=k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-k;j++){
			cout<<p[i][j]<<' ';
		}cout<<endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
