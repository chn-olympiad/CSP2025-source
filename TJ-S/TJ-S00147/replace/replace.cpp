#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int n, q, ans;
string st, s1, s2;
map<string, string> mp;

string sf(int i, int j, string s1)
{
	string s = "";
	for(int a = i; a <= j; a++)
		s += s1[a];
	return s;
}

void dfs(string st, string s2)
{
	if(st == s2)
	{
		ans++;
		return ;
	}
	for(int i = 0; i < st.size(); i++)
	{
		for(int j = i; j < st.size(); j++)
		{
			if(mp[sf(i, j, st)] != "")
			{
				string s0 = mp[sf(i, j, st)];
				for(int k = i; k <= j; k++)
					st[k] = s0[k - i];
				dfs(st, s2);
			}
		}
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		string sx, sy;
		cin >> sx >> sy;
		mp[sx] = sy;
	}
	for(int i = 1; i <= q; i++)
	{
		ans = 0;
		cin >> s1 >> s2;
		st = s1;
		dfs(st, s2);
		cout << ans << endl;
	}
	
	return 0;
}
