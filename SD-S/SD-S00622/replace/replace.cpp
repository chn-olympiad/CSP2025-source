#include<bits/stdc++.h>
using namespace std;
const int N = 1000007 * 5;
string s[N][3], t[3];
int n, q;
bool c(int l, int r, int x)
{
	int len = r - l + 1;
	for(int k = 0; k < len; k++)
	{
		if(t[1][k + 1] != s[x][1][k] || t[2][k + 1] != s[x][2][k])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	while(q--)
	{
		cin >> t[1] >> t[2];
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(t[1].size() >= s[i][1].size())
			{
				for(int j = 0; j < t[1].size() - s[i][1].size(); j++)
				{
					cout << i << " ";
					if(c(j, j + s[i][1].size(), i))
					{
						ans++;
					}
				}
			}
			cout << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
