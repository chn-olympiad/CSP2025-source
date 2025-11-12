#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str, ans;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	for (ll i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			ans += str[i];
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	cout << ans;
	return 0;
}