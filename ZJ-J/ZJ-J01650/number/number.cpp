#include <bits/stdc++.h>
using namespace std;

int c[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.size(),k = 1;
	for(int i = 0;i <= len;i++)
		if(s[i] <= '9' && s[i] >= '0')
			c[s[i]-'0']++;
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 1;j <= c[i];j++)
			cout << i;
	}
	return 0;
}

