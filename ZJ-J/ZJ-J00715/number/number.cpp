#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			int num = s[i] - '0';
			cnt[num] ++;
		}
	}
	for (int i = 9; i >= 0; i --)
	{
		if (cnt[i] != 0)
		{
			while(cnt[i] != 0)
			{
				cnt[i] --;
				printf("%d", i);
			}
		}
	}
	puts("");
	return 0; 
}
