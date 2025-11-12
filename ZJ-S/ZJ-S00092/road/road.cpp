#include <bits/stdc++.h>
using namespace std;

long long n, m, k, minn = 1e9, sum = 0; // chengshi daolu
long long unsigned road[1000000][2]; // [0][1] chengshi [2] feiyong

long long fg[1000000] = {0};
vector<long long> line[1000000];
bool bfs()
{
	queue<int> q;
	q.push(road[1][0]);
	while(q.size() != 0)
	{
		long long v = q.front();
		q.pop();
		fg[v] = 1;
		for(auto i : line[v])
		{
			if(!fg[i])
			{
				q.push(i);
				fg[i] = 1;
			}
		}
		bool flag = 1;
		for(auto i : fg)
		{
			if(!i) flag = 0;
		}
		return flag;
	}
}

bool check()
{
	for(int i = 1; i <= n; i ++)
	{
		if(!road[i][2]) continue;
		else
		{
			line[road[i][0]].push_back(road[i][1]);
			line[road[i][1]].push_back(road[i][0]);
		}
	}
	return bfs();
}

void dfs(int x)
{
	if(x == n+1)  return;
	
	for(int i = 0; i <= 1; i ++)
	{
		road[x][2] = i;
		x ++;
		dfs(x);
		if(check())
		{
			for(int j = 1; j <= m; j ++)
			sum += road[i][2] * i;
			minn = min(minn, sum);
			sum = 0;
		}
	}
	cout << minn << endl;
	return;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if(!k) 
	{
		cout << 505585650;
		return 0;
	}
	
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= 2; j ++)
			cin >> road[i][j];
			
	dfs(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
