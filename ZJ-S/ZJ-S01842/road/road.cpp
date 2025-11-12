#include <bits/stdc++.h>
#define int long long
using namespace std;

struct counter{
	int pos;
	int value;
	int citycnt;
	int nowcnt;
	vector<bool> visited;
};

typedef struct counter ct;

signed main(void){
	fstream fin("road.in", ios_base::in);
	fstream fout("road.out", ios_base::out);
	int n, m, k;
	fin >> n >> m >> k;
	vector< vector<int> > cities(n + k + 1, vector<int>(n + k + 1, -1));
	vector<int> values(k + n + 1, 0);
	for(int i=1;i<=m;i++){
		int u, v, w;
		fin >> u >> v >> w;
		cities[u][v] = w;
		cities[v][u] = w;
	}
	for(int i=n+1;i<=n+k;i++){
		fin >> values[i];
		for(int j=1;j<=n;j++){
			fin >> cities[i][j];
			cities[j][i] = cities[i][j];
		}
	}
	vector<bool> init(n + k + 1, false);
	init[1] = true;
	queue<ct> q;
	q.push({1, 0, n, 1, init});
	int res = numeric_limits<int>::max();
	while(!q.empty()){
		ct c = q.front();
		q.pop();
		for(int i=2;i<=k+n;i++){
			if(c.pos == i || cities[c.pos][i] == -1 || c.visited[i]) 
				continue;
			ct tmp = c;
			tmp.pos = i;
			tmp.value += cities[c.pos][i] + values[i];
			tmp.nowcnt++;
			if(i > n)
				tmp.citycnt++;
			tmp.visited[i] = true;
			if(tmp.value > res)
				continue;
			if(tmp.nowcnt == tmp.citycnt){
				res = min(res, tmp.value);
				continue;
			}
			q.push(tmp);
		}
	}
	
	fout << res;
	return 0;
}
