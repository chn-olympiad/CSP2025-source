#include <bits/stdc++.h>
using namespace std;
int c[200005][3];
string s[200005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i][1] >> s[i][2];
		int m = s[i][1].size(),x,y;
		for(int j = 0;j <= m - 1;j++)
		{
			if(s[i][1][j] == 'b')
			{
				x = j;
			}
			if(s[i][2][j] == 'b')
			{
				y = j;
			}
		}
		c[i][1] = x;
		c[i][2] = y;
	}
	while(q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		int m = t1.size();
		if(m != (int)t2.size())
		{
			cout << "0\n";
			continue;
		}
		if(n <= 100)
		{
			int ans = 0;
			for(int i = 1;i <= n;i++)
			{
				int k = s[i][1].size();
				if(k > m)
				{
					continue;
				}
				for(int j = 0;j <= m - k;j++)
				{
					int f = 1;
					for(int w = j;w <= j + k - 1;w++)
					{
						if(t1[w] != s[i][1][w - j])
						{
							f = 0;
							break;
						}
					}
					if(f == 0)
					{
						continue;
					}
					string r = t1;
					for(int w = j;w <= j + k - 1;w++)
					{
						r[w] = s[i][2][w - j];
					}
					ans += (r == t2);
				}
			}
			cout << ans << "\n";
			continue;
		}
		int x,y;
		for(int i = 0;i <= m - 1;i++)
		{
			if(t1[i] == 'b')
			{
				x = i;
			}
			if(t2[i] == 'b')
			{
				y = i;
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int ls = s[i][1].size();
			if(ls <= m && c[i][1] - c[i][2] == x - y)
			{
				if(c[i][1] <= x)
				{
					if(x - c[i][1] <= m - ls)
					{
						ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
