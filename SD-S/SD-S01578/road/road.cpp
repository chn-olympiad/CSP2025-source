#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, k;
const int MAXN = 1e3 + 3;
vector<pair<int,int>> A[MAXN];
int C[12], W2[12][MAXN];
bool visited[MAXN];
int W[MAXN];


bool visited_all(){
	for (int i = 1; i <= n; ++i)
		if (!visited[i])
			return false;
	return true;
}

int dfs(int now, int num){
	visited[now] = true;
	if (visited_all()) return num;
	int t = 0x7fffffff;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < A[i].size(); ++j){
			if (!visited[A[i][j].first])
				t = min(dfs(A[i][j].first, num + A[i][j].second), t);
		}
	}
	visited[now] = false;
	return t;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(W, 0x3f, sizeof(W));
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back({v, w});
		W[v] = min(W[v], w);
	}
	for (int i = 1; i <= k; ++i){
		cin >> C[i];
		for (int j = 1; j <= n; ++j){
			cin >> W2[12][j];
		}
	}
	int t = 0x7fffffff;
	for (int i = 1; i <= n; ++i){
		t = min(dfs(i, 0), t);
	}
	cout << t + 3;
	return 0;
}
