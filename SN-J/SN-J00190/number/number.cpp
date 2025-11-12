#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
string s;
ll cnt[20];
int main()
{
	freopen("number.in","r", stdin);
	freopen("number.out","w", stdout);
	cin >> s;
	for(ll i = 0; i < s.size(); i ++)
	{
		if(s[i] >= '0'&& s[i] <= '9')
		{
			cnt[s[i] - '0'] ++;
		}
	}
	for(ll i = 9; i >= 0; i --)
	{
		for(ll j = cnt[i]; j >= 1; j --)
		{
			cout << i;
		}
	}
	return 0;
}

