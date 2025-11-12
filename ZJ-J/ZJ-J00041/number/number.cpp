#include <bits/stdc++.h>
using namespace std;
char x;
string s;
int a[1000005],p;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.length();
	for (int i = 0;i < len;i++)
	{
		x = s[i];
		if ('0' <= x && x <= '9')
		{
			a[++p] = x-'0';
		}
	}
	sort(a+1,a+p+1,cmp);
	if (a[1] == 0) 
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= p;i++)
	{
		cout << a[i];
	}
	
}
