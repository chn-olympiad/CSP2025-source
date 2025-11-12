//考号：SN-J00196 姓名：吴泽铭 学校：白水县城关第一初级中学 
#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string s,c;
	cin >> s;
	for (int i = 0;i < s.length();++i)
	{
		if ((s[i] >= '1') && (s[i] <= '0')){
			c += s[i];
		}
	}
	int num[c.length()];
	for (int i = 0;i <= c.length()-1;++i)
	{
		num[i]++;
	}
	for (int i = s.length();i >= 0;--i)
	{
		for (int j = 1;j <= num[i];++j)
		{
			cout << i;
		}
	}
	return 0;
}
