#include <bits/stdc++.h>
using namespace std;
const int MAXN = 998244353;
struct N
{
	int id;
	int c;
};
bool cmp(N a,N b)
{
	return a.c < b.c; 
}
void dfs(int t,int &n,int &m,int &cnt,int num,vector<N> &p,string l,string &s,vector<bool> &b)
{
	if (t > n)
	{
		int die = 0;
		for (int i = 0;i < n;i++)
		{
			if (p[l[i]-'0'].id == 0)
			{
				continue;
			}
			else if (s[i] == '0')
			{
				die++;
				for (int j = i+1;j < n;j++)
				{
					if (p[l[j]-'0'].c <= die)
					{
						p[l[j]-'0'].id = 0;
					}
				}
			}
			else
			{
				num++;
			}
		}
		if (num >= m)
		{
			cnt++;
		}
		return ;
	}
	for (int i = 1;i <= n;i++)
	{
		if (b[i])
		{
			b[i] = false;
			string d = "0" + i;
			dfs(t+1,n,m,cnt,num,p,l+d,s,b);
			b[i] = true;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt = 0,one = 0,before = 0;
	string s;
	bool flag = true;
	cin >> n >> m >> s;
	vector<N> p(n+1);
	vector<bool> b(n+1,true);
	for (int i = 1;i <= n;i++)
	{
		cin >> p[i].c;
		p[i].id = i;
	}
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '0')
		{
			flag = false;
			if (one == 0)
			{
				before++;
			}
		}
		else
		{
			one++;
		} 
	}
	if (flag)
	{
		cnt = 1;
		for (int i = n;i >= 1;i--)
		{
			cnt = (cnt*i) % MAXN;
		}
	}
	else if (m == n && !flag)
	{
		cout << cnt;
	}
	else if (one < m)
	{
		cout << cnt;
	}
	else
	{
		int x;
		for (int i = 1;i <= n;i++)
		{
			if (p[i].c > x)
			{
				x = p[i].c;
			}
		}
		if (x < before)
		{
			cout << cnt;
		}
		else
		{
			vector<N> pe(n+1);
			dfs(1,n,m,cnt,0,p,"",s,b);
			cout << cnt;
		}
	}
	return 0;
}