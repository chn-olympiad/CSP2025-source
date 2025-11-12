#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1010],b=0,m=0,x=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[x]=s[i]-'0';
			x++;
		}
	}
	for(int i=0;i<x-1;i++)
	{
		for(int j=0;j<x-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<x;i++)
	{
		cout<<a[i];
	}
	return 0;
}
