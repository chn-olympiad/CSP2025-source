#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
const int MAXN = 1e5 + 7;

inline int read()
{
	int x = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		{
			w = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return w * x;
}

int c[MAXN];

const int Mod = 998244353;

//int jiecheng(int x)
//{
//	int sum = 1;
//	for(int i = 1;  i <= x;  i++)
//	{
//		sum = (sum * i) % Mod; 
//	}
//	return sum;
//}

int sum[MAXN];

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n = read(), m = read();
	
	string s;
	
	s = " " + s;
	
	int cnt = 0;
	
	for(int i = 1;  i <= n;  i++)
	{
		c[i] = read();
		if(c[i] == 0)
		{
			cnt++;
		}
	}
	
	bool f = 1;
	for(int i = 1;  i <= s.size();  i++)
	{
		if(s[i] == '0')
		{
			f = 0;
		}
	}
	
//	if(f)
//	{
//if(f)
//	cout<<jiecheng(n) % Mod;
//		if(m != 0)
//		{
//			cout<<0<<endl;
//			return 0;
//		}
//		else
//		{
//			
//		}
//	}
	
	if(n - cnt < m)
	{
		cout<<0<<endl;
		return 0;
	}
	
	if(f)
	{
		sum[0] = 1;
		for(int i = 1;  i <= 500;  i++)
		{
			sum[i] = (i * sum[i-1]) % Mod;
		}
		cout<<(sum[n] + Mod)%Mod<<endl;
	}
	
	return 0;
}
