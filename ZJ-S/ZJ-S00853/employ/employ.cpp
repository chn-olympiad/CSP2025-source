#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int cnt = 0; 
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if(!a) cnt++;
	}
	long long sum = 0;
	for(int i = m; i <= sum - cnt; i++)
	{
		long long mul = 1;
		for(int j = 1; j <= i; j++)
		{
			mul = (mul * i) % MOD;
		}
		sum = (sum + mul) % MOD;
		mul = 1;
		for(int j = 1; j <= n - i; j++)
		{
			mul = (mul * i) % MOD;
		}
		sum = (sum + mul) % MOD;
	}
	cout << sum;
	return 0;
}
