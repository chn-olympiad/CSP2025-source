#include<bits/stdc++.h>
using namespace std;
int s[5010];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if(n <= 3)
	{
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i];
			ans += s[i];
		}
		sort(s + 1, s + 1 + n);
		if(ans > 2 * s[3]) cout << 1;
		else cout << 0;
	}
	return 0;
}
