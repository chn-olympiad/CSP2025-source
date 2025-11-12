#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
string s;
int cc[20000];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cc[s[i] - '0']++;
		}
	}
//	for (int i = 0; i <= 9; i++) cout << cc[i] << " ";
//	cout << '\n';
	for (int i = 9; i >= 0; i--)
	{
		for (int k = 1; k <= cc[i]; k++) cout << i;
	}
	return 0;
}

