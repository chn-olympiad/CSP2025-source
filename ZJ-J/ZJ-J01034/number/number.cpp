#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int cnt[100],len;
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.length();
	for(int i = 0;i < len;i ++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt[s[i]-'0'] ++;
		}
	}
	for(int k = 9;k >= 0;k --)
	{
		for(int j = 1;j <= cnt[k];j ++)
		{
			cout << k;
		}
	}
	return 0;
}