#include <iostream>
#include <algorithm>
using namespace std;

int a[1000010];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int cur = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cur++;
			a[cur] = s[i] - '0';
		}
	}
	sort(a + 1, a + cur + 1);
	for (int i = cur; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
