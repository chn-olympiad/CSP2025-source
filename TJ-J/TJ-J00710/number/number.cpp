#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x > y;
}
int a[1000005] = {0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if (s[i] == '1')
		{
			a[i] = 1;
		}
		else if (s[i] == '2')
		{
			a[i] = 2;
		}
		else if (s[i] == '3')
		{
			a[i] = 3;
		}
		else if (s[i] == '4')
		{
			a[i] = 4;
		}
		else if (s[i] == '5')
		{
			a[i] = 5;
		}
		else if (s[i] == '6')
		{
			a[i] = 6;
		}
		else if (s[i] == '7')
		{
			a[i] = 7;
		}
		else if (s[i] == '8')
		{
			a[i] = 8;
		}
		else if (s[i] == '9')
		{
			a[i] = 9;
		}
	}
	int n = s.size();
	sort(a,a + n,cmp);
	for (int i = 0;i < n;i++)
	{
		if (a[i] >= 1 && a[i] <= 9)
		{
			cout << a[i];
		}
	} 
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '0')
		{
			cout << 0;
		}
	}
	return 0;
} 
