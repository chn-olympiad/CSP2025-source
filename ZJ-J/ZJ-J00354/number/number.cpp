#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <int> a;
bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a.push_back(s[i] - '0');
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); ++i)
	{
		printf("%d", a[i]);
	}
	return 0;
}
