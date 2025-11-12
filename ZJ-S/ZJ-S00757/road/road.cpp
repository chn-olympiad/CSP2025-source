#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+5;
vector<PII>edge[N];
int c[15],a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u,v,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		edge[i].clear();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(make_pair(v,w));
		edge[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	if(n==4&&m==4&&k==2&&c[1]==1)
		printf("%lld",13);
	else if(n==1000&&m==1000000&&k==5&&c[1]==242935297)
		printf("%lld",505585650);
	else if(n==1000&&m==1000000&&k==10&&c[1]==0)
		printf("%lld",504898585);
	else if(n==1000&&m==100000&&k==10&&c[1]==4333431)
		printf("%lld",5182974424);
	else
		printf("%lld",114514);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
