#include<bits/stdc++.h>
using namespace std;

const int N = 510, MOD = 998244353;
int n, m;
string s;
int c[N];

int fun(int x)
{
	int num1 = 1;
	for(int i = 2; i <= x; i ++)
		num1 = num1 * i % MOD;
	int num2 = 1;
	for(int i = n; i >= n - x + 1; i --)
		num2 = num2 * i % MOD;
	return (num1 * num1) / num2 % MOD;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(c[i] > 0)
			ans ++;
	if(ans < m) 
	{
		puts("0");
		return 0;
	}
	else
		cout << fun(ans) % MOD << endl;
	return 0;
}
