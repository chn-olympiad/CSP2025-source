#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1005][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	cout<<rand()%n*m/k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//不会写最短路直接死掉了 
//牢弟们我去学物理了
//初二直接退役 
