# include<bits/stdc++.h>
using namespace std;
const int MX = 500;
const int inf = 998244353;
int n,m;
string s;
int c[MX + 10];
long long ans = 0;
int cnt = 0;
long long fun(int m)
{
	if(m == 1)
	{
		return 1;
	}
	return 1LL * fun(m - 1) * m % inf; 
}
long long cho[MX + 10][MX + 10];

/*void dfs(int u)
{
	if(u > n)
	{
		ans++;
		ans%=inf;
	}
}*/
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	cho[0][0] = 1;
	for(int i = 1;i <= 500;i++)
	{
		cho[i][0] = 1;
		for(int j = 1;j <= 500;j++)
		{
			cho[i][j] = cho[i - 1][j] + cho[i - 1][j - 1];
			cho[i][j]%=inf;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		cnt+=(s[i] == '1');
		cin >> c[i];
		ans+=(c[i] != 0);
	}
	sort(c + 1,c + n + 1);
	if(cnt == n)
	{
		if(ans < m)
		{
			cout << 0 << endl; 
		}
		else if(ans == m)
		{
			cout << fun(m) << endl;
		}
		else if(ans > m)
		{
			int cnt = n - ans;
			for(int i = 1;i <= n - m;i++)
			{
				if(cnt >= c[i])
				{
					cnt++;
				}
				else
				{
					cout << 0 << endl;
					return 0;
				}
			}
			cout << cho[ans][m] * fun(m) % inf << endl; 
		}
		return 0; 
	}
////	sort(c + 1,c + n + 1);
//	dfs(1);
	return 0;
 } 
