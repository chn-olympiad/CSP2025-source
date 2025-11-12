#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353ll;
long long A(long long n,long long m)
{
	long long res = 1;
	for(long long i = 0;i < m;i++)
	{
		res = (res * (n - i)) % mod;
	}
	return res;
}

int main() 
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	string str;
	cin >> str;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int t;
		cin >> t;
		t -= ans;
		if(!t && i > 1)
		{
			ans ++;
		}
	}
	n -= ans;
	cout << A(n,m);
	return 0;
}
