#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[10000006];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cur= 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cur++;
			a[cur] = s[i] - '0';
		}
	}
	sort(a+1,a+cur+1,cmp);
	for (int i = 1; i <= cur; i++)
	{
		cout << a[i];
	}
	return 0;
}
