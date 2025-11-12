#include <bits/stdc++.h>
using namespace std;

namespace p1
{
	string s;
	int a[10];
	void solve()
	{
		cin >> s;
		for(int i = 0; i < s.size(); i++)
			if(s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
		for(int i = 9; i >= 0; i--)
		{
			while(a[i]--) cout << i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	p1::solve();
	return 0; 
} 
