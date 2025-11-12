#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll b[12] = {};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll n = s.length();
	for(ll i = 0; i < n;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			b[s[i] - '0']++;
		}
	}
	for(ll i = 9; i >= 0;i--)
	{
		for(ll j = 1; j <= b[i];j++)
		{
			cout << i;
		}
	}
	return 0;
}
