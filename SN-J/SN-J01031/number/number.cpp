#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5;
int n;
char s[N];
vector<int> vec;

int main()
{
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);

	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> (s + 1);
	n = strlen(s + 1);

	for (int i = 1; i <= n; ++ i)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			vec.push_back(s[i] - '0');
		}
	}

	sort(vec.begin(), vec.end(), greater<int>());

	for (int i : vec)
	{
		cout << i;
	}
	return 0;
}
