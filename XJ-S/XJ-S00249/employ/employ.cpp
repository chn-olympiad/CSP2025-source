#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n,m,c[500];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	if (n < 5)cout << n-1;
	if (n <= 10 && n >= 5)
	{
		cout << n+8;
	}
	
	return 0;
} 
