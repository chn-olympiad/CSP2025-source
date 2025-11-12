#include <bits/stdc++.h>

using namespace std;

int a[1000001],n,ans;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cout <<s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			a[i]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	int m=1;
	for (int i=0;i<n;i++)
	{
		if (a[i]==0)
		{
			ans+=m;
		}
		else
		{
			ans+=a[i]*m;
		}
		m*=10;
	}
	cout <<ans;
	return 0;
 } 
