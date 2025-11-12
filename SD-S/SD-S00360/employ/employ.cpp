#include <iostream>
#include <vector>

using namespace std;
const int inf =  998244353; 

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector <int> c(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}
	if (n == m)
	{
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 0 || c[i + 1] == 0)
			{
				cout << 0;
				return 0;
			}
		}
		long long ans = 1;
		for (int i = 1; i <= n; ++i)
		{
			ans *= i;
			ans %= inf;
		}
		cout << ans;
	}
	
	return 0;
}
