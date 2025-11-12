#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num;
	int lu[10005];
}city[10005];
int cost[10086];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		city[u].lu[v]=w;
		city[v].lu[u]=w;
		city[u].num++;
		city[v].num++;
	}
	for(int i=1;i<=k;i++){
		int w[n+1];
		for(int j=1;j<=n;j++)cin>>w[j];
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			city[n+i].lu[j]=w[i];
			city[j].lu[n+i]=w[i];
			city[n+i].num++;
			city[j].num++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=city[i].lu[i+1];
	cout<<ans;
	return 0;
}
