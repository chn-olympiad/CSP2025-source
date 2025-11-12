#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m;
	cin >> n >> m;
	long long a = 1,b = 1;
	for (long long i = n;i >= n-m+1;i--)
	{
		a = a*i;
		a = a%998244353;
	}
	for (long long i = m;i >= 1;i--)
	{
		b = b*i;
		b = b%998244353;
	}
	cout << (a/b)%998244353;
	return 0;
}
