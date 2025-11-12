#include<bits/stdc++.h>
using namespace std;
vector<int> f;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			f.push_back(s[i] - '0');
		}
	}
	sort(f.begin(), f.end());
	if(f[f.size() - 1] == 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = f.size() - 1; i >= 0; i--)
	{
		cout << f[i];
	}
	return 0;
}
