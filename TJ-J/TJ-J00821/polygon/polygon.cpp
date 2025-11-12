#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
long long a[5001];
long long f[5001];
long long mor;
long long ans;
const long long mod = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	f[0] = 1;
	for(int i = 1;i < n;i++)
	{
		mor = (mor * 2) % mod;
		for(int j = 5000;j >= 0;j--)
		{
			if(j + a[i] > 5000) mor = (mor + f[j]) % mod;
			else f[j + a[i]] = (f[j + a[i]] + f[j]) % mod;
		}
		ans = (ans + mor) % mod;
		for(int j = 5000;j > a[i + 1];j--)
		{
			ans = (ans + f[j]) % mod;
		}
	}
	cout << ans;
}
