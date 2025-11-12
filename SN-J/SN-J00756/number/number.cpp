// SN-J00756 王昭云 西安市曲江第一学校
#include <bits/stdc++.h>

using namespace std;

string s;
int x,a[1000005];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			a[++x] = s[i] - '0';
		}
	}
	sort(a + 1,a + x + 1);
	for(int i = x;i >= 1;i--)
		cout << a[i];
	return 0;
} 
