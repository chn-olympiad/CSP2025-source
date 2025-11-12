#include<bits/stdc++.h>
#define x first
#define y second
#define PIR pair<int,int>
#define scnaf scanf
using namespace std;
const int N=1e4+105;
vector<PIR> v1[N],v2[N];
int vis[N];
int a[N];
int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d",u,v,w);
		v1[u].push_back({v,w});
		v2[v].push_back({u,w});
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
		for(int i=1,tmp;i<=n;i++){
			scanf("%d",&tmp);
			v2[i].push_back({j,tmp});
			v2[j].push_back({i,tmp});
		}
	}
	return 0;
}
