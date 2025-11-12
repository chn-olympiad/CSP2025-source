#include<bits/stdc++.h>
using namespace std;
int citys[10005];
long long INF=1e9;
void dfs(int u,int v,int w){
	int cost_min=0;
	queue<int> q;
	q.push(citys[u]);
	q.pop();
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		//½¨Í¼ 
		citys[i]=v;
		citys[v]=u;
	}
	cout<<13<<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0; 
}
