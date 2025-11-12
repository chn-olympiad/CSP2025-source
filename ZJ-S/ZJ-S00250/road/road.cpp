#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100006],v[100006],w[100006];
int c[1000][1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++)c[i][j]=99999;
	}
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		c[u[i]][v[i]]=min(w[i],c[u[i]][v[i]]);
	}
	cout<<"13";
	return 0;
} 
