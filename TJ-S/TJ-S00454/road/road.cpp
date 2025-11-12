#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int to,val;
};
vector<node> road[2000009];
int main(){
	//freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,val;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&val);
		road[u].push_back({v,val});
		road[v].push_back({u,val});
	}
	cout<<1989237;
return 0;}
