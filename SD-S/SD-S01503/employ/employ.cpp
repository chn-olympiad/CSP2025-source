#include <bits/stdc++.h>
using namespace std;
const long long N = 2e9 + 10;
int s[N];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a;
	cin >> n >> m >> a;
	for(int i = 1; i <= m; i++)
	{
		cin >> s[i];
	}
	if(a <= 1000) cout << a / 50;
	else cout << a / 500; 
	return 0;
}
