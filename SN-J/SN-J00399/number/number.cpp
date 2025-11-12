#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<long long> t;
int main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (long long i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			t.push(s[i] - '0');
		}
	}
	while (!t.empty())
	{
		cout << t.top();
		t.pop();
	}
	return 0;
}
