#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a,b,c; 
	for(int i=1;i<=s.size();i++) cout<<s[i];
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i];
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(a[i]>a[i+1])b[i]=a[i];
		else if(a[i]<a[i+1])b[i]=a[i+1];
		else break;
		c[i]=b[i];
	}
	cout<<c;
	return 0;
}

