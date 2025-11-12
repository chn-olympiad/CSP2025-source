#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 1e6 + 10;
const int M = 1e3 + 10;
int n, m, k;
int h[N], e[N], ne[N], idx,w[N],f[N];
int cost[15][N];
queue<int> q;
int vist[N],dist[N];
int st[M][M];
int add(int a,int b,int c){
	e[idx] = b;w[idx] = c;
	ne[idx] = h[a];h[a] = idx ++;
}
int spfa(int s){
	int ans = 0;
	vist[s] = 1;
	dist[s] = 0;
	q.push(s);
	while(q.size()){
		int t = q.front();q.pop();
		for(int i = h[t];i != -1;i = ne[i]){
			int x = e[i],y = f[i];
			//cout << ne[e[i]];
			if(dist[x] > dist[t] + w[i]){
				dist[x] = dist[t] + w[i];
				ans += w[i];
				//cout << ans << "\n";
				if(!vist[x]) vist[x] = 1,q.push(x);
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(dist, 0x3f, sizeof dist);
	memset(h, -1, sizeof h);
	//cout << h[1];
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	for(int i = 1;i <= k;i ++){
		cin >> cost[i][0];
		for(int j = 1;j <= n;j ++){
			cin >> cost[i][j];
		}
	}
	for(int kk = 1;kk <= k;kk ++){
		for(int i = 1;i <= n;i ++ ){
			for(int j = 1;j <= n;j ++){
				if(cost[kk][j] + cost[kk][i] < st[i][j] || st[i][j] == 0){
					add(i, j, cost[kk][j] + cost[kk][i]);
					st[i][j] = cost[kk][j] + cost[kk][i];
				}
			}
		}
	}
		
	
	cout << spfa(1);
	return 0;

}