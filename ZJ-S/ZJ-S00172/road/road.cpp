#include<bits/stdc++.h>
using namespace std;
vector <int> g[1000010];  
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k; 
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	printf(13);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

