#include<bits/stdc++.h>

using namespace std;

const int N = 510;
int n, m;
int d[N];
bool st[N];
int ans = 0;
int now = 0;
string dif;

void dfs(int u)
{
	if(u == n)
	{
		if (now >= m)
			ans  = (ans + 1) % 998244353;
		return ;
	}
	
	for(int i = 1; i <= n ; i ++)
	{	
		if(!st[i])
		{
			st[i] = 1;
			int s = 0;
			for(int j = u - 1; j >= 0 ; j --)
			{
				if(dif[j] == 1)
					break;
				s ++;
			}
			bool flag = 0;
			if(s <= d[i] && dif[u] == '1')
				now ++, flag = 1;
			dfs(u + 1);
			if(flag) now --;
			st[i] = 0;
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);

	cin >> dif;
	
	for(int i = 1; i <= n ; i ++) scanf("%d", &d[i]);
	
	dfs(0);
	cout << ans << "\n";
	
	return 0;
}
