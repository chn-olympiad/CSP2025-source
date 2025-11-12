#include<bits/stdc++.h>
using namespace std;
#define maxn 11451
#define maxm 1145141
#define ll long long
int n,m,k;
ll c[14],a[14][maxn];
vector<pair<ll,ll> >edge[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	int u,v,w;
	int sum=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		edge[u].push_back({v,w});
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("%d",sum);
	return 0;
}
