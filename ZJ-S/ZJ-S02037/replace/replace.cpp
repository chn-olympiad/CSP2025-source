#include <bits/stdc++.h>
using namespace std;
int n, q, tg[2][2], ans;
string s[2][200001], t[2];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	bool bl = 1;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[0][i] >> s[1][i];
		for(int j = 0; j <= s[0][i].size()-1; j++)
		{
			tg[0][0] = tg[0][1] = tg[1][0] = tg[1][1] = 0;
			if(s[0][i][j] == 'a') tg[0][0]++;
			else if(s[0][i][j] == 'b') tg[0][1]++;
			if(s[1][i][j] == 'a') tg[1][0]++;
			else if(s[1][i][j] == 'b') tg[1][1]++;
			if(tg[0][1] != 1 || tg[0][0] + tg[0][1] != s[0][i].size() || tg[1][1] != 1 || tg[1][0] + tg[1][1] != s[1][i].size())
				bl = 0;
		}	
	}	
	while(q--)
	{
		cin >> t[0] >> t[1];
		for(int j = 0; j <= t[0].size()-1; j++)
		{
			tg[0][0] = tg[0][1] = tg[1][0] = tg[1][1] = 0;
			if(t[0][j] == 'a') tg[0][0]++;
			else if(t[0][j] == 'b') tg[0][1]++;
			if(t[1][j] == 'a') tg[1][0]++;
			else if(t[1][j] == 'b') tg[1][1]++;
			if(tg[0][1] != 1 || tg[0][0] + tg[0][1] != t[0].size() || tg[1][1] != 1 || tg[1][0] + tg[1][1] != t[1].size())
				bl = 0;
		}
		if(bl)
			for(int j = 0; j <= t[0].size()-1; j++)
				if(t[0][j] != t[1][j])
					for(int i = 1; i <= n; i ++)
						if(j + s[0][i].size()-1 <= t[0].size())
						{
							string u = t[0];
							for(int k = j; k <= j+s[0][i].size()-1; k++)
								u[k] = s[1][i][k-j];
							if(u == t[1]) ans++;
						}	
		cout << ans << endl;
	}	
	return 0;
}
