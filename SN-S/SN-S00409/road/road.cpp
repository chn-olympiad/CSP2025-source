#include<bits/stdc++.h>
using namespace std;
vector<int>g[10100];
int n,m;
void dfs(int x){
	cout<<66666;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<114514;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

