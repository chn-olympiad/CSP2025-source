#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> num;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num.push_back(int(s[i] - '0'));
		}
	}
	sort(num.begin(), num.end(), cmp);
	for (vector<int>::iterator i = num.begin(); i != num.end(); ++i)
	{
		cout << *i;
	}
	return 0;
}
