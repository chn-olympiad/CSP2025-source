#include "bits/stdc++.h"

#define ll long long

using namespace std;

string s;
ll hash[105];

int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> s;
	for(ll i = 0;s[i];i ++)
	{
		if('0' <= s[i] && '9' >= s[i])
		{
			ll num = s[i] - '0';
			hash[num] ++;
		}
	}
	for(int i = 9;i >= 0;i --)
	{
		while(hash[i] --)
		{
			cout << i;
		}
	}
	
	return 0;
}

