#include<bits/stdc++.h>
using namespace std;

int n, m, k, c[20], a[10004];
struct ed{
	int v, w;
};
vector<ed> e[2000004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		ed t;
		t.v = v, t.w = w;
		e[u].push_back(t);
		t.v = u;
		e[v].push_back(t);
	}
	
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++){
			cin>>a[i];
		}
	}
	
	
	return 0;
}