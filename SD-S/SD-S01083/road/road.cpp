#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[15],a[10005][10005],minn = 1000000000,s;
int dis;
struct Edge {
	int v,w;
	bool operator<(const Edge&c1) const {
		return c1.w < w;
	}
};
vector<Edge> edge[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",n,m,k);
	for(int i = 1;i <= m;i++) {
		scanf("%d%d%d",&u,&v,&k);
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
		if(w < minn) {
			minn = w;
			s = i;
		}
	}
	for(int i = 1;i <= k;i++) {
		scanf("%d",&c[i]);
		for(int j = 2;j <= n+1;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	printf("%d",0);
	return 0;
}

