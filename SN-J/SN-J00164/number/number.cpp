#include<bits/stdc++.h>
using namespace std;
int a[1000000],num = 1;
int main()
{
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[num] = s[i] - '0';
		}
	}
	sort(a + 1,a + num + 1);
	for(int i = num - 1;i > 0;i--)
	{
		cout << s;
	}
	return 0;
}
