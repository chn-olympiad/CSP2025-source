#include<bits/stdc++.h>
using namespace std;
int n, m, c[505], sum = 1;;
string x; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> x;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= m && (n - i) * (n - i - 1) > 0; i++)
	{
		sum += (n - i) * (n - i - 1);
		sum %= 998244353;
	}
	cout << sum;
	return 0;
}

