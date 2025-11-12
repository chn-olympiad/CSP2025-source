#include <bits/stdc++.h>
#define ll long long
#define V vector
using namespace std;
const int maxn = 2e5;
const int maxl = 1e6;
const int maxs = 26;
void read(string& s)
{
	int v = getchar(); s = "";
	while(v < 'a' || v > 'z') v = getchar();
	while(v >= 'a' && v <= 'z')
		s += v, v = getchar();
}

int n, q;
int t_cnt[2] = {1, 1};
int tr[2][maxl + 5][maxs + 5];
int dep[2][maxl + 5];
int lst[2][maxl + 5];
int fa[2][maxl + 5];
string s[2];
string t[2];
string str[maxn + 5][2];
map<pair<int, int>, int> tong;

void bfs(int op)
{
	queue<int> que;
	que.push(1);
	lst[op][1] = 1;
	while(!que.empty())
	{
		int u = que.front(); que.pop();
		for(int i = 1; i <= 26; ++i)
		{
			if(!tr[op][u][i]) 
			{
				if(u == 1)
					tr[op][u][i] = 1;
				else 
					tr[op][u][i] = tr[op][lst[op][u]][i];
			}
			else 
			{
				que.push(tr[op][u][i]);
				if(u == 1)
					lst[op][tr[op][u][i]] = 1;
				else
					lst[op][tr[op][u][i]] = tr[op][lst[op][u]][i];
			}
		}
		
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
	{
		read(s[0]), read(s[1]);
		str[i][0] = s[0], str[i][1] = s[1];
		/*int u[2];
		u[0] = u[1] = 1;
		int len = s[0].size();
		for(int j = 0; j < len; ++j)
		{
			int a = s[0][j] - 'a' + 1, b = s[1][j] - 'a' + 1;
			if(!tr[0][u[0]][a])
				tr[0][u[0]][a] = ++t_cnt[0];
			if(!tr[1][u[1]][b])
				tr[1][u[1]][b] = ++t_cnt[1];
			dep[0][tr[0][u[0]][a]] = dep[0][u[0]] + 1;
			fa[0][tr[0][u[0]][a]] = u[0];
			fa[1][tr[1][u[1]][a]] = u[1];
			dep[1][tr[1][u[1]][b]] = dep[1][u[1]] + 1;
			u[0] = tr[0][u[0]][a], u[1] = tr[1][u[1]][b];
			++tong[{u[0], u[1]}];
		}*/
	}
	/*bfs(0);
	bfs(1);*/
	for(int i = 1; i <= q; ++i)
	{
		read(t[0]), read(t[1]);
		ll ans = 0;
		for(int j = 1; j <= n; ++j)
		{
			for(int k = 0; k + str[j][0].size() - 1 < t[0].size(); ++k)
			{
				string nt = t[0];
				int f = 1;
				for(int l = k; l <= k + str[j][0].size()-1; ++l)
				{
					if(t[0][l] != str[j][0][l-k]) f = 0;
				}
				for(int l = k; l <= k + str[j][0].size()-1; ++l)
					nt[l] = str[j][1][l-k];
				if(f && nt == t[1]) ++ans;
			}
		}
		cout << ans << endl;
		/*continue;
		int len = t[0].size(), l = 1e9, r = -1;
		for(int j = 0; j < len; ++j)
		{
			if(t[0][j] != t[1][j])
				l = min(l, j), r = max(r, j);
		}
		int pos[2];
		pos[0] = pos[1] = 1;
		for(int op = 0; op <= 1; ++op)
			for(int i = 0; i <= r; ++i)
			{
				pos[op] = tr[op][pos[op]][t[op][i] - 'a' + 1];
			}
		while(dep[0][pos[0]] >= r - l + 1 && dep[1][pos[1]] >= r - l + 1)
		{
			if(dep[0][pos[0]] == dep[1][pos[1]])
				ans += tong[{pos[0], pos[1]}],
				pos[0] = lst[0][pos[0]],
				pos[1] = lst[1][pos[1]];
			else if(dep[0][pos[0]] > dep[1][pos[1]]) pos[0] = lst[0][pos[0]];
			else pos[1] = lst[1][pos[1]];
		}
		cout << ans << endl;*/
	}
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/