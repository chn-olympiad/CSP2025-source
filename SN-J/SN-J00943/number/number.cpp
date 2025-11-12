#include <bits/stdc++.h>
using namespace std;
string s;''?a''
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s+=a[i];
		}
	}
	for(int i=0;i<s.length();i++)
	{
		int b[10]=0;
		b[s[i]]++;
	}
	for(int i=9;i>=1;i++)
	{
		if(b[i]!=0)
		{
			for(int j=1;j<=b[i];j++)
			{
				
			}
		}
	}
	return 0;
}
