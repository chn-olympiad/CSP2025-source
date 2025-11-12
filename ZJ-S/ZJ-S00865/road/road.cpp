#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n, m, k;
int c[12], a[12][N], p[12];
struct edge{
	int v, w;
	bool used;
};
vector <edge> f[N];
bool used[N][N];
long long ans, dp[N][N];
int pm=-1e10;
void add_edge(int u, int v, int w){
	edge add;
	add.v=v, add.w=w, add.used=true;
	f[u].push_back(add);
	dp[u][v]=w;
	used[u][v]=true;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++)
			dp[i][j]=1e8;
	}
	for (int i=1; i<=n; i++)
		dp[i][i]=0;
	for (int i=1; i<=m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		add_edge(u, v, w);
		add_edge(v, u, w);
		ans+=w;
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			for (int k=1; k<=n; k++){
				if (dp[j][i]+dp[k][i]<dp[j][k])
					dp[j][k]=dp[j][i]+dp[k][i];
			}
		}
	}
	/*
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	printf("ok\n");
	*/
	for (int i=1; i<=k; i++){
		cin>>c[i];
		for (int j=1; j<=n; j++){
			cin>>a[i][j];
		}
		int add=-1*c[i];
		for (int j=1; j<=n; j++){
			for (int jj=j+1; jj<=n; jj++){
				if (j==jj)
					continue;
				if (dp[j][jj]>=a[i][j]+a[i][jj]){
					add+=dp[j][jj]+(a[i][j]+a[i][jj]);
					if (!used[j][jj])
						add-=dp[j][jj];
					used[j][jj]=false;
				}
			}
		}
		p[i]=add;
		//printf("%d: %d\n", i, p[i]);
		pm=max(pm, add);
	}
	//printf("ans: %lld->", ans);
	ans-=max(0, pm);
	printf("%lld\n", ans);
	return 0;
}