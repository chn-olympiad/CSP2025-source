#include <bits/stdc++.h>
using namespace std;

string s;
int j, a[1000001];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i <= s.size()-1; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[++j] = s[i] - '0';
		}
	}
	sort(a+1, a+j+1, cmp);
	for(int i = 1; i <= j; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}
