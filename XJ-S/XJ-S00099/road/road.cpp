#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int X=1e4+5;
int n,m,k,cnt=0;
struct road{
	int to,w;
};
int c[15],ok[15];
int a[N][N];
road r[X][X];
int num[X];
queue<int> q1;
int dp[N];//1toN
void bfs(){
	q1.push(1);
	while(!q1.empty()){
		int la=q1.front();q1.pop();
		int len=num[la];
		for(int i=0;i<len;i++){
			int ne=r[la][i].to; int mo=r[la][i].w;
			if(dp[la]+mo<dp[ne]&&dp[la]+mo < dp[la]+c[cnt]+a[cnt][ne]){
				dp[ne] = dp[la]+mo;
				q1.push(ne);
			}
			else if(dp[la]+c[cnt]+a[cnt][ne] < dp[la]+mo && dp[ne] > dp[la]+c[cnt]+a[cnt][ne]){
				dp[ne] = dp[la]+c[cnt]+a[cnt][ne];
				q1.push(ne);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u1,v1,w1;
	for(int i=1;i<=m;i++){
		cin>>u1>>v1>>w1;
		num[u1]++;r[u1][num[u1]].w =w1;r[u1][num[u1]].to =v1;
		num[v1]++;r[v1][num[v1]].w =w1;r[v1][num[v1]].to =u1;
	}

	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	bfs();
	cout<<dp[n];
	return 0;
}
