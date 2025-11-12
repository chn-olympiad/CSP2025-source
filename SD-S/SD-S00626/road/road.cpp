#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<cmath>
#include<unordered_map>

using namespace std;

struct Node{
	int v;
	long long w;
	bool friend operator < (Node xx, Node yy){
		return xx.w > yy.w;
	}
}tempNode;

int n, m, k;
size_t timea;
long long ans = 1e18, h[10055];
vector<Node> edge[10055];
bool timeok = 0;
bool ok[10055];
priority_queue<Node> q;
long long c[11], a[11][10005];

long long gettree(int rt){
	memset(h, 127, sizeof(h));
	memset(ok, 0, sizeof(ok));
	while(!q.empty())
		q.pop();
	long long ans_ = 0;
	tempNode = {rt, 0};
	q.push(tempNode);
	while(!q.empty())
	{
		Node p = q.top();
		q.pop();
		if(ok[p.v] || p.w > h[p.v])
			continue;
		ans_ += p.w;
		ok[p.v] = 1;
		for(auto j : edge[p.v])
			if(!ok[j.v] && j.w < h[j.v])
			{
				h[j.v] = j.w;
				q.push(j);
			}
	}
	return ans_;
}

void sou(int k_, int summ){
	if(timeok || (clock() - timea) >= 0.96 * CLOCKS_PER_SEC)
		return ;
	if(summ >= ans)
		return;
	if(k_ == k + 1)
	{
		ans = min(ans, summ + gettree(1));
		return ;
	}
	sou(k_ + 1, summ);
	for(int i = 1; i <= n; i++)
	{
		tempNode = {n + k_, a[k_][i]};
		edge[i].push_back(tempNode);
		tempNode = {i, a[k_][i]};
		edge[n + k_].push_back(tempNode);
	}
	sou(k_ + 1, summ + c[k_]);
	for(int i = 1; i <= n; i++)
	{
		edge[i].erase(edge[i].end() - 1, edge[i].end());
		edge[n + k_].erase(edge[n + k_].end() - 1, edge[n + k_].end());
	}
	return ;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	CLOCKS_PER_SEC
	timea = clock();
	scanf("%d%d%d", &n, &m, &k);
	if(k == 0)
	{
		for(int i = 1; i <= m; i++)
		{
			int u, v;
			long long w;
			scanf("%d%d%lld", &u, &v, &w);
			tempNode = {v, w};
			edge[u].push_back(tempNode);
			tempNode = {u, w};
			edge[v].push_back(tempNode);
		}
		
		cout << gettree(1);
		return 0;
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		tempNode = {v, w};
		edge[u].push_back(tempNode);
		tempNode = {u, w};
		edge[v].push_back(tempNode);
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++)
			scanf("%lld", &a[i][j]);
	}
	sou(1, 0);
	cout << ans;
	return 0;
}
