#include<bits/stdc++.h>
using namespace std;
long long a[1000010],ai = 0;
bool cmp(long long x,long long y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for (long long i = 0;i < s.size();i++)
	{
		char x = s[i];
		if (x <= '9' and x >= '0')
		{
			a[ai++] = x - '0';
		}
	}
	sort(a,a + ai,cmp);
//	cout<<ai;
	for (long long i = 0;i < ai;i++)
	{
		cout<<a[i];
	}
	return 0;
}
