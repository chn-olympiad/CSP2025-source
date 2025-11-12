#include <bits/stdc++.h>
using namespace std;
const long long int M = 998244353;

int n,m,t;
int num[505];
string s;
long long int sum,cnt,ans;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	sum = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		num[t]++;
		sum = (sum*i) %M;
	}
	cnt = 1;
	for (int i = 1; i <= m; i++) cnt = (cnt*i) %M;
	for (int i = 1; i <= (n-m); i++)
	{
		long long int k = 0;
		for (int j = 1; j <= i; j++) k += num[j-1];
		cnt = (cnt*(k-i+1)) %M;
	}
	ans = (M + sum - cnt) % M;
	cout << ans;
	
	return 0;
}
