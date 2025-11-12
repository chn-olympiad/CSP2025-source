#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int n , m , k;
vector<pair<int , int> > g[N];
priority_queue< pair<int,int> > q;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1 ; i <= m ; i++){
		int u , v , w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
}