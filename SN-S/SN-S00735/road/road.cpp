#include<bits/stdc++.h>
using namespace std;
struct ji{
	int to,lo;
}fi;
int n,m,k,g[10020][10020] = {},vi[15] = {},bo[10020] = {},boo = 0,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int fi1;
	for(int i = 1;i <= m;i++){
		int u,v,m;
		cin >> u >> v >> m;
		g[u][v] = g [v][u] = m;
		fi = {v,0},fi1 = u;
	}
	for(int i = 1;i <= k;i++){
		cin >> vi[i];
		for(int j = 1;j <= n;j++){
			int t;
			cin >> t;
			g[n + i][j] = g[j][n + i] = t;
		}
	}
	queue<ji>q;
	q.push(fi);
	bo[fi1] = 1;
	while(q.size()){
		ji r = q.front();
		for(int i = 1;i <= 10010;i++){
			if(g[i][r.to]){
				ji next = {r.to,r.lo + 1};
				q.push(next);
				bo[r.to] = 1;
				boo ++;
			}
		}
		if(boo == m + k)ans = r.lo;
		q.pop();
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
